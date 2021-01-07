#include <stdio.h>
#include <string.h>
#include <time.h>

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

void emprestimo_item(Usuario usuario[], int qtd_usuarios,
                     ItensBiblioteca inclusao[], int qtd_Itens,
                     Emprestimo emprestimo[], int &qtd_emprestimos
                     int dia, int mes, int ano, int hora, int min, int seg)
{
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
                            qtd_emprestimos++;

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
                            printf("Data do emprestimo: %d/%d/%d\n",
                                   emprestimo[qtd_emprestimos].dia_emprestimo, emprestimo[qtd_emprestimos].mes_emprestimo, emprestimo[qtd_emprestimos].ano_emprestimo);
                            printf("Data da devolucao: %d/%d/%d\n",
                                   emprestimo[qtd_emprestimos].dia_devolucao, emprestimo[qtd_emprestimos].mes_devolucao, emprestimo[qtd_emprestimos].ano_devolucao);
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

/* Variáveis da data/hora
Variáveis para o empréstimo
int main()
{
    Emprestimo emprestimo[MAX_USUARIOS_ITENS];
    int qtd_emprestimos = 0;
}
*/

