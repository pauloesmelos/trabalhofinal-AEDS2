/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   arvorebinaria.h
 * Author: pauki
 *
 * Created on 11 de Abril de 2022, 22:02
 */

#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

using namespace std;

typedef struct no_arvore_ no_arvore;
struct no_arvore_{
    int valor;
    int quantidade;
    no_arvore * esq;
    no_arvore * dir;
    struct no_* info;
};

int comparar(string a,string b);
no_arvore * buscaArvore(no_arvore * raiz, string placa);
no_arvore * insereArvore(no_arvore * raiz, no_arvore * no1);
int retornarQuantidade(no_arvore * raiz);
no_arvore * inicia_no(no_* car);
no_arvore * removerBinaria(no_arvore *raiz, string placa);
int getAlturaBinaria(no_arvore * raiz);
void formataVeiculo(no_arvore * raiz);
void imprimeArvoreBinaria(no_arvore * raiz, int opc);
no_arvore * destruirArvoreBinaria(no_arvore * subRaiz);

#endif /* ARVOREBINARIA_H */

