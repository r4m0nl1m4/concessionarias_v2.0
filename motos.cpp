
//Body for "motos" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./motos.h"

//Construtores

moto::moto(string _marca, float _preco, float _chass, time_t _dataF, string _motor, string _modelo) : automovel(_marca, _preco, _chass, _dataF, _motor)
{
    modelo = _modelo;
    total++;
}

moto::moto(string _marca, float _preco, float _chass, string _motor, string _modelo) : automovel(_marca, _preco, _chass, _motor)
{
    modelo = _modelo;
    total++;
}

moto::moto()
{
    total++;
}

//Destrutor

moto::~moto() {}

//Métodos

int moto::getTotal()
{
    return total;
}

void moto::setModelo(string setModelo)
{
    modelo = setModelo;
}

string moto::getModelo()
{
    return modelo;
}

//Sobrecarga de Operadores Relacionais

bool moto::operator ==(moto m)
{
    return ( ( (marca == m.marca && preco == m.preco) && (chass == m.chass && dataF == m.dataF) ) && ( (motor == m.motor) && (modelo == m.modelo) ) );
}

bool moto::operator !=(moto m)
{
    return ( ( (marca != m.marca || preco != m.preco) || (chass != m.chass || dataF != m.dataF) ) && ( (motor != m.motor) && (modelo != m.modelo) ) );
}

//Sobrecarga do Operador de Atribuição

moto & moto::operator =(const moto & m)
{
    if (this != & m)
    {
        marca = m.marca;
        preco = m.preco;
        chass = m.chass;
        dataF = m.dataF;
        motor = m.motor;
        modelo = m.modelo;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, moto & m)
{
    cout << "   Veículo" << endl;
    cout << "   ├Digite o chass: ";
    cin >> m.chass;

    struct tm data = {0};
    int y = 0, mon = 0, d = 0; 

    cout << "   ├Digite a dataF: " << endl;
    cout << "   ├─Digite o dia [ 1-31 ]: ";
    cin >> d;
    cout << "   ├─Digite o mes [ 1-12 ]: ";
    cin >> mon;
    cout << "   ├─Digite o ano [ 1900-]: ";
    cin >> y;

    data.tm_mday = d;
    data.tm_mon  = mon - 1;
    data.tm_year = y - 1900;

    m.dataF = mktime(&data);

    cout << "   ├Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, m.marca);
    cout << "   ├Digite o preço: ";
    cin >> m.preco;

    cout << "   ├Automóvel" << endl;
    cout << "   ├─Digite o motor: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, m.motor);

    cout << "   ├─Moto" << endl;
    cout << "   ├──Digite o modelo: ";
    getline(cin, m.modelo);
    
    cout << "   Moto cadastrada!" << endl;

    return is;
}

ostream & operator <<(ostream & os, moto & m)
{
    cout << "├─── Veículo "                                           << endl;
    cout << "├──── Chass "     << fixed << setprecision(0) << m.chass << endl;
    cout << "├──── Data "      << ctime(&m.dataF);
    cout << "├──── Marca "     << m.marca                             << endl;
    cout << "├──── Preço R$ "  << fixed << setprecision(2) << m.preco << endl;    
    cout << "├──── Automóvel "                                        << endl;
    cout << "├───── Motor "    << m.motor                             << endl;
    cout << "├───── Moto "                                            << endl;
    cout << "├────── Modelo "  << m.modelo;

    return os;
}