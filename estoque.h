
//Header for "estoque" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef estoque_H
#define estoque_H

//Biblioteca
#include <list>

//Classe implícita
using namespace std;

//Classe genérica
template <class T>
class estoque
{
    private:
      //Atributo
        list<T> container;   //Elementos armazenados no estoque
    public:
      //Métodos
        //Construtor
        estoque (){};
        //Esvaziar
        void clear()
        {
            container.clear();
        }
        //Vazia?
        bool empty() const
        {
            return container.empty();
        }
        //Produção trimestral
        void print_producao_trimestal()
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
        //Deletar veículo
        template <typename U>        
        T& del(U vehicle)
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
        //Apresentar
        void print()
        {
            //Acesso a lista
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
                cout << *i << endl;
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
        //Topo
        T& top()
        {
            return container.back();
        }
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
        //Encarecer
        void increase_tax_rate(float n)
        {
            //Acesso ao estoque de veículos
            for(typename list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
            }
        }
};

#endif // estoque_H