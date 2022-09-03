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
#include "arvoreavl.h"

using namespace std;


int compara(string a,string b){ /* Função auxiliar utilizada para comparar duas Placas */
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

arvore_avl* arvore_avlvoarvore_avl(no_ * carro){
    arvore_avl *arvore_avlvo = (arvore_avl*)malloc(sizeof(arvore_avl)); /* Função que cria um arvore_avlvo nó */

    if(arvore_avlvo){
        arvore_avlvo->info = carro;
        arvore_avlvo->esq = NULL;
        arvore_avlvo->dir = NULL;
        arvore_avlvo->altura = 0;
    }
    else
        printf("\nErro ao alocar o no\n"); // mudar pra cout
    return arvore_avlvo;
}

/*
    Retorna o maior dentre dois valores
    a, b -> altura de dois nós da árvore
*/
short maior(short a, short b){
    return (a > b)? a: b;
}


//  Retorna a altura de um nó ou -1 caso ele seja null
short alturaDoarvore_avl(arvore_avl *arvore_avl){
    if(arvore_avl == NULL)
        return -1;
    else
        return arvore_avl->altura;
}

//   Calcula e retorna o fator de balanceamento de um nó
short fatorDeBalanceamento(arvore_avl *arvore_avl){
    if(arvore_avl)
        return (alturaDoarvore_avl(arvore_avl->esq) - alturaDoarvore_avl(arvore_avl->dir));
    else
        return 0;
}


// função para a rotação à esquerda
arvore_avl* rotacaoEsquerda(arvore_avl *r){
    arvore_avl *y, *f;

    y = r->dir;
    f = y->esq;

    y->esq = r;
    r->dir = f;

    r->altura = maior(alturaDoarvore_avl(r->esq), alturaDoarvore_avl(r->dir)) + 1;
    y->altura = maior(alturaDoarvore_avl(y->esq), alturaDoarvore_avl(y->dir)) + 1;

    return y;
}

// função para a rotação à direita
arvore_avl* rotacaoDireita(arvore_avl *r){
    arvore_avl *y, *f;

    y = r->esq;
    f = y->dir;

    y->dir = r;
    r->esq = f;

    r->altura = maior(alturaDoarvore_avl(r->esq), alturaDoarvore_avl(r->dir)) + 1;
    y->altura = maior(alturaDoarvore_avl(y->esq), alturaDoarvore_avl(y->dir)) + 1;

    return y;
}

arvore_avl* rotacaoEsquerdaDireita(arvore_avl *r){
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

arvore_avl* rotacaoDireitaEsquerda(arvore_avl *r){
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção
    Recebe o nó que está desbalanceado e retorna a arvore_avlva raiz após o balanceamento
*/
arvore_avl* balancear(arvore_avl *raiz){
    short fb = fatorDeBalanceamento(raiz);

    // Rotação à esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // Rotação à direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) >= 0)
        raiz = rotacaoDireita(raiz);

    // Rotação dupla à esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    // Rotação dupla à direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

/*
    Insere um arvore_avlvo nó na árvore
    raiz -> raiz da árvore
    x -> valor a ser inserido
    Retorarvore_avl: endereço do arvore_avlvo nó ou arvore_avlva raiz após o balanceamento
*/
arvore_avl* inserirAvl(arvore_avl *raiz, no_ * carro){
    if(raiz == NULL) // árvore vazia
        return arvore_avlvoarvore_avl(carro);
    else{ // inserção será à esquerda ou à direita
        if(compara(carro->placa,raiz->info->placa) < 0) /* x < raiz->valor ,a < b*/
            raiz->esq = inserirAvl(raiz->esq, carro);
        else if(compara(carro->placa,raiz->info->placa) > 0) /* x > raiz->valor , a > b */
            raiz->dir = inserirAvl(raiz->dir, carro);
        else
            cout << "\nInsercao não realizada pois o veículo já está cadastrado.\n";
    }

    // Recalcula a altura de todos os nós entre a raiz e o arvore_avlvo nó inserido
    raiz->altura = maior(alturaDoarvore_avl(raiz->esq), alturaDoarvore_avl(raiz->dir)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}
void formataAvl(arvore_avl * raiz){ /* Função Auxiliar que imprime todos nós contidos numa Árvore AVL */

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

/*
    Função para remover um nó da Árvore AVL
    Pode ser necessário rebalancear a árvore e a raiz pode ser alterada
    por isso precisamos retornar a raiz >Pesquisamos via PLACA DO VEÍCULO
*/
arvore_avl* removerAvl(arvore_avl *raiz, string placa) {
    if(raiz == NULL){
        cout << "Valor nao encontrado!\n";
        return NULL;
    } else { // procura o nó a remover
        if(compara(raiz->info->placa,placa) == 0) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                cout << "Veículo de placa < " << placa << " > " << "removido com sucesso." << endl;
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){
                    arvore_avl *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->info->placa = aux->info->placa;
                    aux->info->placa = placa;
                    //printf("Elemento trocado: %d !\n", chave);
                    cout << "Elemento de placa " << placa << " trocado. " << endl;
                    raiz->esq = removerAvl(raiz->esq, placa);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    arvore_avl *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    cout << "Elemento de placa " << placa << " com 1 filho removido.";
                    return aux;
                }
            }
        } else {
            if(compara(placa,raiz->info->placa) < 0) // chave < raiz->valor
                raiz->esq = removerAvl(raiz->esq, placa);
            else
                raiz->dir = removerAvl(raiz->dir, placa);
        }

        // Recalcula a altura de todos os nós entre a raiz e o arvore_avlvo nó inserido
        raiz->altura = maior(alturaDoarvore_avl(raiz->esq), alturaDoarvore_avl(raiz->dir)) + 1;

        // verifica a necessidade de rebalancear a árvore
        raiz = balancear(raiz);

        return raiz;
    }
}

void imprimirAvl(arvore_avl *raiz, int nivel){
    int i;
    if(raiz != NULL){
        imprimirAvl(raiz->dir, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        //printf("%d", raiz->valor);
        cout << raiz->info->placa << endl;
        //formataAvl(raiz);
        imprimirAvl(raiz->esq, nivel + 1);
    }
}

/* Exibe arvore Pre Ordem         */
void exibirArvorePreOrdem(arvore_avl * raiz,int opc){ /* opc 1 = Exibir a placa , opc 2 = Exibir todos dados do carro */
    switch(opc){
        case 1:
            if (raiz == NULL)
                return;
            else if( raiz != NULL){
                //printf("%d ",raiz->valor);
                cout << raiz->info->placa << endl;
                exibirArvorePreOrdem(raiz->esq,1);
                exibirArvorePreOrdem(raiz->dir,1);
            }
        break;
         case 2:
            if (raiz == NULL)
                return;
            else if( raiz != NULL){
                formataAvl(raiz);
                exibirArvorePreOrdem(raiz->esq,2);
                exibirArvorePreOrdem(raiz->dir,2);
            }
        break;
         default:
             cout << "\nOpção inválida.\n1.Exibir a placa \n2.Exibir todos dados do veículo\n";
         break;
    }


}
/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
arvore_avl * destruirArvoreAvl(arvore_avl * subRaiz){
	if (subRaiz){
		destruirArvoreAvl(subRaiz->esq);
		destruirArvoreAvl(subRaiz->dir);
		free(subRaiz);
	}
	return NULL;
}
 /*libera toda memoria de uma arvore e coloca NULL arvore_avl valor da raiz    */

arvore_avl * buscaAvl(arvore_avl * raiz, string placa){
    //retorna null se o valor não for encontrado
    //caso contrário, retorna o nó contendo o valor
    if(raiz == NULL ||compara(raiz->info->placa,placa) == 0){ // raiz->valor == valor
        return raiz;
    }

    if(compara(raiz->info->placa,placa) > 0){ //raiz->valor > valor
        return buscaAvl(raiz->esq, placa);
    }else{
        return buscaAvl(raiz->dir, placa);
    }
}
