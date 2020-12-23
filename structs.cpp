#include <string.h>

const int TAM_NOME = 100;
const int MAX_NOME = 30;
const int MIN_NOME = 4;
const int MAX_USUARIOS_ITENS = 50;

struct Usuario {
    long long cpf;
    char nome[TAM_NOME];
};


struct ItensBiblioteca {
 int codigo;
 char titulo[NOMES];
 char tipo;
 char autor[NOMES];
 char editora[15];
 int anopubl;
};
