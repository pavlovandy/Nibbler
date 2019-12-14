/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DyLibLoad.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:30:58 by anri              #+#    #+#             */
/*   Updated: 2019/12/07 18:46:17 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_OTHER_DYLIBLOAD_HPP
# define NIBBLER_OTHER_DYLIBLOAD_HPP

# include "../graphic/IGraphicLibrary.hpp"
# include <dlfcn.h>
# include <exception>
# include "../sound/ISoundLib.hpp"

# ifdef __APPLE__
#  define SDL_LIB_PATH		"libSDL_lib.dylib"
#  define SFML_LIB_PATH		"libSFML_lib.dylib"
#  define OPENGL_LIB_PATH	"libOpenGL_lib.dylib"
#  define SFMLSOUND_LIB_PATH "libSFML_audioLib.dylib"
# else
#  define SDL_LIB_PATH		"/home/anri/CLionProjects/Nibbler/libSDL_lib.so"
#  define SFML_LIB_PATH		"/home/anri/CLionProjects/Nibbler/libSFML_lib.so"
#  define OPENGL_LIB_PATH	"/home/anri/CLionProjects/Nibbler/libOpenGL_lib.so"
#  define SFMLSOUND_LIB_PATH "/home/anri/CLionProjects/Nibbler/libSFML_audioLib.so"
#endif

namespace DyLibLoad {
	class LibLoadError : public std::runtime_error {
	public:
		LibLoadError(const char *);
		virtual ~LibLoadError() = default ;
		virtual char const *	what() const noexcept(true) override ;
	};

    template < class T >
	class DyLibLoader {
	public:

        typedef T* allocator_t(int, int);
        typedef void deallocator_t( T* );

        T*	loadLib( const std::string &, int, int );
		void	closeLib();
        T*	changeLib( const std::string &, int, int );
		~DyLibLoader<T>();

		static DyLibLoader<T>&	getInstance();

	private:
		DyLibLoader<T>( );
		DyLibLoader<T>( const DyLibLoader<T> & ) = delete ;
		DyLibLoader<T>&	operator=( const DyLibLoader<T> & ) = delete ;

		void*			handler_;
		allocator_t		*alloc_;
        T*	            lib_;
		deallocator_t	*dealloc_;
		std::string     last_lib_path_;
	};
}

#endif