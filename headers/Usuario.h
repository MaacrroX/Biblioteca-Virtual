#pragma once

#include "MaterialBibliografico.h"

class Usuario {
    protected:
        std::string nombre;
        std::string id;
        MaterialBibliografico* materialPrestado[5];
    
    public:
        Usuario(std::string nombre, std::string id);

        std::string getNombre() const;
        std::string getId() const;
        void prestarMaterial(MaterialBibliografico* material);
        void devolverMaterial(std::string MaterialBibliografico);
        void mostrarMaterial();

        ~Usuario();

};