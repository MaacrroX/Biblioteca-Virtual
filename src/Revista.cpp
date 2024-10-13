#include "../headers/Revista.h"
#include <iostream>

Revista::Revista(std::string nombre, std::string isbn, std::string autor, bool prestado, int numEdicion,  std::string mesDePublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado) {
        this->numEdicion = numEdicion;
        this->mesDePublicacion = mesDePublicacion;
    }

int Revista:: getNumEdicion() const {
    return numEdicion;
}

std::string Revista:: getMesDePublicacion() const {
    return mesDePublicacion;
}

void Revista::mostrarInformacion() {
    std::cout << "\nTítulo: " << nombre << "\n"
              << "ISBN: " << isbn << "\n"
              << "Autor: " << autor << "\n"
              << "Prestado: " << (prestado ? "Prestado" : "Disponible") << "\n"
              << "Número de Edición: " << numEdicion << "\n"
              << "Mes de Publicación: " << mesDePublicacion << std::endl;
}

Revista::~Revista(){}
