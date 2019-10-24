
#Makefile for "concessionarias" C++ application
#Created by r4m0nl1m4 29/10/2019

#executável
PROG = concessionarias								
#compilador
CC = g++
#diretorio
DIR = pwd
#diretivas de compilação
CPPFLAGS = -O0       \
           -g        \
           -Wall     \
           -ansi     \
           -pedantic \
           -DIR      
#diretivas para o ligador (linker)
LDFLAGS = -DIR
#arquivos objetos definidos como pré-requisito
OBJS = main.o concessionarias.o veiculos.o automoveis.o caminhoes.o motos.o					

#regra de construção do executável
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)			

#regra de construção dos arquivos objetos
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

concessionarias.o : concessionarias.h
	$(CC) $(CPPFLAGS) -c concessionarias.cpp

veiculos.o : estoque.h veiculos.h 
	$(CC) $(CPPFLAGS) -c veiculos.cpp

automoveis.o : automoveis.h
	$(CC) $(CPPFLAGS) -c automoveis.cpp

caminhoes.o : caminhoes.h
	$(CC) $(CPPFLAGS) -c caminhoes.cpp

motos.o : motos.h
	$(CC) $(CPPFLAGS) -c motos.cpp

#regra de limpeza dos arquivos
clean:
	rm -rf core $(PROG) $(OBJS)