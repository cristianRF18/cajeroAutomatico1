 / Proyecto: Cajero Automatico
// Hecho en C

#include <stdio.h>
#include <string.h>

// cantidad de usuarios que va a tener el sistema
#define TOTAL_USUARIOS 5

// estructura para guardar los datos de cada usuario
struct Usuario {
    char usuario[30];
    char contrasena[30];
    char nombre[50];
    double saldo;
};

// aqui van todos los usuarios con sus datos
struct Usuario usuarios[TOTAL_USUARIOS] = {
    {"admin", "1234",   "Carlos Martinez", 15000.00},
    {"maria", "abcd",   "Maria Gonzalez",   8500.50},
    {"pedro", "pass1",  "Pedro Jimenez",    3200.75},
    {"lucia", "lucia9", "Lucia Ramirez",   21000.00},
    {"juan",  "juan01", "Juan Herrera",      500.00}
};

int main() {
    printf("Cajero Automatico\n");
    return 0;
}
