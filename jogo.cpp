#include <iostream>
#include "jogador.h"
#include <algorithm>
#include <map>
#include "jogo.h"


using namespace std;

int Jogo::Randado(){
    int topo = 6;
    int bot = 1;
    int random = rand() % (topo-bot +1) + bot;

    return random;
}

int Jogo:: add_jogador(){
    string nome;
    cout << "Digite o nome do novo jogador" <<endl;
    cin.ignore();
    getline(cin, nome);
    cout<<endl;
    
    Jogador *j = new Jogador(nome,0,0);
    this -> lista_jogador.push_back(*j);
    cout<<"Jogador adicionado"<<endl;

    return 1;
}
void Jogo::listar_jogadores(){
	int pp = lista_jogador.size();
	for(int i = 0; i < pp; i++){
		cout << i+1 << " - " << this->lista_jogador[i].getNome() << "/soma dos dados: " << this ->lista_jogador[i].getSomad() << " /status: " << this->lista_jogador[i].getStatus() << endl;
		cout << endl;
	}
}

void Jogo::start_jogo(int max){
		int aux;
		int contador = 0;
		int i = 0;
		int pp = lista_jogador.size();
    while(contador < pp)
		{
			if(i == pp){
				i = -1;
				cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< "Rodada finalizada - Jogadores e suas pontuações abaixo: (Status 0 -> jogando | Status 2 -> parou | Status 3 -> Bateu)"<<endl;
				listar_jogadores();// listar jogadores ordenadamente
				cout<< endl;
				i++;
			}
			cout << lista_jogador[i].getNome()<<endl;
			if (lista_jogador[i].getStatus() == 0) {
				cout << "Deseja jogar (1) ou parar (2)?" << endl;
				cin >> aux;
				if (aux == 1) {
					int x = lista_jogador[i].getSomad() + Randado() + Randado();
					lista_jogador[i].setSomad(x);
					cout << lista_jogador[i].getSomad() <<" é o valor dos seus dados"<< endl;
					if (lista_jogador[i].getSomad()>max) {
						lista_jogador[i].setStatus(3); //ultrapassou o limite
						contador++;
					}
					else if(lista_jogador[i].getSomad() == max){
						cout << lista_jogador[i].getNome() << " Ganhou ao acertar " << max << endl; 
						break;
					}
				}
				if (aux == 2) {
					lista_jogador[i].setStatus(2); // parou de jogar
					contador++;
				}
			}
			else if(lista_jogador[i].getStatus() == 3)
			{
				cout<< lista_jogador[i].getNome() << " Estourou." << endl;
				cout<< endl;	
			}
			i++;
		}
		listar_jogadores();
		cout<< endl;
}

void Jogo::menu(){
    while(true){
		int choice;
		cout << "*========== Randados da sorte ==========*" << endl;
		cout << "1 - Adicionar jogador" << endl;
		cout << "2 - Listar jogadores" << endl;
		cout << "3 - Comecar Jogo" << endl;
		cout << "0 - Sair" << endl;
		cin >> choice;
		cout<<endl;
		if(choice == 1){
			add_jogador();
		}else if(choice == 2){
			listar_jogadores();
		}else if(choice == 3){
			cout << "Qual o valor máximo a ser atingido nessa rodada?"<<endl;
			int k;
			cin >> k;
			start_jogo(k); 
		}else if(choice == 0){
			break;
		}
	}
}
