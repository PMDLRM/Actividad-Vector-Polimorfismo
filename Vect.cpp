#include <iostream>
#include <math.h>
#include <tgmath.h>
#include "Vect.h"
#include <list>
#include <iterator>

Vect::Vect(){ 
  Fraccion arr[0];
  arreglo = arr;
  tamanio = 0;
}

Vect::Vect(Fraccion *arr, int tam){
  arreglo = arr;
  tamanio = tam;
}

Vect::Vect(int tam){
  Fraccion arr[tam];
  for(int i; i < tam; i++){
    Fraccion tempFrac;
    arr[i] = tempFrac;
  }
  arreglo = arr;
  tamanio = tam;
}

Vect::~Vect(){
}

// Getters
Fraccion Vect::getArreglo(){
  return *arreglo;
}

int Vect::getTamanio(){
  return tamanio;
}

// Setters
void Vect::setArreglo(Fraccion arr[]){
  arreglo = arr;
}

void Vect::setTamanio(int tam){
  tamanio = tam;
}

// Funciones de operaciones con vectores 
Vect Vect::sumaVectores(Vect vect2){
  Fraccion tempFrac;
  Fraccion *arr[tamanio];
  for(int i = 0; i < tamanio; i++){
    arr[i] = new Fraccion();
  }
  Vect res(*arr,tamanio);
  if(compruebaTamanio(vect2)){        // temp
    for(int i = 0; i < tamanio; i++){
      tempFrac = arreglo[i].suma(vect2.arreglo[i]);
      res.arreglo[i].setDenominador(tempFrac.getDenominador());
      res.arreglo[i].setNumerador(tempFrac.getNumerador());
    }
  }
  return res;
}

Vect Vect::restaVectores(Vect vect2){
  Fraccion tempFrac;
  Fraccion *arr[tamanio];
  for(int i = 0; i < tamanio; i++){
    arr[i] = new Fraccion();
  }
  Vect res(*arr,tamanio);
  if(compruebaTamanio(vect2)){
        for(int i = 0; i < tamanio; i++){
            tempFrac = arreglo[i].resta(vect2.arreglo[i]);
            res.arreglo[i].setDenominador(tempFrac.getDenominador());
            res.arreglo[i].setNumerador(tempFrac.getNumerador());
        }
  }
  return res;
}

float Vect::productoPunto(Vect vect2){
  float res = 0;
  float tempMult = 0;
  int tempNum = 0;
  int tempDen = 0;
  if(compruebaTamanio(vect2)){
    for(int i = 0; i < tamanio; i++){
      tempNum = arreglo[i].multiplicacion(vect2.arreglo[i]).getNumerador();
      tempDen = arreglo[i].multiplicacion(vect2.arreglo[i]).getDenominador();
      res += (float) tempNum / (float) tempDen;
    }
  }
  return res;
}

Vect Vect::producto(Vect vect2){ // Producto Cruz
    Fraccion *arr[tamanio];
    for(int i = 0; i < tamanio; i++){
      arr[i] = new Fraccion();
    }
    Vect res(*arr, tamanio);
    Fraccion mult1 = arreglo[1].multiplicacion(vect2.arreglo[2]);
    Fraccion mult2 = arreglo[2].multiplicacion(vect2.arreglo[1]);
    Fraccion mult3 = arreglo[0].multiplicacion(vect2.arreglo[2]);
    Fraccion mult4 = arreglo[2].multiplicacion(vect2.arreglo[0]);
    Fraccion mult5 = arreglo[0].multiplicacion(vect2.arreglo[1]);
    Fraccion mult6 = arreglo[1].multiplicacion(vect2.arreglo[0]);

    if(tamanio == 3 && vect2.getTamanio() == 3){
        res.arreglo[0] = mult1.resta(mult2);
        res.arreglo[1] = mult3.resta(mult4);
        res.arreglo[1].setNumerador(-res.arreglo[1].getNumerador());
        res.arreglo[2] = mult5.resta(mult6);
    }
    else cout<<"Los vectores deben de tener 3 elementos"<<endl;
    return res;
}

float Vect::anguloVectores(Vect vect2){
    float res;
    float prod_punto = productoPunto(vect2);
    float magnitud1 = magnitud();
    float magnitud2 = vect2.magnitud();
    res = acos(prod_punto / (magnitud1 * magnitud2));
    res = res * 180.0/3.141592653589793238463;
    return res;
}

// Funciones para asignar función a operadores
Vect Vect::operator + (Vect obj){
    return this->sumaVectores(obj);
}

Vect Vect::operator - (Vect obj){
    return this->restaVectores(obj);
}

Vect Vect::operator * (Vect obj){
    return this->productoPunto(obj); // Producto punto
}


// Otros métodos
bool Vect::compruebaTamanio(Vect vect2){
  if(tamanio != vect2.getTamanio()){
    cout<<"Error: Los vectores no tienen las mismas dimensiones"<<endl;
    return false;
  }
  else return true; 
}


float Vect::magnitud(){ 
    float resultado = 0;

    for (int i = 0; i < tamanio; i++){
        float numerador = (float) arreglo[i].getNumerador();
        float denominador = (float) arreglo[i].getDenominador();
        resultado += pow(numerador,2)/pow(denominador,2);
    }
    resultado = sqrt(resultado);
    return resultado;
}

Vect Vect::producto(int num){ // Escalamiento
  Fraccion *arr[tamanio];
  for(int i = 0; i < tamanio; i++){
    arr[i] = new Fraccion();
  }
  Vect res(*arr,tamanio);
  for (int i = 0; i < tamanio; i++){
    res.arreglo[i].setNumerador(arreglo[i].getNumerador() * num);
    res.arreglo[i].setDenominador(arreglo[i].getDenominador());
  }
  return res;
} 

// Imprimir vector
void Vect::print(){
    cout << "[";
    for (int i = 0; i < tamanio-1; i++){
        arreglo[i].simplificar();
        arreglo[i].imprimir();
        if(i <= tamanio-1){
            cout << ", ";
        }
    }
    arreglo[tamanio-1].simplificar();
    arreglo[tamanio-1].imprimir();
    cout << "]" << endl;
    cout << "\n";
}