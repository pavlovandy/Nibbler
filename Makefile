all:
	sh build.sh

install:
	sh install.sh

clean:
	rm -rf build
	rm -rf cmake-build-debug

fclean: clean
	rm -rf Nibbler
	rm -rf libSDL_lib*
	rm -rf libSFML_lib*
	rm -rf libOpenGL_lib*

re: fclean all