#include <stdio.h>
#include <ctype.h>
#include <string.h>
const int TAM_NOME = 100;
const int MAX_NOME = 30;
const int MIN_NOME = 4;
const int MAX_USUARIOS_ITENS = 50;

//ORDENACAO DE USUARIO:
//CPF
void Ordernar_por_CPF(Usuario ordena[], int listagem){
  bool troca=true;

  while(listagem >0 && troca){
    int i;
    Usuario aux;
    troca=false;
    for(i=0;i<listagem;i++){
      if(ordena[i].cpf> ordena[i+1].cpf){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    listagem-=1;
  }
}
//CPF

//NOME
void Ordernar_por_Nome(Usuario ordena[], int listagem){
  bool troca=true;

  while(listagem >0 && troca){
    int i;
    Usuario aux;
    troca=false;
    for(i=0;i<listagem;i++){
      if(strcmpi(ordena[i].nome, ordena[i+1].nome)>0){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    listagem-=1;
  }
}
//NOME

//ORDENACAO DE ITENS (CODIGO E TITULO):

//CODIGO
void Ordernar_por_Codigo(ItensBiblioteca ordena[], int listagem){
  bool troca=true;

  while(listagem >0 && troca){
    int i;
    ItensBiblioteca aux;
    troca=false;
    for(i=0;i<listagem;i++){
      if(ordena[i].codigo> ordena[i+1].codigo){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    listagem-=1;
  }
}
//CODIGO

//TITULO
void Ordernar_por_Titulo(ItensBiblioteca ordena[], int listagem){
  bool troca=true;
  while(listagem >0 && troca){
    int i;
    ItensBiblioteca aux;
    troca=false;
    for(i=0;i<listagem;i++){
      if(strcmpi(ordena[i].titulo, ordena[i+1].titulo)>0){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    listagem-=1;
  }
}
//TITULO 
