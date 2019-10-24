
//Body for "automoveis" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./automoveis.h"

//Construtores

automovel::automovel(string _marca, float _preco, float _chass, time_t _dataF, string _motor) : veiculo(_marca, _preco, _chass, _dataF)
{
    motor = _motor;
    total++;
}

automovel::automovel(string _marca, float _preco, float _chass, string _motor) : veiculo(_marca, _preco, _chass)
{
    motor = _motor;
    total++;
}

automovel::automovel()
{
    total++;
}

//Destrutor

automovel::~automovel() {}

//Métodos

int automovel::getTotal()
{
    return total;
}

void automovel::setMotor(string setMotor)
{
    motor = setMotor;
}

string automovel::getMotor()
{
    return motor;
}

//Sobrecarga de Operadores Relacionais

bool automovel::operator ==(automovel a)
{
    return ( ( (marca == a.marca && preco == a.preco) && (chass == a.chass && dataF == a.dataF) ) && (motor == a.motor) );
}

bool automovel::operator !=(automovel a)
{
    return ( ( (marca != a.marca || preco != a.preco) || (chass != a.chass || dataF != a.dataF) ) && (motor != a.motor) );
}

//Sobrecarga do Operador de Atribuição

automovel & automovel::operator =(const automovel & a)
{
    if (this != & a)
    {
        marca = a.marca;
        preco = a.preco;
        chass = a.chass;
        dataF = a.dataF;
        motor = a.motor;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, automovel & a)
{
    cout << " Veículo" << endl;
    cout << "  Digite o chass: ";
    cin >> a.chass;

    struct tm data = {0};
    int y = 0, m = 0, d = 0; 

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

    a.dataF = mktime(&data);

    cout << "  Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, a.marca);
    cout << "  Digite o preço: ";
    cin >> a.preco;

    cout << "  Automóvel" << endl;
    cout << "   Digite o motor: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, a.motor);

    return is;
}

ostream & operator <<(ostream & os, automovel & a)
{
    cout << "├─── Veículo "                                           << endl;
    cout << "├──── Chass "     << fixed << setprecision(0) << a.chass << endl;
    cout << "├──── Data "      << ctime(&a.dataF);
    cout << "├──── Marca "     << a.marca                             << endl;
    cout << "├──── Preço R$ "  << fixed << setprecision(2) << a.preco << endl;    
    cout << "├──── Automóvel "                                        << endl;
    cout << "├───── Motor "    << a.motor;

    return os;
}