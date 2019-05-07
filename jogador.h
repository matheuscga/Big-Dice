#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include <string>

using namespace std;

class Jogador{
	private:
		string nome;
		int status;  
		int somad;

	public:
		Jogador(string nome, int status, int somad);

		void setNome(string nome);
		string getNome();

		void setStatus(int status);
		int getStatus();

		void setSomad(int somad);
		int getSomad();
};

#endif