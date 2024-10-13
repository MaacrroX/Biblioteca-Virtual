#include "../headers/MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->prestado = prestado;
}

std::string MaterialBibliografico::getIsbn() const {
    return isbn;
}

std::string MaterialBibliografico::getAutor() const {
    return autor;
}

std::string MaterialBibliografico::getNombre() const {
    return nombre;
}

bool MaterialBibliografico::getPrestado() const {
    return prestado;
}

void MaterialBibliografico::cambiarEstado() {
    if(this->prestado == true){
        prestado = false;
    } else if(this->prestado == false){
        prestado = true;
    }
}

void MaterialBibliografico::mostrarInformacion() {
    std::cout << "Título: " << nombre << "\n"
              << "ISBN: " << isbn << "\n"
              << "Autor: " << autor << "\n"
              << "Prestado: " << (prestado ? "Prestado" : "Disponible") << std::endl;
}

MaterialBibliografico::~MaterialBibliografico() {

}