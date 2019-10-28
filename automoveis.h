
//Header for "automoveis" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef automoveis_H
#define automoveis_H

//Bibliotecas novas
#include "./veiculos.h"

//Classe implícita
using namespace std;

class automovel : public veiculo 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        string motor;
    public:        
        //Construtores
        automovel(string _marca, float _preco, float _chass, time_t _dataF, string _motor);
        automovel(string _marca, float _preco, float _chass, string _motor);
        automovel();
        //Destrutor
        ~automovel();
        //Inserção e obtenção
        static int getTotal();
        void setMotor(string setMotor);
        string getMotor();
        //Arquivo       
        void writeDataInFile(ofstream& file); 
        //Sobrecarga de Operadores Relacionais
        bool operator ==(automovel a);
        bool operator !=(automovel a);
        //Sobrecarga do Operador de Atribuição
        automovel & operator =(const automovel & a);
        //Sobrecarga de Operadores IO
        friend istream & operator >>(istream & is, automovel & a);
        friend ostream & operator <<(ostream & os, automovel & a);
};

#endif    /* automoveis_H */