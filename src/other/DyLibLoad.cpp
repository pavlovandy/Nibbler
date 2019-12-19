/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DyLibLoad.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:34:24 by anri              #+#    #+#             */
/*   Updated: 2019/12/07 17:33:33 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DyLibLoad.hpp"
#include <iostream>

namespace DyLibLoad {

    LibLoadError::LibLoadError(char const *str) : std::runtime_error(str) {
    }

    char const *LibLoadError::what() const noexcept(true) {
        return std::runtime_error::what();
    }

    template < class T >
    DyLibLoader<T> &DyLibLoader<T>::getInstance() {
        static DyLibLoader lib;
        return lib;
    }

    template < class T >
    DyLibLoader<T>::DyLibLoader() : handler_(nullptr), \
    alloc_(nullptr), lib_(nullptr), dealloc_(nullptr) {}

    template < class T >
    DyLibLoader<T>::~DyLibLoader() {
        closeLib();
    }

    template < class T >
    void DyLibLoader<T>::closeLib() {
        if (handler_) {
            dealloc_(lib_);
            dlclose(handler_);
            handler_ = nullptr;
            dealloc_ = nullptr;
            alloc_ = nullptr;
        }
    }

    template < class T >
    T *DyLibLoader<T>::changeLib(const std::string &path, int w, int h) {
        if (last_lib_path_ == path)
            return lib_;
        closeLib();
        return loadLib(path, w, h);
    }

    template < class T >
    T *DyLibLoader<T>::loadLib(const std::string &path, int w, int h) {
        last_lib_path_ = path;
        handler_ = dlopen(path.c_str(), RTLD_LAZY | RTLD_LOCAL);
        if (!handler_)
			throw LibLoadError(dlerror());
        dealloc_ = reinterpret_cast<deallocator_t *>(dlsym(handler_, "deallocator"));
        if (!dealloc_)
            throw LibLoadError(dlerror());
        alloc_ = reinterpret_cast<allocator_t *>(dlsym(handler_, "allocator"));
        if (!alloc_)
            throw LibLoadError(dlerror());
        lib_ = alloc_(w, h);
        return lib_;
    }

    template
    class DyLibLoader<IGraphicLibrary>;

    template
    class DyLibLoader<ISoundLib>;

}