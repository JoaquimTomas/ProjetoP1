#include <stdio.h>

#include "funcoes_ficheiros.h"



void guardarficheiroTexto (tipoVeiculo listaVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    FILE *ficheiro;
    int i;
    ficheiro=fopen("dadosVeiculos.txt","w");

    if(ficheiro==NULL)
    {
        printf("\n\nERRO:Falha na abertura de ficheiro\n\n");
    }
    else
    {
        fprintf(ficheiro,"Total de veiculos: %d\n",quantVeiculos);
        for(i=0; i<quantVeiculos; i++)
        {
            fprintf(ficheiro,"Matricula:%s\n",listaVeiculos[i].matricula);
            fprintf(ficheiro,"Data Fabrico: %d-%d-%d\n",listaVeiculos[i].dataFabrico.dia,listaVeiculos[i].dataFabrico.mes,listaVeiculos[i].dataFabrico.ano);
            fprintf(ficheiro,"Carga Maxima: %.02f\n",listaVeiculos[i].cargaMax);
            fprintf(ficheiro,"Numero de encomendas: %d\nQuantidade Viagens %d\n",listaVeiculos[i].numEncomendas,listaVeiculos[i].quantViagens);
            switch(listaVeiculos[i].estado)
            {
            case 'D':
                fprintf(ficheiro,"Estado:Disponivel\n",listaVeiculos[i].estado);
                break;
            case 'E':
                fprintf(ficheiro,"Estado:Em Carga\n",listaVeiculos[i].estado);
                break;
            case 'T':
                fprintf(ficheiro,"Estado:Em Transporte\n",listaVeiculos[i].estado);
                break;
            case 'R':
                fprintf(ficheiro,"Estado:Em Regresso\n",listaVeiculos[i].estado);
                break;
            case 'A':
                fprintf(ficheiro,"Estado:Avariado\n",listaVeiculos[i].estado);
                break;
            }
        }
    }
    fclose(ficheiro);
}

void gravarFicheiroBinario (tipoVeiculo listaVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    FILE *ficheiro;
    int controlo;

    ficheiro=fopen("dadosVeiculos.bin","wb");
    if(ficheiro==NULL)
    {
        printf("\n\nERRO:Erro na abertura ou criacao do ficheiro");
    }
    else
    {
        controlo=fwrite(&quantVeiculos,sizeof(int),1,ficheiro);
        if(controlo!=1)
        {
            printf("\n\nERRO:Erro na gravacao dos dados(quantidade Veiculos");
        }
        else
        {
            controlo=fwrite(listaVeiculos, sizeof(tipoVeiculo),quantVeiculos,ficheiro);
            if(controlo!=quantVeiculos)
            {
                printf("\n\nERRO:Erro na gravacao dos dados (lista de Veiculos\n");
            }
            else
            {
                printf("\nGravacao efetuada com sucesso\n\n");
            }
        }
    }
    fclose(ficheiro);
}

void lerFicheiroBinario(tipoVeiculo listaVeiculos[MAX_VEICULOS], int *quantVeiculos)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosVeiculos.bin","rb");
    if(ficheiro==NULL)
    {
        printf("\n\nErro na abertura do ficheiro");
    }
    else
    {
        controlo=fread(quantVeiculos, sizeof(int),1,ficheiro);
        if(controlo != 1)
        {
            printf("\n\nErro: erro na leitura dos veiculos");
        }
        else
        {
            controlo=fread(listaVeiculos, sizeof(tipoVeiculo), *quantVeiculos, ficheiro);
            if(controlo != *quantVeiculos)
            {
                printf("\n\nErro na leitura dos veiculos");
            }
            else
            {
                printf("\n\nLeitura efetuada com sucesso");
            }
        }
    }
    fclose(ficheiro);
}

void gravarFicheiroBinarioEncomendas(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    FILE *ficheiro;
    int  controlo;

    ficheiro=fopen("dadosEncomenda.bin","wb");
    if (ficheiro==NULL)
    {
        printf("\n\nErro: Erro na abertura do ficheiro");
    }
    else
    {
        controlo=fwrite(&quantEncomendas, sizeof(int), 1, ficheiro);
        if(controlo!=1)
        {
            printf("\n\nErro:Erro na gravacao das encomendas");
        }
        else
        {
            controlo = fwrite(listaEncomendas, sizeof(tipoEncomenda), quantEncomendas, ficheiro);
            if(controlo != quantEncomendas)
            {printf("Erro na gravaçao (lista Estudantes)");}
            else
            {
            printf("\n\nGravacao Encomendas efetuada com sucesso");
            }
        }
    }
    fclose(ficheiro);
}

void guardarFicheiroTextoEncomendas(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    FILE *ficheiro;
    int i;

    ficheiro = fopen("dadosEncomendas.txt","w");
    if(ficheiro==NULL)
    {
        printf("\n\nERRO: Falha na abertura do ficheiro");

    }
    else
    {
        fprintf(ficheiro,"total de encomendas: %d\n",quantEncomendas);
        for(i=0; i<quantEncomendas; i++)
        {
            fprintf(ficheiro,"Numero Registo: %d\n",listaEncomendas[i].numeroReg);
            fprintf(ficheiro,"Data registo: %d-%d-%d\n",listaEncomendas[i].dataReg);
            fprintf(ficheiro,"Peso:%.02f\n",listaEncomendas[i].peso);
            fprintf(ficheiro,"Destino: %s\n",listaEncomendas[i].destino);
            fprintf(ficheiro,"Observacoes: %s\n",listaEncomendas[i].obs);
            switch(listaEncomendas[i].estado)
            {
            case 'R':
                fprintf(ficheiro,"Estado:Registada\n",listaEncomendas[i].estado);
                break;
            case 'C':
                fprintf(ficheiro,"Estado:Carregada\n",listaEncomendas[i].estado);
                break;
            case 'E':
                fprintf(ficheiro,"Estado:Entregue\n",listaEncomendas[i].estado);
                break;
            case 'D':
                fprintf(ficheiro,"Estadodo: Devolvida\n",listaEncomendas[i].estado);
                break;
            }
        }
    }
    fclose(ficheiro);

}

void lerFicheiroBinarioEncomendas(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int *quantEncomendas)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosEncomenda.bin","rb");
    if(ficheiro==NULL)
    {
        printf("\n\nErro na abertura do ficheiro");
    }
    else
    {
        controlo=fread(quantEncomendas,sizeof(int), 1,ficheiro);
        if(controlo != 1)
        {
            printf("\n\nErro: erro na leitura das encomendas");
        }
        else
        {
            controlo=fread(listaEncomendas,sizeof(listaEncomendas), *quantEncomendas,ficheiro);
            if(controlo != *quantEncomendas)
            {
                printf("\n\nErro na leitura das encomendas");
            }
            else
            {
                printf("\n\nLeitura Encomendas efetuada com sucesso");
            }
        }
    }
    fclose(ficheiro);
}
