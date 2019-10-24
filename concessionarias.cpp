
//Body for "concessionarias" C++ application
//Created by r4m0nl1m4 09/09/2019

//Cabeçalho
#include "./concessionarias.h"

//Construtores

concessionaria::concessionaria(string _nome, string _cnpj, e _est)
{
    nome = _nome;
    cnpj = _cnpj;
    estoque = _est;
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
    estoque = setEstoque;
}

//e concessionaria::getEstoque()
//{
//    return estoque;
//}

int concessionaria::getProducao_trimestre()
{
    int proT = estoque.caminhoes.size() + estoque.motos.size();
    cout << "├── Concessionária " << nome << " produziu " << proT << " veículo(s) no último trimestre." << endl;
    estoque.print(estoque.getProducao_trimestal(estoque.caminhoes));
    estoque.print(estoque.getProducao_trimestal(estoque.motos));
    if(proT == 0) cout << "├─── Nenhum veículo produzido no último trimestre" << endl;
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
            if(!estoque.checkIn(estoque.caminhoes, novoCaminhao))
            {
                estoque.caminhoes.push_back(novoCaminhao);
                naut++;
            }           
            break;
        }
        case 2:
        {
            moto novaMoto;
            cin >> novaMoto;
            if(!estoque.checkIn(estoque.motos, novaMoto))
            {
                estoque.motos.push_back(novaMoto);
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
    estoque.increase_tax_rate(estoque.caminhoes, n);
    estoque.increase_tax_rate(estoque.motos, n);
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
        estoque.caminhoes = c.estoque.caminhoes;
        estoque.motos = c.estoque.motos;
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

    c.estoque.print(c.estoque.caminhoes);
    c.estoque.print(c.estoque.motos);

    return os;
}