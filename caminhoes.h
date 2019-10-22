
//Header for "caminhoes" C++ application
//Created by r4m0nl1m4 09/09/2019

//Guarda
#ifndef caminhoes_H
#define caminhoes_H

//Bibliotecas
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

//Bibliotecas novas
#include "./automoveis.h"

//Classe implícita
using namespace std;

class caminhao : public automovel 
{
    protected:
        //propriedades
        string carga;
    public:        
        //contador objetos
        static int total;

        //Construtores
        caminhao(string _marca, float _preco, float _chass, time_t _dataF, string _motor, string _carga);
        caminhao(string _marca, float _preco, float _chass, string _motor, string _carga);
        caminhao();

        //Destrutor
        ~caminhao();

        //Métodos
        static int getTotal();
        void setCarga(string setCarga);
        string getCarga();

        //Sobrecarga de Operadores Relacionais
        bool operator ==(caminhao c);
        bool operator !=(caminhao c);

        //Sobrecarga do Operador de Atribuição
        caminhao & operator =(const caminhao & c);

        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, caminhao & c);
        friend ostream & operator <<(ostream & os, caminhao & c);
};

#endif    /* caminhoes_H */