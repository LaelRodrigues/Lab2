/**
 * @file	jogador.h
 * @brief	Arquivo cabecalho com a definicao da classe Jogador
 					que representa um jogador
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	09/09/2017
 * @date	09/09/2017
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#include "dado.h"

#include <string>
using std::string;

/**
 * @class   Jogador jogador.h
 * @brief   Classe que representa um jogador
 * @details Os atributos da classe Dado sao nome, dados
 */

class Jogador {
	private:
		string nome; 	/**< Nome do jogador */
		Dado dados;		/**< Dados */	

	public:
		
		/** @brief valor maximo que o jogador pode chegar */
		static int valor;

		/** @brief Construtor padrao */
		Jogador();
	
		/** @brief Destrutor padrao */
		~Jogador();

		/** @brief Construtor parametrizado */
		Jogador(string n);

		/** @brief Retorna o nome */
		string getNome();

		/** @brief Modifica o nome */
		void setNome(string n);

		/** @brief Retorna os dados */    
		Dado getDados();

		/** @brief Sobrecarga do operador de igualdade */
		Jogador& operator=(const Jogador &j);
};

#endif