#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "funcoes_veiculos.h"
#include "constantes.h"

int main()
{
    tipoVeiculo vetorVeiculos[MAX_VEICULOS];
    int quantVeiculos=0;
    printf("quantidade de veiculos = %d",quantVeiculos);
    vetorVeiculos[0]=inserirVeiculo(&quantVeiculos);
    printf("quantidade de veiculos = %d",quantVeiculos);
}
