
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
  printf("dia: ");
  scanf("%d", &dia_devolucao);
  getchar();
  printf("do mes: ");
  scanf("%d", &mes_devolucao);
  getchar();
  printf("do ano: ");
  scanf("%d", &ano_devolucao);
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


  time_t t = time(NULL);
  struct tm lt = *localtime(&t);
  int ano = lt.tm_year + 1900;
  int mes = lt.tm_mon + 1;
  int dia = lt.tm_mday;
  if(ano_devolucao < ano) return true;
  if(ano_devolucao == ano && mes_devolucao < mes) return true;
  if(ano_devolucao == ano && mes_devolucao == mes && dia_devolucao < dia) return true;

  return false;
}



void devolucao(Usuario usuario[], Emprestimo emprestimo[], int qtd_usuarios,  int &qtd_emprestimos){
  Emprestimo devolvido;
  long long int cpf;
  int dia_devolucao, mes_devolucao, ano_devolucao;
  bool data_errada;
  
    if(qtd_emprestimos==0){
    puts("Biblioteca nao tem emprestimos!");
    return;
  }

  //Conferindo se o usuario e cadastrado e se tem emprestimo, retornando mensagens de erro se necessario como o layout define
  puts("Digite seu CPF:");
  scanf("%lld", &cpf);
  getchar();

  if(confere_cpf(usuario, qtd_usuarios, cpf)){
    if(confere_emprestimo(emprestimo,qtd_emprestimos, cpf)){
        devolvido = emprestimo_devolvido(emprestimo, qtd_emprestimos, cpf);
    }else{
        printf("CPF: %lld\n\n Usuario nao tem emprestimo!\n", cpf);
        return;
      }
  }else {
    printf("CPF: %lld\n\n Usuario nao cadastrado!\n", cpf);
    return;
  }
  //pegando a data da devolucao e conferindo se e valida dentro de um ano e dentro da data de emprestimo.
  puts("digite a data da devolucao:");
  do{
    data_errada= data_da_devolucao(dia_devolucao, mes_devolucao, ano_devolucao, devolvido);
    if(data_errada) puts("Data de devolucao invalida. digite uma data valida");
  }while(data_errada);

  //printando devolucao e conferindo se ha multa e seu preco

  bool prazo;
  if(ano_devolucao < devolvido.ano_devolucao)prazo=true;
  if(ano_devolucao == devolvido.ano_devolucao && mes_devolucao < devolvido.mes_devolucao){
    prazo=true;
  }else if(dia_devolucao <= devolvido.dia_devolucao && mes_devolucao == devolvido.mes_devolucao && ano_devolucao == devolvido.ano_devolucao){
    prazo=true;
  } else prazo=false;




  printf("\n\nCPF: %lld\n", devolvido.cpf);
  printf("Data da devolucao: %02d/%02d/%02d\n\n",dia_devolucao, mes_devolucao, ano_devolucao );
  printf("Nome: %s\n",devolvido.nome);
  printf("Titulo: %s\n\n",devolvido.titulo);

  if(prazo){
    printf("Devolucao realizada com sucesso no prazo!\n");
    return;
  }

  printf("Data da devolucao: %02d/%02d/%02d\n\n",devolvido.dia_devolucao, devolvido.mes_devolucao, devolvido.ano_devolucao );


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

  printf("Devolucao realizada com atraso de: %d dias\n",contagem_da_multa);
  printf("Multa de R$ %.2f\n", multa);
}
