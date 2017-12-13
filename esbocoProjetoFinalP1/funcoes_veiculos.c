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
    veiculo.pesoEncomendas=0;
    (*quantVeiculos)++;
    return veiculo;
}

void inserirMatricula(char matricula[5])
{
    char a,b;
    int numMatricula,v2000;//v2000 usada para verificar se é inteiro
    char controlos [2];
    numMatricula = lerInteiro("\nPor favor introduza os primeiros dois numeros da matricula: ", 10,99);
    sprintf(matricula, "%d", numMatricula);

    do
    {
        printf("Por favor introduza os caracteres da matricula: ");
        scanf(" %c%c", &a, &b);
        v2000 = a;
    }
    while(v2000 == 48 || v2000 == 49 || v2000 == 50 || v2000 == 51 || v2000 == 52 || v2000 == 53 || v2000 == 54 || v2000 == 55 || v2000 == 56 || v2000 == 57 || b == '\n' || a == '\n');
//comparamos os valores de v2000 com os da tabela ASCII para saber se sao inteiros ou caracteres
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
    int duh=0;
    do
    {
        printf("\nIntroduza o Estado do Veiculo: %c%c - %c%c - %c%c\n(D)disponivel || (A)Avariado:",estado.matricula[0],estado.matricula[1],estado.matricula[2],estado.matricula[3],estado.matricula[4],estado.matricula[5]);
        scanf(" %c",&opcao);
        opcao=toupper(opcao);
        switch(opcao)
        {
        case 'D'://disponivel
            duh++;
            break;
        case 'A'://Avariado
            duh++;
            break;
        default:
            opcao=estadoVeiculo(estado);
        }
    }while(duh==0);
    return opcao;
}


void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS])
{
    printf("\n\t***************Listar Veiculos**************");
    int i;
    for(i=0; i<quantVeiculos; i++)
    {
        printf("\n\nMatricula: %c%c - %c%c - %c%c \n",vetorVeiculos[i].matricula[0],vetorVeiculos[i].matricula[1],vetorVeiculos[i].matricula[2],vetorVeiculos[i].matricula[3],vetorVeiculos[i].matricula[4],vetorVeiculos[i].matricula[5]);

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
        printf("\nPeso das encomendas carregadas:%0.2f", vetorVeiculos[i].pesoEncomendas);
        printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculos[i].numEncomendas,vetorVeiculos[i].quantViagens);
    }
}
int procurarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int i, opcao=0;
    if(quantVeiculos == 0)
    {
        printf("\nAinda nao Existem veiculos");
    }
    else
    {
        do
        {
            printf("\nSelecione um dos seguites Veiculos:");
            for(i=0; i<quantVeiculos; i++)
            {
                printf("\n Nr.Carrinha:%d || Matricula:%c%c - %c%c - %c%c",i+1, vetorVeiculos[i].matricula[0],vetorVeiculos[i].matricula[1],vetorVeiculos[i].matricula[2],vetorVeiculos[i].matricula[3],vetorVeiculos[i].matricula[4],vetorVeiculos[i].matricula[5]);
            }
            printf("\nopcao:");
            scanf(" %d",&opcao);
            for(i=0; i<=quantVeiculos; i++)
            {
                if(i==opcao && opcao != 0)
                {
                    opcao--;
                    return opcao;
                }
            }
            printf("\nErro, por favor introduza um dos veiculos listados");
        }
        while(opcao == 0 || opcao !=0);
    }

}

void alterarEstadoVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos)
{
    int indice;
    char opcao;
    indice = procurarVeiculo(vetorVeiculo, quantVeiculos);
    switch(vetorVeiculo[indice].estado)
    {
    case 'D':
        do
        {
            printf("\nEstado Atual:Disponivel");
            printf("\nEscolha o estado a substituir:\n(E)-Em carga || (T)Em Transporte || (R)- Em Regresso || (A)-Avariado\nopcao:");
            scanf(" %c",&opcao);
            opcao = toupper(opcao);
            printf("opcao: %c",opcao);
            vetorVeiculo[indice].estado = opcao;
        }while(vetorVeiculo[indice].estado == 'D');

        break;
    case 'E':
        do
        {
            printf("\nEstado Atual:Em Carga");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (T)Em Transporte || (R)- Em Regresso || (A)-Avariado\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        }
        while(opcao != 'D' || opcao != 'T' || opcao != 'R' || opcao != 'A');
        vetorVeiculo[indice].estado = opcao;
        break;
    case 'T':
        do
        {
            printf("\nEstado Atual:Em Transporte");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (E)-Em Carga || (R)-Em Regresso || (A)-Avariado\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        }
        while(opcao != 'D' || opcao != 'E' || opcao != 'R' || opcao != 'A');
        vetorVeiculo[indice].estado=opcao;
        break;
    case 'R':
        do
        {
            printf("\nEstado Atual:Em Regresso");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (E)-Em Carga || (T)-Em Transporte || (A)-Avariado\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        }
        while(opcao != 'D' || opcao != 'E' || opcao != 'T' || opcao != 'A');
        if(opcao=='D')
        {vetorVeiculo[indice].quantViagens++;}
        vetorVeiculo[indice].estado=opcao;
        break;
    case 'A':
        do
        {
            printf("\nEstado Atual:Avariado");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (E)-Em Carga || (T)-Em Transporte || (R)-Em Regresso\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        }
        while(opcao != 'D' || opcao != 'E' || opcao != 'T' || opcao != 'R');
        vetorVeiculo[indice].estado=opcao;

        break;
    }
}

