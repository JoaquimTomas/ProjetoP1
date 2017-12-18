#include <stdio.h>
#include <string.h>

#include "funcoes_ficheiros.h"
#include "constantes.h"
#include "funcoes_menu.h"


int menuPrincipal(int quantVeiculos,int quantEncomendas,int quantDevol)
{
    int opcao;
    printf("\n\t********************Menu*******************");
    printf("\nQuantidade de Veiculos: %d ", quantVeiculos );
    printf("\tQuantidade de Encomendas: %d\n", quantEncomendas);
    printf("\nQuantidade de Encomendas Devolvidas: %d\n", quantDevol);
    printf("\nMenu Veiculo-1");
    printf("\nMenu Encomenda-2");
    printf("\nGuardar Ficheiro-3");
    printf("\nLer Ficheiro-4");
    printf("\nDados Estatisticos-5");
    printf("\nSair-6");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    limpaBufferStdin();
    return opcao;

}
int menuVeiculos (int quantVeiculos)
{
    int opcao;
    printf("\n\t**************Menu Veiculos******************");
    printf("\nQuantidade de Veiculos: %d ", quantVeiculos );

    printf("\nInserir veiculo-1");
    printf("\nListar Veiculo(s)-2");
    printf("\nAlterar estado de um Veiculo-3");
    printf("\nListar Veiculos(Decrescente pelo Nr.Encomedas Entregues)-4");
    printf("\nDescarregar Veiculo-5");
    printf("\nConsultar Veiculo-6");
    printf("\nRegistar Estado de Viagem-7");
    printf("\nRetroceder-8");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    limpaBufferStdin();
    return opcao;
}
int menuEncomendas(int quantEncomendas)
{
    int opcao;
    printf("\n\t*************Menu Encomendas****************");
    printf("\nQuantidade de Encomendas: %d", quantEncomendas);
    printf("\nInserir Encomenda-1");
    printf("\nListar Encomeda(s)-2");
    printf("\nEliminar Encomenda-3");
    printf("\nAlterar Estado de uma Encomenda-4");
    printf("\nCarregar Encomenda-5");
    printf("\nListar Veiculo (de uma encomenda entregue)-6");
    printf("\nConsultar Encomenda-7");
    printf("\nRetroceder-8");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    return opcao;
}
int menuCarregarEncomenda (void)
{
    int opcao;
    printf("\n\t************Carregar Encomenda**************");
    printf("\nSelecionar Veiculo-1");
    printf("\nSelecao Automatica-2");
    printf("\nSair-3");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    return opcao;

}
int menuAlterarEstado(void)
{
    int opcao;
    printf("\n\t**************Alterar Estado***************");
    printf("\nAlterar Estado Encomenda-1");
    printf("\nAlterar Estado de uma encomenda devolvida-2");
    printf("\nSair-3");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    return opcao;
}
int menuViagems(void)
{
    int opcao;
    printf("\n\t**************Registar Viagem***************");
    printf("\nComecar Viagem-1");
    printf("\nComecar regresso de viagem-2");
    printf("\nSair-3");
    printf("\nOpcao:");
    scanf(" %d",&opcao);
    return opcao;
}

void dadosEstatisticos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas)
{
    tipoData dataPesquisa;
    float pesoMedio=0, pesoCargaTrasporte=0;
    int quantEncEntregues=0, veiculosEmTransporte=0, viagens=100, i, indice, var,j,k=0,r=0,contador=0;
    char destino[MAX_STRING], destinoCerto[MAX_STRING];
    if(quantEncomendas == 0 || quantVeiculos == 0)
    {
        printf("\nNao Existem Encomendas ou Veiculos Registados");
    }
    else
    {
        printf("introduza a data a pesquisar:");
        dataPesquisa=lerData();
        for(i=0; i<quantEncomendas; i++)
        {
            pesoMedio = pesoMedio+vetorEncomendas[i].peso;
            if(vetorEncomendas[i].estado == 'E')
            {
                quantEncEntregues++;
                if((dataPesquisa.ano == vetorEncomendas[i].dataReg.ano) && (dataPesquisa.mes == vetorEncomendas[i].dataReg.mes) && (dataPesquisa.dia == vetorEncomendas[i].dataReg.dia))
                {
                    contador++;
                }
            }


        }
        for(i=0; i<quantVeiculos; i++)
        {
            if(vetorVeiculos[i].estado == 'T')
            {
                veiculosEmTransporte++;
                pesoCargaTrasporte = pesoCargaTrasporte + vetorVeiculos[i].pesoEncomendas;
            }
            if(vetorVeiculos[i].quantViagens < viagens)
            {
                viagens = vetorVeiculos[i].quantViagens;
                indice = i;
            }
        }

        for(i=0; i<quantEncomendas; i++)
        {
            strcpy(destino, vetorEncomendas[i].destino);
            k=0;
            for(j=0; j<quantEncomendas; j++)
            {
                var=strcmp(destino, vetorEncomendas[i].destino);
                if(var==0)
                {
                    k++;
                }
            }
            if(r<k)
            {
                r=k;
                strcpy(destinoCerto, destino);
            }
        }


        pesoMedio = pesoMedio/quantEncomendas;
        printf("\nPeso Medio Encomendas: %0.2f %%", pesoMedio);
        printf("\nQuantidade Encomendas Entregues: %d", quantEncEntregues);
        pesoCargaTrasporte = (float)veiculosEmTransporte / pesoCargaTrasporte;
        pesoCargaTrasporte = pesoCargaTrasporte * 100.0;
        printf("\nPeso medio Encomendas a serem Transportadas %0.2f %%",pesoCargaTrasporte);
        printf("\nVeiculo com Menos Viagens: %s || Numero Viagens: %d", vetorVeiculos[indice].matricula, vetorVeiculos[indice].quantViagens);
        printf("\nDestino com mais entregas \" %s \"",destinoCerto);
        printf("\nO numero de Entregas feitas na data: %d | %d | %d , foram: %d", dataPesquisa.dia, dataPesquisa.mes, dataPesquisa.ano, contador);
    }
}







