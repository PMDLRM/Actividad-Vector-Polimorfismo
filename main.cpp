#include <iostream>
#include "Vect.h"

using namespace std;

/* Actividad de Poliformismo

Equipo:
Mauricio Cuadros - A01236054
Alejandro Mendoza - A01235311
Pedro Andrés Fernández - A01235998
Paola De La Rosa - A01233794
Luis Olave - A01233818

*/

int main() {
    
    // Vector 1 y 2 -> Vector 3 (3 dimensiones) //


    // Se crean objetos fracción
    Fraccion frac1(1,2);
    Fraccion frac2(1,3);
    Fraccion frac3(2,3);
    Fraccion fracV;

    // Se crean arreglos fracción
    Fraccion arr1[3] = {frac1, frac3, frac1};
    Fraccion arr2[3] = {frac2, frac2, frac3};
    Fraccion arrV[3] = {fracV, fracV, fracV};

    Vect vector1(arr1,3);
    Vect vector2(arr2,3);
    Vect vector3(arrV,3);


    cout << "----- Vectores de 3 dimensiones -----" << endl; 
    cout << "\nVector 1: ";
    vector1.print();
    cout << "Vector 2: ";
    vector2.print();
    
    // Escalamiento vectores (multiplica el vector por un entero)
    cout << "\nEscalamiento vector 1 con 10 (multiplicar por 10): " << endl;
    vector3 = vector1.producto(10);
    vector3.print();

    cout << "Escalamiento vector 2 con 10 (multiplicar  por 10): " << endl;
    vector3 = vector2.producto(10);
    vector3.print();

    // Magnitudes vectores
    cout << "\nMagnitud del vector 1: " << endl;
    cout << vector1.magnitud(); 
    cout << "\n\nMagnitud del vector 2: " << endl;
    cout << vector2.magnitud(); 

    // Suma vectores 
    cout << "\n\n\nSuma vector 1 + vector 2: " << endl;
    vector3 = vector1 + vector2;
    vector3.print();

    // Resta vectores
    cout << "\nResta vector 1 - vector 2: " << endl;
    vector3 = vector1 - vector2;
    vector3.print();
    
    // Producto punto
    float punto = vector1.productoPunto(vector2);
    cout << "\nProducto punto vector 1 con vector 2: " << endl; 
    cout << punto << endl;

    // Producto cruz (no soportada para 4 dimensiones)
    cout << "\n\nProducto Cruz vector 1 con vector 2: " << endl;    
    vector3 = vector1.producto(vector2);
    vector3.print(); 

    // Ángulo entre vectores
    float angulo = vector1.anguloVectores(vector2);
    cout << "\nÁngulo entre el vector 1 y el vector 2: " << endl;
    cout << angulo;


    // Vector 4 y 5 -> Vector 6 (4 dimensiones) //

    // Se crean objetos fracción
    Fraccion frac4(1,2);
    Fraccion frac5(1,3);
    Fraccion frac6(1,4);
    Fraccion frac7(1,5);

    // Se crean arreglos fracción
    Fraccion arr4[4] = {frac4, frac5, frac6, frac7};
    Fraccion arr5[4] = {frac2, frac2, frac3, frac3};

    Vect vector4(arr4,4);
    Vect vector5(arr5,4);
    Vect vector6(arrV,4);


    cout << "\n\n\n----- Vectores de 4 dimensiones -----" << endl; 

    cout << "\nVector 4: ";
    vector4.print();
    cout << "Vector 5: ";
    vector5.print();

    // Magnitudes vectores
    cout << "\nMagnitud del vector 4: " << endl;
    cout << vector4.magnitud(); 
    cout << "\n\nMagnitud del vector 5: " << endl;
    cout << vector5.magnitud();

    cout << "\n\n\nEscalamiento vector 4 con 10 (multiplicar por 10): " << endl;
    vector6 = vector4.producto(10);
    vector6.print();

    cout << "Escalamiento vector 5 con 10 (multiplicar  por 10): " << endl;
    vector6 = vector5.producto(10);
    vector6.print();

    // Suma vectores
    cout << "\nSuma vector 4 + vector 5: " << endl;
    vector6 = vector4 + vector5;
    vector6.print();

    // Resta vectores
    cout << "\nResta vector 4 - vector 5: " << endl;
    vector6 = vector4 - vector5;
    vector6.print();

    // Producto punto
    float punto2 = vector4.productoPunto(vector5);
    cout << "\nProducto punto vector 4 con vector 5: " << endl; 
    cout << punto2 << endl;

    // Producto cruz (no soportada para 4 dimensiones)
    cout << "\nProducto Cruz vector 4 con vector 5 (no válida para 4 dimensiones): " << endl;   
    vector6 = vector4.producto(vector5);
    

    // Validación que no se pueden hacer operaciones entre vectores de distinto tamaño //
    cout << "\n\n\n--- Validación que no se puedan hacer operaciones entre vectores de distintas dimensiones ---" << endl;

    cout << "\nSuma vector 1 (3 dimensiones) y vector 4 (4 dimensiones): " << endl;
    vector1 + vector4;

    cout << "\n\nResta vector 1 (3 dimensiones) y vector 4 (4 dimensiones): " << endl;
    vector1 - vector4;

    cout << "\n\nProducto Punto vector 1 (3 dimensiones) y vector 4 (4 dimensiones): " << endl; 
    float punto3 = vector1.productoPunto(vector4);

    cout << "\n\nProducto Cruz vector 1 (3 dimensiones) y vector 4 (4 dimensiones): " << endl;
    vector1.producto(vector4);
    
    return 0;
}