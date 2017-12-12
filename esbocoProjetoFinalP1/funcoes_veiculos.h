#ifndef FUNCOES_VEICULOS_H_INCLUDED
#define FUNCOES_VEICULOS_H_INCLUDED

#include "constantes.h"
#include "funcoes_auxiliares.h"
tipoVeiculo inserirVeiculo(int *quantVeiculos);
char estadoVeiculo (tipoVeiculo estado);
void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS]);
void inserirMatricula(char matricula[5]);


#endif // FUNCOES_VEICULOS_H_INCLUDED

