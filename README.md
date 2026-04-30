 # Cajero Automatico Digital

Este programa simula un cajero automatico básico hecho en C.

---

## ¿Que hace el programa?

El usuario inicia sesion con su nombre de usuario y contraseña. Si los datos son correctos puede ver su saldo, depositar o retirar dinero. Si los datos son incorrectos no puede entrar.

---

## Funciones que tiene

- Inicio de sesion con usuario y contraseña
- Ver saldo disponible
- Depositar dinero
- Retirar dinero (verifica que haya saldo)
- Salir del sistema

---

## Mejora que agregue

Le puse un limite de 3 intentos al inicio de sesion. Si el usuario falla 3 veces el sistema se cierra. Esto lo hice porque en un cajero real no te dejan intentar infinitas veces, es una medida de seguridad básica.

---

## Como compilar y ejecutar

```bash
gcc cajero.c -o cajero
./cajero
```

En Windows:
```bash
gcc cajero.c -o cajero
cajero.exe
```

---

## Usuarios de prueba

| Usuario | Contraseña | Saldo |
|---------|-----------|-------|
| admin   | 1234      | $15,000.00 |
| maria   | abcd      | $8,500.50  |
| pedro   | pass1     | $3,200.75  |
| lucia   | lucia9    | $21,000.00 |
| juan    | juan01    | $500.00    |
