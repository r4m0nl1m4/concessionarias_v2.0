
//Header for "veiculos" C++ application
//Created by r4m0nl1m4 09/09/2019

//Guarda
#ifndef veiculos_H
#define veiculos_H

//Bibliotecas
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

//Classe implícita
using namespace std;

class veiculo
{
    private:
        //propriedades
        string marca;
        float preco, chass;
        time_t dataF;
    public:        
        //contador objetos
        static int total;

        //Construtores
        veiculo(string marca, float preco, float chass, time_t dataF);
        veiculo(string marca, float preco, float chass);
        veiculo();

        //Destrutor
        ~veiculo();

        //Métodos
        static int getTotal();
        void setMarca(string setMarca);
        string getMarca();
        void setPreco(float setPreco);
        float getPreco();
        void setChass(float setChass);
        float getChass();
        void setDataF(time_t setDataF);
        time_t getDataF();

        //Sobrecarga de Operadores Relacionais
        bool operator ==(veiculo a);
        bool operator !=(veiculo a);

        //Sobrecarga do Operador de Atribuição
        veiculo & operator =(const veiculo & a);

        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, veiculo & a);
        friend ostream & operator <<(ostream & os, veiculo & a);
};

#endif    /* veiculos_H */