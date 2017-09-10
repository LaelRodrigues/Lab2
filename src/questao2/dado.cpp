/**
 * @file	dado.cpp
 * @brief	Arquivo corpo com a implementacao da classe Dado
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	09/09/2017
 * @date	09/09/2017
 */

#include "dado.h"

std::random_device Dado::rd{};
std::mt19937 Dado::gen(Dado::rd());
std::uniform_int_distribution<> Dado::dis(1,6);

Dado::Dado() {
	d1 = round(dis(gen));
	d2 = round(dis(gen));
	//Construtor padrao
}

/**
 * @param d1 Dado 1
 * @param d2 Dado 2
 */
Dado::Dado(int _d1, int _d2) {
	d1 = _d1;
	d2 = _d2;
}
/** @return Soma dos dados */
int Dado::jogar() {
	d1 = round(dis(gen));
	d2 = round(dis(gen));
	return d1+d2;
}

/** @return Dado 1*/
int Dado::getD1(){
	return d1;
}

/** @return Dado 2*/
int Dado::getD2(){
	return d2;
}

Dado Dado::operator+(const Dado &d)  {
	d1 += d.d2;
	d2 += d.d2;
	return Dado(d1,d2);
}

int Dado::operator+(const int &val) {
	int soma = val + d1 + d2;
	return soma;
}

ostream& operator<< (std::ostream &o, Dado const &d)  {
	o << d.d1 << " " << d.d2;
	return o;
}

Dado& Dado::operator=(const Dado &d) {
	d1 = d.d1;
	d2 = d.d2;
	return *this;
}


Dado::~Dado() {
	//Destrutor padrao
}