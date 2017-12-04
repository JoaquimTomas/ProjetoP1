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

void lerFicheiroBinario(tipoVeiculo listaVeiculos[MAX_VEICULOS],int quantVeiculos)
{

}
