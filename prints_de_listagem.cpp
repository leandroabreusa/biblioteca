
Emprestimo printa_emprestimo (Emprestimo  emprestimo[], int qtd_emprestimos, long long int cpf){
  for (int i = 0; i < qtd_emprestimos; i++){
    if (emprestimo[i].cpf == cpf) return emprestimo[i];
  }
  return emprestimo[i];
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

      printf("%-11s Emprestimo: %02d/%02d/02%d a %02d/%02d/%02d\n",vazio, print_emprestimo.dia_emprestimo, print_emprestimo.mes_emprestimo, print_emprestimo.ano_emprestimo, print_emprestimo.dia_devolucao, print_emprestimo.mes_devolucao, print_emprestimo.ano_devolucao);

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
    printf("%-6d ", item[i].codigo);
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
    printf("%-6d ", emprestimo[i].codigo);
      printf("%-30s  ", emprestimo[i].titulo);
    printf("  %02d/%02d/%02d  %02d/%02d/%02d\n",emprestimo[i].dia_emprestimo, emprestimo[i].mes_emprestimo, emprestimo[i].ano_emprestimo%100, emprestimo[i].dia_devolucao, emprestimo[i].mes_devolucao, emprestimo[i].ano_devolucao%100);
  }
  printf("%s\n", printa);
}
