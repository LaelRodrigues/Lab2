/**
 * @file	jogador.cpp
 * @brief	Arquivo corpo com a implementacao da classe Jogador
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	10/09/2017
 * @date	10/09/2017
 */

#include "jogador.h"

Jogador::Jogador() {
	nome = " ";
	//construtor padrao
}

/** @param n Nome */
Jogador::Jogador(string n) {
	nome = n;
}

/** @return	Nome */
string Jogador::getNome() {
	return nome;
}

/** @param n Nome */
void Jogador::setNome(string n) {
	nome = n;
}

/** @return Dados */
Dado Jogador::getDados() {
	return dados;
}

Jogador::~Jogador() {
	//Destrutor padrao
}

/** @param j Referencia para o objeto Jogador */
Jogador& Jogador::operator=(const Jogador &j) {
	nome = j.nome;
	dados = j.dados;
	return *this;
}
