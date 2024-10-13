#include "../headers/Libro.h"
#include<iostream>

Libro::Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechaDePublicacion, std::string resumen)
    : MaterialBibliografico(nombre, isbn, autor, prestado){
        this -> fechaDePublicacion = fechaDePublicacion;
        this -> resumen = resumen;
    }

std::string Libro:: getFechaDePublicacion() const {
    return fechaDePublicacion;
}

std::string Libro::getResumen() const{
    return resumen;
}

void Libro::mostrarInformacion() {
    std::cout << "\nTítulo: " << this->nombre << "\n"
              << "ISBN: " << this->isbn << "\n"
              << "Autor: " << this->autor << "\n"
              << "Prestado: " << (this->prestado ? "Prestado" : "Disponible") << "\n"
              << "Fecha de Publicación: " << this->fechaDePublicacion << "\n"
              << "Resumen: " << this->resumen << std::endl;
}

Libro::~Libro() {}
