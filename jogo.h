#ifndef _JOGO_H
#define _JOGO_H

#include <iostream>
#include "jogador.h"
#include <vector>

using namespace std;

class Jogo{
	private:
		vector <Jogador> lista_jogador;

	public:
		int add_jogador();
		void listar_jogadores();
        void start_jogo(int max);
		void menu();
		int Randado();
};



#endif