#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"
#include "funcoes_menu.h"
#include "funcoes_ficheiros.h"

int main()
{
    int opcao;

    tipoVeiculo listaVeiculos[MAX_VEICULOS];
    tipoEncomenda listaEncomendas[MAX_ENCOMENDA];
    int quantVeiculos=0,quantEncomendas=0;
    do
    {
        opcao = menuPrincipal(quantVeiculos,quantEncomendas);
        switch(opcao)
        {

        case 1:
            do
            {
                opcao=menuVeiculos(quantVeiculos);
                switch(opcao)
                {
                case 1://inserir veiculos
                    listaVeiculos[quantVeiculos] = inserirVeiculo(&quantVeiculos);

                    break;
                case 2://listar veiculos
                    listarVeiculos(quantVeiculos,listaVeiculos);
                    break;
                case 3://alterar estado dum veiculo
                    break;
                case 4://sair

                    break;
                default:
                    printf("\n\nOpcao invalida");

                    break;


                }

            }
            while(opcao != 4);
            break;
        case 2:
            do
            {
                opcao = menuEncomendas(quantEncomendas);
                switch(opcao)
                {
                case 1://inserir encomendas
                    listaEncomendas[quantEncomendas] =  inserirEncomenda(&quantEncomendas);
                    break;
                case 2://listar encomendas
                    listarEncomenda(quantEncomendas, listaEncomendas);
                    break;
                case 3://Eliminar encomenda
                    eliminarEncomenda(&quantEncomendas, listaEncomendas, listaVeiculos);
                    break;
                case 4://Alterar estado
                    alterarEstado(listaEncomendas, quantEncomendas);
                    break;
                case 6://sair
                    break;
                default:
                    printf("\nOpcao Invalida");
                }
            }
            while(opcao != 6);
            break;
        case 3:
            gravarFicheiroBinario(listaVeiculos, quantVeiculos);
            gravarFicheiroBinarioEncomendas(listaEncomendas, quantEncomendas);
            break;
        case 4:
            lerFicheiroBinarioEncomendas(listaEncomendas, quantEncomendas);
            lerFicheiroBinario(listaVeiculos, quantVeiculos);
            break;
        case 5:
            break;
        default:
            printf("\nOpcao Invalida ");
            break;
        }


    }
    while(opcao != 5);
    return 0;

}
