
//Body for "veiculos" C++ application
//Created by r4m0nl1m4 09/09/2019

//Cabeçalho
#include "./veiculos.h"

//Construtores

veiculo::veiculo(string _marca, float _preco, float _chass, time_t _dataF)
{
    marca = _marca;
    preco = _preco;
    chass = _chass;
    dataF = _dataF;
    total++;
}

veiculo::veiculo(string _marca, float _preco, float _chass)
{
    marca = _marca;
    preco = _preco;
    chass = _chass;
    dataF = time(NULL);
    total++;
}

veiculo::veiculo()
{
    preco = 0;
    chass = 0;
    dataF = time(NULL);
}

//Destrutor

veiculo::~veiculo() {}

//Métodos

int veiculo::getTotal()
{
    return total;
}

void veiculo::setMarca(string setMarca)
{
    marca = setMarca;
}

string veiculo::getMarca()
{
    return marca;
}

void veiculo::setPreco(float setPreco)
{
    preco = setPreco;
}

float veiculo::getPreco()
{
    return preco;
}

void veiculo::setChass(float setChass)
{
    chass = setChass;
}

float veiculo::getChass()
{
    return chass;
}

void veiculo::setDataF(time_t setDataF)
{
    dataF = setDataF;
}

time_t veiculo::getDataF()
{
    return dataF;
}

//Sobrecarga de Operadores Relacionais

bool veiculo::operator ==(veiculo a)
{
    return ( (marca == a.marca && preco == a.preco) && (chass == a.chass && dataF == a.dataF) );
}

bool veiculo::operator !=(veiculo a)
{
    return ( (marca != a.marca || preco != a.preco) || (chass != a.chass || dataF != a.dataF) );
}

//Sobrecarga do Operador de Atribuição

veiculo & veiculo::operator =(const veiculo & a)
{
    if (this != & a)
    {
        marca = a.marca;
        preco = a.preco;
        chass = a.chass;
        dataF = a.dataF;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, veiculo & a)
{
    veiculo aux;
    string marca;
    float preco = 0, chass = 0;
    struct tm data = {0};
    time_t dataF;
    int y = 0, m = 0, d = 0; 

    cout << " Veículo" << endl;
    cout << "  Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, marca);

    cout << "  Digite o preço: ";
    cin >> preco;

    cout << "  Digite o chass: ";
    cin >> chass;

    cout << "  Digite a dataF: " << endl;
    cout << "   Digite o dia [ 1-31 ]: ";
    cin >> d;
    cout << "   Digite o mes [ 1-12 ]: ";
    cin >> m;
    cout << "   Digite o ano [ 1900-]: ";
    cin >> y;

    data.tm_mday = d;
    data.tm_mon  = m - 1;
    data.tm_year = y - 1900;

    dataF = mktime(&data);

    a = veiculo(marca, preco, chass, dataF);

    return is;
}

ostream & operator <<(ostream & os, veiculo & a)
{
    cout << "├─── Veículo"                                           << endl;
    cout << "├──── Marca "    << a.marca                             << endl;
    cout << "├──── Preço R$ " << fixed << setprecision(2) << a.preco << endl;
    cout << "├──── Chass "    << fixed << setprecision(0) << a.chass << endl;
    cout << "├──── data  "    << ctime(&a.dataF);

    return os;
}