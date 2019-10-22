
README for "concessionarias" C++ application
Created by r4m0nl1m4 29/10/2019

No terminal, chame o makefile.

	<user_name>@<host_name>$ make

Exemplo de execução:

...Instanciação de uma concessionária...

Concessionária
 Digite o nome: Volkswagen do Brasil
 Digite o CNPJ: 59.104.422/0058-1
 Cadastrar veículo [Y/N]? y
 Digite a qntd: 1
 Veículo
  Digite o chass: 98765
  Digite a dataF: 
   Digite o dia [ 1-31 ]: 1
   Digite o mes [ 1-12 ]: 9
   Digite o ano [ 1900-]: 2019
  Digite a marca: Volkswagen Fusca
  Digite o preço: 10000

...Apresentação dos dados da(s) concessionária(s)...

├── Concessionária
├─── Nome Volkswagen do Brasil
├─── CNPJ 59.104.422/0058-1
├─── Naut 1
├─── ProT 1
├─── Veículo
├──── Chass 98765
├──── Data  Sun Sep  1 00:00:00 2019
├──── Marca Volkswagen Fusca
├──── Preço R$ 10000.00

...Produção trimestral da(s) concessionária(s)...

├── Concessionária Volkswagen do Brasil produziu 1 veículo(s) no último trimestre.
├─── Veículo
├──── Chass 98765
├──── Data  Sun Sep  1 00:00:00 2019
├──── Marca Volkswagen Fusca
├──── Preço R$ 10000.00

...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária...

├── Concessionária
├─── Nome Volkswagen do Brasil
├─── CNPJ 59.104.422/0058-1
├─── Naut 1
├─── ProT 1
├─── Veículo
├──── Chass 98765
├──── Data  Sun Sep  1 00:00:00 2019
├──── Marca Volkswagen Fusca
├──── Preço R$ 15000.00

...Apresentação do balanço das operações da(s) concessionária(s)...

Balanço             
 Média              1
 Veículo(s)         1
 Concessionária(s)  1
 Produção Trimestre 1
