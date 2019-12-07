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

# ifdef __APPLE__
#  define SDL_LIB_PATH		"libSDL_lib.dylib"
#  define SFML_LIB_PATH		"libSFML_lib.dylib"
#  define OPENGL_LIB_PATH	"libOpenGL_lib.dylib"
# else
#  define SDL_LIB_PATH		"libSDL_lib.so"
#  define SFML_LIB_PATH		"libSFML_lib.so"
#  define OPENGL_LIB_PATH	"libOpenGL_lib.so"
#endif

enum GraphicalLibrary {
	SDL_Num,
	SFML_Num,
	OpenGL_Num
};

class IGraphicLibrary;

namespace DyLibLoad {
	typedef IGraphicLibrary* allocator_t(int, int);
	typedef void deallocator_t( IGraphicLibrary* );

	class LibLoadError : public std::runtime_error {
	public:
		LibLoadError(const char *);
		virtual ~LibLoadError() = default ;
		virtual char const *	what() const noexcept(true) override ;
	};

	class DyLibLoader {
	public:
		IGraphicLibrary*	loadLib( const std::string &, int, int );
		void	closeLib();
		IGraphicLibrary*	changeLib( const std::string &, int, int );
		~DyLibLoader();
		static DyLibLoader&	getInstance();

	private:
		DyLibLoader( );
		DyLibLoader( const DyLibLoader & ) = delete ;
		DyLibLoader&	operator=( const DyLibLoader & ) = delete ;

		void*			handler_;
		allocator_t		*alloc_;
		IGraphicLibrary*	glib_;
		deallocator_t	*dealloc_;
		std::string last_lib_path_;
	};
}

#endif