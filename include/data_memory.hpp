#pragma once
#include <vector>
#include "../include/common.hpp"

#define RESET_REGISTER 0  //valor al que se inicializa cualquier registro
#define ACCUMULATOR_REGISTER 0  //posición del registro acumulador
//clase que contiene los registros de la máquina ram
class data_memory
{
  private:
    std::vector<data_memory_t> memory_; //vector de registros
  public:
    data_memory(void);
    ~data_memory(void);
    //función que redimenciona el vector para que la posición indicada sea accesible
    void resize(const int position);
    //sobrecarga del operador [] que permite acceder a la posicion indicada por parámetro
    //lanza una excepción si la posición es negativa
    //si la posición esta fuera de las dimensiones del vector, llama a resize
    data_memory_t& operator[](const int position);
    //función que vuelca sobre un flujo de salida el contenido de los registros correctamente formateado
    std::ostream& view(std::ostream &os) const;
    //sobrecarga del operador << que llama a la función view para volcar la visualización sobre un flujo de salida
    friend std::ostream& operator<<(std::ostream &os, const data_memory memory);
};
