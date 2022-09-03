/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   arvoreavl.h
 * Author: pauki
 *
 * Created on 11 de Abril de 2022, 22:07
 */

#ifndef ARVOREAVL_H
#define ARVOREAVL_H

using namespace std;

typedef struct arvore_avl{
    struct no_ * info;
    struct arvore_avl *esq, *dir;
    short altura;
}arvore_avl;

int compara(string a,string b);
arvore_avl* arvore_avlvoarvore_avl(no_ * carro);
short maior(short a, short b);
short alturaDoarvore_avl(arvore_avl *arvore_avl);
short fatorDeBalanceamento(arvore_avl *arvore_avl);
arvore_avl* rotacaoEsquerda(arvore_avl *r);
arvore_avl* rotacaoDireita(arvore_avl *r);
arvore_avl* rotacaoEsquerdaDireita(arvore_avl *r);
arvore_avl* rotacaoDireitaEsquerda(arvore_avl *r);
arvore_avl* balancear(arvore_avl *raiz);
arvore_avl* inserirAvl(arvore_avl *raiz, no_ * carro);
void formataAvl(arvore_avl * raiz);
arvore_avl* removerAvl(arvore_avl *raiz, string placa);
void imprimirAvl(arvore_avl *raiz, int nivel);
void exibirArvorePreOrdem(arvore_avl * raiz,int opc);
arvore_avl * destruirArvoreAvl(arvore_avl * subRaiz);
arvore_avl * buscaAvl(arvore_avl * raiz, string placa);

#endif /* ARVOREAVL_H */

