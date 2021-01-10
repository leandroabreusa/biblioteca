#include <stdio.h>

void exclui_usuario(Usuario usuario[], int &qtd_usuarios,
                    Emprestimo emprestimo[], int qtd_emprestimos)
{
    long long cpf;

    if (qtd_usuarios > 0)
    {
        printf("CPF: ");
        scanf("%lld", &cpf);

        if (testa_cpf(cpf))
        {
            int posicao_cpf = busca_cpf(usuario, qtd_usuarios, cpf);
            int posição_emprestimo_cpf = busca_cpf_emprestimo(emprestimo, qtd_emprestimos, cpf);

            if (posicao_cpf != -1)
            {
                if (posicao_emprestimo_cpf == -1)
                {
                    qtd_usuarios--;

                    usuario[posicao_cpf] = usuario[qtd_usuarios];

                    puts("Exclusao realizada com sucesso!");
                }
                else
                    puts("Erro na exclusao. Usuario possui um emprestimo!");
            }
            else
                puts("Erro na exclusao. Usuario nao cadastrado!");

        }
        else
            puts("Erro na exclusao. Tamanho do CPF invalido!");
    }
    else
        puts("Erro na exclusao. Nao existem usuarios cadastrados!");
}
}
/* Não precisa adicionar nada na main, tudo que eu usei já existe nos outros
códigos
int main()
{
}
