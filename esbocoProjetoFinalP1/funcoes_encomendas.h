#ifndef FUNCOES_ENCOMENDAS_H_INCLUDED
#define FUNCOES_ENCOMENDAS_H_INCLUDED

#include "constantes.h"
char estadoEncomenda (int var);
tipoEncomenda inserirEncomenda (int *quantEncomendas);
//void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA]);
void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, int var);

void eliminarEncomenda (int *quantEncomendas, tipoEncomenda vetorEncomendas[MAX_STRING], tipoVeiculo vetorVeiculo[MAX_STRING]);
int procurarEncomenda(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas);
void alterarDestino (tipoEncomenda listarEncomenda[MAX_ENCOMENDA], int quantEncomendas, int procurar);
void alterarEstado (tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas,tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos, int *quantDevol);

void registarCarregamento (int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas);

void carregarEncomendaAuto(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEmcomendas, int var);

void descarregarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas, int *quantDevol);

void consultaEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas);

#endif //FUNCOES_ENCOMENDAS_H_INCLUDED
