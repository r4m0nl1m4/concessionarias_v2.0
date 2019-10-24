
//Body for "concessionarias" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./concessionarias.h"

//Construtores

concessionaria::concessionaria(string _nome, string _cnpj, e _est)
{
    nome = _nome;
    cnpj = _cnpj;
    stock = _est;
    naut = _est.caminhoes.size() + _est.motos.size();
    total++;
}

concessionaria::concessionaria(string _nome, string _cnpj)
{
    nome = _nome;
    cnpj = _cnpj;
    naut = 0;
    total++;
}

concessionaria::concessionaria()
{
    naut = 0;
    total++;
}

//Destrutor

concessionaria::~concessionaria() {}

//Métodos

int concessionaria::getTotal()
{
    return total;
}

void concessionaria::setNome(string setNome)
{
    nome = setNome;
}

string concessionaria::getNome()
{
    return nome;
}

void concessionaria::setCNPJ(string setCNPJ)
{
    cnpj = setCNPJ;
}

string concessionaria::getCNPJ()
{
    return cnpj;
}

void concessionaria::setEstoque(e setEstoque)
{
    stock = setEstoque;
}

//e concessionaria::getEstoque()
//{
//    return estoque;
//}

int concessionaria::getProducao_trimestre()
{
    //Quantidade de veículos produzidos
    int proT = stock.caminhoes.size() + stock.motos.size();    
    //Apresentação dos dados
    cout << "├── Concessionária " << nome << " produziu " << proT << " veículo(s) no último trimestre." << endl;
    //Caso não tenha produzição trimestral
    if(proT == 0) 
        cout << "├─── Nenhum veículo produzido no último trimestre" << endl;
    else
    {
        //Produção trimestral de caminhões
        stock.caminhoes.print_producao_trimestal();
        //Produção trimestral de motos
        stock.motos.print_producao_trimestal();
    }
    return proT;
}

//Adiciona um veículo ao estoque
void concessionaria::add_veiculo()
{
    int codigo;
    cout << "  Veículos:                   "  << endl;
    cout << "  ├Automóveis:                "  << endl;
    cout << "  ├─[1] Caminhão              "  << endl;
    cout << "  ├─[2] Moto                  "  << endl;
    cout << "  ├─[0] Sair                  "  << endl;
    cout << "  Digite o código do veículo: ";
    cin >> codigo;
    switch(codigo)
    {
        case 1:
        {//As chaves criam um bloco e um escopo, para poder criar as variáveis.
            caminhao novoCaminhao;
            cin >> novoCaminhao;
            if(!stock.caminhoes.checkIn(novoCaminhao))
            {
                stock.caminhoes.push(novoCaminhao);
                naut++;
            }           
            break;
        }
        case 2:
        {
            moto novaMoto;
            cin >> novaMoto;
            if(!stock.motos.checkIn(novaMoto))
            {
                stock.motos.push(novaMoto);
                naut++;
            }
            break;
        }
        case 0:
            exit(EXIT_FAILURE);
        default:
            cout << "  Código inválido!";
            exit(EXIT_FAILURE);
            break;
    }
}

void concessionaria::increase_tax_rate(float n)
{
    stock.caminhoes.increase_tax_rate(n);
    stock.motos.increase_tax_rate(n);
}

//Sobrecarga de Operadores Relacionais

bool concessionaria::operator ==(concessionaria c)
{
    return ( nome == c.nome && cnpj == c.cnpj );
}

bool concessionaria::operator !=(concessionaria c)
{
    return ( nome != c.nome || cnpj != c.cnpj );
}

//Sobrecarga do Operador de Atribuição

concessionaria & concessionaria::operator =(const concessionaria & c)
{
    if (this != & c)
    {
        nome = c.nome;
        cnpj = c.cnpj;
        stock.caminhoes = c.stock.caminhoes;
        stock.motos = c.stock.motos;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, concessionaria & c)
{
    cout << "Concessionária" << endl;
    cout << " Digite o nome: ";
    cin.ignore(c.nome.size(),'\n'); //Limpa o caracter de nova linha \n do buffer de entrada
    getline(cin, c.nome);           //Lê o dado de entrada até que uma nova linha seja detectada
    cout << " Digite o CNPJ: ";    
    cin.ignore(c.cnpj.size(),'\n');
    getline(cin, c.cnpj);

    //Lógica operacional para o incremento do estoque

    string comando;
    int qntd = 0;

    cout << " Cadastrar veículo [Y/N]? ";
    cin.ignore(comando.size(),'\n');
    getline(cin, comando);
    
    if (comando == "Y" || comando == "y" )
    {
        cout << " Digite a qntd: ";
        cin >> qntd;
    }

    //Adiciona uma quantidade de veículos ao estoque
    for(int i = 0 ; i < qntd ; i++)
    {
        c.add_veiculo();
    }

    return is;
}

ostream & operator <<(ostream & os, concessionaria & c)
{
    cout << "├── Concessionária"                      << endl;
    cout << "├─── Nome " << c.nome                    << endl;
    cout << "├─── CNPJ " << c.cnpj                    << endl;
    cout << "├─── Naut " << c.naut                    << endl;
    cout << "├─── ProT " << c.getProducao_trimestre() << endl;

    c.stock.caminhoes.print();
    c.stock.motos.print();

    return os;
}