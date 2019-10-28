
README for "concessionarias" C++ application
Created by r4m0nl1m4 and willimax 29/10/2019

No terminal, chame o makefile.

  Para compilação:	

	<user_name>@<host_name>$ make

  Para limpeza dos arquivos de compilação:

        <user_name>@<host_name>$ make clean

Exemplo de execução:

...Instanciação de uma concessionária...

    Insira os dados da concessionária:
     Digite a quantidade de proprietarios: 2
      Proprietário [1]:
       Digite o nome/razão social: Manolo One
       Digite o CNPJ/CPF: 123.456.789-01
      Proprietário [2]:
       Digite o nome/razão social: Manolo Two
       Digite o CNPJ/CPF: 123.456.789-02
     Jurídico: 
      Digite a razão social: Manolo's Cars LTDA
      Digite o CNPJ: 12.345.789/000-1
     Cadastrar veículo [Y/N]? y
      Digite a quantidade: 2
       Menu para cadastro de veículos: 
       ├Automóveis:                    
       ├─[1] Caminhão                  
       ├─[2] Moto                      
       ├─[0] Sair                      
       Digite o código do veículo [1]: 1
        Veículo
        ├Digite o chass: 56789
        ├Digite a dataF: 
        ├─Digite o dia [ 1-31 ]: 1
        ├─Digite o mes [ 1-12 ]: 9
        ├─Digite o ano [ 1900-]: 2019
        ├Digite a marca: Truck
        ├Digite o preço: 100000
        ├Automóvel
        ├─Digite o motor: Gasolina
        ├─Caminhão
        ├──Digite a carga: Perigosa
        Caminhão cadastrado!
       Digite o código do veículo [2]: 2
        Veículo
        ├Digite o chass: 98765
        ├Digite a dataF: 
        ├─Digite o dia [ 1-31 ]: 29
        ├─Digite o mes [ 1-12 ]: 10
        ├─Digite o ano [ 1900-]: 2019
        ├Digite a marca: Motocycle
        ├Digite o preço: 10000
        ├Automóvel
        ├─Digite o motor: Elétrico
        ├─Moto
        ├──Digite o modelo: Esportiva
        Moto cadastrada!

...Apresentação dos dados da(s) concessionária(s)...

    Dados da concessionária 
     Proprietários: 2
      1. Nome/razão social: Manolo One
         CPF/CNPJ: 123.456.789-01
      2. Nome/razão social: Manolo Two
         CPF/CNPJ: 123.456.789-02
     Jurídico 
      Nome: Manolo's Cars LTDA
      CNPJ: 12.345.789/000-1
     Estoque: 2
      Produção Trimestral: 2
      Detalhamento dos veículos cadastrados: 

       Caminhão 
        Veículo 
        ├Chass 56789
        ├Data Sun Sep  1 00:00:00 2019
        ├Marca Truck
        ├Preço R$ 100000.00
        ├Automóvel 
        ├─Motor Gasolina
        ├──Caminhão 
        ├───Carga Perigosa

       Moto 
        Veículo 
        ├Chass 98765
        ├Data Tue Oct 29 00:00:00 2019
        ├Marca Motocycle
        ├Preço R$ 10000.00
        ├Automóvel 
        ├─Motor Elétrico
        ├──Moto 
        ├───Modelo Esportiva

...Produção trimestral da(s) concessionária(s)...

    A concessionária Manolo's Cars LTDA produziu 2 veículo(s) no último trimestre.

       Caminhão 
        Veículo 
        ├Chass 56789
        ├Data Sun Sep  1 00:00:00 2019
        ├Marca Truck
        ├Preço R$ 100000.00
        ├Automóvel 
        ├─Motor Gasolina
        ├──Caminhão 
        ├───Carga Perigosa

       Moto 
        Veículo 
        ├Chass 98765
        ├Data Tue Oct 29 00:00:00 2019
        ├Marca Motocycle
        ├Preço R$ 10000.00
        ├Automóvel 
        ├─Motor Elétrico
        ├──Moto 
        ├───Modelo Esportiva

...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária...

     Estoque: 2
      Produção Trimestral: 2
      Detalhamento dos veículos cadastrados: 

       Caminhão 
        Veículo 
        ├Chass 56789
        ├Data Sun Sep  1 00:00:00 2019
        ├Marca Truck
        ├Preço R$ 150000.00
        ├Automóvel 
        ├─Motor Gasolina
        ├──Caminhão 
        ├───Carga Perigosa

       Moto 
        Veículo 
        ├Chass 98765
        ├Data Tue Oct 29 00:00:00 2019
        ├Marca Motocycle
        ├Preço R$ 15000.00
        ├Automóvel 
        ├─Motor Elétrico
        ├──Moto 
        ├───Modelo Esportiva

...Apresentação do balanço das operações da(s) concessionária(s)...

    Balanço              
     Concessionária(s)   2
     Média da Produção   1.00
     Produção Trimestral 2
     Veículo(s)          2
     ├Automóvel(is)      2
     ├─Caminhão(ões)     1
     ├─Moto(s)           1

...Busca veículo no estoque pelo seu chassis...

    Digite o chass: 98765

       Moto 
        Veículo 
        ├Chass 98765
        ├Data Tue Oct 29 00:00:00 2019
        ├Marca Motocycle
        ├Preço R$ 15000.00
        ├Automóvel 
        ├─Motor Elétrico
        ├──Moto 
        ├───Modelo Esportiva


...Nova instância criada a partir do arquivo gerado anteriormente...

    Dados da concessionária 
     Proprietários: 2
      1. Nome/razão social: Manolo One
         CPF/CNPJ: 123.456.789-01
      2. Nome/razão social: Manolo Two
         CPF/CNPJ: 123.456.789-02
     Jurídico 
      Nome: Manolo's Cars LTDA
      CNPJ: 12.345.789/000-1
     Estoque: 2
      Produção Trimestral: 2
      Detalhamento dos veículos cadastrados: 

       Caminhão 
        Veículo 
        ├Chass 56789
        ├Data Sun Sep  1 00:00:00 2019
        ├Marca Truck
        ├Preço R$ 150000.00
        ├Automóvel 
        ├─Motor Gasolina
        ├──Caminhão 
        ├───Carga Perigosa

       Moto 
        Veículo 
        ├Chass 98765
        ├Data Tue Oct 29 00:00:00 2019
        ├Marca Motocycle
        ├Preço R$ 15000.00
        ├Automóvel 
        ├─Motor Elétrico
        ├──Moto 
        ├───Modelo Esportiva
