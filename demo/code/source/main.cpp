#include <iostream>
#include "Example.hpp"
#include <Aplication.hpp>
#include <LuaScripting.hpp>

using namespace std;

// FUNCIONALIDADES DE LA HERRAMIENTA

// LEER UN XML CON LA DESCRIPCION DE LA ESCENA Y CARGARLA
// ESCRIBIR UN XML CON LA DESCRIPCION DE LA ESCENA ACTUAL
// VER LA JERARQUIA DE ENTIDADES EN TIEMPO REAL
// AÑADIR OBJETOS DE TIPO: MALLA; CILINDRO; MODELO3D Y LUZ
// RENDERIZAR ESOS OBJETOS EN TIEMPO REAL
// CAMBIAR JERARQUIA DE ESCENA EN TIEMPO REAL
// CAMBIAR TRANSFORM DE LAS ENTIDADES EN TIEMPO REAL
// CAMBIAR POSICION DE LA CAMARA CON EL RATON (IMPLEMENTADO CON LA LIBRERIA)
// CAMBIAR TEXTURAS DEL SKYBOX EN TIEMPO REAL -- Ocional (?)
// CAMBIAR PROPIEDADES DE LA LIZ EN TIEMPO REAL
// AÑADIR CON LUA, UN CICLO DE UPDATE A LAS ENTIDADES QUE DESEMOS
// DETERMINAR POR CONSOLA QUE ESCENA QUEREMOS ABRIR
// CAMBIAR EL NOMBRE A LAS ENTIDADES
// CAMBIAR EL TIPO DE OPACIDAD
// CAMBIAR LAS TEXTURAS -- Opcional (?)

/*
----------------------------|
|                           |
|---------------------------|
|      |              |     |
|      |              |     |
|      |              |-----|
|      |              |     |
|      |              |     |
|---------------------------|
*/

int main()
{
    cout << test();

    SceneCreator::Aplication app;

    app.getScripting().exec("loadScene('Esto es mi path')");


    return 0;
}