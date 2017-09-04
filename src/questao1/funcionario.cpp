/**
 * @file	funcionario.cpp
 * @brief	Arquivo corpo com a implementacao dos metodos da 
 						classe Funcionario
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	03/09/2017
 * @date	04/09/2017
 */ 

#include "funcionario.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


Funcionario::Funcionario(){
	cpf = "0";
	// Construtor padrao
}

/**
 * @param n nome
 * @param s salario
 * @param d data de admissao
 */

Funcionario::Funcionario(string c, string n, float s, Data &d)  {
	setCpf(c);
	setNome(n);
	setSalario(s);
	setData_admissao(d);

}

/** @return CPF */
string Funcionario::getCpf() {
	return cpf;
}

/**	
 * @details Se o valor dado para o CPF for invalido o programa
 *			exibe uma mesagem de erro e termina a execucao.
 * @param c CPF
 */
void Funcionario::setCpf(string c) {
	if((int)c.size() < 11) {
		cout << "Numero de CPF invalido!!" << endl;
		cout << "Modo de uso: Digite 11 digitos." << endl;
		return;
	}
	for(int i = 0; i < (int)c.size(); i++) {
		if(c[i] < 48|| c[i] > 57) {
			cout << "Numero de CPF invalido!!" << endl;
			cout << "Modo de uso: Digite 11 digitos." << endl;
			return;
		}
	}
	cpf = c;
}


/** @return Nome */
string Funcionario::getNome() {
	return nome;
}


/** @param n nome */
void Funcionario::setNome(string n) {
	nome = n;
}


/** @return Salario */
float Funcionario::getSalario(){
	return salario;
}


/**	
 * @details Se o valor dado para o salario for invalido o programa
 *			exibe uma mesagem de erro e termina a execucao.
 * @param s Salario
 */
void Funcionario::setSalario(float s){

	if(s < 0.0) {
		cout << "Erro, valor do invalido para o salario." << endl;
		return;
	}
	salario = s;
}

/** @return Data de admissao */
Data Funcionario::getData_admissao() {
	return data_admissao;
}


/**	
 * @details Se o valor dado para a data de admissao for invalido o programa
 *			exibe uma mensagem de erro e termina a execucao.
 * @param d Referencia para a data de admissao 
 */
void Funcionario::setData_admissao(Data &d) {
	data_admissao.setDia(d.getDia());
	data_admissao.setMes(d.getMes());
	data_admissao.setAno(d.getAno());
}

/**
 * @param f Referencia para o objeto Funcionario a ser comparado
 * @return True se os objetos forem iguais e false caso contrario
 */
bool Funcionario::operator==(Funcionario &f) {
	if(cpf == f.getCpf()) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @details Se o valor referente a pocentagem de aumento for invalido
 *			o programa exibe uma mensagem  de erro e encerra a execucao
 * @param Valor da porcentagem de aumento
 */
void Funcionario::aumentoSalario(int p){
	if(p < 0) {
		cout << "valor referente a porcentagem de aumento eh invalido!" << endl;
		return; 
	}
	salario = salario * (1 + (p/100)); 
}

/** 
 * @param i Referencia para stream de entrada
 * @param f Referencia para o objeto Funcionario
 * @return Referencia para a stream de entrada
 */ 
istream& operator>> (istream &i, Funcionario &f) {
	cout << "Digite o nome: ";
	i >> f.nome;  
	cout << "Digite o cpf(apenas algorimos): ";
	i >> f.cpf;
	cout << "Digite o salario: ";
	i >> f.salario;
	cout << "Digite a data de admissao(exemplo: 10 05 2015): ";
	i >> f.data_admissao;
	return i;
}

/** 
 * @param o Referencia para stream de saida
 * @param f Referencia para o objeto Funcionario
 * @return Referencia para a stream de saida
 */ 
ostream& operator<< (ostream &o, Funcionario &f) {
	o << "nome: " << f.nome << endl;
	o << "CPF: " << f.cpf << endl;
	o << "Salario: " << f.salario << endl;
	o << "Data de admissao: ";
	o << f.data_admissao;
	return o;

}