#include <stdio.h>
#include <string.h>
#include "tools.cpp"
#include "structs.cpp"

void inclusao_usuarios (Usuario usuario[], int &qtd_usuarios)
{
    int CPF;
    if (qtd_usuarios < MAX_USUARIOS_ITENS)
    {
        printf("CPF: ");
        scanf("%lld", &CPF);

        // Limpa o ENTER
        getchar();

        if (testa_cpf(usuario, qtd_usuarios))
        {
            if (existeCPF(usuario, CPF)){
                puts("Erro no cadastro. CPF ja cadastrado!");
                return;
            }

            usuario[qtd_usuarios].cpf = CPF;

            printf("Nome: ");
            gets(usuario[qtd_usuarios].nome);

            conversaoCaixaAlta(usuario[qtd_usuarios].nome);
            //strupr(usuario[qtd_usuarios].nome);

            if (testa_tamanho_string(MIN_NOME, MAX_NOME,
                                     usuario, qtd_usuarios))
            {
                puts("\nCadastro realizado com sucesso!");
                qtd_usuarios++;
            }
            else
                puts("\nErro no cadastro. Tamanho do nome invalido!");
        }
        else
            puts("Erro no cadastro. Tamanho do CPF invalido!");
        }
    else
        puts("Erro no cadastro. Ja foi atingido o limite de 50 usuarios!");
}
/*
void listagem_usuarios_CPF(Usuario usuario[]){
    Usuario temporario;

    //ORDENA LISTAGEM
    for (int x = 0; ;x++){
        temporario = usuario[x+1];

        if (temporario.cpf < usuario[x].cpf){
            usuario[x + 1] = usuario[x];
            usuario[x] = temporario;

            if (x - 1 >= 0){
                int temp_x = x;
                while(usuario[temp_x].cpf < usuario[temp_x - 1].cpf && temp_x - 1 >=0) {
                    temporario = usuario[temp_x - 1];
                    usuario[temp_x - 1] = usuario[temp_x];
                    usuario[temp_x] = temporario;
                    temp_x--;
                }
            }
        }
    }
}
*/

/* Na main precisamos declarar o vetor de struct e o contador que diz quantos usu�rios s�o armazenados nesse programa
int main()
{
    Usuario usuario[MAX_USUARIOS_ITENS];
    int qtd_usuarios = 0;
}

*/
