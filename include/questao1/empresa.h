/**
 * @file	empresa.h
 * @brief	Arquivo cabecalho com a definicao da classe Empresa
 					que representa um empresa
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	06/05/2017
 * @date	07/05/2017
 */

#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

#include <string>
using std::string;

#include <vector>
using std::vector;


/**
 * @class   Empresa empresa.h
 * @brief   Classe que representa uma empresa
 * @details Os atributos de um empresa sao seu nome, cnpj e funcionarios
 */

class Empresa {
	private:
		string nome;				/**< Nome da empresa */
		string cnpj;				/**< Cnpj da empresa(formato: XX.XXX.XXX/YYYY-ZZ) */
		vector<Funcionario*> funcionarios;		/** < Lista de funcionarios */

	public: 
		/** @brief Atributo estatico */
		static int numEmpresas; 

		/** @brief Construtor padrao */
		Empresa();

		/** @brief Destrutor padrao */
		~Empresa();									

		/** @brief Construtor parametrizado */
		Empresa(string n, string c, Funcionario &f);

		/** @brief Retorna o nome da empresa */
		string getNome();								

		/** @brief Modificar o nome da empresa */
		void setNome(string n);							

		/** @brief Retorna o cnpj da empresa */
		string getCnpj();								

		/** @brief Modifica o cnpj da empresa */
		void setCnpj(string c);

		/** @brief Retorna os funcionarios da empresa */
		vector<Funcionario*> getFuncionarios();

		/** @brief Modifica o funcionarios da empresa */
		void setFuncionarios(Funcionario &f);								

};

#endif