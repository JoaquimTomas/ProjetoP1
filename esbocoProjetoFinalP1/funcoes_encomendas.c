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
    encomenda.estado=estadoEncomenda(encomenda);
    lerString("\nUma breve descricao(opcional):",encomenda.obs,MAX_STRING);

}

char estadoEncomenda (tipoEncomenda encomenda)
{
    printf("\n(R)Registada || (C)Carregada || (E)Entregue || (D)Devolvida:");
    char opcao;
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
        opcao=estadoEncomenda(encomenda);
    }
    return opcao;
}

void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA])
{
    printf("\n\t******************Listar Encomenda*****************");
    int i;
    for(i=0;i<quantEncomendas;i++)
    {
    printf("\n\nNumero Registo:%d",vetorEncomendas[i].numeroReg);
    printf("\nData Registo: %d-%d-%d",vetorEncomendas[i].dataReg.dia,vetorEncomendas[i].dataReg.mes,vetorEncomendas[i].dataReg.ano);
    printf("\nCarga MAX:%0.2f",vetorEncomendas[i].peso);
    switch(vetorEncomendas[i].estado)
    {
    case 'R':printf("\nEstado:Registada");
        break;
    case 'C':printf("\nEstado:Carregada");
        break;
    case 'E':printf("\nEstado:Entregue");
        break;
    case 'D':printf("\nEstado:Devolvida");
        break;}
        printf("\nObservacoes:%s",vetorEncomendas[i].obs);
    }
}

void eliminarEncomenda (int *quantEncomendas, tipoEncomenda vetorEncomendas[MAX_STRING], tipoVeiculo vetorVeiculo[MAX_STRING])
{
    int procura,i;
    printf("\n\t************Eliminar Encomenda**************");
    procura=lerInteiro("\nIntroduza o numero de Registo a eliminar",MIN_ENCOMENDA,MAX_ENCOMENDA);
    for(i=0;i<*quantEncomendas;i++)
    {
        if(vetorEncomendas[i].numeroReg == procura)
        {
            vetorEncomendas[i].numeroReg = vetorEncomendas[i+1].numeroReg;
            break;
        }
    }
    printf("\nNao foi encontrado");
}
