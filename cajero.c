// Proyecto: Cajero Automatico Digital
// Lenguaje: C
// Descripcion: simula un cajero con login, saldo, deposito y retiro
//
// Mejora que agregue: limite de 3 intentos en el login.
// Si el usuario falla 3 veces el sistema se cierra.
// Lo hice porque en los cajeros reales tampoco te dejan
// intentar infinitas veces, es una medida de seguridad.

#include <stdio.h>
#include <string.h>

// numero total de usuarios del sistema
#define TOTAL_USUARIOS 5

// estructura para guardar la info de cada usuario
struct Usuario {
    char usuario[30];    // nombre de usuario para entrar
    char contrasena[30]; // contraseña
    char nombre[50];     // nombre completo
    double saldo;        // dinero disponible
};

// arreglo con los usuarios que tiene el sistema
struct Usuario usuarios[TOTAL_USUARIOS] = {
    {"admin", "1234",   "Carlos Martinez", 15000.00},
    {"maria", "abcd",   "Maria Gonzalez",   8500.50},
    {"pedro", "pass1",  "Pedro Jimenez",    3200.75},
    {"lucia", "lucia9", "Lucia Ramirez",   21000.00},
    {"juan",  "juan01", "Juan Herrera",      500.00}
};

// prototipos de las funciones
int  iniciar_sesion();
void mostrar_menu();
void consultar_saldo(int idx);
void depositar(int idx);
void retirar(int idx);

// funcion principal, controla todo el flujo del programa
int main() {
    int idx;     // guarda cual usuario inicio sesion
    int opcion;  // guarda la opcion que elige el usuario

    // pantalla de inicio
    printf("====================================\n");
    printf("     CAJERO AUTOMATICO DIGITAL      \n");
    printf("====================================\n\n");

    // pedir login
    idx = iniciar_sesion();

    // si el login fallo, cerrar el programa
    if (idx == -1) {
        printf("Acceso denegado.\n");
        return 0;
    }

    printf("\nBienvenido %s!\n", usuarios[idx].nombre);

    // mostrar el menu en un bucle hasta que el usuario salga
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

// funcion de inicio de sesion
// busca al usuario en el arreglo y compara la contraseña
// retorna el indice si entro bien, -1 si fallo 3 veces
int iniciar_sesion() {
    char usu[30];
    char pass[30];
    int i;
    int intentos = 0;

    // maximo 3 intentos (mejora de seguridad)
    while (intentos < 3) {
        printf("Usuario   : ");
        scanf("%s", usu);
        printf("Contrasena: ");
        scanf("%s", pass);

        // recorro el arreglo buscando el usuario
        i = 0;
        while (i < TOTAL_USUARIOS) {
            if (strcmp(usuarios[i].usuario, usu) == 0 &&
                strcmp(usuarios[i].contrasena, pass) == 0) {
                return i; // encontre al usuario, retorno su indice
            }
            i++;
        }

        // si llego aqui es porque no coincidio ninguno
        intentos++;
        printf("\nDatos incorrectos. Le quedan %d intento(s).\n\n", 3 - intentos);
    }

    return -1; // se acabaron los intentos
}

// muestra las opciones disponibles
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

// muestra el saldo actual del usuario
void consultar_saldo(int idx) {
    printf("\n-- Saldo --\n");
    printf("Nombre : %s\n", usuarios[idx].nombre);
    printf("Saldo  : $ %.2f\n\n", usuarios[idx].saldo);
}

// agrega dinero al saldo del usuario
void depositar(int idx) {
    double monto;

    printf("\n-- Deposito --\n");
    printf("Cuanto quiere depositar? $ ");
    scanf("%lf", &monto);

    // el monto tiene que ser positivo
    if (monto <= 0) {
        printf("El monto tiene que ser mayor a cero.\n\n");
        return;
    }

    // sumo el monto al saldo
    usuarios[idx].saldo = usuarios[idx].saldo + monto;

    printf("Deposito realizado!\n");
    printf("Saldo nuevo: $ %.2f\n\n", usuarios[idx].saldo);
}

// retira dinero del saldo, verifica que haya suficiente
void retirar(int idx) {
    double monto;

    printf("\n-- Retiro --\n");
    printf("Cuanto quiere retirar? $ ");
    scanf("%lf", &monto);

    if (monto <= 0) {
        printf("El monto tiene que ser mayor a cero.\n\n");
        return;
    }

    // verifico que tenga saldo suficiente antes de restar
    if (monto > usuarios[idx].saldo) {
        printf("No tiene suficiente saldo.\n");
        printf("Su saldo es: $ %.2f\n\n", usuarios[idx].saldo);
        return;
    }

    // resto el monto del saldo
    usuarios[idx].saldo = usuarios[idx].saldo - monto;

    printf("Retiro exitoso!\n");
    printf("Saldo nuevo: $ %.2f\n\n", usuarios[idx].saldo);
}
