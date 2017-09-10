/**
 * @file	main.cpp
 * @brief	Arquivo corpo de teste das classes Dado e
 *					Jogador
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	10/09/2017
 * @date	10/09/2017
 */ 


#include "dado.h"
#include "jogador.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int Jogador::valor = 0;

/** @brief Funcao principal */
int main() {
	cout << "-----------jogo de dados-------------" << endl;
	cout << "O objetivo e ficar mais proximo e abaixo de um valor N" << endl;
	cout << endl;
	int numJogadores;
	string nome;
	cout << "Digite o numero de jogadores: " << endl;
	cin >> numJogadores;

	Jogador *jogadores = new Jogador[numJogadores];
	cout << "Digite os nomes dos jogadores: " << endl;
	for(int i = 0; i < numJogadores; i++) {
		cin >> nome;
		jogadores[i].setNome(nome); 
	}

	int n;
	cout << "Digite o Valor N:" << endl;
	cin >> n;
	Jogador::valor = n;

	int *soma = new int[numJogadores];
	int *estado = new int[numJogadores];
	for(int i = 0; i < numJogadores; i++) {
		estado[i] = 1;
	}

	int controle1 = numJogadores;
	int controle2 = numJogadores;
	int opcao;
	while(controle1 != 0 && controle2 != 1) {
		for(int i = 0; i < numJogadores; i++) {
			if(estado[i] == 0) {
				continue;
			}
			else {
				do { 
					cout << "Jogador " << i+1 << endl;
					cout << "(1) jogar os dados " << endl;
					cout << "(0) parar(e nao jogar mais na rodada) " << endl;
					cout << "opcao: ";
					cin >> opcao;
					if(opcao == 0) {
						controle1--;
						estado[i] = 0;
					}
					else if(opcao == 1){
						jogadores[i].getDados().jogar();
						soma[i] =  jogadores[i].getDados() + soma[i];
						cout << "Pontuacao atual = " <<  soma[i] << endl;
						cout << endl;
						if(soma[i] > Jogador::valor) {
							controle1--;
							controle2--;
							estado[i] = 0;
						}
						else if(soma[i] == Jogador::valor){
							controle1 = 0;
							break;
						}
					}
					else {
						cout << "Valor invalido!!" << endl;
					}
				} while(opcao != 1 && opcao != 0);
				if(controle2 == 1) break;
				if(controle1 == 0) break;
			}
		}
	}

	Jogador vencedor;
	int cont, menor;
	cont = 0;
	for(int i = 0; i < numJogadores; i++) {
		if(soma[i] > Jogador::valor) {
			continue;
		}
		else if(soma[i] <= Jogador::valor && cont == 0){
			menor = Jogador::valor - soma[i];
			vencedor = jogadores[i];
			cont++;
		}
		else if(soma[i] <= Jogador::valor && (Jogador::valor - soma[i]) < menor){
			menor = Jogador::valor - soma[i];
			vencedor = jogadores[i];
		}
	}
	for(int i = 0; i < numJogadores; i++) {
		cout << jogadores[i].getNome() << ", pontuacao = " << soma[i] << endl;
	}
	cout << "Vencedor: " << vencedor.getNome() << endl;
	return 0;
}