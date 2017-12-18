#ifndef FUNCOES_FICHEIROS_H_INCLUDED
#define FUNCOES_FICHEIROS_H_INCLUDED

#include "constantes.h"

void guardarficheiroTexto (tipoVeiculo listaVeiculos[MAX_VEICULOS], int quantVeiculos);
void gravarFicheiroBinario (tipoVeiculo listaVeiculos[MAX_VEICULOS], int quantVeiculos);
void lerFicheiroBinario(tipoVeiculo listaVeiculos[MAX_VEICULOS],int *quantVeiculos);
void gravarFicheiroBinarioEncomendas(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int quantEncomendas);
void guardarFicheiroTextoEncomendas(tipoEncomenda listaEncomedas[MAX_ENCOMENDA], int quantEncomendas);
void lerFicheiroBinarioEncomendas(tipoEncomenda listaEncomendas[MAX_ENCOMENDA], int *quantEncomendas);
void guardarFicheiroTextoEncDevolv(tipoEncomenda listaEncomendas[MAX_ENCOMENDA],tipoVeiculo listaVeiculos[MAX_VEICULOS],int quantDevol);




#endif // FUNCOES_FICHEIROS_H_INCLUDED
