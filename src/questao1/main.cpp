/**
 * @file	main.cpp
 * @brief	Arquivo corpo de teste das classes Data,
 *					Funcionario e Empresa
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	06/09/2017
 * @date	09/09/2017
 */ 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>

#include <ctime>

#include "data.h"
#include "funcionario.h"
#include "empresa.h"

int Funcionario::numFuncionarios = 0;
int Empresa::numEmpresas = 0;

/** @brief Funcao principal */
int main() {

	time_t t = time(NULL);
	tm* tempo = localtime(&t);

	//varial do tipo Data que armazena a data atual */
	Data dataCorrente(tempo->tm_mday, tempo->tm_mon+1, tempo->tm_year+1900);

	int numEmpresas;
	cout << "Digite o numero o numero de empresas: ";
	cin >> numEmpresas;

	Empresa *empresas = new Empresa[numEmpresas];

	string nome, cnpj;
	for(int i = 0; i < numEmpresas; i++) {
		while(1) {
			cout << "------- " << (i+1) <<"º Empresa -------" << endl;
			cout << "Digite o nome: ";
			cin >> nome;
			empresas[i].setNome(nome);
			cout << "digite o cnpj 14 digitos(valores inteiros): ";
			cin >> cnpj;
			empresas[i].setCnpj(cnpj);
			if(empresas[i].getCnpj() != " ") break;
		}
		int opcao;
		do {
			cout << "------- Operacoes -------" << endl;
			cout << "(1) Adicionar funcionario" << endl;
			cout << "(2) Listar os dados dos funcionarios" << endl; 
			cout << "(3) Dar um aumento aos funcionarios" << endl;
			cout << "(4) Listar os dados dos funcionarios em periodo de experiencia" << endl;
			cout << "(5) Media de funcionarios por empresa" << endl;;
			cout << "(0) Sair" << endl;
			cout << "Opcao: ";
			cin >> opcao;

			Funcionario *funcionario = new Funcionario;
			vector<Funcionario*> lista = empresas[i].getFuncionarios();
			vector<Funcionario*>::iterator it;
			int cont, cont2, aumento, media;
			cont = 0;
			cont2 = 0;
			switch(opcao) {
				case 1:
					cout << endl;
					cin >> *funcionario;
					if(funcionario->getCpf() == "0" || funcionario->getSalario() == 0) break;
					if(funcionario-> getData_admissao().getDia() == -1 || funcionario->getData_admissao().
					getMes() == -1 || funcionario->getData_admissao().getAno() == -1) break;
					for(it = lista.begin(); it < lista.end(); ++it) {
						if(**it == *funcionario) {
							cout << "Erro: Funcionario ja foi adicionado." << endl;
							cont++;
						}
					}
					if(cont == 0) empresas[i].setFuncionarios(*funcionario);
					cout << endl;
					cont = 0;
					break;

				case 2:
					if(lista.empty()){
						cout << "Na existem funcionarios na empresa." << endl;
						break;
					}
					for(it = lista.begin(); it < lista.end(); ++it) {
						cout << "_______________________" << endl;
						cout << endl;
						cout << (cont+1) <<"º " << "Funcionario" << endl;
						cout << **it << endl;
						cout << "_______________________" << endl;
						cont++;
					}
					cont = 0;
					break;

				case 3:
					cout << "Digite a porcentagem de aumento(valor inteiro): ";
					cin >> aumento;
					if(aumento <= 0) {
						cout << "valor referente a porcentagem de aumento eh invalido!" << endl;
						break;
					}
					for(it = lista.begin(); it < lista.end(); ++it) {
						*funcionario = **it;
						funcionario->aumentoSalario(aumento);
						**it = *funcionario;
					}
					break;

				case 4:
					for(it = lista.begin(); it < lista.end(); ++it) {
						*funcionario = **it;
						if(funcionario->getData_admissao() - dataCorrente < 90) {
							cont2++;
							cout << "_______________________" << endl;
							cout << endl;
							cout << (cont+1) <<"º " << "Funcionario" << endl;
							cout << **it << endl;
							cout << "_______________________" << endl;
						}
						cont++;
					}
					if(cont2 == 0) {
						cout << "Não exitem funcionarios em periodo de experiencia." << endl;
					}
					cont = 0;
					break;

				case 5:
					media = (Funcionario::numFuncionarios)/(Empresa::numEmpresas);
					cout << "Media = " << media << endl;
					break;

				case 0:
					break;	

				default:
					cout << "Valor invalido!!" << endl;
					break;
			}
		} while(opcao != 0);
	}
	return 0;
}