Nombre: Mauro Ignacio Lainez Marin / Rut: 21.540.696-2 / Corre: mauro.lainez@alumnos.ucn.cl / Paralelo: C2

# Simulador de Bibliotec Digital

Un sistema diseñado para gestionar materiales bibliográficos, permitir a los usuarios prestar y devolver libros y revistas, y administrar usuarios en una biblioteca.


## Descripción

Este proyecto es un simulador  de gestion de biblioteca que permite a los usuarios:

-Agregar materiales (Libros y Revistas) a la biblioteca.
-Mostrar la Información de los materiales.
-Buscar materiales por título o autor.
-Prestar y devolver materiales.
-Gestionar usuario (agregar, buscar y eliminar usuarios).

# Objetos Creados en el main

1. MaterialBibliografico* biblioteca[100];
    Descripción: Arreglo que almacena punteros a objetos de tipo MaterialBibliografico.
    Propósito: Permite gestionar hasta 100 materiales (libros o revistas) en la biblioteca.
    Métodos relevantes:
        mostrarInformacion(): Método virtual que permite mostrar la información específica de cada material.

2. Usuario* usuarios[100];
    Descripción: Arreglo que almacena punteros a objetos de tipo Usuario.
    Propósito: Permite gestionar hasta 100 usuarios que pueden prestar o devolver materiales.

# Proceso de Ejecución

Al iniciar el programa, se muestra un menú con las siguientes opciones:

1. Agregar material a la biblioteca

    Los usuarios pueden agregar materiales (libros o revistas) al sistema.

2. Mostrar información de la biblioteca

    Muestra la información de todos los materiales registrados en la biblioteca utilizando el método mostrarInformacion().

3. Buscar en la biblioteca

    Permite buscar un material por título o autor y muestra su información si se encuentra.

4. Prestar o devolver material

    Los usuarios pueden prestar o devolver materiales ingresando su ID y el ISBN del material.

5. Gestión de Usuario

    Permite crear, buscar y eliminar usuarios del sistema.

6. Salir

    Termina la ejecución del programa.