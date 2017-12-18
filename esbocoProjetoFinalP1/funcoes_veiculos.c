#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include"constantes.h"
#include "funcoes_veiculos.h"
#include "funcoes_auxiliares.h"
#include "funcoes_encomendas.h"


tipoVeiculo inserirVeiculo (int *quantVeiculos) {
    tipoVeiculo veiculo;
    if(*quantVeiculos==10) {
        printf("\n\nAtingido o numero maximo de veiculos");
    } else {
        printf("\n\t***********Inserir Veiculo**************");

        inserirMatricula(veiculo.matricula);
        printf("\nIntroduza a data de fabrico;");
        veiculo.dataFabrico = lerData();
        veiculo.cargaMax = lerFloat("\nIntroduza a carga maxima:",CARGA_MIN,CARGA_MAX);
        veiculo.estado = estadoVeiculo(veiculo);
        veiculo.numEncomendas=0;
        veiculo.quantViagens=0;
        veiculo.pesoEncomendas=0;
        (*quantVeiculos)++;
    }
    return veiculo;
}
void inserirMatricula(char matricula[8]) {
    int i;
    lerString("\nIntroduza a Matricula:",matricula,9);

    matricula[8]='\0';

    //checa se os caracteres introduzidos sao numero ou letras
    for(i=0; i<8; i++) {
        //coloca "-" nas posicoes 2 e 5 do vetor
        if(i==2 || i==5) {
            matricula[i]='-';

        } else {
            if(i==1 || i==4 || i==7) {
                //este if existe para saltar os numeros 1,4,7 do i
            } else {
                if((isalnum(matricula[i]) && isalnum(matricula[i+1])) != 0) {


                    //checa se o utilizador colocou os numeros ou letras seguidos;

                    if(isalpha(matricula[i]) == isalpha(matricula[i+1])) {
                    } else {
                        printf("\nTera de introduzir uma matricula do tipo XX-YY-ZZ");
                        inserirMatricula(matricula);
                    }
                } else {
                    printf("\nTera de colocar a matricula na forma XX-YY-ZZ");
                }
            }
        }

    }
}
char estadoVeiculo (tipoVeiculo estado) {
    char opcao;
    int duh=0;
    do {
        printf("\nIntroduza o Estado do Veiculo: %s\n(D)disponivel || (A)Avariado:",estado.matricula);
        scanf(" %c",&opcao);
        opcao=toupper(opcao);
        switch(opcao) {
        case 'D'://disponivel
            duh++;
            break;
        case 'A'://Avariado
            duh++;
            break;
        default:
            opcao=estadoVeiculo(estado);
        }
    } while(duh==0);
    return opcao;
}
void listarVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculos[MAX_VEICULOS]) {

    if(quantVeiculos == 0) {
        printf("\nNao existem veiculos para listar");
    } else {
        printf("\n\t***************Listar Veiculos**************");
        int i;
        for(i=0; i<quantVeiculos; i++) {
            printf("\n\nMatricula: %s\n",vetorVeiculos[i].matricula);

            printf("Data Fabrico: %d-%d-%d",vetorVeiculos[i].dataFabrico.dia,vetorVeiculos[i].dataFabrico.mes,vetorVeiculos[i].dataFabrico.ano);
            printf("\nCarga Maxima:%0.2f\n",vetorVeiculos[i].cargaMax);
            switch(vetorVeiculos[i].estado) {
            case 'D':
                printf("\nEstado:Disponivel");
                break;
            case 'E':
                printf("\nEstado:Em Carga");
                break;
            case 'T':
                printf("\nEstado:Em Transporte");
                break;
            case 'R':
                printf("\nEstado:Em Regresso");
                break;
            case 'A':
                printf("\nEstado:Avariado");
                break;
            }
            printf("\nPeso das encomendas carregadas:%0.2f", vetorVeiculos[i].pesoEncomendas);
            printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculos[i].numEncomendas,vetorVeiculos[i].quantViagens);
        }
    }
}
int procurarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos) {
    int i, opcao=0;
    if(quantVeiculos == 0) {
        printf("\nAinda nao Existem veiculos");
    } else {
        do {
            printf("\nSelecione um dos seguites Veiculos:");
            for(i=0; i<quantVeiculos; i++) {
                printf("\n Nr.Carrinha:%d || Matricula:%s",i+1, vetorVeiculos[i].matricula);
            }
            printf("\nopcao:");
            scanf(" %d",&opcao);
            for(i=0; i<=quantVeiculos; i++) {
                if(i==opcao && opcao != 0) {
                    opcao--;
                    return opcao;
                }
            }
            printf("\nErro, por favor introduza um dos veiculos listados");
        } while(opcao == 0 || opcao !=0);
    }
    return 0;
}

void alterarEstadoVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas) {
    int indice,baza=1;
    char opcao, opcao2;
    indice = procurarVeiculo(vetorVeiculo, quantVeiculos);
    switch(vetorVeiculo[indice].estado) {
    case 'D':
        do
        {
            opcao = 'D';
            printf("\nEstado Atual:Disponivel");
            printf("\nEscolha o estado a substituir:\n(E)-Em carga || (A)-Avariado\nopcao:");
            scanf(" %c",&opcao);
            opcao = toupper(opcao);
            if(opcao == 'A')
            {
                baza = 0;
            }
            else
            {
            if(opcao == 'E')
            {
                do
                {
                printf("\nNao Existem Encomendas nesse veiculo deseja carregar (S/N)");
                scanf(" %c",&opcao2);
                opcao2=toupper(opcao2);
                if(opcao2=='S')
                   {
                    carregarEncomendaAuto(vetorVeiculo, quantVeiculos, vetorEncomendas, quantEncomendas, indice);
                    baza=0;


                   }
                     else
                    {
                        vetorVeiculo[indice].estado = 'D';
                        baza=0;
                    }

                }while(baza != 0);
            }

            }
                 }while(baza != 0);


        break;
    case 'E':
        do {
            printf("\nEstado Atual:Em Carga");
            printf("Escolha o estado a substituir:\n(T)Em Transporte || (S)-Sair\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        } while(opcao != 'T');
        vetorVeiculo[indice].estado = opcao;
        break;
    case 'T':
        do {
            printf("\nEstado Atual:Em Transporte");
            printf("Escolha o estado a substituir:\n (R)-Em Regresso \nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        } while(opcao != 'R');
        vetorVeiculo[indice].estado=opcao;
        break;
    case 'R':
        do {
            printf("\nEstado Atual:Em Regresso");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (S)-Sair \nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
             vetorVeiculo[indice].quantViagens++;
        } while(opcao != 'D' || opcao != 'S');
        if(opcao=='D') {
            vetorVeiculo[indice].quantViagens++;
        }
        vetorVeiculo[indice].estado=opcao;
        break;
    case 'A':
        do {
            printf("\nEstado Atual:Avariado");
            printf("Escolha o estado a substituir:\n(D)-Disponivel || (S)-Sair\nopcao:");
            scanf(" %c",&opcao);
            opcao=toupper(opcao);
        } while(opcao != 'D' || opcao != 'S');
        vetorVeiculo[indice].estado=opcao;

        break;
    }
}


void listarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDA], int quantEncomendas) {
    int i, indiceEnc,j;
    indiceEnc = procurarEncomenda(vetorEncomendas, quantEncomendas);
    if(vetorEncomendas[indiceEnc].estado == 'E') {
        for(j=0; j<quantVeiculos; j++) {
            if(strcmp(vetorVeiculos[j].matricula,vetorEncomendas[indiceEnc].matriculaEnc)==0) {
                i=j;
            }
        }
        printf("\n\nMatricula: %s \n",vetorVeiculos[i].matricula);//,vetorVeiculos[i].matricula[1],vetorVeiculos[i].matricula[2],vetorVeiculos[i].matricula[3],vetorVeiculos[i].matricula[4],vetorVeiculos[i].matricula[5

        printf("Data Fabrico: %d-%d-%d",vetorVeiculos[i].dataFabrico.dia,vetorVeiculos[i].dataFabrico.mes,vetorVeiculos[i].dataFabrico.ano);
        printf("\nCarga Maxima:%0.2f\n",vetorVeiculos[i].cargaMax);
        switch(vetorVeiculos[i].estado) {
        case 'D':
            printf("\nEstado:Disponivel");
            break;
        case 'E':
            printf("\nEstado:Em Carga");
            break;
        case 'T':
            printf("\nEstado:Em Transporte");
            break;
        case 'R':
            printf("\nEstado:Em Regresso");
            break;
        case 'A':
            printf("\nEstado:Avariado");
            break;
        }
        printf("\nPeso das encomendas carregadas:%0.2f", vetorVeiculos[i].pesoEncomendas);
        printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculos[i].numEncomendas,vetorVeiculos[i].quantViagens);
    } else {
        printf("\nA encomenda selecionada ainda nao foi entregue");
    }
}
void consultarVeiculo(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos) {
    int found;

    found = procuraMatricula(vetorVeiculo, quantVeiculos);

    if(found != -1) {
        printf("\n\nMatricula: %s \n",vetorVeiculo[found].matricula);

        printf("Data Fabrico: %d-%d-%d",vetorVeiculo[found].dataFabrico.dia,vetorVeiculo[found].dataFabrico.mes,vetorVeiculo[found].dataFabrico.ano);
        printf("\nCarga Maxima:%0.2f\n",vetorVeiculo[found].cargaMax);
        switch(vetorVeiculo[found].estado) {
        case 'D':
            printf("\nEstado:Disponivel");
            break;
        case 'E':
            printf("\nEstado:Em Carga");
            break;
        case 'T':
            printf("\nEstado:Em Transporte");
            break;
        case 'R':
            printf("\nEstado:Em Regresso");
            break;
        case 'A':
            printf("\nEstado:Avariado");
            break;

        }
        printf("\nPeso das encomendas carregadas:%0.2f", vetorVeiculo[found].pesoEncomendas);
        printf("\nNumero de encomendas entregues:%d || Numero de Viagens:%d",vetorVeiculo[found].numEncomendas,vetorVeiculo[found].quantViagens);
    }

}
void organizaVeiculos(tipoVeiculo vetorVeiculo[MAX_VEICULOS], int quantVeiculos) {
    int i, j, aux;
    if(quantVeiculos == 0) {
        printf("\nNao existem veiculos registados.");
    } else {
        do {
            for(i = 0; i < quantVeiculos - 1; i++) {
                for(j=i + 1; j < quantVeiculos ; j++) {

                    if(vetorVeiculo[j].numEncomendas > vetorVeiculo[i].numEncomendas && vetorVeiculo[i].estado == 'E') {
                        aux = vetorVeiculo[j].numEncomendas;
                        vetorVeiculo[j].numEncomendas = vetorVeiculo[i].numEncomendas;
                        vetorVeiculo[i].numEncomendas = aux;

                    }
                }
            }

        } while(j != quantVeiculos);
        listarVeiculos(quantVeiculos, vetorVeiculo);
    }

}
int procuraMatricula(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos) {

    int i,found=-1,leng;
    char matriculaProc [8];

    if(quantVeiculos == 0) {

        printf("\nNao existem veiculos introduzidos.\n");
        return found;

    } else {

        lerString("\nPor favor introduza a matricula que deseja procurar(\"XX-YY-ZZ\"): ", matriculaProc, 9);

        leng = strlen(matriculaProc);

        if( leng < 8 ) {

            printf("\nPor favor introduza a matricula completa.\n");
            consultarVeiculo(vetorVeiculos, quantVeiculos);

        } else {
            for(i=0; i<=quantVeiculos ; i++) {

                if(strncmp(matriculaProc,vetorVeiculos[i].matricula, 8) == 0) {//strncmp compara strings ate n chars, neste caso 8

                    found = i;
                    i = quantVeiculos;//igualo a quantVeiculos para sair do loop
                }
            }

        }
    }
    return found;
}
void registarViagem(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos) {

    int found, opcao;
    if(quantVeiculos == 0) {
        printf("\nNao existem veiculos para listar");
    } else {
        found = procuraMatricula(vetorVeiculos, quantVeiculos);
        printf("\nRegistar comeco de viagem- 1");
        printf("\nRegistar regresso de viagem- 2");
        printf("\nOpcao:");
        scanf(" %d", &opcao);

        switch(opcao){
        case 1:
            vetorVeiculos[found].estado = 'T';
            printf("\nVeiculo %s alterado para \"Em Transporte\"", vetorVeiculos[found].matricula);
            break;
        case 2:
            vetorVeiculos[found].estado = 'R';
            printf("\nVeiculo %s alterado para \"Em Regresso\"", vetorVeiculos[found].matricula);
            break;
        default:
            printf("\n\nOpcao invalida");
        break;

        }

    }

}
