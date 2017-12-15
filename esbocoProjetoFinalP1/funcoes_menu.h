#ifndef FUNCOES_MENU_H_INCLUDED
#define FUNCOES_MENU_H_INCLUDED

#include "constantes.h"
#include "funcoes_veiculos.h"
#include "constantes.h"
#include "funcoes_encomendas.h"
int menuPrincipal(int quantVeiculos,int quantEncomendas);
int menuVeiculos (int quantVeiculos);
int menuEncomendas(int quantEncomendas);

int menuCarregarEncomenda (void);
int menuAlterarEstado(void);

#endif //FUNCOES_MENU_H_INCLUDED
