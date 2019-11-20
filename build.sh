#!/bin/bash

echo "Checking required libraries..."

echo "SDL installing..."
brew install sdl2
brew install sdl2_image
echo "SDL installed..."

echo "SFML installing..."
brew install sfml
echo "SFML installed..."

echo "OpenGL installing..."
brew install glew
echo "OpenGL installed..."

# libOpenGL         GLUT  OpenGL -lSDL2
## libSDL           -fPIC -lSDL2
## libSFML         -fPIC -lsfml-graphics -lsfml-window -lsfml-system -rpath
## libSFMLSound     -lsfml-audio -lsfml-system
