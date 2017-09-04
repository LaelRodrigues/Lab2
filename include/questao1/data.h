/**
 * @file	data.h
 * @brief	Arquivo cabecalho com a definicao da classe Data
 					que representa uma data
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	02/09/2017
 * @date	03/09/2017
 */

#ifndef DATA_H
#define DATA_H

#include <ostream>
using std::ostream;

#include <istream>
using std::istream;


/**
 * @class   Data data.h
 * @brief   Classe que representa uma data
 * @details Os atributos de uma data sao dia, mes e ano 
 */

class  Data {	
	private:
		int dia;	/**< Dia correspondente a data */
		int mes;	/**< Mes correspondente a data */
		int ano;	/**< Ano correspondente a data */

	public:
		
		/** @brief Construtor padrao */
		Data();

		/** @brief Construtor parametrizado */
		Data(int d, int m, int a);

		/** @brief Retorna o dia */
		int getDia();

		/** @brief Modificar o dia */
		void setDia(int d);	

		/** @brief Retorna o mes */
		int getMes();

		/** @brief Modificar o mes */
		void setMes(int m);	

		/** @brief Retorna o ano */
		int getAno();

		/** @brief Modificar o ano */
		void setAno(int a);	

		/** @brief Sobrecarga do operator de subtracao */
		int operator-(Data &d);

		/** @brief Sobrecarga do operador de extracao de stream */
		friend istream& operator>> (istream &i, Data &d);

		/** @brief Sobrecarga do operador de insercao de stream */
		friend ostream& operator<< (ostream &o, Data &d);
};

#endif