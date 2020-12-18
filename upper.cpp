#include <string.h>
#include <stdio.h>
#include <ctype.h>

void conversaoCaixaAlta(char vetor[]){
    //CONVERTE PARA CAIXA ALTA
    for (size_t i = 0; i < strlen(vetor); i++) {
        if(vetor[i] >= 'a' && vetor[i] <= 'z') {
            vetor[i] = toupper(vetor[i]);
        }
    }
    //printf("%s\n", vetor);
}

/*
int main(){
    char nome[7] = "lo han";
    conversaoCaixaAlta(nome);
}
*/