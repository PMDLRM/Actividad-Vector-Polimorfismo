#include <iostream>
#include <string>
#include <cstdlib>
#include "Fraccion.h"

using namespace std;

Fraccion::Fraccion(){
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int num, int den){
    numerador = num;
    denominador = den;
}

Fraccion::~Fraccion(){
}

  //getters
int Fraccion::getNumerador(){
    return numerador;
}

int Fraccion::getDenominador(){
    return denominador;
}

  //setters
void Fraccion::setNumerador(int num){
    numerador = num;
}

void Fraccion::setDenominador(int den){
    denominador = den;
}

  //metodos operaciones
Fraccion Fraccion::simplificar(){
    //signos
    if(numerador < 0 || denominador < 0){
        if(numerador < 0 && denominador < 0){
            numerador *= -1;
            denominador *= -1;
        }
        else if(denominador < 0){
            numerador *= -1;
            denominador *= -1;
        }
    }

    //simplificado
    /*
    int menor = 0;
    
    if(numerador == denominador){
      Fraccion newFrac(numerador, denominador);
      return (newFrac);
    }
    else if(abs(numerador) <= abs(denominador)){
        menor = abs(numerador);
    }
    else{
        menor = abs(denominador);
    }
    

    for(int i = 1; i <= menor; i++){
        if(numerador%i == 0 && denominador%i == 0){
            numerador = numerador / i;
            denominador = denominador / i;
            if(i != 1){i--;}
        }
    }

   
    if(numerador == 0){
      denominador = 1;
    }
    */
    int divisor = 2;

    if (denominador > 1){
        while ( divisor <= (denominador^(1/2)) ) {
            if (denominador % divisor == 0 && numerador % divisor == 0){
                numerador = numerador / divisor;
                denominador = denominador / divisor;
            }
            //if (numerador % divisor != 0 || denominador % divisor != 0){
            else{
                divisor++;
            }
        }
    }
    Fraccion nuevaFraccion(numerador, denominador);
    return nuevaFraccion;
}

Fraccion Fraccion::suma(Fraccion frac){
    int newDen = frac.denominador * denominador;
    int newNum = (frac.numerador * denominador) + (numerador * frac.denominador);
    Fraccion newFrac(newNum, newDen);
    newFrac.simplificar();
    return (newFrac);
}

Fraccion Fraccion::resta(Fraccion frac){
    int newDen = frac.getDenominador() * denominador;
    int newNum = (numerador * frac.getDenominador()) + (-frac.getNumerador() * denominador);
    Fraccion newFrac(newNum, newDen);
    newFrac.simplificar();
    return (newFrac);
}

Fraccion Fraccion::multiplicacion(Fraccion frac){
    int newDen = frac.denominador * denominador;
    int newNum = frac.numerador * numerador;
    Fraccion newFrac(newNum, newDen);
    newFrac.simplificar();
    return (newFrac);
}

void Fraccion::imprimir(){
    if (numerador == denominador || numerador == 0 || denominador == 1){
        if (numerador == denominador && denominador != 0){
        cout << 1;
        }
        if (numerador == 0 && denominador !=0){
        cout << 0;
        }
        else if (numerador != denominador && denominador == 1){ // else if para no imprimir doble 0, al ser num=0, den=1
        // Así también al tener 1/1, evitar imprimir doble 1
        cout << numerador;
        }
    }
    else{
    cout << numerador << "/" << denominador;
    }
}