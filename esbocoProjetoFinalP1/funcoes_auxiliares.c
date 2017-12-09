#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares.h"
/*

void verificarMatricula(char matricula[7])
{

    int i, controlo, controlo2;
    controlo=sizeof(int);

    for(i=0;i<7;i++)
    {
       isdigit()
    }

}
*/
tipoData lerData(void)
{
    tipoData data;
    data.ano=lerInteiro("\nAno:",2000,2017);
    data.mes=lerInteiro("\nMes:",1,12);
    switch(data.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        data.dia=lerInteiro("\nDia:",1,31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        data.dia=lerInteiro("\nDia:",1,30);
        break;
    default:
        if(data.ano % 400 == 0 || (data.ano%4 == 0 && data.ano % 100 != 0) )
        {
            data.dia=lerInteiro("\nDia:",1,29);
        }
        else
        {
            data.dia=lerInteiro("\nDia:",1,28);
        }
    }
    return data;
}
// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
        {
            limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");
        }

    }
    while (tamanhoString == 1);
}

void limpaBufferStdin(void)
{
    int chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
