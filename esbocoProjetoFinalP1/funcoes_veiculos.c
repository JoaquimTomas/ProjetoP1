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
    limpaBufferStdin();
    inserirMatricula(veiculo.matricula);
    printf("\nIntroduza a data de fabrico;");
    veiculo.dataFabrico = lerData();
    veiculo.cargaMax = lerFloat("\nIntroduza a carga maxima:",CARGA_MIN,CARGA_MAX);
    veiculo.estado = estadoVeiculo(veiculo);
    veiculo.numEncomendas=0;
    veiculo.quantViagens=0;
    (*quantVeiculos)++;
    return veiculo;
}

void inserirMatricula(char matricula[5])
{
    char a,b;
    int numMatricula,controlo,bacon;
    char controlos [2];
    numMatricula = lerInteiro("\nPor favor introduza os primeiros dois numeros da matricula: ", 10,99);
    sprintf(matricula, "%d", numMatricula);

        do
        {
            printf("Por favor introduza os caracteres da matricula: ");
            controlo = scanf(" %c%c", &a, &b);
            bacon = a;
        }
        while(bacon == 48 || bacon == 49 || bacon == 50 || bacon == 51 || bacon == 52 || bacon == 53 || bacon == 54 || bacon == 55 || bacon == 56 || bacon == 57 || b == '\n' || a == '\n'); //comparamos os valores de bacon com os da tabela ASCII para saber se sao inteiros ou caracteres
        a = toupper(a);
        b = toupper(b);
        matricula [2] = a;
        matricula [3] = b;
        numMatricula = lerInteiro("Por favor introduza os segundos dois numeros da matricula: ", 10,99);
        sprintf(controlos, "%d", numMatricula);
        matricula [4] = controlos [0];
        matricula[5] = controlos [1];


}


char estadoVeiculo (tipoVeiculo estado)
{
    char opcao;
    printf("\nIntroduza o Estado do Veiculo: %c%c - %c%c - %c%c\n(D)disponivel || (A)Avariado:",estado.matricula[0],estado.matricula[1],estado.matricula[2],estado.matricula[3],estado.matricula[4],estado.matricula[5]);
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
    for(i=0; i<quantVeiculos; i++)
    {
        printf("\n\nMatricula: %c%c - %c%c - %c%c \n",vetorVeiculos[i].matricula[0],vetorVeiculos[i].matricula[1],vetorVeiculos[i].matricula[2],vetorVeiculos[i].matricula[3],vetorVeiculos[i].matricula[4],vetorVeiculos[i].matricula[51

        printf("Data Fabrico: %d-%d-%d",vetorVeiculos[i].dataFabrico.dia,vetorVeiculos[i].dataFabrico.mes,vetorVeiculos[i].dataFabrico.ano);
        printf("\nCarga Maxima:%0.2f\n",vetorVeiculos[i].cargaMax);
        switch(vetorVeiculos[i].estado)
        {
        case 'D':
            printf("\nEstado:Disponivel");
            break;
        case 'E':
            printf("\nEstado:Em Carga");
            break;
        case 'T':
            printf("\nEstado:Em Transporte");
            break;
        case 'R':
            printf("\nEstado:Em Regresso");
            break;
        case 'A':
            printf("\nEstado:Avariado");
            break;
        }
        printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculos[i].numEncomendas,vetorVeiculos[i].quantViagens);
    }

}
