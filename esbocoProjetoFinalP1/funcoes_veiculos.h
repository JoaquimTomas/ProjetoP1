#ifndef FUNCOES_VEICULOS_H_INCLUDED
#define FUNCOES_VEICULOS_H_INCLUDED

#include "constantes.h"
#include "funcoes_auxiliares.h"
tipoVeiculo inserirVeiculo(int *quantVeiculos);
char estadoVeiculo (tipoVeiculo estado);
void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS]);
void inserirMatricula(char matricula[8]);

void alterarEstadoVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas);
int procurarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void listarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas);

void organizaVeiculos(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos);
void consultarVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos);
int procuraMatricula(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void registarViagem(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);



#endif // FUNCOES_VEICULOS_H_INCLUDED

