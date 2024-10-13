#include "../headers/Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, std::string id){
    this->nombre = nombre;
    this->id = id;

    for(int i = 0; i < 5; i++){
        materialPrestado[i] = nullptr;
    }
}

std::string Usuario::getId() const{
    return this->id;
}

std::string Usuario::getNombre() const {
    return this->nombre;
}

void Usuario::prestarMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < 5; i++){
        if( materialPrestado[i] == nullptr) {
            materialPrestado[i] = material;
            material->cambiarEstado();
            break;
        }
    }
}   

void Usuario::devolverMaterial(std::string isbn) {
    for(int i = 0; i < 5; i++) {
        if (materialPrestado[i] != nullptr && materialPrestado[i]->getIsbn() == isbn) {
            materialPrestado[i]->cambiarEstado();
            materialPrestado[i] = nullptr;
            break;
        }
    }
}

void Usuario::mostrarMaterial() {
    for (int i = 0; i < 5;i++){
        if(materialPrestado[i]!= nullptr){
            materialPrestado[i]->mostrarInformacion();
        }
    }
}

Usuario::~Usuario() {
    std::cout <<"Usuario " + nombre + " eliminado" <<std::endl;
}