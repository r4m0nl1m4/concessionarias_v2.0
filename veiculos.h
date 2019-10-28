
//Header for "veiculos" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef veiculos_H
#define veiculos_H

//Bibliotecas
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

//Classe implícita
using namespace std;

class veiculo
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        string marca;
        float preco, chass;
        time_t dataF;
    public:        
        //Construtores
        veiculo(string _marca, float _preco, float _chass, time_t _dataF);
        veiculo(string _marca, float _preco, float _chass);
        veiculo();
        //Destrutor
        ~veiculo();
        //Inserção e obtenção
        static int getTotal();
        void setMarca(string setMarca);
        string getMarca();
        void setPreco(float setPreco);
        float getPreco();
        void setChass(float setChass);
        float getChass();
        void setDataF(time_t setDataF);
        time_t getDataF();
        //Arquivo
        void readDataOnFile(istream & file);          
        void writeDataInFile(ofstream& file);
        //Sobrecarga de Operadores Relacionais
        bool operator ==(veiculo v);
        bool operator !=(veiculo v);
        //Sobrecarga do Operador de Atribuição
        veiculo & operator =(const veiculo & v);
        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, veiculo & v);
        friend ostream & operator <<(ostream & os, veiculo & v);
};

#endif    /* veiculos_H */