
//Body for "concessionarias" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./concessionarias.h"

//Construtores

concessionaria::concessionaria(list<p> _proprietarios, j _juridico, e _est)
{
    proprietarios = _proprietarios;
    juridico = _juridico;
    stock = _est;
    total++;
}

concessionaria::concessionaria(list<p> _proprietarios, j _juridico)
{
    proprietarios = _proprietarios;
    juridico = _juridico;
    stock.naut = 0;
    total++;
}

concessionaria::concessionaria()
{
    stock.naut = 0;
    total++;
}

//Destrutor

concessionaria::~concessionaria() {}

//Contador de objetos

int concessionaria::getTotal()
{
    return total;
}

void concessionaria::setProprietarios(list<p> setProprietarios)
{
    proprietarios.assign(setProprietarios.begin(), setProprietarios.end());
}

//concessionaria::list<p> concessionaria::getProprietarios()
//{
//    return proprietarios;
//}

void concessionaria::setJuridico(j setJuridico)
{
    juridico = setJuridico;
}

concessionaria::j concessionaria::getJuridico()
{
    return juridico;
}

void concessionaria::setEstoque(e setEstoque)
{
    stock = setEstoque;
}

void concessionaria::setEstoque_increase_tax_rate(float n)
{
    stock.caminhoes.increase_tax_rate(n);
    stock.motos.increase_tax_rate(n);
}

concessionaria::e concessionaria::getEstoque()
{
    return stock;
}

int concessionaria::getEstoque_producao_trimestral()
{
    return ( stock.caminhoes.producao_trimestral() + stock.motos.producao_trimestral() );
}

void concessionaria::getEstoque_veiculo(float chass)
{
    stock.caminhoes.getVeiculo(chass);
    stock.motos.getVeiculo(chass);

    cout << endl;
}

//Apresentação

void concessionaria::printProprietarios()
{
    cout <<     "     Proprietários: "   << proprietarios.size()         << endl;
    int n = 1;
    for(list<p>::iterator i = proprietarios.begin() ; i != proprietarios.end() ; i++)
    {        
        cout << "      " << n << ". Nome/razão social: "  << (*i).nome   << endl;
        cout << "         CPF/CNPJ: "                     << (*i).codigo << endl;
        n++;
    }
}

void concessionaria::printJuridico()
{
    cout << "     Jurídico "                                 << endl;
    cout << "      Nome: "               << juridico.nome    << endl;
    cout << "      CNPJ: "               << juridico.cnpj    << endl;
}

void concessionaria::printEstoque()
{
    cout << "     Estoque: "                                << stock.naut                       << endl;
    cout << "      Produção Trimestral: "                   << getEstoque_producao_trimestral() << endl;
    cout << "      Detalhamento dos veículos cadastrados: "                                     << endl;

    stock.caminhoes.print();
    stock.motos.print();
}

void concessionaria::printEstoque_producao_trimestral()
{
    int proT = stock.caminhoes.producao_trimestral() + stock.motos.producao_trimestral();
    //Apresentação dos dados
    cout << "    A concessionária " << juridico.nome << " produziu " << proT << " veículo(s) no último trimestre." << endl;
    //Caso não tenha produzição trimestral
    if(proT == 0) 
        cout << "Nenhum veículo produzido no último trimestre" << endl;
    else
    {
        //Produção trimestral de caminhões
        stock.caminhoes.print_producao_trimestral();
        //Produção trimestral de motos
        stock.motos.print_producao_trimestral();
    }
}

//Arquivo

void concessionaria::readDataOnFile()
{   
    string strFile = "dados.txt";                                     //Nome do arquivo
    const char *cstr = strFile.c_str();                               //String to C string version
    ifstream file;                                                    //Instancia para a leitura 
    file.open(cstr);                                                  //Abre o arquivo
    bool status;                                                      //Status do arquivo                       
    status = !( ( file.fail() || !file.is_open() ) || !file.good() );  
    if(!status)                                                       //Deu ruim!
    {
        cout << "O arquivo não pode ser aberto para leitura.\n";
        cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        //Proprietarios
        int qtd_p = 0;
        //Escopos
        int scope = 1;
        string i = "0", m;
        //Lê os escopos do arquivo
        while(getline(file, i))                            //final do arquivo?
        {
            //scope 1
            //if (scope == 01)
            // cout << "scope" << scope << endl;
            //scope 2 Dados dos proprietarios
            if(scope == 02)
            {
                file.ignore(256, ':');                     //ignore until ': '
                getline(file, i);                          //get    until '\n'
                qtd_p = atoi(i.c_str());                   //Quantidade de proprietarios
                //cout << "scope" << scope << endl
                //cout << "->" << i << endl;
                //Atualiza lista de proprietarios
                for(int p = 1 ; p <= qtd_p ; p++)
                {
                    file.ignore(256, ':');                 //ignore until ':'
                    getline(file, prop.nome);
                    //cout << "->" << prop.nome << endl;
                    file.ignore(256, ':');                 //ignore until ':'
                    getline(file, prop.codigo);
                    //cout << "->" << prop.codigo << endl; 
                    proprietarios.push_back(prop);         //Adiciona a lista de proprietários*/
                }
            }
            //scope 3 Dados do juridico
            else if(scope == 03)
            {
                //cout << "scope" << scope << endl;
                //Atualiza dados juridicos
                file.ignore(256, ':');                     //ignore until ':'
                getline(file, juridico.nome);
                //cout << "->" << juridico.nome << endl;
                file.ignore(256, ':');                     //ignore until ':'
                getline(file, juridico.cnpj);
                //cout << "->" << juridico.cnpj << endl;
            }
            // Outros scopes Dados do estoque
            else if(scope > 1)
            {
                if(i == "       Caminhão")                 //achou caminhão!!!
                {                  
                    stock.naut = stock.naut + 1;
                    caminhao truck;
                    truck.readDataOnFile(file);
                    stock.caminhoes.push(truck);
                }
                if(i == "       Moto")                     //achou moto!!!
                {
                    stock.naut = stock.naut + 1;
                    moto motocycle;
                    motocycle.readDataOnFile(file);
                    stock.motos.push(motocycle);
                }
            }
            scope++;
        }

        file.close();                                      //Fecha o arquivo
    }
}

void concessionaria::writeDataInFile()
{
    string nameFile = "dados.txt";                                            //Nome do arquivo
    const char *cstr = nameFile.c_str();                                      //String to C string version
    ofstream file;                                                            //Instancia ofstream para a escrita
    file.open(cstr);                                                          //Cria/Abre o arquivo
    bool status;                                                              //Status do arquivo                    
    status = !( file.fail() || !file.is_open() || !file.good() );             
    if(!status)                                                               //Deu ruim!
    {
        cout << "Arquivo não pode ser aberto para escrita.\n"; 
        cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    else                                                                      //De boas...
    {
        file                                                                     << endl;
        file     << "    Dados da concessionária:"                               << endl;
        file     << "     Proprietários:"               << proprietarios.size()  << endl;
        int n = 1;
        for(list<p>::iterator i = proprietarios.begin() ; i != proprietarios.end() ; i++)
        {   
            file << "      " << n << "  Nome/razão social:"     << (*i).nome     << endl;
            file << "         CPF/CNPJ:"                        << (*i).codigo   << endl;
            n++;
        }
        file << "     Jurídico               "                  << endl;
        file << "      Razão social:"          << juridico.nome << endl;
        file << "      CNPJ:"                  << juridico.cnpj << endl;
        file << "     Estoque                "                  << endl;
        file << "      Total:"                                  << stock.naut                       << endl;
        file << "      Caminhões:"                              << stock.caminhoes.size()           << endl;
        file << "      Motos:"                                  << stock.motos.size()               << endl;
        file << "      Produção Trimestral:"                    << getEstoque_producao_trimestral() << endl;
        file << "      Detalhamento dos veículos cadastrados:"                                      << endl;
        
        stock.caminhoes.writeDataInFile(file);
        stock.motos.writeDataInFile(file);

        file.close();                                                         //Fecha o arquivo
    }
}

//Sobrecarga de Operadores Relacionais

bool concessionaria::operator ==(concessionaria c)
{
    return ( juridico.nome == c.juridico.nome || juridico.cnpj == c.juridico.cnpj );
}

bool concessionaria::operator !=(concessionaria c)
{
    return ( juridico.nome != c.juridico.nome || juridico.cnpj != c.juridico.cnpj );
}

//Sobrecarga do Operador de Atribuição

concessionaria & concessionaria::operator =(const concessionaria & c)
{
    if (this != & c)
    {
        proprietarios = c.proprietarios;
        juridico = c.juridico;
        stock = c.stock;
    }
    return *this;
}

//Sobrecarga de Operadores IO

istream & operator >>(istream & is, concessionaria & c)
{
    int qntd = 0;
    //Get proprietarios from user
    cout << "    Insira os dados da concessionária:" << endl;
    cout << "     Digite a quantidade de proprietarios: ";
    cin >> qntd;
    cin.ignore();                                                   //ignore '\n' from enter on buffer
    for(int i = 1 ; i <= qntd ; i++)
    {    
        cout << "      Proprietário [" << i << "]:" << endl;
        cout << "       Digite o nome/razão social: ";         
        getline(cin, c.prop.nome);
        cout << "       Digite o CNPJ/CPF: ";
        c.prop.codigo = '\0';
        getline(cin, c.prop.codigo);           
        c.proprietarios.push_back(c.prop);                          //Adiciona a lista de proprietários
    }
    //Get juridico from user
    cout << "     Jurídico: " << endl;
    cout << "      Digite a razão social: ";
    cin.ignore(c.juridico.nome.size(),'\n'); 
    getline(cin, c.juridico.nome);
    cout << "      Digite o CNPJ: ";    
    cin.ignore(c.juridico.cnpj.size(),'\n');
    getline(cin, c.juridico.cnpj);
    //Get estoque from user
    string comando;    
    cout << "     Cadastrar veículo [Y/N]? ";
    //cin.ignore(comando.size(),'\n');
    //getline(cin, comando);
    cin >> comando;    
    if (comando == "Y" || comando == "y" )
    {
        qntd = 0;
        cout << "      Digite a quantidade: ";
        cin >> qntd;
        cout << "       Menu para cadastro de veículos: "  << endl;
        cout << "       ├Automóveis:                    "  << endl;
        cout << "       ├─[1] Caminhão                  "  << endl;
        cout << "       ├─[2] Moto                      "  << endl;
        cout << "       ├─[0] Sair                      "  << endl;
    }
    for(int i = 1 ; i <= qntd ; i++)
    {   //Adiciona um veículo ao estoque
        int codigo;
        cout << "       Digite o código do veículo [" << i << "]: ";
        cin >> codigo;
        switch(codigo)
        {
            case 1:
            {//As chaves criam um bloco e um escopo, para poder criar as variáveis.
                caminhao novoCaminhao;
                cin >> novoCaminhao;
                if(!c.stock.caminhoes.checkIn(novoCaminhao))
                {
                    c.stock.caminhoes.push(novoCaminhao);
                    c.stock.naut++;
                }           
                break;
            }
            case 2:
            {
                moto novaMoto;
                cin >> novaMoto;
                if(!c.stock.motos.checkIn(novaMoto))
                {
                    c.stock.motos.push(novaMoto);
                    c.stock.naut++;
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

    return is;
}

ostream & operator <<(ostream & os, concessionaria & c)
{
    cout << "    Dados da concessionária " << endl;
    c.printProprietarios();
    c.printJuridico();
    if(c.stock.naut != 0) c.printEstoque();
    return os;
}