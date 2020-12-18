#include <string.h>

void conversaoCaixaAlta(char vetor[]){
  for (size_t i = 0; i < strlen(vetor); i++) {
      if(vetor[i] >= 'a' && vetor[i] <= 'z') {
         vetor[i] = *(vetor - 32);
    }
  }
}