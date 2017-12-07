#include <stdio.h>

#include "funcoes_ficheiros.h"
#include "constantes.h"
#include "funcoes_menu.h"

void menu(tipoVeiculo listaVeiculos[MAX_VEICULOS], int *quantVeiculos, tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int *quantEncomendas)
{

    int opcao;
    do
    {
        printf("\n\t********************Menu*******************");
        printf("\nMenu Veiculo-1");
        printf("\nMenu Encomenda-2");
        printf("\nGuardar Ficheiro-3");
        printf("\nLer Ficheiro-4");
        printf("\nSair-5");
        printf("\nOpcao:");
        scanf(" %d",&opcao);
        switch(opcao)
        {
        case 1:
            do
            {
                printf("\n\t**************Menu Veiculos******************");
                printf("\nInserir veiculo-1");
                printf("\nListar Veiculo(s)-2");
                printf("\nAlterar estado de um Veiculo-3");
                printf("\nRetroceder-4");
                printf("\nOpcao:");
                scanf(" %d",&opcao);
                switch(opcao)
                {
                case 1:listaVeiculos[*quantVeiculos]=inserirVeiculo(&quantVeiculos);
                    break;
                case 2:listarVeiculos(quantVeiculos, listaVeiculos);
                    break;
                case 3:
                    break;
                case 4:menu(listarVeiculos,&quantEncomendas,listarEncomenda,&quantEncomendas);
                    break;
                    default:
                printf("\nOpcao Invalida");
                }

            }while(opcao!=4);

        case 2:
            do
            {

                printf("\n\t*************Menu Encomendas****************");
                printf("\nInserir Encomenda-1");
                printf("\nListar Encomeda(s)-2");
                printf("\nEliminar Encomenda-3");
                printf("\nAlterar Estado de uma Encomenda-4");
                printf("\nRetroceder-6");
                printf("\nOpcao:");
                scanf(" %d",&opcao);
                switch(opcao)
                {
                case 1:listaEncomenda[*quantEncomendas]=inserirEncomenda(&quantEncomendas);
                    break;
                case 2:listarEncomenda(*quantEncomendas,listaEncomenda);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                    case 6:menu(listarVeiculos,&quantEncomendas,listarEncomenda,&quantEncomendas);
                    break;
                default:
                    printf("\nOpcao Invalida");
                }
            }
            while(opcao!=6);
            break;
        case 3:guardarficheiroTexto(listaVeiculos, *quantVeiculos);
                gravarFicheiroBinario(listaVeiculos, *quantVeiculos);
            break;
        case 4:lerFicheiroBinario(listaVeiculos,*quantVeiculos);
            break;
        case 5:
            break;
        default:
            printf("\nOpcao Invalida");
        }
    }
    while(opcao!=5);


}
