/**
 * @file	funcionario.cpp
 * @brief	Arquivo corpo com a implementacao dos metodos da 
 						classe Funcionario
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	03/09/2017
 * @date	09/09/2017
 */ 

#include "funcionario.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


Funcionario::Funcionario(){
	nome = " ";
	cpf = "0";
	salario = -1;
	// Construtor padrao
}


/**
 * @param c cpf
 * @param n nome
 * @param s salarios
 * @param d Data de admissao
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
	if((int)c.size() != 11) {
		cout << "Numero de CPF invalido!!" << endl;
		cout << "Modo de uso: Digite 11 digitos(valores inteiros)." << endl;
		return;
	}
	for(int i = 0; i < (int)c.size(); i++) {
		if(c[i] < 48|| c[i] > 57) {
			cout << "Erro: Numero de CPF invalido!!" << endl;
			cout << "Modo de uso: Digite 11 digitos(valores inteiros)." << endl;
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
		cout << "Erro, valor invalido para o salario." << endl;
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
bool Funcionario::operator==(const Funcionario &f) {
	if(cpf == f.cpf) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @details Se o valor referente a pocentagem de aumento for invalido
 *			o programa exibe uma mensagem  de erro e encerra a execucao
 * @param p Valor da porcentagem de aumento
 */
void Funcionario::aumentoSalario(int p){
	salario = salario * (1.0 + (float(p)/100.0)); 
}

/** 
 * @param i Referencia para stream de entrada
 * @param f Referencia para o objeto Funcionario
 * @return Referencia para a stream de entrada
 */ 
istream& operator>> (istream &i, Funcionario &f) {
	string cpf;
	int s;
	Data d;
	cout << "Digite o nome: ";
	i >> f.nome;
	cout << "Digite o cpf 11 digitos(valores inteiros): ";
	i >> cpf;
	f.setCpf(cpf);
	if(f.getCpf() == "0") return i;
	cout << "Digite o salario: ";
	i >> s;
	f.setSalario(s);
	if(f.getSalario() == -1) return i;
	cout << "Digite a data de admissao(exemplo: 10 05 2015): ";
	i >> d;
	f.setData_admissao(d);
	if(f.getData_admissao().getDia() == -1 || f.getData_admissao().getMes() == -1 || f.getData_admissao().getAno() == -1);
	return i;
	//numFuncionarios++;

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

/** 
 * @param f Referencia para o objeto Funcionario
 * @return Referencia para o objeto que invoca o metodo
 */
Funcionario& Funcionario::operator=(const Funcionario &f) {
	nome = f.nome;
	cpf = f.cpf;
	salario = f.salario;
	data_admissao = f.data_admissao;
	return *this;
} 

Funcionario::~Funcionario() {
	//Destrutor padrao
}