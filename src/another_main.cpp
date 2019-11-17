/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 02:19:58 by anri              #+#    #+#             */
/*   Updated: 2019/11/17 02:49:48 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>
#include "graphic/IGraphicLibrary.hpp"
#include <unistd.h>

typedef IGraphicLibrary* allocator_t(int, int);
typedef void deallocator_t( IGraphicLibrary* );

int		main() {
	auto handler = dlopen("./graphic/SDL/libSDL.so", RTLD_LAZY | RTLD_LOCAL);
	if (!handler)
	{
		std::cerr << dlerror() << std::endl;
		return (1);
	}
	allocator_t* fun = reinterpret_cast<allocator_t*>(dlsym(handler, "allocator"));
	auto GL = (*fun)( 400, 400 );
	sleep(5);
	deallocator_t* fun2 = reinterpret_cast<deallocator_t*>(dlsym(handler, "deallocator"));
	(*fun2)(GL);
	dlclose(handler);
	return (0);
}