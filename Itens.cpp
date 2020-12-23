#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tool.cpp"
#include "structs.cpp"


  void Cadastro_Codigo_Itens_Biblioteca(ItensBiblioteca inclusao[], int posicao_item, bool &key){
    char trash[1000];
    puts("        CADASTRO DE ITENS\n");
    printf("\nCodigo\n");
    do{
      scanf("%d", &inclusao[posicao_item].codigo);
      gets(trash);
      if(inclusao[posicao_item].codigo<0 || inclusao[posicao_item].codigo>=1000000){
         puts("Codigo invalido. Insira um codigo valido de ate 6 digitos:");
      }
    }while(inclusao[posicao_item].codigo<0 || inclusao[posicao_item].codigo>=1000000);

    if(posicao_item==0) key=false;
    else key=true;

      if(key==true){
        key=false;
        for (int i=0; i< posicao_item;i++){
          if(inclusao[i].codigo == inclusao[posicao_item].codigo){
            key=true;
            break;
          }
        }
      }
  }

  void Cadastro_Itens_Biblioteca(ItensBiblioteca &inclusao) {
   char trash[1000];
    //ITEM
    puts("\nTipo de item (R- revista / L- livro)\n");
    do{
      scanf(" %c", &inclusao.tipo);
      if (inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l'){
       gets(trash);
        puts("Essa nao e uma entrada valida. Por favor entre com o tipo correto do item (R- revista / L- livro)");
      }
    }while(inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l');
    getchar();
    //ITEM


    //TITULO
    puts("\nTitulo do item\n");
    gets(inclusao.titulo);
    while (strlen(inclusao.titulo)>MAX_NOME || strlen(inclusao.titulo)<MIN_NOME) {
      puts("Titulo invalido. Entre com um titulo de 4 ate 30 caracteres");
      gets(inclusao.titulo);
    }
    //TITULO

    //TESTE DE AUTOR
    switch (inclusao.tipo) {
      case 'R': strcpy(inclusao.autor, "NAO APLICAVEL");break;
      case 'r': strcpy(inclusao.autor, "NAO APLICAVEL"); inclusao.tipo='R';break;
      case 'L':puts("\nNome do autor\n");gets(inclusao.autor); break; //AUTOR
      case 'l':puts("\nNome do autor\n");gets(inclusao.autor);inclusao.tipo='L'; break; //AUTOR

    }
    while (strlen(inclusao.autor)>MAX_NOME || strlen(inclusao.autor)<MIN_NOME) {
      puts("Nome invalido. Entre com um nome de 4 ate 30 caracteres");
      gets(inclusao.autor);
    }
    //TESTE DE AUTOR


    //EDITORA
    puts("\nEditora\n");
    do{
      gets(inclusao.editora);
      if(strlen(inclusao.editora)>15 || strlen(inclusao.editora)<MIN_NOME) puts("\nNome de editora invalido. Entre com um nome de 4 ate 15 caracteres:\n");
    } while (strlen(inclusao.editora)>15 || strlen(inclusao.editora)<MIN_NOME);
    //EDITORA


    //ANO DE PUBLICACAO
    puts("\nAno que foi publicado\n");
    do{
      scanf("%d", &inclusao.anopubl);
      if(inclusao.anopubl>=10000 || inclusao.anopubl<1000){
       gets(trash);
       puts("Ano invalido. Entre novamente:");
      }
    }while(inclusao.anopubl>=10000 || inclusao.anopubl<1000);
    getchar();
    //ANO DE PUBLICACAO

    // CONVERSAO PARA CAIXA ALTA
    conversaoCaixaAlta(inclusao.titulo);
    conversaoCaixaAlta(inclusao.editora);
    conversaoCaixaAlta(inclusao.autor);


  }

  void retorno_visual(ItensBiblioteca item){
    putchar('\n');
    printf("Codigo: %d\n",item.codigo);

    printf("Tipo: %c\n", item.tipo);

    printf("Titulo: ");
    puts(item.titulo);

    if(item.tipo=='L'){
      printf("Autor: ");
      puts(item.autor);
    }

    printf("Editora: ");
    puts(item.editora);

    printf("Ano: %d\n\n",item.anopubl);

    puts("Cadastro realizado com sucesso!");

  }

int Cadastrar_Itens(ItensBiblioteca item[], int &qtd_Itens) {
    bool key;
    item[qtd_Itens].codigo=-1;
    if(qtd_Itens==MAX_USUARIOS_ITENS-1){
      puts("Erro no cadastro. Ja foi atingido o limite de 50 usuarios!");
      return 0;
    }

    Cadastro_Codigo_Itens_Biblioteca(item, qtd_Itens, key);

    if (key==true){
      printf("Codigo: %d\nErro no cadastro. Item ja cadastrado\n", item[qtd_Itens].codigo);
      return 0;
    }
    else{
      Cadastro_Itens_Biblioteca(item[qtd_Itens]);
      retorno_visual(item[qtd_Itens]);
      qtd_Itens+=1;
    }
    return 0;
  }
 /* int main() {
    
    ItensBiblioteca item[MAX_USUARIOS_ITENS];
    int qtd_Itens=0;

    
    bool key;
    item[qtd_Itens].codigo=-1;
    
    if(qtd_Itens==MAX_USUARIOS_ITENS-1){
      puts("Erro no cadastro. Ja foi atingido o limite de 50 usuarios!");
      
      return 0;
    }
    
    Cadastro_Codigo_Itens_Biblioteca(item, qtd_Itens, key);

    if (key==true){
      printf("Codigo: %d\nErro no cadastro. Item ja cadastrado\n", item[qtd_Itens].codigo);
      break;
    }
    else{
      Cadastro_Itens_Biblioteca(item[qtd_Itens]);
      retorno_visual(item[qtd_Itens]);
      qtd_Itens+=1;
    }
    return 0;
  }*/
