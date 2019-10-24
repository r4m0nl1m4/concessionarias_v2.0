
//Header for "concessionarias" C++ application
//Created by r4m0nl1m4 29/10/2019

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
#include "./estoque.h"
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
        estoque<caminhao> caminhoes;
        struct e
        {
            estoque<caminhao> caminhoes;
            estoque<moto> motos;
        } stock;
        int naut;
    public:
        //contador objetos
        static int total;

        //Construtores
        concessionaria(string _nome, string _cnpj, e _est);
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
        void setEstoque(e setEstoque);
        //e getEstoque();
        
        void add_veiculo();
        int getProducao_trimestre();
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