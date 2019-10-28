
//Header for "concessionarias" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef concessionarias_H
#define concessionarias_H

//Bibliotecas
#include <cstdlib>
#include <fstream>
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
    public:
        //Estrutura de dados de um proprietario
        struct p
        {
            string nome;
            string codigo;
        };
        //Estrutra de dados do juridico
        struct j
        {
            string nome;
            string cnpj;
        };
        //Estrutura de dados do estoque
        struct e
        {
            estoque<caminhao> caminhoes;
            estoque<moto> motos;
            int naut;
        };
        //Contador objetos
        static int total;
    private:
        //Dados de um proprietario
        p prop;
        //Lista de proprietarios
        list<p> proprietarios;
        //Dados da concessionária
        j juridico;
        //Dados do estoque
        e stock;
    public:
        //Construtores
        concessionaria(list<p> _proprietarios, j _juridico, e _est);
        concessionaria(list<p> _proprietarios, j juridico);
        concessionaria();
        //Destrutor
        ~concessionaria();
        //Inserção e obtenção
        static int getTotal();
        void setProprietarios(list<p> setProprietarios);
        //list<p> getProprietarios();
        void setJuridico(j setJuridico);
        j    getJuridico();
        void setEstoque(e setEstoque);
        void setEstoque_increase_tax_rate(float n);
        e    getEstoque();
        int  getEstoque_producao_trimestral();
        void getEstoque_veiculo(float chass);
        //Apresentação
        void printProprietarios();
        void printJuridico();
        void printEstoque();
        void printEstoque_producao_trimestral();
        //Arquivo
        void readDataOnFile();
        void writeDataInFile();        
        //Sobrecarga de Operadores Relacionais
        bool operator ==(concessionaria a);
        bool operator !=(concessionaria a);
        //Sobrecarga do Operador de Atribuição
        concessionaria & operator =(const concessionaria & a);
        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, concessionaria & c);
        friend ostream & operator <<(ostream & os, concessionaria & c);
};

#endif    /* concessionarias_H */