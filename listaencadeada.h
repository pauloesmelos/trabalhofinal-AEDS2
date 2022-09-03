/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   listaencadeada.h
 * Author: pauki
 *
 * Created on 11 de Abril de 2022, 22:05
 */

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

using namespace std;

typedef struct no_{
    string modelo;
    string marca;
    string tipo;
    string ano;
    string km;
    string potencia_do_motor;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    struct no_ *proximo;
}no;

typedef struct topo{
    int tamanho;
    struct no_ *proximo;
    struct no_ *primeiro;
    struct no_ *ultimo;
};


topo* inicia();
topo * encerra(topo* inicio);
void insere(topo* inicio, no* insere);
no* entrada(no* entrada);
void remove(topo* inicio, string remove);
no* buscarLista(topo * ptopo, string placa);
void imprime(topo* inicio);
void imprimeVeiculo(no* carro);
void atualiza(topo* inicio);

#endif /* LISTAENCADEADA_H */

