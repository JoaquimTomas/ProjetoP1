#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include"constantes.h"
#include "funcoes_veiculos.h"
#include "funcoes_auxiliares.h"
#include "funcoes_encomendas.h"

tipoEncomenda inserirEncomenda (int *quantEncomendas)
{
    tipoEncomenda encomenda;
    printf("\n\t***************Inserir Encomenda******************");
    encomenda.numeroReg=lerInteiro("\n\nIntroduza Numero de Registo",MIN_ENCOMENDA,MAX_ENCOMENDA);
    encomenda.dataReg=lerData();
    encomenda.peso=lerFloat("\nIntroduza o peso:",CARGA_MIN,CARGA_MAX);
    lerString("\nDestino:",encomenda.destino,MAX_STRING);
    int var=0;
    lerString("\nUma breve descricao:",encomenda.obs,MAX_STRING);
    encomenda.estado=estadoEncomenda(var);
    limpaBufferStdin();
    (*quantEncomendas)++;
    return encomenda;

}

void alterarEstado (tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas)
{
    int procura,var=1;
    printf("\n\t***************Alterar Estado*****************");
    procura = procurarEncomenda(listaEncomenda, quantEncomendas);
    // printf("teste:%d, %c", procura,listaEncomenda[procura].estado);
    switch(listaEncomenda[procura].estado)
    {
        printf("\nIntroduza o Estado a substituir");
    case 'R':
        printf("\nEstado atual: Registada");
        listaEncomenda[procura].estado = estadoEncomenda(var);
        break;
    case 'C':
        printf("\nEstado atual: Carregada");
        listaEncomenda[procura].estado=estadoEncomenda(var);
        break;
    case 'E':
        printf("\nEstado atual: Entregue");
        listaEncomenda[procura].estado=estadoEncomenda(var);
        break;
    case 'D':
        printf("\nEstado atual: Devolvida");
        listaEncomenda[procura].estado=estadoEncomenda(var);
        break;
    }
    if(listaEncomenda[procura].estado == 'D')
    {
        alterarDestino(listaEncomenda, quantEncomendas, procura);
    }
}


char estadoEncomenda (int var)
{
    char opcao;
    if(var==0)
    {
        printf("\nEncomenda Registada.");
        opcao = 'R';
        switch(opcao)
        {
        case 'R':
            break;
        case 'C':
            break;
        case 'E':
            break;
        case 'D':
            break;
        default:
            opcao=estadoEncomenda(var);
        }
    }
    else
    {

        printf("\n(R)Registada || (C)Carregada || (E)Entregue || (D)Devolvida");
        printf("\nOpcao:");
        scanf(" %c",&opcao);
        opcao=toupper(opcao);
        switch(opcao)
        {
        case 'R':
            break;
        case 'C':
            break;
        case 'E':
            break;
        case 'D':
            break;
        default:
            opcao=estadoEncomenda(var);
        }
    }
    return opcao;
}

void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA])
{
    if(quantEncomendas<=0)
    {

        printf("\n\tNao existem encomendas de momento. \n");
    }
    else
    {
        printf("\n\t******************Listar Encomenda*****************");
        int i;
        for(i=0; i<quantEncomendas; i++)
        {
            printf("\n\nNumero Registo:%d",vetorEncomendas[i].numeroReg);
            printf("\nData Registo: %d-%d-%d",vetorEncomendas[i].dataReg.dia,vetorEncomendas[i].dataReg.mes,vetorEncomendas[i].dataReg.ano);
            printf("\nCarga MAX:%0.2f",vetorEncomendas[i].peso);
            switch(vetorEncomendas[i].estado)
            {
            case 'R':
                printf("\nEstado:Registada");
                break;
            case 'C':
                printf("\nEstado:Carregada");
                break;
            case 'E':
                printf("\nEstado:Entregue");
                break;
            case 'D':
                printf("\nEstado:Devolvida");
                break;
            }
            printf("\nDestino:%s",vetorEncomendas[i].destino);
            printf("\nObservacoes:%s",vetorEncomendas[i].obs);
        }
    }
}

int procurarEncomenda(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    int procura,i;
    procura=lerInteiro("\nIntroduza o Numero de  Registo a procurar",MIN_ENCOMENDA,MAX_ENCOMENDA);
    for(i=0; i<=quantEncomendas; i++)
    {
        if(procura == listaEncomendas[i].numeroReg)
        {
            // i=quantEncomendas;
            return i;
        }
    }

    printf("\n\nNumero nao encontrado");

}


void eliminarEncomenda (int *quantEncomendas, tipoEncomenda vetorEncomendas[MAX_STRING], tipoVeiculo vetorVeiculo[MAX_STRING])
{
    int procura,i,j;
    tipoEncomenda achado;
    printf("\n\t************Eliminar Encomenda**************");
    procura=lerInteiro("\nIntroduza o numero de Registo a eliminar",MIN_ENCOMENDA,MAX_ENCOMENDA);

    for(i=0; i<=*quantEncomendas; i++)
    {
        if(vetorEncomendas[i].numeroReg == procura)
        {
            procura = -1;
            for(j=i; j<=*quantEncomendas+1; j++)
            {
                achado=vetorEncomendas[j+1];
                vetorEncomendas[j]=achado;
            }

        }

    }

    if(procura == -1)
    {
        printf("eliminacao efetuada com sucesso");
        (*quantEncomendas)--;
    }
    else
    {
        printf("\nNao foi encontrado");
    }


}

void alterarDestino (tipoEncomenda listarEncomenda[MAX_ENCOMENDA], int quantEncomendas, int procura)
{
    // int procura;
    //  procura=procurarEncomenda(listarEncomenda, quantEncomendas);
    limpaBufferStdin();
    lerString("\n\nIntroduza o novo destino:", listarEncomenda[procura].obs,MAX_STRING);
}
