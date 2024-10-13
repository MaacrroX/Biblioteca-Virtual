#include <iostream>
#include "../headers/MaterialBibliografico.h"
#include "../headers/Libro.h"
#include "../headers/Revista.h"
#include "../headers/Usuario.h"
#include "MaterialBibliografico.cpp"
#include "Libro.cpp"
#include "Revista.cpp"
#include "Usuario.cpp"

MaterialBibliografico* biblioteca[100];
int numMaterial = 0;
Usuario* usuarios[100];
int numUsuarios = 0;


int mostrarMenu() {
    std::cout<< "\nBienvenido\n" <<
                "1. Agregar material a la biblioteca\n" <<
                "2. Mostrar información de la biblioteca\n" <<
                "3. Buscar en la bilioteca\n" <<
                "4. Prestar o devolver material \n" <<
                "5. Gestion de Usuario\n" <<
                "6. Salir\n" <<
                "Ingresar Opción: ";
    int opcion;
    std::cin >> opcion;

    return opcion;
}

Usuario* buscarUsuario(std::string id) {
    for (Usuario* user : usuarios) {
        if(user != nullptr && user->getId() == id){
            return user;
        }
    }
    return nullptr;
}

MaterialBibliografico* buscarMaterial(std::string isbn){
    for(MaterialBibliografico* material : biblioteca) {
        if(material != nullptr && material->getIsbn() == isbn){
            return material;
        }
    }
    return nullptr;
}

void agregarMaterial(){
    if (numMaterial < 100){
        int tipoMaterial;
        std::cout << "\n¿Qué tipo de material quieres agregar?\n"
                  << "1. Libro\n"
                  << "2. Revista\n"
                  << "Ingresar opción: ";
        std::cin >> tipoMaterial;

        std::string nombre, isbn, autor, fechaDePublicacion, resumen, mesDePublicacion;
        bool prestado = false;  

        std::cout << "Ingresar nombre del material: ";
        std::cin.ignore(); 
        std::getline(std::cin, nombre);
        std::cout << "Ingresar ISBN: ";
        std::getline(std::cin, isbn);
        std::cout << "Ingresar autor: ";
        std::getline(std::cin, autor);

        if (tipoMaterial == 1) {  
            std::cout << "Ingresar fecha de publicación (DD/MM/AAAA): ";
            std::getline(std::cin, fechaDePublicacion);
            std::cout << "Ingresar resumen: ";
            std::getline(std::cin, resumen);

            Libro* libro = new Libro(nombre, isbn, autor, prestado, fechaDePublicacion, resumen);
            biblioteca[numMaterial++] = libro;
            std::cout << "Libro agregado exitosamente.\n";
        } 
        else if (tipoMaterial == 2) {  
            int numEdicion;
            std::cout << "Ingresar número de edición: ";
            std::cin >> numEdicion;
            std::cin.ignore();  
            std::cout << "Ingresar mes de publicación: ";
            std::getline(std::cin, mesDePublicacion);

            Revista* revista = new Revista(nombre, isbn, autor, prestado, numEdicion, mesDePublicacion);
            biblioteca[numMaterial++] = revista;
            std::cout << "Revista agregada exitosamente.\n";
        } 
        else {
            std::cout << "Opción no válida, regresando al menú principal.\n";
        }
    }
    else {
        std::cout <<"Biblioteca llena.\n";
    }
}

void mostrarBiblioteca(){
    if(numMaterial == 0){
        std::cout <<"\nBiblioteca vacia,\n";
        return;
    }
    for(MaterialBibliografico* material : biblioteca){
        if(material != nullptr){
            std::cout<< "\n";
            material->mostrarInformacion();
        }
    }
}

void busquedaMateriales() {
    std::cout <<"\nIngrese titulo o autor: ";
    std::string busqueda;
    std::cin.ignore();
    std::getline(std::cin, busqueda);
    
    for(MaterialBibliografico* material : biblioteca) {
        if(material != nullptr){
            if(material->getNombre() == busqueda || material->getAutor() == busqueda){
                std::cout << "\n";
                material->mostrarInformacion();
                break;
            }
        }
    }

}

void prestarODevolver() { 
    int opcion;
    std::cout <<"\n1. Prestar / 2. Devolver\n"
              << "Ingresar opción: ";
    std::cin >> opcion;

    std::cout <<"ID del Usuario: ";
    std::string id;
    std::cin >> id;
    Usuario* user = buscarUsuario(id);

    if (user == nullptr) {
        std::cout << "Usuario no encontrado.\n";
        return;
    }

    std::cout <<"ISBN del material: ";
    std::string isbn;
    std::cin >> isbn; 
    MaterialBibliografico* material = buscarMaterial(isbn);

    if (material == nullptr) {
        std::cout << "Material no encontrado.\n";
        return;
    }

    if(opcion == 1) {
        user->prestarMaterial(material);
    } 
    else if (opcion == 2) { 
        user->devolverMaterial(isbn);
    }

}

void gestionarUsuarios() {
    std::cout << "\nGestionar Usuarios.\n"
              << "1. Crear usuario\n"
              << "2. Buscar usuario\n"
              << "3. Eliminar usuario\n"
              << "Ingrese una opcion: ";
    int opcion;
    std::cin >> opcion;

    if (opcion == 1) {
        if (numUsuarios >= 50) {
            std::cout << "No se pueden agregar más usuarios.\n";
            return; 
        }

        std::string nombre, id;
        std::cout << "Nombre de usuario: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "ID del usuario: ";
        std::getline(std::cin, id);

        
        if (buscarUsuario(id) != nullptr) {
            std::cout << "El ID ya está en uso. Intente con otro ID.\n";
            return; 
        }

        Usuario* nuevoUsuario = new Usuario(nombre, id);
        usuarios[numUsuarios++] = nuevoUsuario;
        std::cout << "Usuario creado exitosamente.\n";

    } else if (opcion == 2) {
        std::cout << "Ingrese ID del usuario a buscar: ";
        std::string id;
        std::cin.ignore();
        std::getline(std::cin, id);

        Usuario* user = buscarUsuario(id);
        if (user != nullptr) {
            std::cout << "ID: " << user->getId() << "\n";
            std::cout << "Nombre: " << user->getNombre() << "\n";
            user->mostrarMaterial();
        } else {
            std::cout << "Usuario no encontrado.\n";
        }

    } else if (opcion == 3) {
        std::cout << "Ingrese ID del usuario a eliminar: ";
        std::string id;
        std::cin.ignore();
        std::getline(std::cin, id);

        Usuario* usuario = buscarUsuario(id);
        if (usuario != nullptr) {
            for (int i = 0; i < numUsuarios; i++) {
                if (usuarios[i] == usuario) {
                    delete usuarios[i];
                    usuarios[i] = nullptr;

                    for (int j = i; j < numUsuarios - 1; j++) {
                        usuarios[j] = usuarios[j + 1];
                    }
                    usuarios[numUsuarios - 1] = nullptr;

                    numUsuarios--;
                    std::cout << "Usuario eliminado exitosamente.\n";
                    return;
                }
            }
        } else {
            std::cout << "Usuario no encontrado.\n";
        }
    } else {
        std::cout << "Opción inválida.\n";
    }
}

int main() {
    bool continuar = true;

    while(continuar) {
        int opcion = mostrarMenu();
    
        switch(opcion){
            case 1:
                agregarMaterial();
                break;
            case 2:
                mostrarBiblioteca();
                break;
            case 3:
                busquedaMateriales();
                break;
            case 4:
                prestarODevolver();
                break;
            case 5:
                gestionarUsuarios();
                break;
            case 6: 
                continuar = false;
                break;
            default:
                std::cout<<"\nOpción inválida, por favor elige una opción válida.\n";
        }
    }
    return 0;
}
