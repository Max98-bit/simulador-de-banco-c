#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "sos.h"

int main(){
    
    do{
        BORRAR_LA_PANTALLA;
        opciones_menu_principal();

        // Seleccionar una opcion
        SALTO_DE_LINEA;
        fflush(stdin); // Liberar teclado
        TAB; printf("Seleccione una opcion > ");
        scanf("%c",&opc_menuPrincipal);

        switch (opc_menuPrincipal)
        {
            case '1':
                BORRAR_LA_PANTALLA;
                fnc_menu_comprar();
            break;
        }

    }while( opc_menuPrincipal != '0' );

    return 0;
}