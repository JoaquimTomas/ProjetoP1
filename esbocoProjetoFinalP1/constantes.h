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
    int mes,dia,ano;//self explanatory

}tipoData;


typedef struct
{
    int numeroReg;//registo da encomenda
    char matriculaEnc[8];//matricula do veiculo onde se encontra a encomenda
    tipoData dataReg;//data de quando é feito o registo da encomenda
    tipoData dataDevol;//data de quando a encomenda é devolvida
    float peso;//self explanatory
    char destino[MAX_STRING];//self explanatory
    char estado;//estado da encomenda, entregue, devolvida, etc
    char obs[MAX_STRING];//observaçao
    char razao[MAX_STRING];//razao de devolver

}tipoEncomenda;


typedef struct
{
    char matricula[8];//self explanatory
    tipoData dataFabrico;//
    float cargaMax;//self explanatory
    float pesoEncomendas;//peso de encomendas no veiculo
    char estado;//self explanatory
    int numEncomendas;//numero de encomedas no veiculo
    int quantViagens;//self explanatory

}tipoVeiculo;



#endif // CONSTANTES_H_INCLUDED
