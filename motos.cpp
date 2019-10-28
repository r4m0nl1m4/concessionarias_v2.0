
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

//Inserção e obtenção

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

//Arquivo

void moto::readDataOnFile(istream & file)
{
    string aux;
    //Ler chass
    string _chass;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _chass);
    chass = atof(_chass.c_str()); 
    //Ler data
    struct tm _data_tm = {0};
    string _data;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _data);   
    string m = _data.substr(4,3), d = _data.substr(8,2), y = _data.substr(20,4);
    string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for(int i = 0 ; i < 12 ; i++) if(months[i] == m) _data_tm.tm_mon = i;
    _data_tm.tm_mday = atoi(d.c_str());
    _data_tm.tm_year = atoi(y.c_str()) - 1900;
    dataF = mktime(&_data_tm);
    //Ler marca
    string _marca;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _marca);
    marca = _marca.c_str();
    //Ler preco
    string _preco;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _preco);
    preco = atof(_preco.c_str());
    //...next...
    getline(file, aux);
    //Ler motor                       
    string _motor;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _motor);
    motor = _motor.c_str();
    //...next...
    getline(file, aux);
    //Ler modelo
    string _modelo;
    file.ignore(256, ':');        //ignore until ':'
    getline(file, _modelo);
    modelo = _modelo.c_str();
} 

void moto::writeDataInFile(ofstream& file)
{
    bool status;                                                                   //Status do arquivo                    
    status = !( file.fail() || !file.is_open() || !file.good() );                  //Abre um arquivo para escrita usando o ofstream 
    if(!status)                                                                    //Deu ruim!
    {
        cout << "Arquivo não pode ser aberto para escrita.\n"; 
        cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    else                                                                           //De boas...
    {
        file                                                                << endl;
        file << "       Moto"                                               << endl;
        file << "        Veículo"                                           << endl;
        file << "        ├Chass:"      << fixed << setprecision(0) << chass << endl;
        file << "        ├Data:"       << ctime(&dataF);
        file << "        ├Marca:"      << marca                             << endl;
        file << "        ├Preço [R$]:" << fixed << setprecision(2) << preco << endl;    
        file << "        ├Automóvel"                                        << endl;
        file << "        ├─Motor:"     << motor                             << endl;
        file << "        ├──Moto"                                           << endl;
        file << "        ├───Modelo:"  << modelo                            << endl;
    }
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
    cout << "        Veículo" << endl;
    cout << "        ├Digite o chass: ";
    cin >> m.chass;

    struct tm data = {0};
    int y = 0, mon = 0, d = 0; 

    cout << "        ├Digite a dataF: " << endl;
    cout << "        ├─Digite o dia [ 1-31 ]: ";
    cin >> d;
    cout << "        ├─Digite o mes [ 1-12 ]: ";
    cin >> mon;
    cout << "        ├─Digite o ano [ 1900-]: ";
    cin >> y;

    data.tm_mday = d;
    data.tm_mon  = mon - 1;
    data.tm_year = y - 1900;

    m.dataF = mktime(&data);

    cout << "        ├Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, m.marca);
    cout << "        ├Digite o preço: ";
    cin >> m.preco;

    cout << "        ├Automóvel" << endl;
    cout << "        ├─Digite o motor: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, m.motor);

    cout << "        ├─Moto" << endl;
    cout << "        ├──Digite o modelo: ";
    getline(cin, m.modelo);
    
    cout << "        Moto cadastrada!" << endl;

    return is;
}

ostream & operator <<(ostream & os, moto & m)
{
    cout                                                                 << endl;
    cout << "       Moto "                                               << endl;
    cout << "        Veículo "                                           << endl;
    cout << "        ├Chass "     << fixed << setprecision(0) << m.chass << endl;
    cout << "        ├Data "      << ctime(&m.dataF);
    cout << "        ├Marca "     << m.marca                             << endl;
    cout << "        ├Preço R$ "  << fixed << setprecision(2) << m.preco << endl;    
    cout << "        ├Automóvel "                                        << endl;
    cout << "        ├─Motor "    << m.motor                             << endl;
    cout << "        ├──Moto "                                           << endl;
    cout << "        ├───Modelo " << m.modelo;

    return os;
}