 #include <iostream>
#include <string>

using namespace std;

class Fraccion{
  protected:
  int numerador;
  int denominador;

  public:
  Fraccion();
  Fraccion(int num, int den);
  ~Fraccion();

  //getters
  int getNumerador();
  int getDenominador();

  //setters
  void setNumerador(int num);
  void setDenominador(int den);

  //metodos operaciones
  Fraccion simplificar();
  Fraccion suma(Fraccion frac);
  Fraccion resta(Fraccion frac);
  Fraccion multiplicacion(Fraccion frac);
  void imprimir();

};