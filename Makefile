all:
	sh install.sh
	sh build.sh

clean:
	rm -rf build
	rm -rf cmake-build-debug

fclean: clean
	rm -rf Nibbler
	rm -rf libSDL_lib*
	rm -rf libSFML_lib*

re: fclean all