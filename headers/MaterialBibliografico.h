#pragma once

#include <string>

class MaterialBibliografico{
    protected:
        std::string nombre;
        std::string isbn;
        std::string autor;
        bool prestado;

    public:
        MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado);

        std::string getNombre() const;
        std::string getAutor() const;
        std::string getIsbn()const ;
        bool getPrestado()const ;
        void cambiarEstado();
        virtual void mostrarInformacion();
        
        virtual ~MaterialBibliografico();
        
};