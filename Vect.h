#include <iostream>
#include <string>
#include "Fraccion.h"

class Vect{
  protected:
  // Atributos
  Fraccion *arreglo;
  int tamanio;
    
  public:
  // Constructores
  Vect();
  Vect(Fraccion arr[], int tam);
  Vect(int tam);
  ~Vect();

  // Getters
  Fraccion getArreglo();
  int getTamanio();

  // Setters
  void setArreglo(Fraccion arr[]);
  void setTamanio(int tam);


  // Funciones de operaciones entre vectores
  Vect sumaVectores(Vect vect2);
  Vect restaVectores(Vect vect2);
  float productoPunto(Vect vect2);
  Vect producto(Vect vect2); // Producto Cruz
  float anguloVectores(Vect vect2);

  // Funciones para operadores
  Vect operator + (Vect);
  Vect operator - (Vect);
  Vect operator * (Vect); // Producto punto
  
  // Otros métodos
  bool compruebaTamanio(Vect);
  float magnitud();
  Vect producto(int num); // Escalamiento
  void print();
};