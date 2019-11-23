/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DyLibLoad.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:34:24 by anri              #+#    #+#             */
/*   Updated: 2019/11/23 15:13:53 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DyLibLoad.hpp"
#include <iostream>

using DyLibLoad::DyLibLoader;

DyLibLoad::LibLoadError::LibLoadError(char const * str) : std::runtime_error(str) {
}

char const *	DyLibLoad::LibLoadError::what() const noexcept(true) {
	return std::runtime_error::what();	
}

DyLibLoader&	DyLibLoader::getInstance() {
	static DyLibLoader	lib;
	return lib;
}

DyLibLoader::DyLibLoader( ) : handler_(nullptr), alloc_(nullptr), dealloc_(nullptr) {
}

DyLibLoader::~DyLibLoader() {
	if (dlerror())
		std::cerr << dlerror() << std::endl;
	closeLib();
}

void	DyLibLoader::closeLib() {
	if (handler_) {
		dealloc_(glib_);
		dlclose(handler_);
		handler_ = nullptr;
		dealloc_ = nullptr;
		alloc_ = nullptr;
	}
}

IGraphicLibrary*	DyLibLoader::changeLib( const std::string & path, int w, int h ) {
	if (last_lib_path_ == path)
		return glib_;
	closeLib();
	return loadLib(path, w, h);
} 

IGraphicLibrary*	DyLibLoader::loadLib( const std::string & path, int w, int h ) {
	last_lib_path_ = path;
	handler_ = dlopen(path.c_str(), RTLD_LAZY | RTLD_LOCAL);
	if (!handler_)
		throw LibLoadError(dlerror());
	dealloc_ = reinterpret_cast<deallocator_t*>(dlsym(handler_, "deallocator"));
	if (!dealloc_)
		throw LibLoadError(dlerror());
	alloc_ = reinterpret_cast<allocator_t*>(dlsym(handler_, "allocator"));
	if (!alloc_)
		throw LibLoadError(dlerror());
	glib_ = alloc_( w, h );
	return glib_;
}