#include <stdio.h>

#include "funcoes_ficheiros.h"
#include "constantes.h"
#include "funcoes_menu.h"


int menuPrincipal(int quantVeiculos,int quantEncomendas)
{
    int opcao;
    printf("\n\t********************Menu*******************");
    printf("\nQuantidade de Veiculos: %d ", quantVeiculos );
    printf("\tQuantidade de Encomendas: %d", quantEncomendas);
    printf("\nMenu Veiculo-1");
    printf("\nMenu Encomenda-2");
    printf("\nGuardar Ficheiro-3");
    printf("\nLer Ficheiro-4");
    printf("\nSair-5");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    return opcao;

}


int menuVeiculos (int quantVeiculos)
{
    int opcao;
    printf("\n\t**************Menu Veiculos******************");
    printf("\nQuantidade de Veiculos: %d ", quantVeiculos );

    printf("\nInserir veiculo-1");
    printf("\nListar Veiculo(s)-2");
    printf("\nAlterar estado de um Veiculo-3");
    printf("\nRetroceder-4");
    printf("\nOpcao:");
    scanf(" %d",&opcao);

    return opcao;
}

int menuEncomendas(int quantEncomendas)
{
    int opcao;
     printf("\n\t*************Menu Encomendas****************");
        printf("\nQuantidade de Encomendas: %d", quantEncomendas);
                printf("\nInserir Encomenda-1");
                printf("\nListar Encomeda(s)-2");
                printf("\nEliminar Encomenda-3");
                printf("\nAlterar Estado de uma Encomenda-4");
                printf("\nCarregar Encomenda-5");
                printf("\nRetroceder-6");
                printf("\nOpcao:");
                scanf(" %d",&opcao);
                return opcao;
}
