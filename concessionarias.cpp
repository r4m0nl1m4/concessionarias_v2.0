
//Body for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Cabeçalho
#include "./concessionarias.h"

//Construtores

concessionaria::concessionaria(string _nome, string _cnpj, list<veiculo> _estoque, list<caminhao> _estoqueCaminhoes, list<moto> _estoqueMotos)
{
    nome = _nome;
    cnpj = _cnpj;
    estoque = _estoque;
    estoqueCaminhoes = _estoqueCaminhoes;
    estoqueMotos = _estoqueMotos;
    naut = _estoque.size() + _estoqueCaminhoes.size() + _estoqueMotos.size();
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

void concessionaria::setEstoque(list<veiculo> setEstoque)
{
    estoque = setEstoque;
}

list<veiculo> concessionaria::getEstoque()
{
    return estoque;
}

void concessionaria::setEstoqueCaminhoes(list<caminhao> setEstoqueCaminhoes)
{
    estoqueCaminhoes = setEstoqueCaminhoes;
}

list<caminhao> concessionaria::getEstoqueCaminhoes()
{
    return estoqueCaminhoes;
}

void concessionaria::setEstoqueMotos(list<moto> setEstoqueMotos)
{
    estoqueMotos = setEstoqueMotos;
}

list<moto> concessionaria::getEstoqueMotos()
{
    return estoqueMotos;
}

list<veiculo> concessionaria::getProducao_trimestre()
{
    double idade = 0, trimestre = 3*30*24*60*60;
    list<veiculo> proT;
    time_t now, dataF;

    //Acesso ao estoque de veículos
    for(list<veiculo>::iterator i = estoque.begin() ; i != estoque.end() ; i++)
    {   
        //Data atual
        now = time(NULL);
        //Data de fabricação
        dataF = (*i).getDataF();
        //Idade da produção em segundos
        idade = difftime(now, dataF);
        if(idade <= trimestre)
        {
            proT.push_back(*i);
        }    
    }

    return proT;
}

//Veículo já consta no estoque?
template <typename T, typename U>
bool concessionaria::checkEstoque(T begin, T end, U element)
{
    //Acesso ao estoque de veículos
    while(begin != end)
    {
        //Lógica operacional para a aferição de igualdade
        if((*begin) == element)
        {
            cout << endl << "ERROR! Veículo já adicionado" << endl;
            (*begin).total--;
            //Sai da iteração
            return true;
        }
        ++begin;
    }
    return false;
}

//Adiciona um veículo ao estoque
void concessionaria::add_veiculo()
{
    int codigo;
    cout << "  Veículos:                   "  << endl;
    cout << "   Automóveis:                "  << endl;
    cout << "    [1] Caminhão              "  << endl;
    cout << "    [2] Moto                  "  << endl;
    cout << "    [0] Sair                  "  << endl;
    cout << "  Digite o código do veículo: ";
    cin >> codigo;
    switch(codigo)
    {
        case 1:
        {//As chaves criam um bloco e um escopo, para poder criar as variáveis.
            caminhao novoCaminhao;
            cin >> novoCaminhao;
            if(!checkEstoque(estoqueCaminhoes.begin(), estoqueCaminhoes.end(), novoCaminhao))
            {
                estoque.push_back(novoCaminhao);
                estoqueCaminhoes.push_back(novoCaminhao);
                naut++;
            }           
            break;
        }
        case 2:
        {
            moto novaMoto;
            cin >> novaMoto;
            if(!checkEstoque(estoqueMotos.begin(), estoqueMotos.end(), novaMoto))
            {
                estoque.push_back(novaMoto);
                estoqueMotos.push_back(novaMoto);
                naut++;
            }
            break;
        }
        case 0:
            exit (EXIT_FAILURE);
        default:
            cout << "  Código inválido!";
            exit (EXIT_FAILURE);
            break;
    }
}

void concessionaria::increase_tax_rate(float n)
{
    //Acesso ao estoque de veículos
    for(list<veiculo>::iterator i = estoque.begin() ; i != estoque.end() ; i++)
    {
        (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
    }

    //Acesso ao estoque de caminhões
    for(list<caminhao>::iterator i = estoqueCaminhoes.begin() ; i != estoqueCaminhoes.end() ; i++)
    {
        (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
    }
    //Acesso ao estoque de motos
    for(list<moto>::iterator i = estoqueMotos.begin() ; i != estoqueMotos.end() ; i++)
    {
        (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
    }
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
        estoque = c.estoque;
        estoqueCaminhoes = c.estoqueCaminhoes;
        estoqueMotos = c.estoqueMotos;
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
    cout << "├── Concessionária"                               << endl;
    cout << "├─── Nome " << c.nome                             << endl;
    cout << "├─── CNPJ " << c.cnpj                             << endl;
    cout << "├─── Naut " << c.naut                             << endl;
    cout << "├─── ProT " << (c.getProducao_trimestre()).size() << endl;

    //Acesso ao estoque de veículos
    //for(list<veiculo>::iterator i = c.estoque.begin() ; i != c.estoque.end() ; i++)
    //{
    //    cout << *i << endl;    
    //}

    //Acesso ao estoque de caminhões
    for(list<caminhao>::iterator i = c.estoqueCaminhoes.begin() ; i != c.estoqueCaminhoes.end() ; i++)
    {
        cout << *i << endl;    
    }
    //Acesso ao estoque de motos
    for(list<moto>::iterator i = c.estoqueMotos.begin() ; i != c.estoqueMotos.end() ; i++)
    {
        cout << *i << endl;    
    }

    return os;
}