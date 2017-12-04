#ifndef FUNCOES_ENCOMENDAS_H_INCLUDED
#define FUNCOES_ENCOMENDAS_H_INCLUDED

#include "constantes.h"
char estadoEncomenda (tipoEncomenda encomenda);
tipoEncomenda inserirEncomenda (int *quantEncomendas);
void listarEncomenda (int quantEncomendas, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA]);
void eliminarEncomenda (int *quantEncomendas, tipoEncomenda vetorEncomendas[MAX_STRING], tipoVeiculo vetorVeiculo[MAX_STRING]);
#endif //FUNCOES_ENCOMENDAS_H_INCLUDED
