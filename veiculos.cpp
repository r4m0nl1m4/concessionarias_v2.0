
//Body for "veiculos" C++ application
//Created by r4m0nl1m4 and willimax 29/10/2019

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
    total++;
}

//Destrutor

veiculo::~veiculo() {}

//Inserção e obtemção

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

//Arquivo
void veiculo::readDataOnFile(istream & file)  
{
    //Ler chass
    string _chass;
    file.ignore(256, ':');                        //ignore until ':'
    getline(file, _chass);
    chass = atof(_chass.c_str());
    //Ler data
    string _data;
    //time_t _d;
    file.ignore(256, ':');                        //ignore until ':'
    getline(file, _data);
    //(stock.caminhoes.newest()).setDataf(101);
    //Ler marca
    string _marca;
    file.ignore(256, ':');                        //ignore until ':'
    getline(file, _marca);
    marca = _marca;
    //Ler preco
    string _preco;
    file.ignore(256, ':');                        //ignore until ':'
    getline(file, _preco);
    preco = atof(_preco.c_str());
}

void veiculo::writeDataInFile(ofstream& file)
{
    bool status;                                                                //Status do arquivo                    
    status = !( file.fail() || !file.is_open() || !file.good() );               //Abre um arquivo para escrita usando o ofstream 
    if(!status)                                                                 //Deu ruim!
    {
        cout << "Arquivo não pode ser aberto para escrita.\n"; 
        cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    else                                                                        //De boas...
    {
        file << "├─── Veículo "                                        << endl;
        file << "├──── Chass "    << fixed << setprecision(0) << chass << endl;
        file << "├──── Data "     << ctime(&dataF);
        file << "├──── Marca "    << marca                             << endl; 
        file << "├──── Preço R$ " << fixed << setprecision(2) << preco; 
    }
}

//Sobrecarga de Operadores Relacionais

bool veiculo::operator ==(veiculo v)
{
    return ( (marca == v.marca && preco == v.preco) && (chass == v.chass && dataF == v.dataF) );
}

bool veiculo::operator !=(veiculo v)
{
    return ( (marca != v.marca || preco != v.preco) || (chass != v.chass || dataF != v.dataF) );
}

//Sobrecarga do Operador de Atribuição

veiculo & veiculo::operator =(const veiculo & v)
{
    if (this != & v)
    {
        marca = v.marca;
        preco = v.preco;
        chass = v.chass;
        dataF = v.dataF;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, veiculo & v)
{
    cout << " Veículo" << endl;    
    cout << "  Digite o chass: ";
    cin >> v.chass;

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

    v.dataF = mktime(&data);

    cout << "  Digite a marca: ";
    cin.ignore(sizeof(is),'\n');
    getline(cin, v.marca);
    cout << "  Digite o preço: ";
    cin >> v.preco;

    return is;
}

ostream & operator <<(ostream & os, veiculo & v)
{
    cout << "├─── Veículo "                                          << endl;
    cout << "├──── Chass "    << fixed << setprecision(0) << v.chass << endl;
    cout << "├──── Data "     << ctime(&v.dataF);
    cout << "├──── Marca "    << v.marca                             << endl;
    cout << "├──── Preço R$ " << fixed << setprecision(2) << v.preco;    

    return os;
}