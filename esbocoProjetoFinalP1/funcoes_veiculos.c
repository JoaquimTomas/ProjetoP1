#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include"constantes.h"
#include "funcoes_veiculos.h"
#include "funcoes_auxiliares.h"


tipoVeiculo inserirVeiculo (int *quantVeiculos)
{
    printf("\n\t***********Inserir Veiculo**************");
    tipoVeiculo veiculo;
    lerString("\ninsira a matricula:",veiculo.matricula,7);
    printf("\nIntroduza a data de fabrico;");
    veiculo.dataFabrico = lerData();
    veiculo.cargaMax = lerFloat("\nIntroduza a carga maxima:",CARGA_MIN,CARGA_MAX);
    veiculo.estado = estadoVeiculo(veiculo);
    veiculo.numEncomendas=0;
    veiculo.quantViagens=0;
    (*quantVeiculos)++;
    return veiculo;
}

char estadoVeiculo (tipoVeiculo estado)
{
    char opcao;
    printf("\nIntroduza o Estado do Veiculo:%s\n(D)disponivel ||(E)Em Carga ||(T)Em Transporte ||(R)Em Regresso||(A)Avariado:",estado.matricula);
    scanf(" %c",&opcao);
    opcao=toupper(opcao);
    switch(opcao)
    {
    case 'D':
        break;
    case 'E':
        printf("\n\nATENCAO ainda nao existem encomendas");
        break;
    case 'T':
        break;
    case 'R':
        break;
    case 'A':
        break;
    default:
        opcao=estadoVeiculo(estado);
    }
    return opcao;
}

void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS])
{
    printf("\n\t***************Listar Veiculos**************");
    int i;
    for(i=0;i<quantVeiculos;i++)
    {
    printf("\n\nMatricula:%s\n",vetorVeiculos[i].matricula);
    printf("Data Fabrico: %d-%d-%d",vetorVeiculos[i].dataFabrico.dia,vetorVeiculos[i].dataFabrico.mes,vetorVeiculos[i].dataFabrico.ano);
    printf("\nCarga Maxima:%0.2f\n",vetorVeiculos[i].cargaMax);
    switch(vetorVeiculos[i].estado)
    {
    case 'D':
        printf("\nEstado:Disponivel");
        break;
    case 'E':printf("\nEstado:Em Carga");
        break;
    case 'T':printf("\nEstado:Em Transporte");
        break;
    case 'R':printf("\nEstado:Em Regresso");
        break;
    case 'A':printf("\nEstado:Avariado");
        break;
    }
    printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculos[i].numEncomendas,vetorVeiculos[i].quantViagens);
    }

}
