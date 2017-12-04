#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"

int main()
{
    tipoVeiculo listaVeiculos[MAX_VEICULOS];
    tipoEncomenda listaEncomendas[MAX_ENCOMENDA];
    int quantVeiculos=0,quantEncomendas=0;
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
                case 1:listaVeiculos[quantVeiculos]=inserirVeiculo(&quantVeiculos);
                    break;
                case 2:listarVeiculos(quantVeiculos, listaVeiculos);
                    break;
                case 3:
                    break;
                case 4:
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
                case 1:listaEncomendas[quantEncomendas]=inserirEncomenda(&quantEncomendas);
                    break;
                case 2:listarEncomenda(quantEncomendas,listaEncomendas);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                default:
                    printf("\nOpcao Invalida");
                }
            }
            while(opcao!=6);
            break;
        case 3:guardarficheiroTexto(listaVeiculos, quantVeiculos);
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("\nOpcao Invalida");
        }
    }
    while(opcao!=5);

}
