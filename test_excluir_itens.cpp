#include <stdio.h>
#include <string.h>

const int TAM_NOME = 100;
const int MAX_NOME = 30;
const int MIN_NOME = 4;
const int MAX_USUARIOS_ITENS = 50;

struct Emprestimo {
    int codigo;
};

struct ItensBiblioteca {
 int codigo;
 char titulo[TAM_NOME];
};

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

void Excluir_Item(Emprestimo emprestimo[], int qtd_emprestimos,ItensBiblioteca item[], int &posicao_item){
  int codigo = 0, tentativas = 1;
  for (int x = 1; x <= tentativas; x++){
      puts("Insira um codigo de ate 6 digitos: ");
      scanf("%d", &codigo);
      getchar();

      if(codigo > 0 && codigo < 1000000){ break; }
      printf("Codigo invalido! *(voce tem mais %d tentativas)*\n\n", (tentativas-x));
  }

  if (!verificaCodigo(item, codigo, posicao_item)){
    printf("Erro na exclusao. Item nao cadastrado!\n");
    return;
  }
  else {
    if (existe_emprestimo(emprestimo, qtd_emprestimos, codigo)){
      printf("Erro na exclusao. Item esta emprestado!\n");
      return;
    }
    else {
      //EXCLUIR
      ItensBiblioteca temp;
      temp.codigo = 0;
      strcpy(temp.titulo, "");

      for (int x = 0; x <= posicao_item; x++){
        if (item[x].codigo == codigo){
          //Se posição não for a ultima, rearranjar itens
          for (; x < posicao_item; x++){
            item[x] = item[x+1];
            //Zera posição
            item[x+1] = temp;
          }

          break;
        }
      }

      printf("Exclusao realizada com sucesso!\n");
      posicao_item-=1;
      return;
    }
  }
}



int main(int argc, char *argv[]){
    Emprestimo emprestimo[1];
    emprestimo[0].codigo =  1;

    ItensBiblioteca item[4];

    int list[4] = {1, 2, 3, 4};
    char names[4][4] = {"sdg", "bds", "lkd", "gjj"};
    for (int x = 0; x<4; x++){
        item[x].codigo = list[x];
        strcpy(item[x].titulo, names[x]);
    }

    int qt = 3;
    Excluir_Item(emprestimo, 1, item, qt);

    //printf("%d\n", qt);
    for (int x = 0; x < (qt+1); x++){
        printf("%d -> %s\n", item[x].codigo, item[x].titulo);
    }
    return 0;
}
