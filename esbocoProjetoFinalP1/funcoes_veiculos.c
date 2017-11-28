#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include"constantes.h"
#include "funcoes_veiculos.h"
#include "funcoes_auxiliares.h"


tipoVeiculo inserirVeiculo (int *quantVeiculos)
{
    tipoVeiculo veiculo;
    lerString("\ninsira a matricula:",veiculo.matricula,7);
    printf("\nIntroduza a data de fabrico;");
    veiculo.dataFabrico = lerData();
    veiculo.cargaMax = lerFloat("\nIntroduza a carga maxima:",CARGA_MIN,CARGA_MAX);
    veiculo.estado = estadoVeiculo(veiculo);
    (*quantVeiculos)++;
}

char estadoVeiculo (tipoVeiculo estado)
{
    char opcao;
    /*do
    {
    printf("\nIntroduza o Estado do Veiculo:%s\n(D)disponivel ||(E)Em Carga ||(T)Em Transporte ||(R)Em Regresso||(A)Avariado:",estado.matricula);
    scanf(" %c",&opcao);
    opcao=toupper(opcao);
    if(opcao=='E')
    {
        printf("\n\nATENCAO ainda nao existem encomendas");
    }
    }while(opcao!='D' || opcao!='E' || opcao!='T'|| opcao!='R'|| opcao!='A');*/
    printf("\nIntroduza o Estado do Veiculo:%s\n(D)disponivel ||(E)Em Carga ||(T)Em Transporte ||(R)Em Regresso||(A)Avariado:",estado.matricula);
    scanf(" %c",&opcao);
    opcao=toupper(opcao);
    switch(opcao)
    {
    case 'D':
        break;
    case 'E': printf("\n\nATENCAO ainda nao existem encomendas");
        break;
    case 'T':
            break;
    case 'R':
            break;
    case 'A':
            break;
            default: opcao=estadoVeiculo(estado);

    }

    return opcao;
}
/*
tipoEncomenda registarEncomenda(void)
{
    tipoEncomenda encomenda;
    lerString("\nItroduza o destino da encomenda",tipoEncomenda.destino,MAX_STRING);
    tipoEncomenda.estado
    tipoEncomenda.numeroReg=lerInteiro("Introduza o numero da rencomenda:",MIN_ENCOMENDA,MAX_ENCOMENDA);
    encomenda.peso=lerFloat("\nIntroduza o peso da encomenda",)

}
*/
