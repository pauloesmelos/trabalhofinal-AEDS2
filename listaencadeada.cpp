/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "listaencadeada.h"
//b

using namespace std;


topo* inicia(){
    /*Inicia a Lista Principal pela inserção de um elemento base.*/
    topo* inicio = new(topo);
    inicio->tamanho = 0;
    inicio->proximo = NULL;
    inicio->primeiro = NULL;
    inicio->ultimo = NULL;
    return inicio;
}

topo * encerra(topo* inicio){
    /*Desloca o espaço de memória ocupado pela Lista Principal.*/
    no* ant;
    no* act = inicio->proximo;
    while(act != NULL){
        ant = act;
        act = act->proximo;
        delete(ant);
    }
    delete(inicio);
    return NULL;
}

void insere(topo* inicio, no* insere){
    /*Insere um elemento na Lista Principal, ordenado com base na placa.*/
    no *ant = NULL;
    no *act = inicio->proximo;
    while(act != NULL && act->placa < insere->placa){
        ant = act;
        act = act->proximo;
    }
    if(ant == NULL){
        inicio->proximo = insere;
        inicio->primeiro = insere;
    }
    else{
        ant->proximo = insere;
    }
    insere->proximo = act;
    if(act == NULL)
        inicio->ultimo = insere;
    inicio->tamanho++;
}

no* entrada(no* entrada){
    /*Recebe, do usuário, os dados de um nó; para inserção na Lista Principal.*/
    cout << "Insira o MODELO do veículo: ";
    cin >> entrada->modelo;
    cout << "Insira a MARCA do veículo: ";
    cin >> entrada->marca;
    cout << "Insira o TIPO do veículo: ";
    cin >> entrada->tipo;
    cout << "Insira o ANO do veículo: ";
    cin >> entrada->ano;
    cout << "Insira a QUILOMETRAGEM do veículo: ";
    cin >> entrada->km;
    cout << "Insira a POTÊNCIA do veículo: ";
    cin >> entrada->potencia_do_motor;
    cout << "Insira o COMBUSTÍVEL do veículo: ";
    cin >> entrada->combustivel;
    cout << "Insira o tipo de CÂMBIO do veículo: ";
    cin >> entrada->cambio;
    cout << "Insira o tipo de DIREÇÃO do veículo: ";
    cin >> entrada->direcao;
    cout << "Insira a COR do veículo: ";
    cin >> entrada->cor;
    cout << "Insira a quantidade de PORTAS do veículo: ";
    cin >> entrada->portas;
    cout << "Insira a PLACA do veículo: ";
    cin >> entrada->placa;
    cout << "< Elemento Registrado >" << endl;
    return entrada;
}

void remove(topo* inicio, string remove){
    /*Remove algum elemento da Lista Principal com base na placa.*/
    int i = 0;
    no* p = inicio->proximo;
    no* aux;
    if(p->placa == remove){
        i = 1;
        inicio->proximo = p->proximo;
        inicio->primeiro = inicio->proximo;
        delete p;
        inicio->tamanho--;
    }
    else{
        while(p->proximo != NULL && i == 0){
            if(p->proximo->placa == remove){
                i = 1;
            }
            else{
                p = p->proximo;
            }
        }
        if(p != NULL && i == 1){
            aux = p->proximo;
            p->proximo = aux->proximo;
            if(p->proximo == NULL)
                inicio->ultimo = p;
            delete aux;
            inicio->tamanho--;
        }
    }
    if(i == 1)
        cout << "< Elemento Removido >" << endl;
    else
        cout << "! Elemento Não Encontrado !" << endl;
}

/*
      Função para buscar um elemento na lista
*/
no* buscarLista(topo * ptopo, string placa){
    no *aux, *no = NULL;

    aux = ptopo->primeiro;
    while(aux && aux->placa != placa)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

void imprime(topo* inicio){
    /*Imprime, na tela, um relatório com todos os elementos da Lista Principal.*/
    no *p = inicio->proximo;
    int i = 1;
    while(p != NULL){
        cout << "-" << i << "-" << endl << endl;
        cout << "Modelo: " << p->modelo << endl;
        cout << "Marca: " << p->marca << endl;
        cout << "Tipo: " << p->tipo << endl;
        cout << "Ano: " << p->ano << endl;
        cout << "KM: " << p->km << endl;
        cout << "Potência do Motor: " << p->potencia_do_motor << endl;
        cout << "Combustivel: " << p->combustivel << endl;
        cout << "Cambio: " << p->cambio << endl;
        cout << "Direcao: " << p->direcao << endl;
        cout << "Cor: " << p->cor << endl;
        cout << "Portas: " << p->portas << endl;
        cout << "Placa: " << p->placa << endl << endl;
        p = p->proximo;
        i++;
    }
    cout << endl;
    cout << "- Número de Veículos Registrados: " << inicio->tamanho << endl;
    cout << "- Primeira Placa: " << inicio->primeiro->placa << endl;
    cout << "- Ultima Placa: " << inicio->ultimo->placa << endl << endl;
    cout << "< Lista Impressa >" << endl;
}

void imprimeVeiculo(no* carro){
    cout << carro->placa << setw(1)  << " | ";
    cout << carro->modelo << setw(2)  << " | ";
    cout << carro->marca << setw(2)  << " | ";
    cout << carro->tipo << setw(2)  << " | ";
    cout << carro->ano << setw(2)  << " | ";
    cout << carro->km << setw(2)  << " | ";
    cout << carro->potencia_do_motor << setw(2)  << " | ";
    cout << carro->combustivel << setw(2)  << " | ";
    cout << carro->cambio << setw(2)  << " | ";
    cout << carro->direcao << setw(2)  << " | ";
    cout << carro->cor << setw(2)  << " | ";
    cout << carro->portas << setw(2)  << " | " << endl;//
}

void atualiza(topo* inicio){
    /* Escreve, no arquivo de texto, os dados lidos e modificados pelo programa.*/
    no* p = inicio->proximo;
    ofstream myfile("BD_veiculos.txt");
    if(myfile.is_open()){
        while(p != NULL){
            myfile << p->modelo << " ";
            myfile << p->marca << " ";
            myfile << p->tipo << " ";
            myfile << p->ano << " ";
            myfile << p->km << " ";
            myfile << p->potencia_do_motor << " ";
            myfile << p->combustivel << " ";
            myfile << p->cambio << " ";
            myfile << p->direcao << " ";
            myfile << p->cor << " ";
            myfile << p->portas << " ";
            myfile << p->placa;
            if(p->proximo != NULL)
                myfile << endl;
            p = p->proximo;
        }
    }

}