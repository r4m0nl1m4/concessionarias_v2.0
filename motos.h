
//Header for "motos" C++ application
//Created by r4m0nl1m4 and willimax 29/10/2019

//Guarda
#ifndef motos_H
#define motos_H

//Bibliotecas novas
#include "./automoveis.h"

//Classe implícita
using namespace std;

class moto : public automovel 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        string modelo;
    public:        
        //Construtores
        moto(string _marca, float _preco, float _chass, time_t _dataF, string _motor, string _modelo);
        moto(string _marca, float _preco, float _chass, string _motor, string _modelo);
        moto();
        //Destrutor
        ~moto();
        //Inserção e obtenção
        static int getTotal();
        void setModelo(string setModelo);
        string getModelo();
        //Arquivo
        void readDataOnFile(istream & file);           
        void writeDataInFile(ofstream& file);
        //Sobrecarga de Operadores Relacionais
        bool operator ==(moto m);
        bool operator !=(moto m);
        //Sobrecarga do Operador de Atribuição
        moto & operator =(const moto & m);
        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, moto & m);
        friend ostream & operator <<(ostream & os, moto & m);
};

#endif    /* motos_H */