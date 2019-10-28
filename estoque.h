
//Header for "estoque" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef estoque_H
#define estoque_H

//Biblioteca
#include <list>
#include <ctime>

//Classe implícita
using namespace std;

//Classe genérica
template <class T>
class estoque
{
    private:
        //Elementos armazenados no estoque
        list<T> container;
    public:
        //Construtor
        estoque (){};
        //Contém veículo?
        template <typename U>
        bool checkIn(U vehicle)
        {
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i) == vehicle)
                {
                    cout << "   ERROR! Veículo já adicionado" << endl;
                    (*i).total--;
                    //Sai da iteração
                    return true;
                }
            }
            return false;
        }
        //Esvaziar
        void clear()
        {
            container.clear();
        }
        //Deletar veículo
        template <typename U>        
        void del(U vehicle)
        {
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i) == vehicle)
                {
                    container.erase(i);
                }
            }
        }
        //Vazia?
        bool empty() const
        {
            return container.empty();
        }
        //Retorna o último veículo adicionado
        T& newest()
        {
            return container.front();
        }
        //Obter veículo
        template <typename U>        
        void getVeiculo(U chass)
        {
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i).getChass() == chass)
                {
                    cout << *i << endl;
                }
            }
        }
        //Encarecer
        void increase_tax_rate(float n)
        {
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
            }
        }
        //Apresentar dados dos veículos
        void print()
        {
            //Acesso a lista
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
                cout << *i << endl;
        }
        //Escrever dados dos veículos em um arquivo
        void readDataOnFile(istream & file)
        {/*
            //Acesso a lista
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
                (*i).readDataOnFile(file);*/
        }
        //Escrever dados dos veículos em um arquivo
        void writeDataInFile(ofstream& file)
        {
            //Acesso a lista
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
                (*i).writeDataInFile(file);
        }
        //Imprimi a produção trimestral
        void print_producao_trimestral()
        {
            //Variáveis para a amálise
            double idade = 0, trimestre = 3*30*24*60*60;
            time_t now, dataF;       
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
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
                    cout << *i << endl;
                }    
            }
        }
        //Produção trimestral
        int producao_trimestral()
        {
            //Variáveis para a amálise
            double idade = 0, trimestre = 3*30*24*60*60;
            time_t now, dataF;
            int proT = 0;       
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
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
                    proT++;
                }    
            }
            return proT;
        }
        //Empilhar
        void push(const T& element)
        {
            container.push_back(element);
        }
        //Tamanho?
        int size()
        {
            return container.size();
        }
};

#endif /* estoque_H */