#pragma once

#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
    private:
        std::string fechaDePublicacion;
        std::string resumen;

    public:
        Libro(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string fechaDePublicacion, std::string resumen);

        std::string getFechaDePublicacion() const;
        std::string getResumen() const;
        void mostrarInformacion() override;

        ~Libro();
};