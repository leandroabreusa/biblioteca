#include <stdio.h>
#include <string.h>
#include "upper.cpp"

const int TAM_NOME = 100;
const int MAX_NOME = 30;
const int MIN_NOME = 4;
const int MAX_USUARIOS = 50;

struct Usuario {
    long long cpf;
    char nome[TAM_NOME];
};

bool testa_tamanho_string (int n, int k,
                           Usuario usuario[], int qtd_usuarios)
{
    // Se o tamanho estiver fora dos limites permitidos, retorna falso
    if (strlen(usuario[qtd_usuarios].nome) < n ||
        strlen(usuario[qtd_usuarios].nome) > k)
            return false;

    // Se n�o, retorna verdadeiro
    return true;
}

// Testa se o cpf tem 11 d�gitos
bool testa_cpf (Usuario usuario[], int qtd_usuarios)
{
    // Se n�o tiver, retorna falso
    if (usuario[qtd_usuarios].cpf < 10000000000 ||
        usuario[qtd_usuarios].cpf > 99999999999)
            return false;

    // Se n�o, retorna verdadeiro
    return true;
}

void inclusao_usuarios (Usuario usuario[], int &qtd_usuarios)
{
    if (qtd_usuarios < MAX_USUARIOS)
    {
        printf("CPF: ");
        scanf("%lld", &usuario[qtd_usuarios].cpf);

        // Limpa o ENTER
        getchar();

        if (testa_cpf(usuario, qtd_usuarios))
        {
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


/* Na main precisamos declarar o vetor de struct e o contador que diz quantos usu�rios s�o armazenados nesse programa
int main()
{
    Usuario usuario[MAX_USUARIOS];
    int qtd_usuarios = 0;
}

*/
