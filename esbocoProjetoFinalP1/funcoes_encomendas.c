#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include"constantes.h"
#include "funcoes_veiculos.h"
#include "funcoes_auxiliares.h"
#include "funcoes_encomendas.h"
#include "funcoes_ficheiros.h"

tipoEncomenda inserirEncomenda (int *quantEncomendas)
{
    tipoEncomenda encomenda;
    char opcao;
    printf("\n\t***************Inserir Encomenda******************");
    encomenda.numeroReg=*quantEncomendas+1;
    printf("\nNumero de Registo da sua encomenda:%d",encomenda.numeroReg);
    encomenda.dataReg=lerData();
    encomenda.peso=lerFloat("\nIntroduza o peso:",CARGA_MIN,CARGA_MAX);
    lerString("\nDestino:",encomenda.destino,MAX_STRING);
    int var=0;
    do
    {
        printf("\nDeseja inserir uma observacao?(S/N)");
        scanf(" %c",&opcao);
        opcao=toupper(opcao);
        switch(opcao)
        {
        case 'S':
            limpaBufferStdin();
            lerString("\nUma breve descricao:",encomenda.obs,MAX_STRING);
            opcao='N';
            break;
        case 'N':
            encomenda.obs[0]= '\0';
            break;
        default:
            printf("\nOpcao Invalida");
        }
    }
    while(opcao != 'N');


    encomenda.estado=estadoEncomenda(var);
    limpaBufferStdin();
    (*quantEncomendas)++;
    return encomenda;

}
void registarCarregamento (int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas)
{
    int p=0;
    if(quantVeiculos == 0)
    {
        printf("\n\nInpossivel carregar, -nao existem veiculos inseridos-\n");
    }
    else
    {
        int numero,i,j,var=0;
        j=procurarEncomenda(listaEncomenda, quantEncomendas);
        if(j!=-1)
        {

            do
            {
                printf("\nIntroduza o Nr. Veiculo a carregar:");
                for(i=0; i<quantVeiculos; i++)
                {
                    if(vetorVeiculos[i].estado == 'D' || vetorVeiculos[i].estado == 'E')
                    {
                        if((vetorVeiculos[i].pesoEncomendas+listaEncomenda[j].peso <= vetorVeiculos[i].cargaMax))
                        {
                            printf("\nNr. Veiculo:%d || Matricula:%s",i+1, vetorVeiculos[i].matricula);
                            var++;
                        }
                    }
                }
                if(var==0)
                {
                    printf("\nNao Existem Veiculos disponiveis");
                    break;
                }

                else
                {
                    printf("\nIntroduza Nr. Veiculo:");
                    scanf(" %d",&numero);
                    numero--;
                    if(vetorVeiculos[numero].estado == 'E' || vetorVeiculos[numero].estado == 'D')
                    {
                        vetorVeiculos[numero].pesoEncomendas=vetorVeiculos[numero].pesoEncomendas+listaEncomenda[j].peso;
                        strcpy(listaEncomenda[j].matriculaEnc,vetorVeiculos[numero].matricula);
                        //  listaEncomenda[j].matriculaEnc=vetorVeiculos[numero].matricula;
                        listaEncomenda[j].estado = 'C';
                        printf("\nMatricula encomenda: %s",listaEncomenda[j].matriculaEnc);
                        // vetorVeiculos[numero].numEncomendas++;
                        if(vetorVeiculos[numero].pesoEncomendas>=(vetorVeiculos[numero].cargaMax*0.8))
                        {
                            vetorVeiculos[numero].estado= 'T';
                            p=1;
                        }
                        else
                        {
                            vetorVeiculos[numero].estado= 'E';
                            p=1;
                        }
                    }
                    else
                    {
                        printf("\nErro: Veiculo nao Disponivel, ou inexistente");
                    }
                }
                printf("\tEstado veiculo: %c\n",vetorVeiculos[numero].estado);
            }
            while(p!=1);
        }
    }

}


void alterarEstado (tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas,tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos, int *quantDevol)
{
    int procura, baza=1;
    char opcao;
    printf("\n\t***************Alterar Estado*****************");
    procura = procurarEncomenda(listaEncomenda, quantEncomendas);
    switch(listaEncomenda[procura].estado)
    {
        printf("\nIntroduza o Estado a substituir");
    case 'R':
        do
        {
            printf("\nEstado atual: Registada");
            printf("\n(C)Carregada || (S)-Sair");
            printf("\nOpcao:");
            scanf(" %c",&opcao);
            opcao = toupper(opcao);
            if(opcao =='C')
            {
                printf("Numero Registo: %d",listaEncomenda[procura].numeroReg);
                registarCarregamento(quantVeiculos, vetorVeiculo, listaEncomenda, quantEncomendas);
                baza = 0;
            }
            else
            {
                listaEncomenda[procura].estado = 'R';
                baza = 0;
            }
        }
        while(baza != 0);


        break;
         case 'C':
             do
             {
             printf("\nEstado atual: Carregada");
             printf("\n(E)-Entregue || (D)-Devolvida");
             scanf(" %c",&opcao);
             opcao=toupper(opcao);
             if(opcao == 'E')
             {
             listaEncomenda[procura].estado='C';
             baza=0;
             }
             else
             {  if(opcao=='D')
             {
                 listaEncomenda[procura].estado = 'D';
                 printf("\nIntroduza a data de devolucao");
                 listaEncomenda[procura].dataDevol=lerData();
                 guardarFicheiroTextoEncDevolv(listaEncomenda, vetorVeiculo, *quantDevol);
                 baza=0;
             }
             }
             }while(baza!=0);
             break;
         case 'E':
             printf("\nEstado atual: Entregue");
             break;
         case 'D':
             do
             {
             printf("\nEstado atual: Devolvida");
             printf("\n(R)-Registada || (S)-Sair");
             scanf(" %c",&opcao);
             opcao=toupper(opcao);
             if(opcao == 'R')
             {
                 listaEncomenda[procura].estado='R';
                 baza =0;
             }
             else
             {if(opcao=='S')
             {listaEncomenda[procura].estado='D';
             baza =0;
             }}
    }while(baza != 0);

             break;
    }
    if(listaEncomenda[procura].estado == 'D')
    {
        alterarDestino(listaEncomenda, quantEncomendas, procura);
        lerString("\nPor favor insira a razao de devolucao: ", listaEncomenda[procura].razao, MAX_STRING);
        printf("\nPor favor insira a data de devolucao: ");
        listaEncomenda[procura].dataDevol = lerData();
        (*quantDevol)++;
        guardarFicheiroTextoEncDevolv(listaEncomenda, vetorVeiculo, *quantDevol);

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
void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, int var)
{
    int i, controlo, opcao, indice;


    if(quantEncomendas==0)
    {

        printf("\n\tNao existem encomendas de momento. \n");

    }
    else
    {

        if(var == 0)
        {
            indice = procurarVeiculo(vetorVeiculos,quantVeiculos);
            for(i=0; i<quantEncomendas; i++)
            {
                controlo = strcmp(vetorVeiculos[indice].matricula, vetorEncomendas[indice].matriculaEnc);
                if(controlo==0)
                {
                    printf("\n\nNumero Registo:%d",vetorEncomendas[i].numeroReg);
                    printf("\nData Registo: %d-%d-%d",vetorEncomendas[i].dataReg.dia,vetorEncomendas[i].dataReg.mes,vetorEncomendas[i].dataReg.ano);
                    printf("\nPeso:%0.2f",vetorEncomendas[i].peso);
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
                    printf("\nEntregue-1 ||Devolvida-2");
                    do
                    {
                        scanf(" %d",&opcao);
                        switch (opcao)
                        {
                        case 1:
                            vetorEncomendas[i].estado = 'E';
                            opcao=3;

                            break;
                        case 2:
                            vetorEncomendas[i].estado = 'E';
                            break;
                            opcao=3;
                        case 3:
                            break;
                        default:
                            printf("\nOpcao invalida");
                        }
                    }
                    while(opcao!=3);
                }
            }

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
}
int procurarEncomenda(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    int procura,i;
    if(quantEncomendas ==0)
    {
        printf("\nNao existem encomendas registadas.\n");
        return -1;
    }
    else
    {
        procura=lerInteiro("\nIntroduza o Numero de  Registo a procurar",MIN_ENCOMENDA,MAX_ENCOMENDA);
        for(i=0; i<=quantEncomendas; i++)
        {
            if(procura == listaEncomendas[i].numeroReg)
            {
                // i=quantEncomendas;
                return i;
            }
        }

        printf("\n\nNumero nao encontrado\n");
        return -1;
    }

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
        printf("Eliminacao efetuada com sucesso");
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
    lerString("\nIntroduza o novo destino:", listarEncomenda[procura].obs,MAX_STRING);
}
void carregarEncomendaAuto(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEmcomendas, int var)
{
    int i, encomenda;
    encomenda=procurarEncomenda(vetorEncomendas, quantEmcomendas);

        if(var != -1 && encomenda != -1)
        {
            if(vetorVeiculos[var].pesoEncomendas+vetorEncomendas[encomenda].peso < vetorVeiculos[var].cargaMax)
            {
                strcpy(vetorEncomendas[encomenda].matriculaEnc, vetorVeiculos[var].matricula);
                //mudar estado emconmeda
                vetorEncomendas[encomenda].estado='C';
                //mudar estado veiculo
                vetorVeiculos[var].estado='E';
                vetorVeiculos[var].pesoEncomendas = vetorVeiculos[var].pesoEncomendas + vetorEncomendas[encomenda].peso;
                printf("\nEncomenda esta no seguinte veiculo: ");
                printf("Matricula: %s\n", vetorVeiculos[var].matricula);
            }
        }
        else
        {
            if(encomenda != -1)
            {
                for(i=0; i<quantVeiculos; i++)
                {
                    if(vetorVeiculos[i].estado == 'D' || vetorVeiculos[i].estado == 'E')
                    {
                        if(vetorVeiculos[i].pesoEncomendas+vetorEncomendas[encomenda].peso < vetorVeiculos[i].cargaMax)
                        {
                            strcpy(vetorEncomendas[encomenda].matriculaEnc, vetorVeiculos[i].matricula);
                            //mudar estado emconmeda
                            vetorEncomendas[encomenda].estado='C';
                            //mudar estado veiculo
                            vetorVeiculos[i].estado='E';
                            vetorVeiculos[i].pesoEncomendas = vetorVeiculos[i].pesoEncomendas + vetorEncomendas[encomenda].peso;
                            printf("\nEncomenda esta no veiculo seguinte: ");
                            printf("Nr. Veiculo: %d || Matricula: %s\n",i+1, vetorVeiculos[i].matricula);
                            break;
                        }
                    }
                }
            }
        }
}
void descarregarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas, int *quantDevol)
{
    int found,i,opcao,controlo;

    found = procuraMatricula(vetorVeiculos, quantVeiculos);

    if(found != -1)
    {
        for(i=0; i<quantEncomendas; i++)
        {

            controlo = strcmp(vetorVeiculos[found].matricula, vetorEncomendas[i].matriculaEnc);

            if(controlo == 0 && (vetorEncomendas[i].estado!='E' || vetorEncomendas[i].estado!='D'))
            {
                printf("\n\nNumero Registo:%d",vetorEncomendas[i].numeroReg);
                printf("\nData Registo: %d-%d-%d",vetorEncomendas[i].dataReg.dia,vetorEncomendas[i].dataReg.mes,vetorEncomendas[i].dataReg.ano);
                printf("\nEntregue-1 ||Devolvida-2");
                printf("\nOpcao:");
                scanf(" %d",&opcao);

                switch(opcao)
                {

                case 1:
                    vetorEncomendas[i].estado = 'E';
                    vetorVeiculos[found].numEncomendas++;
                    printf("\nEncomenda entregue.\n");


                    break;
                case 2:
                    vetorEncomendas[i].estado = 'D';
                    alterarDestino(vetorEncomendas, quantEncomendas, found);
                    lerString("\nPor favor insira a razao de devolucao: ", vetorEncomendas[i].razao, MAX_STRING);
                    printf("\nPor favor insira a data de devolucao: ");
                    vetorEncomendas[i].dataDevol = lerData();
                    (*quantDevol)++;
                    guardarFicheiroTextoEncDevolv(vetorEncomendas,vetorVeiculos, *quantDevol);

                    break;
                default:
                    printf("\nOpcao invalida");

                }
            }

        }
    }

    /* for(i=0;i<quantVeiculos;i++)
     {
                 printf("Nr. Veiculo:%d || Matricula:%c%c - %c%c - %c%c",i+1, vetorVeiculos[i].matricula[0],vetorVeiculos[i].matricula[1],vetorVeiculos[i].matricula[2],vetorVeiculos[i].matricula[3],vetorVeiculos[i].matricula[4],vetorVeiculos[i].matricula[5]);
     }
     printf("\nOpcao:");
     printf("Encomendas Carregadas:");*/

}
void consultaEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    int i,found,registo;
    if(quantEncomendas == 0)
    {
        printf("\nNao existem encomendas.\n");
    }
    else
    {

        registo = lerInteiro("\nPor favor insira o registo que procura: \n", 1, quantEncomendas);

        for(i=0; i<quantEncomendas ; i++)
        {

            if(registo == vetorEncomendas[i].numeroReg)
            {

                found = i;
                i=quantEncomendas;
            }
        }
        printf("\n\nNumero Registo:%d",vetorEncomendas[found].numeroReg);
        printf("\nData Registo: %d-%d-%d",vetorEncomendas[found].dataReg.dia,vetorEncomendas[found].dataReg.mes,vetorEncomendas[found].dataReg.ano);
        printf("\nCarga MAX:%0.2f",vetorEncomendas[found].peso);
        switch(vetorEncomendas[found].estado)
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
        printf("\nDestino:%s",vetorEncomendas[found].destino);
        printf("\nObservacoes:%s",vetorEncomendas[found].obs);

    }
}


