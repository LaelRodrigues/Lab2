/**
 * @file	funcionario.h
 * @brief	Arquivo cabecalho com a definicao da classe Funcionario
 					que representa um funcionario
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	03/09/2017
 * @date	04/09/2017
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using std::string;
using std::getline;

#include <ostream>
using std::ostream;

#include <istream>
using std::istream;


#include "data.h"


/**
 * @class   Funcionario funcionario.h
 * @brief   Classe que representa um funcionario
 * @details Os atributos de um funcionario sao seu rg, nome, salario e data de admissao
 */

class Funcionario {
	private:
		string nome;		/**< Nome do funcionario */
		string cpf; 		/**< CPF do funcionario */
		float salario;		/**< Salario do funcionario */
		Data data_admissao;	/**< Data de admissao do funcionario(formato: DD/MM/AAAA) */

	public: 

		/** @brief Atributo estatico */
		static int numFuncionarios;

		/** @brief Construtor padrao */
		Funcionario();								

		/** @brief Destrutor padrao */
		~Funcionario();

		/** @brief Construtor parametrizado */
		Funcionario(string c, string n, float s, Data &data_admissao);	

		/** @brief Retorna o nome do funcionario */
		string getNome();								

		/** @brief Modificar o nome do funcionario */
		void setNome(string n);

		/** @brief Retorna o CPF do funcionario */
		string getCpf();

		/** @brief Modificar o CPF do funcionario */
		void setCpf(string c);							

		/** @brief Retorna o valor do salario do funcionario */
		float getSalario();								

		/** @brief Modifica o valor do salario do funcionario */
		void setSalario(float s);						

		/** @brief Retorna a data de admissao do funcionario */
	    Data getData_admissao();						

	    /** @brief Modifica a data de admissao do funcionario */
		void setData_admissao(Data &d);

		/** @brief Sobrecarga do operador de comparacao */
		bool operator==(const Funcionario &f);

		/** @brief Metodo para aumento de salario */
		void aumentoSalario(int p);	

		/** @brief Sobrecarga do operator de extracao de stream */
		friend istream& operator>> (istream &i, Funcionario &f);

		/** @brief Sobrecarga do operator de insercao de stream */
		friend ostream& operator<< (ostream &o, Funcionario &f);

		/** @brief Sobrecarga do operador de igualdade */
		Funcionario& operator=(const Funcionario &f);

};

#endif
