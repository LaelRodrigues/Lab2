/**
 * @file	dado.h
 * @brief	Arquivo cabecalho com a definicao da classe Dado
 					que representa um dados
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	09/09/2017
 * @date	09/09/2017
 */

#ifndef DADO_H
#define DADO_H

#include <random>

#include <ostream>
using std::ostream;

/**
 * @class   Dado dado.h
 * @brief   Classe que representa dados
 * @details Os atributos da classe Dado sao d1, d2
 */

class Dado {
	private:
		int d1;			/**< Dado 1 */
		int d2;			/**< Dado 2 */

	public:

		/** @brief Instancia o gerador de numeros*/
		static std::random_device rd;  

		/** @brief Gerador de numero randomicos */
		static std::mt19937 gen;
	
		/** @brief Distribuicao com valores inteiros */
		static std::uniform_int_distribution<> dis;

		/** @brief Construtor padrao */
		Dado();	

		/**@brief Destrutor padrao */
		~Dado();

		/** @brief Construtor parametrizado*/
		Dado(int _d1, int _d2);

		/** @brief Sobrecarga do operador de insercao em stream */
		friend ostream& operator<< (ostream &o, Dado const &d);

		/** @brief Jogar os dados */
		int jogar();

		/** @brief Retorna o valor de d1 */		
		int getD1();

		/** @brief Retorna o valor de d2 */		
		int getD2();

		/** @brief Sobrecarga do operador de adicao para o objeto dado */
		Dado operator+(const Dado &d);

		/**
		 * @brief Sobrecarga do operador de adicao para somar um objeto  
		 * 		  dado a valores inteiros
		 */
		int operator+(const int &val);

		/** @brief Sobrecarga do operador de adicao para o objeto dado */
		Dado& operator=(const Dado &d);


};
#endif