#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "structs.cpp"
#include "incluir_emprestimo_item.cpp"

bool verificaCodigo(ItensBiblioteca item[], int codigo, int posicao_item){
    for (int x = 0; x < posicao_item; x++){
        if (item[x].codigo == codigo){
            return true;
        }
    }
    return false;
}

bool existe_emprestimo (Emprestimo emprestimo[], int qtd_emprestimos, int codigo){
  for (int i = 0; i < qtd_emprestimos; i++){
    if (emprestimo[i].codigo == codigo) { return true; }
  }
  return false;
}

void conversaoCaixaAlta(char vetor[]){
    //CONVERTE PARA CAIXA ALTA
    for (size_t i = 0; i < strlen(vetor); i++) {
        if(vetor[i] >= 'a' && vetor[i] <= 'z') {
            vetor[i] = toupper(vetor[i]);
        }
    }
    //printf("%s\n", vetor);
}

bool existeCPF(Usuario usuarios[], long long cpf){
    int length = sizeof(usuarios)/sizeof(usuarios[0]);

    for (int x = 0; x < length; x++){
        if (usuarios[x].cpf == cpf){
            return true;
        }
    }
    return false;
}

bool testa_tamanho_string (int n, int k,
                           Usuario usuario[], int qtd_usuarios)
{
    // Se o tamanho estiver fora dos limites permitidos, retorna falso
    if (strlen(usuario[qtd_usuarios].nome) < n ||
        strlen(usuario[qtd_usuarios].nome) > k)
            return false;

    // Se n�o, retorna verdadeiro
    return true;
}

// Testa se o cpf tem 11 d�gitos
bool testa_cpf (Usuario usuario[], int qtd_usuarios)
{
    // Se n�o tiver, retorna falso
    if (usuario[qtd_usuarios].cpf < 10000000000 ||
        usuario[qtd_usuarios].cpf > 99999999999)
            return false;

    // Se n�o, retorna verdadeiro
    return true;
}

/*
int main(){
    char nome[7] = "lo han";
    conversaoCaixaAlta(nome);
}
*/