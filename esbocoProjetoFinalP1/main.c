#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"
#include "funcoes_menu.h"
#include "funcoes_ficheiros.h"

int main() {
    int opcao, opcao2;


    tipoVeiculo listaVeiculos[MAX_VEICULOS];
    tipoEncomenda listaEncomendas[MAX_ENCOMENDA];
    int quantVeiculos=0,quantEncomendas=0,quantDevol=0;
    do {
        opcao2=0;
        opcao = menuPrincipal(quantVeiculos,quantEncomendas,quantDevol);
        switch(opcao) {

        case 1:
            do {
                opcao=menuVeiculos(quantVeiculos);
                switch(opcao) {
                case 1://inserir veiculos
                    listaVeiculos[quantVeiculos] = inserirVeiculo(&quantVeiculos);
                    break;
                case 2://listar veiculos
                    listarVeiculos(quantVeiculos,listaVeiculos);
                    break;
                case 3:
                    alterarEstadoVeiculo(listaVeiculos, quantVeiculos,listaEncomendas, quantEncomendas);
                    break;
                case 4:
                    organizaVeiculos(listaVeiculos, quantVeiculos);
                    break;
                case 5:
                    descarregarVeiculo(listaVeiculos, quantVeiculos,listaEncomendas,quantEncomendas,&quantDevol);
                    break;
                case 6:
                    consultarVeiculo(listaVeiculos, quantVeiculos);

                    break;
                case 7:
                    registarViagem(listaVeiculos, quantVeiculos);
                    break;
                case 8:
                    break;
                default:
                    printf("\n\nOpcao invalida");
                }

            } while(opcao != 8);
            break;
        case 2:
            do {
                opcao = menuEncomendas(quantEncomendas);
                switch(opcao) {
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
                    do {
                        opcao2=menuAlterarEstado();
                        switch(opcao2) {
                        case 1:
                            alterarEstado(listaEncomendas, quantEncomendas,&quantDevol, listaVeiculos, quantVeiculos);

                            break;
                        case 2:
                            break;

                        }
                    } while(opcao2!=3);

                    break;
                case 5:
                    opcao2=menuCarregarEncomenda();
                    do {
                        switch(opcao2) {
                        case 1:
                            registarCarregamento(quantVeiculos, listaVeiculos, listaEncomendas, quantEncomendas);
                            opcao2=3;
                            break;
                        case 2:
                            carregarEncomendaAuto(listaVeiculos, quantVeiculos, listaEncomendas, quantEncomendas,-1);
                            opcao2=3;
                            break;
                        case 3:
                            break;
                        default:
                            printf("\nOpcao Invalida");
                        }
                    } while(opcao2!=3);

                    break;
                case 6://listar o veiculo que entregou a encomenda
                    listarVeiculo(listaVeiculos, quantVeiculos, listaEncomendas, quantEncomendas);
                    break;
                case 7:
                    consultaEncomenda(listaEncomendas, quantEncomendas);

                    break;
                case 8:

                    break;
                default:
                    printf("\nOpcao Invalida");
                }
            } while(opcao != 8);
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
            dadosEstatisticos(listaVeiculos, quantVeiculos,listaEncomendas, quantEncomendas);
            break;
        case 6:
            break;
        default:
            printf("\nOpcao Invalida ");
            break;
        }


    } while(opcao != 6);
    return 0;

}
