 / Proyecto: Cajero Automatico
// Hecho en C

#include <stdio.h>
#include <string.h>

#define TOTAL_USUARIOS 5

struct Usuario {
    char usuario[30];
    char contrasena[30];
    char nombre[50];
    double saldo;
};

struct Usuario usuarios[TOTAL_USUARIOS] = {
    {"admin", "1234",   "Carlos Martinez", 15000.00},
    {"maria", "abcd",   "Maria Gonzalez",   8500.50},
    {"pedro", "pass1",  "Pedro Jimenez",    3200.75},
    {"lucia", "lucia9", "Lucia Ramirez",   21000.00},
    {"juan",  "juan01", "Juan Herrera",      500.00}
};

// prototipo de la funcion de login
int iniciar_sesion();

int main() {
    int idx;

    printf("====================================\n");
    printf("     CAJERO AUTOMATICO DIGITAL      \n");
    printf("====================================\n\n");

    // llamar la funcion de login y guardar que usuario entro
    idx = iniciar_sesion();

    // si devuelve -1 es porque fallo el login
    if (idx == -1) {
        printf("Acceso denegado.\n");
        return 0;
    }

    printf("\nBienvenido %s!\n", usuarios[idx].nombre);

    return 0;
}

// funcion de inicio de sesion
// retorna el indice del usuario si entro bien, o -1 si fallo
int iniciar_sesion() {
    char usu[30];
    char pass[30];
    int i;
    int intentos = 0;

    // le doy 3 intentos al usuario
    while (intentos < 3) {
        printf("Usuario   : ");
        scanf("%s", usu);
        printf("Contrasena: ");
        scanf("%s", pass);

        // busco el usuario en el arreglo
        i = 0;
        while (i < TOTAL_USUARIOS) {
            if (strcmp(usuarios[i].usuario, usu) == 0 &&
                strcmp(usuarios[i].contrasena, pass) == 0) {
                return i; // lo encontre
            }
            i++;
        }

        // si llega aqui es que no coincidio
        intentos++;
        printf("\nDatos incorrectos. Le quedan %d intento(s).\n\n", 3 - intentos);
    }

    return -1;
}
