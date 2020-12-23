#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "structs.cpp"

//ORDENACAO DE USUARIO:
//CPF
void Ordernar_por_CPF(Usuario ordena[], int qtd_usuarios){
  bool troca=true;

  while(qtd_usuarios >0 && troca){
    int i;
    Usuario aux;
    troca=false;
    for(i=0;i<qtd_usuarios;i++){
      if(ordena[i].cpf> ordena[i+1].cpf){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    qtd_usuarios-=1;
  }
}
//CPF

//NOME
void Ordernar_por_Nome(Usuario ordena[], int qtd_usuarios){
  bool troca=true;

  while(qtd_usuarios >0 && troca){
    int i;
    Usuario aux;
    troca=false;
    for(i=0;i<qtd_usuarios;i++){
      if(strcmpi(ordena[i].nome, ordena[i+1].nome)>0){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    qtd_usuarios-=1;
  }
}
//NOME

//ORDENACAO DE ITENS (CODIGO E TITULO):

//CODIGO
void Ordernar_por_Codigo(ItensBiblioteca ordena[], int qtd_Itens){
  bool troca=true;

  while(qtd_Itens >0 && troca){
    int i;
    ItensBiblioteca aux;
    troca=false;
    for(i=0;i<qtd_Itens;i++){
      if(ordena[i].codigo> ordena[i+1].codigo){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    qtd_Itens-=1;
  }
}
//CODIGO

//TITULO
void Ordernar_por_Titulo(ItensBiblioteca ordena[], int qtd_Itens){
  bool troca=true;
  while(qtd_Itens >0 && troca){
    int i;
    ItensBiblioteca aux;
    troca=false;
    for(i=0;i<qtd_Itens;i++){
      if(strcmpi(ordena[i].titulo, ordena[i+1].titulo)>0){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    qtd_Itens-=1;
  }
}
//TITULO 
