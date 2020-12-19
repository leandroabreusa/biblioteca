#include <string.h>

const int TAM_NOME = 100;
const int MAX_NOME = 30;
const int MIN_NOME = 4;
const int MAX_USUARIOS = 50;

struct Usuario {
    long long cpf;
    char nome[TAM_NOME];
};

const size_t NOMES= 30;
const size_t MAX_USU_IT = 50;

struct ItensBiblioteca {
 int codigo;
 char titulo[NOMES];
 char tipo;
 char autor[NOMES];
 char editora[15];
 int anopubl;
};
