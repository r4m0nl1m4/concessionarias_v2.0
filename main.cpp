
//Main for "concessionarias" C++ application
//Created by r4m0nl1m4 and willimax 29/10/2019

//Bibliotecas
#include <iostream>

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
int main()
{
	//Declaração das concessionárias
	concessionaria c1, c2;

	//Instanciação de uma concessionária
	cout << endl << "...Instanciação de uma concessionária..." << endl << endl;
	cin >> c1;

	//Apresentação dos dados das concessionárias
	cout << endl << "...Apresentação dos dados da(s) concessionária(s)..." << endl << endl;
	cout << c1;

	//Produção trimestral da(s) concessionária(s)
	cout << endl << "...Produção trimestral da(s) concessionária(s)..." << endl << endl;
	c1.printEstoque_producao_trimestral();

	//Ajuste nos preços dos veículos de uma concessionária
	cout << endl << "...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária..." << endl << endl;
	c1.setEstoque_increase_tax_rate(50);
	c1.printEstoque();

	//Salva os dados em um arquivo
	c1.writeDataInFile();

    //Apresentação das operações da(s) concessionária(s) 
    cout << endl << "...Apresentação do balanço das operações da(s) concessionária(s)..." << endl << endl;    
    cout << "    Balanço              "                                                                 << endl;
    cout << "     Concessionária(s)   " << concessionaria::getTotal()                                   << endl; //Total de concessionárias
    cout << "     Média da Produção   " << float(veiculo::getTotal())/float(concessionaria::getTotal()) << endl; //Média de veículos por concessionárias
    cout << "     Produção Trimestral " << c1.getEstoque_producao_trimestral()                          << endl; //Produção trimestral total da(s) concessionária(s)
    cout << "     Veículo(s)          " << veiculo::getTotal()                                          << endl; //Total de veículos
    cout << "     ├Automóvel(is)      " << automovel::getTotal()                                        << endl; //  /   /  automóveis
    cout << "     ├─Caminhão(ões)     " << caminhao::getTotal()                                         << endl; //  /   /  caminhões
    cout << "     ├─Moto(s)           " << moto::getTotal()                                             << endl; //  /   /  motos


    //Busca veículo no estoque pelo seu chassis
    cout << endl << "...Busca veículo no estoque pelo seu chassis..." << endl << endl;    
    float chass;
	cout << "    Digite o chass: ";
	cin  >> chass;
	c1.getEstoque_veiculo(chass);

    //Lê dados do arquivos
    cout << endl << "...Nova instância criada a partir do arquivo gerado anteriormente..." << endl << endl;    
	c2.readDataOnFile();
	cout << c2 << endl;

	return 0;
}