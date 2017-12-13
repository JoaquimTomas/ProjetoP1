#ifndef FUNCOES_VEICULOS_H_INCLUDED
#define FUNCOES_VEICULOS_H_INCLUDED

#include "constantes.h"
#include "funcoes_auxiliares.h"
tipoVeiculo inserirVeiculo(int *quantVeiculos);
char estadoVeiculo (tipoVeiculo estado);
void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS]);
void inserirMatricula(char matricula[5]);

void alterarEstadoVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos);
int procurarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);


#endif // FUNCOES_VEICULOS_H_INCLUDED

