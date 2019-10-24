
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
        struct e
        {
            list<caminhao> caminhoes;
            list<moto>     motos;

            template <typename T, typename U>
            bool checkIn(list<T> l, U element)
            {
                //Acesso ao estoque de veículos
                for(typename list<T>::iterator i = l.begin() ; i != l.end() ; i++)
                {
                    //Lógica operacional para a aferição de igualdade
                    if((*i) == element)
                    {
                        cout << "   ERROR! Veículo já adicionado" << endl;
                        (*i).total--;
                        //Sai da iteração
                        return true;
                    }
                }
                return false;
            }

            template <typename T>
            void increase_tax_rate(list<T> l, float n)
            {
                //Acesso ao estoque de veículos
                for(typename list<T>::iterator i = l.begin() ; i != l.end() ; i++)
                {
                    (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
                }
            }

            template <typename T>
            void print(list<T> l)
            {
                //Acesso a lista
                for(typename list<T>::iterator i = l.begin() ; i != l.end() ; i++)
                    cout << *i << endl;
            }

            template <typename T>
            list<T> getProducao_trimestal(list<T> l)
            {
                //Variáveis para a amálise
                double idade = 0, trimestre = 3*30*24*60*60;
                time_t now, dataF;
                list<T> proT;                
                //Acesso ao estoque de veículos
                for(typename list<T>::iterator i = l.begin() ; i != l.end() ; i++)
                {   
                    //Data atual
                    now = time(NULL);
                    //Data de fabricação
                    dataF = (*i).getDataF();
                    //Idade da produção em segundos
                    idade = difftime(now, dataF);
                    //Condicional de idade
                    if(idade <= trimestre)
                    {
                        proT.push_back(*i);
                    }    
                }
                //Retorna produção semestral da categoria 
                return proT;
            }

        } estoque;
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
        int getProducao_trimestre();
        
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