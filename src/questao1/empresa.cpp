/**
 * @file	empresa.cpp
 * @brief	Arquivo corpo com a implementacao dos metodos da 
 						classe Empresa
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	05/09/2017
 * @date	09/09/2017
 */ 

#include "empresa.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

Empresa::Empresa(){
	cnpj = " ";
	numEmpresas++;
	// Construtor padrao
}

/**
 * @param n nome
 * @param c cnpj
 * @param f funcionario
 */

Empresa::Empresa(string n, string c, Funcionario &f) {
	setNome(n);
	setCnpj(cnpj);
	setFuncionarios(f);
	numEmpresas++;

}

/** @return Nome */
string Empresa::getNome(){
	return nome;
}

/** @param n Nome */
void Empresa::setNome(string n){
	nome = n;
}

/** @return cnpj */
string Empresa::getCnpj() {
	return cnpj;
}

/**	
 * @details Se o valor dado para o CNPJ for invalido o programa
 *			exibe uma mesagem de erro e termina a execucao.
 * @param c cnpj
 */
void Empresa::setCnpj(string c) {
	if((int)c.size() != 14 ) {
		cout << "Numero de CNPJ invalido!!" << endl;
		cout << "Modo de uso: Digite 14 digitos." << endl;
		return;
	}
	for(int i = 0; i < (int)c.size(); i++) {
		if(c[i] < 48|| c[i] > 57) {
			cout << "Erro: Numero de CNPJ invalido!!" << endl;
			cout << "Modo de uso: Digite 14 digitos(valores inteiros)." << endl;
			return;
		}
	}
	cnpj = c;
}

/** @return	apontador para a lista de funcionairos */
vector<Funcionario*> Empresa::getFuncionarios() {
	return funcionarios;
}

/** @param f referencia para um objeto funcionario */
void Empresa::setFuncionarios(Funcionario &f) {
	Funcionario::numFuncionarios++;
	funcionarios.push_back(new Funcionario(f));
}

//Destrutor padrao
Empresa::~Empresa() {
	funcionarios.clear();
}