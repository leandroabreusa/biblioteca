#include <stdio.h>
#include "itens.cpp"
#include "usuarios.cpp"
#include "tools.cpp"
#include "structs.cpp"

void MenuPrincipal()
{
    printf("Menu Principal\n");
    printf("1-Cadastro de Usuario\n");
    printf("2-Cadastro de Itens da biblioteca\n");
    printf("3-Emprestimo/devolucao\n");
    printf("4-Fim\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
    case '1':
        CadastroDeUsuario();
        break;
    case '2':
        /*chamada*/
        break;
    case '3':
        /*chamada*/
        break;
    case '4':
        puts("Fim");
        return;
}

}

void CadastroDeUsuario()
{
    printf("Menu do Cadastro de Usuarios\n");
    printf("1-Cadastrar novo usuario");
    printf("2-Excluir usuario\n");
    printf("3-Listar usuarios (ordenado por CPF)\n");
    printf("4-Listar usuarios (ordenado por nome)\n");
    printf("5-Voltar");

    int opcao;

    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        /*codigo*/
        break;
    case 2:
        /*codigo*/
        break;
    case 3:
        /*codigo*/
        break;
    case 4:
        /*codigo*/
        break;
    case 5:
        return;

    }

}

void menuCadastroItens(ItensBiblioteca item){
    printf("Menu do Cadastro de Itens da Biblioteca\n");

    printf("1-Cadastrar novo item\n");
    printf("2-Excluir item\n");
    printf("3-Listar itens (ordenado por codigo)\n");
    printf("4-Listar itens (ordenado por titulo)\n");
    printf("5-Voltar\n");

    char INPUT;
    scanf(" %c", &INPUT);
    switch (INPUT) {
    case '1':
        Cadastrar_Itens(item, &qtd_Itens);
        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    case '5':
        return;
}
}

void menuEmprestimoDevolucao(Usuario usuarios[], ItensBiblioteca item[]){
    printf("Menu do Emprestimo/Devolucao\n");

    printf("1-Emprestar item\n");
    printf("2-Devolver item\n");
    printf("3-Listar emprestimos\n");
    printf("4-Voltar\n");

    char INPUT;
    scanf(" %c", &INPUT);

    switch (INPUT) {
    case '1':
        int codigo;
        printf("Código do item: ");
        scanf("%d", &codigo);
        verificaCodigo(item, codigo);

        long long CPF;
        printf("CPF: ");
        scanf("%ll", &CPF);
        existeCPF(usuarios, CPF);

        /* chama função */
        break;
    case '2':
        /* chama função */
        break;
    case '3':
        /* chama função */
        break;
    case '4':
        return;
}
}

int main(){
    return 0;
}
