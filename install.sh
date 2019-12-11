#!/bin/bash

echo "Checking required libraries..."

echo "SDL installing..."
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
echo "SDL installed..."

echo "SFML installing..."
brew install sfml
echo "SFML installed..."

echo "OpenGL installing..."
brew install glew
brew install glfw3
echo "OpenGL installed..."
