#TODO

all: main

greetings:
	@echo "Software compílando!"

jogador.o: jogador.cpp
	g++ -c -Wall jogador.cpp
jogo.o: jogo.cpp 
	g++ -c -Wall jogo.cpp 
main.o: main.cpp jogo.cpp
	g++ -c -Wall main.cpp
main: jogador.o jogo.o main.o
	g++ -o main main.o jogador.o jogo.o 