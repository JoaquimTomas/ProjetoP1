#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define MAX_STRING 50
#define MAX_VEICULOS 10
#define MAX_ENCOMENDA 100
#define MIN_ENCOMENDA 1
#define CARGA_MAX 10000
#define CARGA_MIN 0


typedef struct
{
    int mes,dia,ano;

}tipoData;


typedef struct
{
    int numeroReg;
    char matriculaEnc[5];
    tipoData dataReg;
    float peso;
    char destino[MAX_STRING];
    char estado;
    char obs[MAX_STRING];
}tipoEncomenda;


typedef struct
{
    char matricula[8];
    tipoData dataFabrico;
    float cargaMax;
    float pesoEncomendas;
    char estado;
    int numEncomendas;
    int quantViagens;
}tipoVeiculo;



#endif // CONSTANTES_H_INCLUDED
