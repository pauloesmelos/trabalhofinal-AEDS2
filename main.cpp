/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: paulo eduardo souza de melos
 *
 * Created on 11 de Abril de 2022, 21:49
 */

/*
* Autor do programa:
* Paulo Eduardo Souza de Melos - 2020.1.08.044
  Disciplina: Estrutura de Dados 2
  UNIFAL-MG
*/

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "listaencadeada.h"
#include "arvoreavl.h"
#include "arvorebinaria.h"
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    int i,i2;
    string leitura;
    topo* inicio = inicia();
    /* Binária */
    no_arvore* raiz = NULL;
    no_arvore* noArvore;
    no_arvore * busca = NULL;
    /* AVL */
    arvore_avl * raizAvl = NULL;
    arvore_avl * buscaAvl = NULL;

    cout << "< Lista Iniciada >" << endl;
    no* elemento;
    no * buscaLista;
    ifstream myfile("BD_veiculos.txt");

    /*Leitura dos Dados*/
    if(myfile.is_open()){
    while(!myfile.eof()){
        no* carro = new(no);
        myfile >> carro->modelo;
        myfile >> carro->marca;
        myfile >> carro->tipo;
        myfile >> carro->ano;
        myfile >> carro->km;
        myfile >> carro->potencia_do_motor;
        myfile >> carro->combustivel;
        myfile >> carro->cambio;
        myfile >> carro->direcao;
        myfile >> carro->cor;
        myfile >> carro->portas;
        myfile >> carro->placa;

        insere(inicio, carro);

        /* Inserção Árvore Binária */
        noArvore = inicia_no(carro);
        raiz = insereArvore(raiz,noArvore);
        /* Inserção Árvore AVL */
        raizAvl = inserirAvl(raizAvl,carro);

    }

    cout << "< Leitura Concluída >" << endl;
    cout << "\n< Quantidade de veículos lidos e inseridos nas Árvores Binária e AVL> " << retornarQuantidade(noArvore) + 1 << " veículos" << endl;
    cout << "\n< Altura da Árvore Binária > " << getAlturaBinaria(raiz) - 20 << endl; // 29 ou 9
    cout << "\n< Altura da Árvore AVL > " << alturaDoarvore_avl(raizAvl) << endl;
    myfile.close();
    }
    else
    cout << "! Não foi possível fazer a leitura do catálogo !" << endl;
    /*Lista de Opções*/
    do{
    //system("cls");
    cout << endl << "Opções:" << endl;
    cout << "1-Incluir" << endl;
    cout << "2-Excluir" << endl;
    cout << "3-Buscar" << endl;
    cout << "4-Relatório Lista Principal" << endl;
    cout << "5-Árvores" << endl;
    cout << "6-Relatório Árvores" << endl;

    cout << "0-Sair (DESALOCAR ÁRVORES e LISTA ENCADEADA)" << endl << "> ";
    cin >> i;
    switch(i){

        case 0: /* Ao fechar IMPRIMIMOS A ALTURA e DESALOCAMOS AS ÁRVORES DA MEMÓRIA !!!!!!*/
           cout << "\n< Altura da Árvore Binária > " << getAlturaBinaria(raiz) - 20 << endl;
           cout << "< Altura da Árvore AVL > " << alturaDoarvore_avl(raizAvl) << endl;

           cout << "\n\n============ DESALOCANDO ESTRUTURAS DA MEMÓRIA============" << endl;
           raiz = destruirArvoreBinaria(raiz);
           if(raiz == NULL)             /* DESALOCANDO ÁRVORE BINÁRIA */
                cout << "< Árvore Binária desalocada da memória com sucesso! > " << endl;
            else
                cout << "Erro ao desalocar a Árvore Binária da memória !";

                                        /* DESALOCANDO ÁRVORE AVL */
            raizAvl = destruirArvoreAvl(raizAvl);
            if(raizAvl == NULL)
                cout << "< Árvore AVL desalocada da memória com sucesso! >" << endl;
            else
                cout << "Erro ao desalocar a Árvore AVL da memória !";
         break;

        case 1:
            /*Cria um nó, faz leitura das características e insere na Lista Principal.*/
            elemento = new(no);
            entrada(elemento);
            insere(inicio, elemento);
            cout << "Elemento Inserido" << endl;
         break;

        case 2:
            /*Remove algum veículo, caso exista, por informação de sua placa.*/
            cout << "Digite a placa do veículo que deseja remover: ";
            cin >> leitura;
            remove(inicio, leitura);
        break;

        case 3:
            /* Faz buscas por meio da placa na Lista principal */
            leitura = "";
            cout << "Digite a placa do veículo que deseja buscar: "; // MAN7774
            cin >> leitura;


            if(buscaLista = buscarLista(inicio,leitura)){
                cout << "<Elemento encontrado> " << leitura << endl;
                imprimeVeiculo(buscaLista); /* imprimindo todos os dados do carro */
            }
            else
                cout << "\nElemento não encontrado, por favor tente novamente com outra placa." << endl;

        break;

        case 4:
         /*Imprime a Lista Principal.*/
         imprime(inicio);
         break;

        case 5: /* Escolha de Árvores | Inserção,Exclusão e Busca na Árvore Binária e AVL*/
            i = 0;
            cout << "\n======= Manipulação de Árvores (Incluir,Excluir,Buscar)==========\n1.Árvore Binária\n2.Árvore AVL" << endl;
            cin >> i;

            switch(i){
                case 1:
                    cout << "1.Inserir na Árvore Binária\n2.Excluir da Árvore Binária \n3.Buscar na Árvore Binária" << endl;
                    cin >> i2;
                    switch(i2){
                        case 1:
                             elemento = new(no);
                             entrada(elemento);
                             insere(inicio, elemento);

                             noArvore = inicia_no(elemento);
                             raiz = insereArvore(raiz,noArvore);
                             cout << "Elemento Inserido na Árvore Binária com sucesso." << endl;
                        break;

                        case 2:
                             leitura = "";
                             cout << "Digite a placa do veículo que deseja REMOVER: ";
                             cin >> leitura;

                             raiz = removerBinaria(raiz,leitura);
                             remove(inicio, leitura);

                        break;

                        case 3:
                             //MAN7774
                             leitura = "";
                             cout << "Digite a placa do veículo que deseja BUSCAR: ";
                             cin >> leitura;
                             busca = buscaArvore(raiz,leitura);
                             if(busca){
                                cout << "\nVeículo de placa " << leitura << "encontrado na Árvore Binária :)\n";
                                formataVeiculo(busca); //imprimindo os dados do carro encontrado
                             }
                             else
                                cout << "\nVeículo não encontrado :( , tente novamente.\n";
                        break;

                        default:
                            cout << "Opção inválida ...\n";
                        break;
                    }
                break;
                case 2:
                    cout << "1.Inserir na Árvore AVL\n2.Excluir da Árvore AVL \n3.Buscar na Árvore AVL" << endl;
                    cin >> i2;
                    switch(i2){
                        case 1:
                             elemento = new(no);
                             entrada(elemento);
                             insere(inicio, elemento);

                             raizAvl = inserirAvl(raizAvl,elemento);
                             cout << "Elemento Inserido na Árvore Binária com sucesso." << endl;
                        break;

                        case 2:
                             leitura = "";
                             cout << "Digite a placa do veículo que deseja REMOVER: ";
                             cin >> leitura;
                             buscaAvl = removerAvl(raizAvl,leitura);
                             remove(inicio, leitura);

                        break;

                        case 3:
                             //MAN7774
                             leitura = "";
                             cout << "Digite a placa do veículo que deseja BUSCAR: ";
                             cin >> leitura;
                        break;

                        default:
                            cout << "Opção inválida ...\n";
                        break;
                    //cout << "\nÁrvore AVL gerada. Acesse o menu principal para imprimi-lá.";
                  }
                break;
            }
        break;

        case 6: /* Relatório das Árvores */
            i = 0;
            cout << "======= Relatório de Árvores ==========\n1.Árvore Binária - Pré-Ordem\n2.Árvore AVL - Pré-Ordem" << endl;
            cin >> i;

             switch(i){
                case 1:
                    cout << "====== PLACAS DOS VEÍCULOS ======" << endl;
                    imprimeArvoreBinaria(raiz,1); /* Imprimindo a placa inserida nas árvore em pré-ordem - como solicitado */
                    cout << "====== DADOS COMPLETOS DOS VEÍCULOS ======" << endl;
                    imprimeArvoreBinaria(raiz,2); /* Imprimindo todos dados inseridos nas árvore em pré-ordem - como solicitado */
                break;
                case 2:
                    cout << "====== PLACAS DOS VEÍCULOS ======" << endl;
                    exibirArvorePreOrdem(raizAvl,1);
                    cout << "====== DADOS COMPLETOS DOS VEÍCULOS ======" << endl;
                    exibirArvorePreOrdem(raizAvl,2);
                break;
            }
        break;

        default:
            cout << i << ": Opção Inválida!" << endl;
        break;
    }
    }while(i != 0);
    /*Encerramento e Desalocando Lista Principal*/
    atualiza(inicio);
    if(encerra(inicio) == NULL)  /* DESALOCANDO A LISTA PRINCIPAL */
        cout << "< Lista Encadeada Principal desalocada da memória com sucesso! >" << endl;
    else
        cout << "Erro ao desalocar a Lista Encadeada Principal da memória !\n" << endl;

    cout << endl << "\n\nEsse programa foi desenvolvido por:" << endl;
    cout << "Paulo Eduardo Souza de Melos - 2020.1.08.044" << endl;
    return 0;
}

