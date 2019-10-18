
README for "concessionarias" C++ application
Created by r4m0nl1m4 09/09/2019

No terminal, chame o makefile.

	<user_name>@<host_name>$ make

Exemplo de execução:

...Instanciação de uma concessionária...

Concessionária                              //PODEM SER INSTANCIADOS N-ÉSIMAS CONCESSIONÁRIAS
 Digite o nome: Volkswagen do Brasil
 Digite o CNPJ: 59.104.422/0058-1
 Cadastrar veículos [Y/N]? y
 Digite a qntd: 1                           //PODEM SER ADICIONADOS N-ÉSIMOS VEICULOS AO ESTOQUE DA CONCESSIONÁRIA
 Veículo
  Digite a marca: Volkswagen Fusca
  Digite o preço: 10000
  Digite o chass: 98765
  Digite a dataF: 
   Digite o dia [ 1-31 ]: 1
   Digite o mes [ 1-12 ]: 9
   Digite o ano [ 1900-]: 2019

...Apresentação dos dados da(s) concessionária(s)...

├── Concessionária
├─── Nome Volkswagen do Brasil
├─── CNPJ 59.104.422/0058-1
├─── Naut 1                                 //NÚMERO DE VEÍCULOS DO ESTOQUE
├─── ProT 1                                 //PRODUÇÃO TRIMESTRAL DE VEÍCULOS DA CONCESSIONÁRIA
├─── Veículo                                //EXIBIÇÃO DE VEÍCULOS(S) CADASTRADO(S)
├──── Marca Volkswagen Fusca
├──── Preço R$ 10000.00
├──── Chass 98765
├──── data  Sun Sep  1 00:00:00 2019

...Produção trimestral da(s) concessionária(s)...

├── Concessionária Volkswagen do Brasil produziu 1 veículo(s) no último trimestre.
├─── Veículo
├──── Marca Volkswagen Fusca
├──── Preço R$ 10000.00
├──── Chass 98765
├──── data  Sun Sep  1 00:00:00 2019

...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária...

├── Concessionária
├─── Nome Volkswagen do Brasil
├─── CNPJ 59.104.422/0058-1
├─── Naut 1
├─── ProT 1
├─── Veículo
├──── Marca Volkswagen Fusca
├──── Preço R$ 15000.00                     //O INCREMENTO DA ALÍQUOTA DO PREÇO PODE SER ALTERADA VIA CHAMADA DE MÉTODO
├──── Chass 98765
├──── data  Sun Sep  1 00:00:00 2019

...Apresentação do balanço das operações da(s) concessionária(s)...

Balanço             
 Média              1
 Veículo(s)         1
 Concessionária(s)  1
 Produção Trimestre 1
