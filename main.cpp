
//Main for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Bibliotecas
#include <iostream>
#include <string>

//Bibliotecas novas
#include "./concessionarias.h"
#include "./veiculos.h"
#include "./automoveis.h"
#include "./caminhoes.h"
#include "./motos.h"

//Classe implícita
using namespace std;

//inicialização dos atributos estáticos das classes
int moto::total = 0, caminhao::total = 0, automovel::total = 0, veiculo::total = 0, concessionaria::total = 0;

//Program
int main(int argc, char* argv[])
{
	//Declaração das concessionárias
	concessionaria c1;

	//Instanciação de uma concessionária
	cout << endl << "...Instanciação de uma concessionária..." << endl << endl;
	cin >> c1;

	//Apresentação dos dados das concessionárias
	cout << endl << "...Apresentação dos dados da(s) concessionária(s)..." << endl << endl;
	cout << c1;

	//Produção trimestral da(s) concessionária(s)
	cout << endl << "...Produção trimestral da(s) concessionária(s)..." << endl << endl;
	int ptotal1 = c1.getProducao_trimestre();

	//Ajuste nos preços dos veículos de uma concessionária
	cout << endl << "...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária..." << endl;
	c1.increase_tax_rate(50);
	cout << endl << c1;

	//Operações da(s) concessionária(s)
	int ctotal   = concessionaria::getTotal();  //Total de concessionárias
	int vtotal   = veiculo::getTotal();         //Total de veículos
	int vatotal  = automovel::getTotal();       //Total de caminhões
	int vactotal = caminhao::getTotal();        //Total de caminhões
	int vamtotal = moto::getTotal();            //Total de motos
	float amedia = float(vtotal)/float(ctotal); //Média de veículos por concessionárias
	int ptotal   = ptotal1;                     //Produção trimestral total da(s) concessionária(s)

    //Apresentação das operações da(s) concessionária(s) 
    cout << endl << "...Apresentação do balanço das operações da(s) concessionária(s)..." << endl << endl;    
    cout << "Balanço             " << endl;
    cout << " Concessionária(s)  " << ctotal   << endl;
    cout << " Média da Produção  " << amedia   << endl;
    cout << " Produção Trimestre " << ptotal   << endl;
    cout << " Veículo(s)         " << vtotal   << endl;
    cout << "  Automóvel(is)     " << vatotal  << endl;
    cout << "   Caminhão(ões)    " << vactotal << endl;
    cout << "   Moto(s)          " << vamtotal << endl;
    cout << endl;

	return 0;
}