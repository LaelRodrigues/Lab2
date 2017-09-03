/**
 * @file	data.cpp
 * @brief	Arquivo corpo com a implementacao da classe Data
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	03/09/2017
 * @date	03/09/2017
 */

#include "data.h"

#include <iostream>
using std::cout;
using std::endl;


Data::Data() {
	// Construtor padrao
}

/**
 * @param d Dia
 * @param m Mes
 * @param a Ano
 */
Data::Data(int d, int m, int a) {
	setDia(d);
	setMes(m);
	setAno(a);	
}

/** @return Nome */
int Data::getDia() {
	return dia;
}

/**	
 * @details Se o valor dado para o dia for invalido o programa
 *			exibe uma mensagem de erro e termina a execucao.
 * @param d Dia
 */
void Data::setDia(int d) {
	if(d <= 0 || d > 31) {
		cout << "O Valor do dia eh invalido!" << endl;
		return;
	} 
	dia = d;
}

/** @return Mes */
int Data::getMes() {
	return mes;
}

/**	
 * @details Se o valor dado para o mes for invalido o programa
 *			exibe uma mensagem de erro e termina a execucao.
 * @param m Mes
 */
void Data::setMes(int m) {
	if(m <= 0 || m > 12) {
		cout << "O valor do mes eh invalido!" << endl;
		return;
	}
	mes = m;
}

/** @return Ano */
int Data::getAno() {
	return ano;
}

/**	
 * @details Se o valor dado para o ano for invalido o programa
 *			exibe uma mensagem de erro e termina a execucao.
 * @param a Ano
 */
void Data::setAno(int a) {
	if(a <= 0) {
		cout << "O valor do ano eh invalido!" << endl;
		return;
	}
	ano = a;
}

/** 
 * @param i Referencia para stream de entrada
 * @param d Referencia para o objeto Data
 * @return Referencia para a stream de entrada
 */ 
ifstream& operator>> (ifstream &i, Data &d) {
	i >> d.dia >> d.mes >> d.ano;
	return i;
}

/** 
 * @param i Referencia para stream de saida
 * @param d Referencia para o objeto Data
 * @return Referencia para a stream de saida
 */ 
ofstream& operator<< (ofstream &o, Data &d) {
	o << d.dia << "/" << d.mes << "/" << d.ano << endl;
	return o;
}