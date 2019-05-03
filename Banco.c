// Subir (push) y Bajar (pull) commit  
// git remote add origin https://github.com/ProgrammerAuditore/simulador-de-banco-c.git
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "banco.h"


int main(){
    
    do{
        inicializar_programa();
        BORRAR_LA_PANTALLA;
        opciones_menu_principal(); // Mensajes
        SEPARADOR;

        // Capturar opcion
        fflush(stdin); // Liberar el teclado
        TAB; printf("Seleccione una opcion >");
        scanf("%c",&opc_menuPrincipal);

        switch (opc_menuPrincipal)
        {
            case '1':
            BORRAR_LA_PANTALLA;
            fnc_menu_crear_cuentas();
            break;

            case '2':
            BORRAR_LA_PANTALLA;
            fnc_menu_buscar_cuentas();
            break;
            
            case '3':
            BORRAR_LA_PANTALLA;
            fnc_menu_modificar_cuentas();
            break;

            case '4':
            BORRAR_LA_PANTALLA;
            fnc_menu_eliminar_cuentas();
            break;

            case '5':
            BORRAR_LA_PANTALLA;
            fnc_menu_ver_cuentas();
            break;

            case '6':
            BORRAR_LA_PANTALLA;
            fnc_transferencia_bancaria();
            break;

            case '7':
            BORRAR_LA_PANTALLA;
            fnc_deposito_de_cuentas();
            break;

            case '8':
            BORRAR_LA_PANTALLA;
            fnc_menu_retirar_deposito();
            break;
        }


    }while ( opc_menuPrincipal != '0');

    printf("Estas fuera del programa"); SALTO_DE_LINEA;
    getch();
    return 0;
}