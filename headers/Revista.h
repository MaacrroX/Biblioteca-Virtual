#pragma once

#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
    private:
        std:: string mesDePublicacion;
        int numEdicion;
    
    public: 
        Revista(std::string nombre, std::string isbn, std::string autor, bool prestado, int numEdicion,  std::string mesDePublicacion);

        std::string getMesDePublicacion() const;
        int getNumEdicion() const;
        void mostrarInformacion() override;

        ~Revista();
};