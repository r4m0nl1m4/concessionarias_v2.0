
//Header for "caminhoes" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef caminhoes_H
#define caminhoes_H

//Bibliotecas novas
#include "./automoveis.h"

//Classe implícita
using namespace std;

class caminhao : public automovel 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        string carga;
    public:        
        //Construtores
        caminhao(string _marca, float _preco, float _chass, time_t _dataF, string _motor, string _carga);
        caminhao(string _marca, float _preco, float _chass, string _motor, string _carga);
        caminhao();
        //Destrutor
        ~caminhao();
        //Inserção e obtenção
        static int getTotal();
        void setCarga(string setCarga);
        string getCarga();
        //Arquivo
        void readDataOnFile(istream & file);        
        void writeDataInFile(ofstream& file);
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