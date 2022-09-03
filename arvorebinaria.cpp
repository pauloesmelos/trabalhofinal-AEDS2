/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "listaencadeada.h"
#include <iomanip>
#include "arvorebinaria.h"
using namespace std;


int comparar(string a,string b){ /* Função auxiliar utilizada para comparar duas Placas */
    int retorno;                 /* Retornos: -1 = a < b , 0 = a == b , 1 = a > b */
    auto cA = a.c_str();
    auto cB = b.c_str();

    if(strcmp(cA,cB) < 0)
        retorno = -1;
    else if(strcmp(cA,cB) == 0)
        retorno = 0;
    else if(strcmp(cA,cB) > 0)
        retorno = 1;
    return retorno;
}

/**
 * @brief realiza a busca do nó na árvore.
 *
 * @param raiz raiz da árvore onde será feita a busca
 * @param valor valor que se deseja buscar na árvore
 * @return no_arvore* retorna NULL caso o valor não esteja na árvore. Caso contrário, o endereço do nó contendo o valor.
 */

no_arvore * buscaArvore(no_arvore * raiz, string placa){
    //retorna null se o valor não for encontrado
    //caso contrário, retorna o nó contendo o valor
    if(raiz == NULL || comparar(raiz->info->placa,placa) == 0){ //testa se placa é igual a placa do parametro | 0 é true
        return raiz;
    }

    if(comparar(raiz->info->placa,placa) > 0){ //1
        return buscaArvore(raiz->esq,placa);
    }
    else if(comparar(raiz->info->placa,placa) < 0){
        return buscaArvore(raiz->dir,placa);
    }

}

/**
 * @brief realiza a inserção do nó na árvore
 *
 * @param raiz raiz da árvore onde será feita a inserção
 * @param no nó que será inserido
 * @return no_arvore* a raiz da árvore.
 */
no_arvore * insereArvore(no_arvore * raiz, no_arvore * no1){ /* Insere um nó na Árvore Binária */

    if(raiz == NULL){
        return no1;
    }

    //evitando que nos duplicados sejam inseridos na arvore
    if(buscaArvore(raiz, no1->info->placa)!= NULL){
        free(no1);
        return raiz;
    }


    if(comparar(raiz->info->placa,no1->info->placa) < 0){
        raiz->dir = insereArvore(raiz->dir, no1);
    }else{
        raiz->esq = insereArvore(raiz->esq, no1);
    }
    no1->quantidade++;
    return raiz;
}


int retornarQuantidade(no_arvore * raiz){
    int a = raiz->quantidade;
    return a;
}

/**
 * @brief aloca a memória e inicia o novo nó com os valores esperados.
 *
 * @param valor valor a ser guardado no nó
 * @return no_arvore* endereço do novo nó alocado.
 */
no_arvore * inicia_no(no_* car){ /* Inicia o nó da Árvore Binária */
    no_arvore * no1 = (no_arvore*)malloc(sizeof(no_arvore));
    no1->info = car;
    no1->esq = NULL;
    no1->dir = NULL;
    return no1;
}

no_arvore * removerBinaria(no_arvore *raiz, string placa) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(comparar(raiz->info->placa,placa) == 0 ) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                cout << "Veículo de placa <" << placa << ">" << "removido com sucesso."<< endl;
                return NULL;
            }
            else{
                // remover nós que possuem 1 ou 2 filhos
            }
        } else {
            if(comparar(placa,raiz->info->placa) < 0) //comparar(placa,raiz->info->placa)
                raiz->esq = removerBinaria(raiz->esq, placa);
            else
                raiz->dir = removerBinaria(raiz->dir, placa);
            return raiz;
        }
    }
}

int getAlturaBinaria(no_arvore * raiz){ /* Retorna a altura da Árvore Binária */
    int e,d;
    if(raiz == NULL)
        return -1;
    else{
        e = getAlturaBinaria(raiz->esq);
        d = getAlturaBinaria(raiz->dir);

        if(e > d)
            return e + 1;
        else
            return d + 1;
    }
}
void formataVeiculo(no_arvore * raiz){ /* Função auxiliar utilizada no imprimirArvoreBinaria para mostrar todos dados do veículo*/

    cout << raiz->info->placa << setw(1)  << " | ";
    cout << raiz->info->modelo << setw(2)  << " | ";
    cout << raiz->info->marca << setw(2)  << " | ";
    cout << raiz->info->tipo << setw(2)  << " | ";
    cout << raiz->info->ano << setw(2)  << " | ";
    cout << raiz->info->km << setw(2)  << " | ";
    cout << raiz->info->potencia_do_motor << setw(2)  << " | ";
    cout << raiz->info->combustivel << setw(2)  << " | ";
    cout << raiz->info->cambio << setw(2)  << " | ";
    cout << raiz->info->direcao << setw(2)  << " | ";
    cout << raiz->info->cor << setw(2)  << " | ";
    cout << raiz->info->portas << setw(2)  << " | " << endl;//
}

/**
 * @brief imprime a árvore passada.
 *
 * @param raiz raiz da árvore a ser impressa
 * @param  parâmetro que define a impressão da árvore. Os valores aceitos são:
 * 1 - imprimir a placa
 * 2 - imprimir o nó com todos os dados
 */

void imprimeArvoreBinaria(no_arvore * raiz, int opc){
    auto aux = "";
    if(raiz == NULL){
        printf("Árvore vazia.\n");
        return;
    }

    switch (opc)
    {
        case 1:
            aux = raiz->info->placa.c_str();
            printf("%s\n",aux);
            if(raiz->esq != NULL){
                imprimeArvoreBinaria(raiz->esq, 1);
            }
            if(raiz->dir != NULL){
                imprimeArvoreBinaria(raiz->dir, 1);
            }
        break;

        case 2:
            formataVeiculo(raiz);
            if(raiz->esq != NULL){
                imprimeArvoreBinaria(raiz->esq, 2);
            }
            if(raiz->dir != NULL){
                imprimeArvoreBinaria(raiz->dir, 2);
            }
        break;
    }
}
//
no_arvore * destruirArvoreBinaria(no_arvore * subRaiz){
	if (subRaiz){
		destruirArvoreBinaria(subRaiz->esq);
		destruirArvoreBinaria(subRaiz->dir);
		free(subRaiz);
	}
	return NULL;
}
