#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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
 char titulo[TAM_NOME];
 char tipo;
 char autor[TAM_NOME];
 char editora[15];
 int anopubl;
};

struct Emprestimo {
    long long cpf;
    int codigo;
    char nome[TAM_NOME];
    char titulo[TAM_NOME];
    char tipo;
    int dia_emprestimo;
    int mes_emprestimo;
    int ano_emprestimo;
    int dia_devolucao;
    int mes_devolucao;
    int ano_devolucao;
};

bool confere_cpf (Usuario  usuario[], int qtd_usuarios, long long int cpf){
  for (int i = 0; i < qtd_usuarios; i++){
    if (usuario[i].cpf == cpf) return true;
  }

  return false;
}

bool confere_emprestimo (Emprestimo  emprestimo[], int qtd_emprestimos, long long int cpf){
  for (int i = 0; i < qtd_emprestimos; i++){
    if (emprestimo[i].cpf == cpf) return true;
  }
  return false;
}

int busca_codigo(ItensBiblioteca inclusao[], int qtd_Itens, int codigo)
{
    for (int i = 0; i < qtd_Itens; i++)
        if (inclusao[i].codigo == codigo)
            return i;

    return -1;
}

int busca_codigo_emprestimo(Emprestimo emprestimo[], int qtd_emprestimos, int codigo)
{
    for (int i = 0; i < qtd_emprestimos; i++)
        if (emprestimo[i].codigo == codigo)
            return i;

    return -1;
}

int busca_cpf(Usuario usuario[], int qtd_usuarios, long long cpf)
{
    for (int i = 0; i < qtd_usuarios; i++)
        if (usuario[i].cpf == cpf)
            return i;

    return -1;
}

int busca_cpf_emprestimo(Emprestimo emprestimo[], int qtd_emprestimos, long long cpf)
{
    for (int i = 0; i < qtd_emprestimos; i++)
        if (emprestimo[i].cpf == cpf)
            return i;

    return -1;
}

void ordena_por_emprestimo(Emprestimo ordena[], int qtd_emprestimos){
  bool troca=true;
  qtd_emprestimos--;

  while(qtd_emprestimos >0 && troca){
    int i;
    Emprestimo aux;
    troca=false;
    for(i=0;i<qtd_emprestimos;i++){
      if(ordena[i].cpf> ordena[i+1].cpf){
        aux=ordena[i+1];
        ordena[i+1]= ordena[i];
        ordena[i]=aux;
        troca=true;
      }
    }
    qtd_emprestimos-=1;
  }
}

void Ordernar_por_CPF(Usuario ordena[], int qtd_usuarios){
  bool troca=true;
  qtd_usuarios--;

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

void Ordernar_por_Nome(Usuario ordena[], int qtd_usuarios){
  bool troca=true;
  qtd_usuarios--;

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

void Ordernar_por_Codigo(ItensBiblioteca ordena[], int qtd_Itens){
  bool troca=true;
  qtd_Itens--;

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

void Ordernar_por_Titulo(ItensBiblioteca ordena[], int qtd_Itens){
  bool troca=true;
  qtd_Itens--;
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
    if (emprestimo[i].codigo == codigo) {
            return true;
    }
  }
  return false;
}

void conversaoCaixaAlta(char vetor[]){
    for (size_t i = 0; i < strlen(vetor); i++) {
        if(vetor[i] >= 'a' && vetor[i] <= 'z') {
            vetor[i] = toupper(vetor[i]);
        }
    }
}

bool existeCPF(Usuario usuarios[], long long cpf, int length){

    for (int x = 0; x < length; x++){
        if (usuarios[x].cpf == cpf){
            return true;
        }
    }
    return false;
}

bool testa_tamanho_string (int n, int k, char nome[])
{
    if (strlen(nome) < n ||
        strlen(nome) > k)
            return false;

    return true;
}

bool testa_cpf(long long cpf)
{
    if (cpf < 10000000000 || cpf > 99999999999)
        return false;

    return true;
}

void inclusao_usuarios (Usuario usuario[], int &qtd_usuarios)
{
    long long CPF;
    char nome[TAM_NOME];

    if (qtd_usuarios < MAX_USUARIOS_ITENS)
    {
        printf("CPF: ");
        scanf("%lld", &CPF);

        getchar();

        if (testa_cpf(CPF)){
            if (existeCPF(usuario, CPF, qtd_usuarios)){
                puts("\nErro no cadastro. CPF ja cadastrado!");
                return;
            }

            printf("Nome: ");
            gets(nome);

            conversaoCaixaAlta(nome);

            if (testa_tamanho_string(MIN_NOME, MAX_NOME, nome))
            {
                usuario[qtd_usuarios].cpf = CPF;
                strcpy(usuario[qtd_usuarios].nome, nome);

                puts("\nCadastro realizado com sucesso!");
                qtd_usuarios++;
            }
            else
                puts("\nErro no cadastro. Nome deve ter entre 4 e 30 caracteres!");
        }
        else
            puts("\nErro no cadastro. CPF deve ter 11 digitos!");
        }
    else
        puts("\nErro no cadastro. Ja foi atingido o limite de 50 usuarios!");
}

void exclui_usuario(Usuario usuario[], int &qtd_usuarios,
                    Emprestimo emprestimo[], int qtd_emprestimos)
{
    long long cpf;

    if (qtd_usuarios > 0)
    {
        printf("CPF: ");
        scanf("%lld", &cpf);

        int posicao_cpf;
        int posicao_emprestimo_cpf;

        posicao_cpf = busca_cpf(usuario, qtd_usuarios, cpf);
        posicao_emprestimo_cpf = busca_cpf_emprestimo(emprestimo, qtd_emprestimos, cpf);

        if (posicao_cpf != -1)
        {
            if (posicao_emprestimo_cpf == -1)
            {
                qtd_usuarios--;

                usuario[posicao_cpf] = usuario[qtd_usuarios];

                puts("\nExclusao realizada com sucesso!");
            }
            else
                puts("\nErro na exclusao. Usuario possui um emprestimo!");
        }
        else
            puts("\nErro na exclusao. Usuario nao cadastrado!");
    }
    else
        puts("\nErro na exclusao. Nao existem usuarios cadastrados!");
}

void Cadastro_Codigo_Itens_Biblioteca(ItensBiblioteca inclusao[], int posicao_item, bool &key){
    char trash[1000];
    printf("Codigo: ");
    do{
      scanf("%d", &inclusao[posicao_item].codigo);
      gets(trash);
      if(inclusao[posicao_item].codigo<0 || inclusao[posicao_item].codigo>=1000000){
         puts("Codigo invalido. Insira um codigo valido de ate 6 digitos.");
         printf("Codigo: ");
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
    printf("Tipo: ");
    do{
      scanf(" %c", &inclusao.tipo);
      if (inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l'){
       gets(trash);
        puts("Essa nao e uma entrada valida. Por favor entre com o tipo correto do item (R- revista / L- livro).");
        printf("Tipo: ");
      }
    }while(inclusao.tipo!='R' && inclusao.tipo!='r' && inclusao.tipo!='L' && inclusao.tipo!='l');
    getchar();

    printf("Titulo: ");
    gets(inclusao.titulo);
    while (strlen(inclusao.titulo)>MAX_NOME || strlen(inclusao.titulo)<MIN_NOME) {
      puts("Titulo invalido. Entre com um titulo de 4 ate 30 caracteres.");
      printf("Titulo: ");
      gets(inclusao.titulo);
    }

    switch (inclusao.tipo) {
      case 'R': strcpy(inclusao.autor, "NAO APLICAVEL");break;
      case 'r': strcpy(inclusao.autor, "NAO APLICAVEL"); inclusao.tipo='R';break;
        case 'L':printf("Autor: ");gets(inclusao.autor); break; //AUTOR
      case 'l':printf("Autor: ");gets(inclusao.autor);inclusao.tipo='L'; break; //AUTOR

    }
    while (strlen(inclusao.autor)>MAX_NOME || strlen(inclusao.autor)<MIN_NOME) {
      puts("Autor invalido. Entre com um nome de autor de 4 ate 30 caracteres.");
      printf("Autor: ");
      gets(inclusao.autor);
    }

    printf("Editora: ");
    do{
      gets(inclusao.editora);
      if(strlen(inclusao.editora)>15 || strlen(inclusao.editora)<MIN_NOME){
          puts("Nome de editora invalido. Entre com um nome de 4 ate 15 caracteres.");
          printf("Editora: ");
      }
    } while (strlen(inclusao.editora)>15 || strlen(inclusao.editora)<MIN_NOME);

    printf("Ano: ");
    do{
      scanf("%d", &inclusao.anopubl);
      if(inclusao.anopubl>=10000 || inclusao.anopubl<1000){
       gets(trash);
       puts("Ano invalido. Entre com um ano valido.");
       printf("Ano: ");
      }
    }while(inclusao.anopubl>=10000 || inclusao.anopubl<1000);
    getchar();

    conversaoCaixaAlta(inclusao.titulo);
    conversaoCaixaAlta(inclusao.editora);
    conversaoCaixaAlta(inclusao.autor);


}

void Cadastrar_Itens(ItensBiblioteca item[], int &qtd_Itens) {
    bool key;
    item[qtd_Itens].codigo=-1;
    if(qtd_Itens==MAX_USUARIOS_ITENS){
      puts("\nErro no cadastro. Ja foi atingido o limite de 50 itens!");
      return;
    }

    Cadastro_Codigo_Itens_Biblioteca(item, qtd_Itens, key);

    if (key==true){
      printf("\nErro no cadastro. Item ja cadastrado!\n");
      return;
    }
    else{
      Cadastro_Itens_Biblioteca(item[qtd_Itens]);
      qtd_Itens+=1;
      puts("\nCadastro realizado com sucesso!");
    }
    return;
  }

void Excluir_Item(Emprestimo emprestimo[], int qtd_emprestimos,ItensBiblioteca item[], int &posicao_item){
  int codigo = 0;
  printf("Codigo: ");
  scanf("%d", &codigo);

  if (!verificaCodigo(item, codigo, posicao_item)){
    printf("\nErro na exclusao. Item nao cadastrado!\n");
    return;
  }
  else {
    if (existe_emprestimo(emprestimo, qtd_emprestimos, codigo)){
      printf("\nErro na exclusao. Item esta emprestado!\n");
      return;
    }
    else {
      ItensBiblioteca temp;
      temp.codigo = 0;
      strcpy(temp.titulo, "");

      for (int x = 0; x <= posicao_item; x++){
        if (item[x].codigo == codigo){
          for (; x < posicao_item; x++){
            item[x] = item[x+1];
            item[x+1] = temp;
          }

          break;
        }
      }

      printf("\nExclusao realizada com sucesso!\n");
      posicao_item-=1;
      return;
    }
  }
}

void data_hora_atual(int &dia, int &mes, int &ano,
                    int &hora, int &min, int &seg)
{
    time_t t = time(NULL);
    struct tm lt = *localtime(&t);
    ano = lt.tm_year + 1900;
    mes = lt.tm_mon + 1;
    dia = lt.tm_mday;
    hora = lt.tm_hour;
    min = lt.tm_min;
    seg = lt.tm_sec;
}

bool eh_bissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return true;
    else
        return false;
}

int numero_dias_mes(int mes, int ano)
{
    if (mes < 1 || mes > 12 || ano <= 0)
        return -1;

    if (mes == 2)
    {
        if (eh_bissexto(ano))
            return 29;
        else
            return 28;
    }
    else if (mes < 7 && mes % 2 == 0 || mes > 8 && mes % 2 != 0)
        return 30;
    else
        return 31;
}

void emprestimo_item(Usuario usuario[], int qtd_usuarios,
                     ItensBiblioteca inclusao[], int qtd_Itens,
                     Emprestimo emprestimo[], int &qtd_emprestimos)
{
    int dia, mes, ano, hora, min, seg;

    if (qtd_emprestimos < MAX_USUARIOS_ITENS)
    {
        int codigo;
        long long cpf;

        printf("Codigo: ");
        scanf("%d", &codigo);

        int posicao_codigo = busca_codigo(inclusao, qtd_Itens, codigo);
        int posicao_emprestimo_codigo = busca_codigo_emprestimo(emprestimo, qtd_emprestimos, codigo);

        if (posicao_codigo != -1)
        {
                if (posicao_emprestimo_codigo == -1)
                {
                    printf("CPF: ");
                    scanf("%lld", &cpf);

                    int posicao_cpf = busca_cpf(usuario, qtd_usuarios, cpf);
                    int posicao_emprestimo_cpf = busca_cpf_emprestimo(emprestimo, qtd_emprestimos, cpf);

                    if (posicao_cpf != -1)
                    {
                        if (posicao_emprestimo_cpf == -1)
                        {
                            emprestimo[qtd_emprestimos].cpf = cpf;
                            emprestimo[qtd_emprestimos].codigo = codigo;
                            strcpy(emprestimo[qtd_emprestimos].nome, usuario[posicao_cpf].nome);
                            strcpy(emprestimo[qtd_emprestimos].titulo, inclusao[posicao_codigo].titulo);
                            emprestimo[qtd_emprestimos].tipo = inclusao[posicao_codigo].tipo;
                            data_hora_atual(dia, mes, ano, hora, min, seg);
                            emprestimo[qtd_emprestimos].dia_emprestimo = dia;
                            emprestimo[qtd_emprestimos].mes_emprestimo = mes;
                            emprestimo[qtd_emprestimos].ano_emprestimo = ano;


                            int dias_mes = numero_dias_mes(mes, ano);
                            if (dia + 7 <= dias_mes && mes != 12)
                            {
                                emprestimo[qtd_emprestimos].dia_devolucao = dia + 7;
                                emprestimo[qtd_emprestimos].mes_devolucao = mes;
                                emprestimo[qtd_emprestimos].ano_devolucao = ano;
                            }
                            else if (dia + 7 > dias_mes && mes != 12)
                            {
                                emprestimo[qtd_emprestimos].mes_devolucao = mes + 1;
                                emprestimo[qtd_emprestimos].ano_devolucao = ano;
                                emprestimo[qtd_emprestimos].dia_devolucao = dia + 7 - dias_mes;
                            }
                            else if (dia + 7 > dias_mes && mes == 12)
                            {
                                emprestimo[qtd_emprestimos].mes_devolucao = 1;
                                emprestimo[qtd_emprestimos].ano_devolucao = ano + 1;
                                emprestimo[qtd_emprestimos].dia_devolucao = dia + 7 - dias_mes;
                            }
                            else
                            {
                                emprestimo[qtd_emprestimos].dia_devolucao = dia + 7;
                                emprestimo[qtd_emprestimos].mes_devolucao = mes;
                                emprestimo[qtd_emprestimos].ano_devolucao = ano;
                            }

                            puts("\nEmprestimo concedido!");
                            printf("Nome: %s\n", emprestimo[qtd_emprestimos].nome);
                            printf("Titulo: %s\n", emprestimo[qtd_emprestimos].titulo);
                            printf("Data do emprestimo: %02d/%02d/%d\n",
                                   emprestimo[qtd_emprestimos].dia_emprestimo, emprestimo[qtd_emprestimos].mes_emprestimo, emprestimo[qtd_emprestimos].ano_emprestimo);
                            printf("Data da devolucao: %02d/%02d/%d\n",
                                   emprestimo[qtd_emprestimos].dia_devolucao, emprestimo[qtd_emprestimos].mes_devolucao, emprestimo[qtd_emprestimos].ano_devolucao);
                            qtd_emprestimos++;
                        }
                        else
                        {
                            puts("\nErro no emprestimo. Usuario ja tem emprestimo!\n");

                            printf("Codigo: %d\n", emprestimo[posicao_emprestimo_cpf].codigo);
                            printf("Titulo: %s\n", emprestimo[posicao_emprestimo_cpf].titulo);
                        }
                    }
                    else
                        puts("\nErro no emprestimo. Usuario nao cadastrado!");
                }
                else
                {
                    puts("\nErro no emprestimo. Item ja emprestado!\n");

                    printf("CPF: %lld\n", emprestimo[posicao_emprestimo_codigo].cpf);
                    printf("Nome: %s\n", emprestimo[posicao_emprestimo_codigo].nome);

                }
        }
        else
            puts("\nErro no emprestimo. Item nao encontrado!");
    }
    else
        puts("Erro no emprestimo. Ja foi atingido o limite de 50 emprestimos!");
}

Emprestimo emprestimo_devolvido (Emprestimo  emprestimo[], int &qtd_emprestimos, long long int cpf){
  Emprestimo aux;
  for (int i = 0; i < qtd_emprestimos; i++){
    if (emprestimo[i].cpf == cpf){
      qtd_emprestimos-=1;
      aux=emprestimo[i];
      emprestimo[i]=emprestimo[qtd_emprestimos];
      return aux;
    }
  }
  return emprestimo[qtd_emprestimos];
}

bool data_da_devolucao(int &dia_devolucao,int &mes_devolucao,int &ano_devolucao, Emprestimo teste){
  printf("Data da devolucao: ");
  scanf("%d/%d/%d", &dia_devolucao, &mes_devolucao, &ano_devolucao);
  getchar();

  if(eh_bissexto(ano_devolucao) && mes_devolucao==2){
    if(dia_devolucao>29) return true;
  } else if (mes_devolucao==2){
    if(dia_devolucao>28) return true;
  }

  if(((mes_devolucao < 7 && mes_devolucao % 2 == 0) || (mes_devolucao > 8 && mes_devolucao % 2 != 0)) && dia_devolucao>30){
    return true;
  }else if (dia_devolucao>31) return true;

  if(mes_devolucao>12) return true;


  if(ano_devolucao < teste.ano_emprestimo) return true;
  if(ano_devolucao == teste.ano_emprestimo && mes_devolucao < teste.mes_emprestimo) return true;
  if(ano_devolucao == teste.ano_emprestimo && mes_devolucao == teste.mes_emprestimo && dia_devolucao < teste.dia_emprestimo) return true;

  return false;
}

void devolucao(Usuario usuario[], Emprestimo emprestimo[], int qtd_usuarios,  int &qtd_emprestimos){
  Emprestimo devolvido;
  long long int cpf;
  int dia_devolucao = 0, mes_devolucao = 0, ano_devolucao = 0;
  bool data_errada;

    if(qtd_emprestimos==0){
    puts("Biblioteca nao tem emprestimos!");
    return;
  }

  printf("CPF: ");
  scanf("%lld", &cpf);
  getchar();

  if(confere_cpf(usuario, qtd_usuarios, cpf)){
    if(confere_emprestimo(emprestimo,qtd_emprestimos, cpf)){
        devolvido = emprestimo_devolvido(emprestimo, qtd_emprestimos, cpf);
    }else{
        printf("\nUsuario nao tem emprestimo!\n");
        return;
      }
  }else {
    printf("\nUsuario nao cadastrado!\n");
    return;
  }

  do{
    data_errada= data_da_devolucao(dia_devolucao, mes_devolucao, ano_devolucao, devolvido);
    if(data_errada) puts("Data de devolucao invalida. Digite uma data valida!");
  }while(data_errada);

  bool prazo;
  if(ano_devolucao < devolvido.ano_devolucao)prazo=true;
  if(ano_devolucao == devolvido.ano_devolucao && mes_devolucao < devolvido.mes_devolucao){
    prazo=true;
  }else if(dia_devolucao <= devolvido.dia_devolucao && mes_devolucao == devolvido.mes_devolucao && ano_devolucao == devolvido.ano_devolucao){
    prazo=true;
  } else prazo=false;

  printf("\nNome: %s\n",devolvido.nome);
  printf("Titulo: %s\n",devolvido.titulo);

  if(prazo){
    printf("\nDevolucao realizada com sucesso no prazo!\n");
    return;
  }

  printf("Data da devolucao: %02d/%02d/%d\n\n",devolvido.dia_devolucao, devolvido.mes_devolucao, devolvido.ano_devolucao );


  int multa_por_ano,multa_por_mes=0,multa_por_dia, ano_bissexto=0;


  multa_por_ano= ano_devolucao - devolvido.ano_devolucao;

  for(int i= devolvido.ano_devolucao; i<=ano_devolucao;i++){
    if(i == ano_devolucao && mes_devolucao<=2) continue;
    if(eh_bissexto(i)) ano_bissexto+=1;
  }
  if(multa_por_ano==0){
    if(devolvido.mes_devolucao>2 && eh_bissexto(devolvido.ano_devolucao)) ano_bissexto-=1;
  }

  if(mes_devolucao > devolvido.mes_devolucao){
    for(int i=devolvido.mes_devolucao;i<mes_devolucao;i++){
      if(i==2){
        multa_por_mes+=28;
      }else if((i < 7 && i % 2 == 0) || (i > 8 &&i % 2 != 0)){
          multa_por_mes+=30;
      } else multa_por_mes+=31;
    }
  }
  if(mes_devolucao < devolvido.mes_devolucao){
    for(int i=devolvido.mes_devolucao;i>mes_devolucao;i--){
      if(i==2){
        multa_por_mes-=28;
      }else if((i < 7 && i % 2 == 0) || (i > 8 &&i % 2 != 0)){
        multa_por_mes-=30;
      } else multa_por_mes-=31;
    }

  }

  multa_por_dia = dia_devolucao - devolvido.dia_devolucao;

  int contagem_da_multa= multa_por_dia+multa_por_mes+365*multa_por_ano+ano_bissexto;

  float multa = contagem_da_multa*1.5;

  printf("Devolucao realizada com atraso de %d dias\n",contagem_da_multa);
  printf("Multa de R$ %.2f\n", multa);
}

Emprestimo printa_emprestimo (Emprestimo  emprestimo[], int qtd_emprestimos, long long int cpf){
  for (int i = 0; i < qtd_emprestimos; i++){
    if (emprestimo[i].cpf == cpf) return emprestimo[i];
  }
}

void imprime_usuario(Usuario usuario[], int qtd_usuarios, Emprestimo emprestimo[], int qtd_emprestimos){
  if(qtd_usuarios==0){
    puts("Biblioteca nao tem usuarios!");
    return;
  }
  char printa[150];
  char vazio[2];
  vazio[0]=' ';
  vazio[1]='\0';

  for(size_t i=0; i<=50;i++){
    if(i==50)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  strcpy(printa, "CPF");
  printf("%-11s ", printa);
  strcpy(printa, "Nome");
  printf("%-30s\n", printa);

  for(size_t i=0; i<=50;i++){
    if(i==50)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  Emprestimo print_emprestimo;

  for(int i=0;i<qtd_usuarios;i++){
    printf("%lld ", usuario[i].cpf);
    printf("%-30s\n", usuario[i].nome);

    if(confere_emprestimo(emprestimo, qtd_emprestimos, usuario[i].cpf)){
      print_emprestimo= printa_emprestimo(emprestimo, qtd_emprestimos, usuario[i].cpf);

      printf("%-11s Emprestimo: %02d/%02d/%d a %02d/%02d/%d\n",vazio, print_emprestimo.dia_emprestimo, print_emprestimo.mes_emprestimo, print_emprestimo.ano_emprestimo, print_emprestimo.dia_devolucao, print_emprestimo.mes_devolucao, print_emprestimo.ano_devolucao);

      printf("%-11s Tipo: ",vazio);
      if(print_emprestimo.tipo=='L') puts("Livro");
      else puts("Revista");

      printf("%-11s Titulo: %-30s\n",vazio, print_emprestimo.titulo);
    }
  }
  printf("%s\n", printa);
}

void imprime_itens(ItensBiblioteca item[], int qtd_Itens){
  if(qtd_Itens==0){
    puts("Biblioteca nao tem itens!");
    return;
  }
  char printa[150];
  for(size_t i=0; i<=91;i++){
    if(i==91)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  strcpy(printa, "Codigo");
  printf("%s ", printa);
  strcpy(printa, "T");
  printf("%s ", printa);
  strcpy(printa, "Titulo");
  printf("%-30s ", printa);
  strcpy(printa, "Autor");
  printf("%-30s ", printa);
  strcpy(printa, "Editora");
  printf("%-15s ", printa);
  strcpy(printa, "Ano");
  printf("%4s\n", printa);


  for(size_t i=0; i<=91;i++){
    if(i==91)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  char vazio[2];
  vazio[0]=' ';
  vazio[1]='\0';

  for(int i=0;i<qtd_Itens;i++){
    printf("%06d ", item[i].codigo);
    printf("%c ", item[i].tipo);
    printf("%-30s ", item[i].titulo);
    if(item[i].tipo=='R') printf("%-30s ", vazio);
    else printf("%-30s ", item[i].autor);
    printf("%-15s ", item[i].editora);
    printf("%d\n", item[i].anopubl);
  }
  printf("%s\n", printa);
}


void imprime_emprestimos(Emprestimo emprestimo[], int qtd_emprestimos){
  if(qtd_emprestimos==0){
    puts("Biblioteca nao tem emprestimos!");
    return;
  }
  char printa[150];
  for(size_t i=0; i<=102;i++){
    if(i==102)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  strcpy(printa, "CPF");
  printf("%-11s ", printa);
  strcpy(printa, "Nome");
  printf("%-30s ", printa);
  strcpy(printa, "Codigo");
  printf("%s ", printa);
  strcpy(printa, "Titulo");
  printf("%-30s  ", printa);
  strcpy(printa, "Emprestimo");
  printf("%s ", printa);
  strcpy(printa, "Devolucao");
  printf("%s\n", printa);


  for(size_t i=0; i<=102;i++){
    if(i==102)printa[i]='\0';
    else printa[i]='-';
  }
  printf("%s\n", printa);

  for(int i=0;i<qtd_emprestimos;i++){
    printf("%lld ", emprestimo[i].cpf);
    printf("%-30s ", emprestimo[i].nome);
    printf("%06d ", emprestimo[i].codigo);
      printf("%-30s  ", emprestimo[i].titulo);
    printf("  %02d/%02d/%02d  %02d/%02d/%02d\n",emprestimo[i].dia_emprestimo, emprestimo[i].mes_emprestimo, emprestimo[i].ano_emprestimo%100, emprestimo[i].dia_devolucao, emprestimo[i].mes_devolucao, emprestimo[i].ano_devolucao%100);
  }
  printf("%s\n", printa);
}

void CadastroDeUsuario(Usuario usuario[], int &qtd_usuarios,
                       Emprestimo emprestimo[], int qtd_emprestimos)
{
    bool finaliza = false;

    while (! finaliza)
    {
        printf("Menu do Cadastro de Usuarios\n");
        printf("1-Cadastrar novo usuario\n");
        printf("2-Excluir usuario\n");
        printf("3-Listar usuarios (ordenado por CPF)\n");
        printf("4-Listar usuarios (ordenado por nome)\n");
        printf("5-Voltar\n");

        int opcao;
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                inclusao_usuarios(usuario, qtd_usuarios);
                putchar('\n');
                break;
            case 2:
                exclui_usuario(usuario, qtd_usuarios, emprestimo, qtd_emprestimos);
                putchar('\n');
                break;
            case 3:
                Ordernar_por_CPF(usuario, qtd_usuarios);
                imprime_usuario(usuario, qtd_usuarios, emprestimo, qtd_emprestimos);
                putchar('\n');
                break;
            case 4:
                Ordernar_por_Nome(usuario, qtd_usuarios);
                imprime_usuario(usuario, qtd_usuarios, emprestimo, qtd_emprestimos);
                putchar('\n');
                break;
            case 5:
                finaliza = true;
                break;
        }
    }
    putchar('\n');
}

void menuCadastroItens(ItensBiblioteca item[], int &qtd_Itens,
                       Emprestimo emprestimo[], int qtd_emprestimos){

    bool finaliza = false;

    while (! finaliza)
    {
        printf("Menu do Cadastro de Itens da Biblioteca\n");

        printf("1-Cadastrar novo item\n");
        printf("2-Excluir item\n");
        printf("3-Listar itens (ordenado por codigo)\n");
        printf("4-Listar itens (ordenado por titulo)\n");
        printf("5-Voltar\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            Cadastrar_Itens(item, qtd_Itens);
            putchar('\n');
            break;
        case 2:
            Excluir_Item(emprestimo, qtd_emprestimos, item, qtd_Itens);
            putchar('\n');
            break;
        case 3:
            Ordernar_por_Codigo(item, qtd_Itens);
            imprime_itens(item, qtd_Itens);
            putchar('\n');
            break;
        case 4:
            Ordernar_por_Titulo(item, qtd_Itens);
            imprime_itens(item, qtd_Itens);
            putchar('\n');
            break;
        case 5:
            finaliza = true;
            break;
        }
    }
    putchar('\n');
}

void menuEmprestimoDevolucao(Usuario usuario[], int qtd_usuarios,
                             ItensBiblioteca item[], int qtd_Itens,
                             Emprestimo emprestimo[], int &qtd_emprestimos){
    bool finaliza = false;

    while (! finaliza)
    {
        printf("Menu do Emprestimo/Devolucao\n");

        printf("1-Emprestar item\n");
        printf("2-Devolver item\n");
        printf("3-Listar emprestimos\n");
        printf("4-Voltar\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            emprestimo_item(usuario, qtd_usuarios, item, qtd_Itens, emprestimo, qtd_emprestimos);
            putchar('\n');
            break;
        case 2:
            devolucao(usuario, emprestimo, qtd_usuarios, qtd_emprestimos);
            putchar('\n');
            break;
        case 3:
            ordena_por_emprestimo(emprestimo, qtd_emprestimos);
            imprime_emprestimos(emprestimo, qtd_emprestimos);
            putchar('\n');
            break;
        case 4:
            finaliza = true;
            break;
        }
    }
    putchar('\n');
}

int main(){
    ItensBiblioteca item[MAX_USUARIOS_ITENS];
    Usuario usuario[MAX_USUARIOS_ITENS];
    Emprestimo emprestimo[MAX_USUARIOS_ITENS];

    int qtd_emprestimos = 0;
    int qtd_usuarios = 0;
    int qtd_Itens = 0;

    bool finaliza = false;

    while(! finaliza)
    {
        printf("Menu Principal\n");
        printf("1-Cadastro de Usuario\n");
        printf("2-Cadastro de Itens da biblioteca\n");
        printf("3-Emprestimo/devolucao\n");
        printf("4-Fim\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            putchar('\n');
            CadastroDeUsuario(usuario, qtd_usuarios, emprestimo, qtd_emprestimos);
            break;
        case 2:
            putchar('\n');
            menuCadastroItens(item, qtd_Itens, emprestimo, qtd_emprestimos);
            break;
        case 3:
            putchar('\n');
            menuEmprestimoDevolucao(usuario, qtd_usuarios, item, qtd_Itens, emprestimo, qtd_emprestimos);
            break;
        case 4:
            finaliza = true;
            break;
        }
    }
}
