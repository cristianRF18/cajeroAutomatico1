// Proyecto: Cajero Automatico
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

int  iniciar_sesion();
void mostrar_menu();
void consultar_saldo(int idx);
void depositar(int idx);
void retirar(int idx);

int main() {
    int idx;
    int opcion;

    printf("====================================\n");
    printf("     CAJERO AUTOMATICO DIGITAL      \n");
    printf("====================================\n\n");

    idx = iniciar_sesion();

    if (idx == -1) {
        printf("Acceso denegado.\n");
        return 0;
    }

    printf("\nBienvenido %s!\n", usuarios[idx].nombre);

    opcion = 0;
    while (opcion != 4) {
        mostrar_menu();

        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            consultar_saldo(idx);
        } else if (opcion == 2) {
            depositar(idx);
        } else if (opcion == 3) {
            retirar(idx);
        } else if (opcion == 4) {
            printf("\nHasta luego!\n");
        } else {
            printf("\nEsa opcion no existe.\n\n");
        }
    }

    return 0;
}

int iniciar_sesion() {
    char usu[30];
    char pass[30];
    int i;
    int intentos = 0;

    while (intentos < 3) {
        printf("Usuario   : ");
        scanf("%s", usu);
        printf("Contrasena: ");
        scanf("%s", pass);

        i = 0;
        while (i < TOTAL_USUARIOS) {
            if (strcmp(usuarios[i].usuario, usu) == 0 &&
                strcmp(usuarios[i].contrasena, pass) == 0) {
                return i;
            }
            i++;
        }

        intentos++;
        printf("\nDatos incorrectos. Le quedan %d intento(s).\n\n", 3 - intentos);
    }

    return -1;
}

void mostrar_menu() {
    printf("\n====================================\n");
    printf("           MENU PRINCIPAL           \n");
    printf("====================================\n");
    printf("  1. Ver saldo\n");
    printf("  2. Depositar\n");
    printf("  3. Retirar\n");
    printf("  4. Salir\n");
    printf("====================================\n");
}

void consultar_saldo(int idx) {
    printf("\n-- Saldo --\n");
    printf("Nombre : %s\n", usuarios[idx].nombre);
    printf("Saldo  : $ %.2f\n\n", usuarios[idx].saldo);
}

// funcion para depositar, le sumo el monto al saldo
void depositar(int idx) {
    double monto;

    printf("\n-- Deposito --\n");
    printf("Cuanto quiere depositar? $ ");
    scanf("%lf", &monto);

    // verifico que no metan un numero raro
    if (monto <= 0) {
        printf("El monto tiene que ser mayor a cero.\n\n");
        return;
    }

    usuarios[idx].saldo = usuarios[idx].saldo + monto;

    printf("Deposito realizado!\n");
    printf("Saldo nuevo: $ %.2f\n\n", usuarios[idx].saldo);
}

// funcion para retirar, verifico que haya plata antes de restar
void retirar(int idx) {
    double monto;

    printf("\n-- Retiro --\n");
    printf("Cuanto quiere retirar? $ ");
    scanf("%lf", &monto);

    if (monto <= 0) {
        printf("El monto tiene que ser mayor a cero.\n\n");
        return;
    }

    // si el monto es mayor al saldo no lo dejo retirar
    if (monto > usuarios[idx].saldo) {
        printf("No tiene suficiente saldo.\n");
        printf("Su saldo es: $ %.2f\n\n", usuarios[idx].saldo);
        return;
    }

    usuarios[idx].saldo = usuarios[idx].saldo - monto;

    printf("Retiro exitoso!\n");
    printf("Saldo nuevo: $ %.2f\n\n", usuarios[idx].saldo);
}
