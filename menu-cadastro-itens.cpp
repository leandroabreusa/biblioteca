#include <stdio.h>
#include "entrada_usuarios.cpp"
#include "Incluir_Item_biblioteca.cpp"

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
        Cadastro_Itens_Biblioteca(item);
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

/*
int main(){
    ItensBiblioteca item[MAX_USU_IT];
    int key, qtd_Itens=0;

    menuCadastroItens(item[qtd_Itens]);
}
*/
