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
    int opcao, opcao2;
    char matricula[8];
    inserirMatricula2(matricula);
    printf("matricula:%s",matricula);


    tipoVeiculo listaVeiculos[MAX_VEICULOS];
    tipoEncomenda listaEncomendas[MAX_ENCOMENDA];
    int quantVeiculos=0,quantEncomendas=0;
    do
    {
        opcao2=0;
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
                case 3:alterarEstadoVeiculo(listaVeiculos, quantVeiculos);
                    break;
                case 4:organizaVeiculos(listaVeiculos, quantVeiculos);
                    break;
                case 5:descarregarVeiculo(listaVeiculos, quantVeiculos, listaEncomendas, quantEncomendas);
                    break;
                case 6:
                    break;
                default:
                    printf("\n\nOpcao invalida");
                }

            }
            while(opcao != 6);
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
                    listarEncomenda(quantEncomendas, listaEncomendas, listaVeiculos, quantVeiculos, 1);
                    break;
                case 3://Eliminar encomenda
                    eliminarEncomenda(&quantEncomendas, listaEncomendas, listaVeiculos);
                    break;
                case 4://Alterar estado
                    do
                    {
                    opcao2=menuAlterarEstado();
                    switch(opcao2)
                    {
                    case 1:
                        alterarEstado(listaEncomendas, quantEncomendas);

                    break;
                    case 2:
                    break;
                    }
                    }while(opcao2!=3);

                    break;
                case 5:
                opcao2=menuCarregarEncomenda();
                do
                {
                switch(opcao2)
                {
                case 1:
                    registarCarregamento(quantVeiculos, listaVeiculos, listaEncomendas, quantEncomendas);
                    opcao2=3;
                    break;
                case 2:
                    carregarEncomendaAuto(listaVeiculos, quantVeiculos, listaEncomendas, quantEncomendas);
                    opcao2=3;
                    break;
                case 3:
                    break;
                default:
                    printf("\nOpcao Invalida");
                }
                }while(opcao2!=3);

                    break;
                case 6://listar o veiculo que entregou a encomenda
                    listarVeiculo(listaVeiculos, quantVeiculos, listaEncomendas, quantEncomendas);
                    break;
                case 7:

                    break;
                default:
                    printf("\nOpcao Invalida");
                }
            }
            while(opcao != 7);
            break;
        case 3:
            gravarFicheiroBinario(listaVeiculos, quantVeiculos);
            gravarFicheiroBinarioEncomendas(listaEncomendas, quantEncomendas);
            guardarficheiroTexto(listaVeiculos, quantVeiculos);
            guardarFicheiroTextoEncomendas(listaEncomendas, quantEncomendas);
            break;
        case 4:
            lerFicheiroBinarioEncomendas(listaEncomendas, &quantEncomendas);
            lerFicheiroBinario(listaVeiculos, &quantVeiculos);
            break;
        case 5:
            break;
        default:
            printf("\nOpcao Invalida ");
            break;
        }


    }
    while(opcao != 99);
    return 0;

}
