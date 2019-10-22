
//Header for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Guarda
#ifndef concessionarias_H
#define concessionarias_H

//Bibliotecas
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <string>

//Bibliotecas novas
#include "./veiculos.h"
#include "./automoveis.h"
#include "./caminhoes.h"
#include "./motos.h"

//Classe implícita
using namespace std;

class concessionaria
{
    protected:
        //propriedades
        string nome, cnpj;
        list<veiculo> estoque;
        list<caminhao> estoqueCaminhoes;
        list<moto>     estoqueMotos;
        int naut;
    public:
        //contador objetos
        static int total;

        //Construtores
        concessionaria(string _nome, string _cnpj, list<veiculo> _estoque, list<caminhao> _estoqueCaminhoes, list<moto> _estoqueMotos);
        concessionaria(string _nome, string _cnpj);
        concessionaria();

        //Destrutor
        ~concessionaria();

        //Métodos
        static int getTotal();
        void setNome(string setNome);
        string getNome();
        void setCNPJ(string setCNPJ);
        string getCNPJ();
        void setEstoque(list<veiculo> setEstoque);
        list<veiculo> getEstoque();
        void setEstoqueCaminhoes(list<caminhao> setEstoqueCaminhoes);
        list<caminhao> getEstoqueCaminhoes();
        void setEstoqueMotos(list<moto> setEstoqueMotos);
        list<moto> getEstoqueMotos();
        list<veiculo> getProducao_trimestre();
        template <typename T, typename U>
        bool checkEstoque(T begin, T end, U element);
        void add_veiculo();
        void increase_tax_rate(float n);

        //Sobrecarga de Operadores Relacionais
        bool operator ==(concessionaria a);
        bool operator !=(concessionaria a);

        //Sobrecarga do Operador de Atribuição
        concessionaria & operator =(const concessionaria & a);

        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, concessionaria & a);
        friend ostream & operator <<(ostream & os, concessionaria & a);
};

#endif    /* concessionarias_H */