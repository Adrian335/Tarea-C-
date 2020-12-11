#include<iostream>

#include <vector>

using namespace std; // Para no tener que utilizar std.. 

namespace myvec{

class Vector {
  public:
    vector<double> vec; // Vector vacío con entradas flotantes (double)

    Vector(int lon) { // Creamos el constructor de la clase
      for( int i = 0; i < lon; i++ ) // Con este for, empezamos a llenar las entradas del vector
      {
        cout<< "Ingrese el elemento "<< i +1 << " al vector" << endl; // Imprime la posición i + 1 del vector (el +1 es por el comienzo en 0)
        double c; // ponemos las entradas del vector tipo flotante
        cin >> c; // Entrada de la componente por teclado
        vec.push_back(c); // Agregamos la componente en la ultima componente (valga la redundancia) del vector. De esta manera vamos llenando las entradas
      }
}

    void PrintVec(void){ // Creamos un método que imprima los vectores
      for(int i=0; i < vec.size(); i++){ // Corremos sobre las posiciones de los vectores. Va desde cero hasta un posición menos del tamaño del vector y 
      									// va de 1 en 1
        cout << vec.at(i) << ' '; // Imprimimos las entradas del vector en una fila y con '' metemos espacio para hacer la distinción. El at saca la posición
      }
}

    void SetPos(int c,double b) {  // En la posición c metemos un valor b. Es decir, cambiamos las entradas del vector
      
      if (c<vec.size()) // Con esta condición estamos cambiando la posición c por el valor b
        {
        vec.insert( vec.begin()+ c, b); 
        vec.erase(vec.begin()+ c +1); 
        } 
      else if (c == vec.size()) // Si vector es más pequeño que la posición que se desea reemplazar, entonces se crea la posición que se desea
        {
        vec.push_back(b);
        } 
      else  // Si son 2 o más posiciones el programa parará
      {
        cout<< "Acción invalida" << endl; // Imprimimos el error
      }
}
    double GetPos(int c){ // Crea un método que crea un flotante, ese flotante es el valor de la posición c del vector
      return vec.at(c); // Retornamos la posición c
}

    int GetSize(void){ // Creamos método que devuelve el tamaño del vector (Argumento vacio)
      return vec.size(); // Retornamos el tamaño del vector creado
    }

    Vector operator = (Vector c) // Se sobre carga el operador igual
      {
        vec = c.vec; // Si el vector que metemos lo renombramos como c.vec
        return *this; // retornamos todo el vector.  usando el puntero especial llamado this. Se trata de un puntero que tiene asociado cada objeto
      }					//  y que apunta a si mismo. Ese puntero se puede usar, y de hecho se usa, para acceder a sus miembros.

    Vector operator + (Vector a) // Sobre cargamos el operador suma
      { 
        if (vec.size() != a.GetSize()) // Verificamos que ambos vectores tengan el mismo tamaño. FUNDAMENTAL para la suma de vectores
        {
          cout<< "No se pueden sumar" << endl; // Tamaños diferentes hacemos saber del error
        }
        else
        {
          Vector nvec(0);  // Creamos un vector vacio que iremos llenando con la suma de los dos vectores.
          for(int i=0; i < vec.size(); i++){
            nvec.SetPos(i,vec.at(i) + a.GetPos(i));
        }
          return nvec; // Retornar el vector resultante de la suma
        }
      }

    Vector operator - (Vector a) // Sobre cargamos el operador resta
      { 
        if (vec.size() != a.GetSize()) // Verificamos que ambos vectores tengan el mismo tamaño. FUNDAMENTAL para la resta de vectores
        {
          cout<< "No se pueden sumar" << endl; //Tamaños diferentes hacemos saber del error
        }
        else
        {
          Vector nvec(0); // Creamos un vector vacio que iremos llenando con la resta de los dos vectores.
          for(int i=0; i < vec.size(); i++){
            nvec.SetPos(i,vec.at(i) - a.GetPos(i));
        }
          return nvec; //Retornar el vector resultante de la resta
        }
      }

    	double& operator[] (int a) // Muestra la posición pedida y también en caso tal de que se desee modificar dicha posición
      {
    	return vec[a];
      }
};
}
