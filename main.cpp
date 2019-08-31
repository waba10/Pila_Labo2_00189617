/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: HP PC
 *
 * Created on 30 de agosto de 2019, 02:29 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

class Pila{
    public:
        Nodo *inicio;
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        
        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicio;
            inicio = n;
        }
        
        void mostrarPila(){
           Nodo *temp = inicio;
           if(!inicio){
               cout<<"Pila vacia"<<endl;
           }else{
               while(temp){
                   cout<<temp->dato<<", ";
                   temp = temp->sig;
               }
           }
        }
        
        int sizePila(){
            Nodo *temp = inicio;
            int contador=0;
           
          
            while(temp){
                temp = temp->sig;
                
                contador++;
            }
            
            return contador;
        }
        Pila(){
            inicio = nullptr;
        }
};

/*
 * 
 */
int main(int argc, char** argv) {
    int numero=1;
    cout<<"Ingrese los numeros y 0 para ver cual pila es mayor"<<endl;
    
    Pila impar = Pila();
    Pila par = Pila();
    
    do{
        cin>>numero;
        
        if(numero%2==0){
            par.push(numero);
        }
        else{
            impar.push(numero);
        }
    }while(numero!=0); 
    
    
    if(par.sizePila()-1>impar.sizePila()){
        cout<<"La pila par es mayor";
    }
    else if(par.sizePila()-1==impar.sizePila()){
        cout<<"El tamaño de las pilas es igual";
    }
    else{
        cout<<"La pila impar es mayor";
    }
    return 0;
}

