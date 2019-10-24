
//Body for "caminhoes" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./caminhoes.h"

//Construtores

caminhao::caminhao(string _marca, float _preco, float _chass, time_t _dataF, string _motor, string _carga) : automovel(_marca, _preco, _chass, _dataF, _motor)
{
    carga = _carga;
    total++;
}

caminhao::caminhao(string _marca, float _preco, float _chass, string _motor, string _carga) : automovel(_marca, _preco, _chass, _motor)
{
    carga = _carga;
    total++;
}

caminhao::caminhao()
{
    total++;
}

//Destrutor

caminhao::~caminhao() {}

//Métodos

int caminhao::getTotal()
{
    return total;
}

void caminhao::setCarga(string setCarga)
{
    carga = setCarga;
}

string caminhao::getCarga()
{
    return carga;
}

//Sobrecarga de Operadores Relacionais

bool caminhao::operator ==(caminhao c)
{
    return ( ( (marca == c.marca && preco == c.preco) && (chass == c.chass && dataF == c.dataF) ) && ( (motor == c.motor) && (carga == c.carga) ) );
}

bool caminhao::operator !=(caminhao c)
{
    return ( ( (marca != c.marca || preco != c.preco) || (chass != c.chass || dataF != c.dataF) ) && ( (motor != c.motor) && (carga != c.carga) ) );
}

//Sobrecarga do Operador de Atribuição

caminhao & caminhao::operator =(const caminhao & c)
{
    if (this != & c)
    {
        marca = c.marca;
        preco = c.preco;
        chass = c.chass;
        dataF = c.dataF;
        motor = c.motor;
        carga = c.carga;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, caminhao & c)
{
    cout << "   Veículo" << endl;
    cout << "   ├Digite o chass: ";
    cin >> c.chass;

    struct tm data = {0};
    int y = 0, m = 0, d = 0; 

    cout << "   ├Digite a dataF: " << endl;
    cout << "   ├─Digite o dia [ 1-31 ]: ";
    cin >> d;
    cout << "   ├─Digite o mes [ 1-12 ]: ";
    cin >> m;
    cout << "   ├─Digite o ano [ 1900-]: ";
    cin >> y;

    data.tm_mday = d;
    data.tm_mon  = m - 1;
    data.tm_year = y - 1900;

    c.dataF = mktime(&data);

    cout << "   ├Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, c.marca);
    cout << "   ├Digite o preço: ";
    cin >> c.preco;

    cout << "   ├Automóvel" << endl;
    cout << "   ├─Digite o motor: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, c.motor);

    cout << "   ├─Caminhão" << endl;
    cout << "   ├──Digite a carga: ";
    getline(cin, c.carga);

    cout << "   Caminhão cadastrado!" << endl;

    return is;
}

ostream & operator <<(ostream & os, caminhao & c)
{
    cout << "├─── Veículo "                                           << endl;
    cout << "├──── Chass "     << fixed << setprecision(0) << c.chass << endl;
    cout << "├──── Data "      << ctime(&c.dataF);
    cout << "├──── Marca "     << c.marca                             << endl;
    cout << "├──── Preço R$ "  << fixed << setprecision(2) << c.preco << endl;    
    cout << "├──── Automóvel "                                        << endl;
    cout << "├───── Motor "    << c.motor                             << endl;
    cout << "├───── Caminhão "                                        << endl;
    cout << "├────── Carga "   << c.carga;

    return os;
}