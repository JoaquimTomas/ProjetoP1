#ifndef FUNCOES_ENCOMENDAS_H_INCLUDED
#define FUNCOES_ENCOMENDAS_H_INCLUDED

#include "constantes.h"
char estadoEncomenda (int var);
tipoEncomenda inserirEncomenda (int *quantEncomendas);
void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA]);
void eliminarEncomenda (int *quantEncomendas, tipoEncomenda vetorEncomendas[MAX_STRING], tipoVeiculo vetorVeiculo[MAX_STRING]);
int procurarEncomenda(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas);
void alterarDestino (tipoEncomenda listarEncomenda[MAX_ENCOMENDA], int quantEncomendas, int procurar);
void alterarEstado (tipoEncomenda listaEncomenda[MAX_ENCOMENDA], int quantEncomendas);
#endif //FUNCOES_ENCOMENDAS_H_INCLUDED
