# Script unix de compilation du projet
g++ -Wall -Werror -pedantic -std=c++17 -o game ./src/main.cpp ./glad/glad.c -lSDL2 -lm -v