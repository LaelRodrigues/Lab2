/**
 * @file	data.cpp
 * @brief	Arquivo corpo com a implementacao da classe Data
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	03/09/2017
 * @date	03/09/2017
 */

#include "data.h"

#include <iomanip>
using std::setfill;
using std::setw;

#include <iostream>
using std::cout;
using std::endl;


Data::Data() {
	dia = -1;
	mes = -1;
	ano = -1;
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


/** @param d Referencia para o objeto Data
 *	@return 
 */
int Data::operator-(Data &d) {
	int tMes, tAno, tMes2, tAno2;
	tAno = 0;
	tAno2 = 0;

	for(int i = 1; i <= ano; i++){
		if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
			tAno += 366;
		}
		else {
			tAno += 365;
		}
	}
	cout << d.ano << endl;
	for(int i = 1; i <= d.ano; i++) {
		if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
			tAno2 += 366; 
		}
		else {
			tAno2 += 365;
		}
	}
	tMes = mes * 30;
	tMes2 = d.getMes() * 30;

	int data1 = tAno + tMes + dia;
	int data2 = tAno2 + tMes2 + d.getDia();
	cout << "dias: " << data1 << " " << data2 << endl;
	int total = data2 - data1;
	cout << "total: " << total << endl;

	return total;   
}


/** 
 * @param i Referencia para stream de entrada
 * @param d Referencia para o objeto Data
 * @return Referencia para a stream de entrada
 */ 
istream& operator>> (istream &i, Data &d) {
	i >> d.dia >> d.mes >> d.ano;
	return i;
}

/** 
 * @param o Referencia para stream de saida
 * @param d Referencia para o objeto Data
 * @return Referencia para a stream de saida
 */ 
ostream& operator<< (ostream &o, Data &d) {
	o << setw(2) << setfill('0') << d.dia << "/";
	o << setw(2) << setfill('0') << d.mes << "/";
	o << setw(2) << setfill('0') << d.ano;
	return o;
}