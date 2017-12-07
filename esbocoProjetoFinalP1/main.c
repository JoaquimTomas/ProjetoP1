#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"
#include "funcoes_menu.h"
int main()
{
    tipoVeiculo listaVeiculos[MAX_VEICULOS];
    tipoEncomenda listaEncomendas[MAX_ENCOMENDA];
    int quantVeiculos=0,quantEncomendas=0;
    menu(listarVeiculos,&quantEncomendas,listarEncomenda,&quantEncomendas);
     }
