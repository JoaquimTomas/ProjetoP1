#ifndef FUNCOES_MENU_H_INCLUDED
#define FUNCOES_MENU_H_INCLUDED

#include "constantes.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"
int menuPrincipal(int quantVeiculos,int quantEncomendas,int quantDevol);
int menuVeiculos (int quantVeiculos);
int menuEncomendas(int quantEncomendas);

int menuCarregarEncomenda (void);
int menuAlterarEstado(void);

int menuViagems(void);

void dadosEstatisticos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas);

#endif //FUNCOES_MENU_H_INCLUDED
