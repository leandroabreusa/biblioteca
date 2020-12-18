#include <stdio.h>
#include <string.h>
#include "upper.cpp"

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


  void Cadastro_Codigo_Itens_Biblioteca(ItensBiblioteca &inclusao){
    char trash[1000];
    puts("        CADASTRO DE ITENS\n");
    printf("\nCodigo\n");
    do{
      scanf("%d", &inclusao.codigo);
      getchar();
      if(inclusao.codigo<0){
        gets(trash);
         puts("Codigo invalido. Insira um codigo valido:");
      }

    }while(inclusao.codigo<0);
  }

  void Cadastro_Itens_Biblioteca(ItensBiblioteca &inclusao) {

    //TITULO
    puts("\nTitulo do item\n");
    gets(inclusao.titulo);
    while (strlen(inclusao.titulo)>30) {
      puts("Titulo invalido. Entre com um titulo de ate 30 caracteres");
      gets(inclusao.titulo);
    }

    //ITEM
    puts("\nTipo de item (R- revista / L- livro)\n");
    do{
      scanf("%c", &inclusao.tipo);
      getchar();
      if (inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l'){
        puts("Essa nao e uma entrada valida. Por favor entre com o tipo correto do item (R- revista / L- livro)");
      }
    }while(inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l');

    switch (inclusao.tipo) {
      case 'R': strcpy(inclusao.autor, "NAO APLICAVEL");break;
      case 'r': strcpy(inclusao.autor, "NAO APLICAVEL"); inclusao.tipo='R';break;
      case 'L':puts("\nNome do autor\n");gets(inclusao.autor); break; //AUTOR
      case 'l':puts("\nNome do autor\n");gets(inclusao.autor);inclusao.tipo='L'; break; //AUTOR

    }
    //TESTE DE AUTOR
    while (strlen(inclusao.autor)>30) {
      puts("Nome invalido. Entre com um nome de ate 30 caracteres");
      gets(inclusao.autor);
    }
    //EDITORA
    puts("\nEditora\n");
    do{
      gets(inclusao.editora);
      if(strlen(inclusao.editora)>15) puts("\nNome de editora invalido. Entre com um nome de editora valido:\n");
    } while (strlen(inclusao.editora)>15);

    //ANO DE PUBLICACAO
    puts("Ano que foi publicado\n");
    do{
      scanf("%d", &inclusao.anopubl);
      getchar();
      if(inclusao.anopubl>=10000 || inclusao.anopubl<1000) puts("Ano invalido. Entre novamente:");
    }while(inclusao.anopubl>=10000 || inclusao.anopubl<1000);


  conversaoCaixaAlta(inclusao.titulo);
  conversaoCaixaAlta(inclusao.editora);
  conversaoCaixaAlta(inclusao.autor);
    // CONVERSAO PARA CAIXA ALTA
    /*strupr(inclusao.titulo);
    strupr(inclusao.editora);
    strupr(inclusao.autor);
    */
  }


  int main() {
    ItensBiblioteca item[MAX_USU_IT];
    int key, qtd_Itens=0;

    item[qtd_Itens].codigo=-1;
    Cadastro_Codigo_Itens_Biblioteca(item[qtd_Itens]);

    if(qtd_Itens==0) key=0;
    else key=1;
    while(key!=0){
       Cadastro_Codigo_Itens_Biblioteca(item[qtd_Itens]);

      for (int i=0; i< qtd_Itens;i++){
        if(item[i].codigo == item[qtd_Itens].codigo) key=1;
        else key=0;
      }
    }
    Cadastro_Itens_Biblioteca(item[qtd_Itens]);

    putchar('\n');
    printf("CODIGO: %d\n\n", item[qtd_Itens].codigo);
    puts("Titulo:\n");
    puts(item[qtd_Itens].titulo);
    puts("Editora:");
    puts(item[qtd_Itens].editora);
    puts("Autor:");
    puts(item[qtd_Itens].autor);
    qtd_Itens+=1;

  }
