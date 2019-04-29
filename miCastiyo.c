#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "micastiyo.h"

int main(){
    
    do{
        BORRAR_LA_PANTALLA;
        opciones_menu_principal();
        SEPARADOR;

        // Seleccionar una opcion
        SALTO_DE_LINEA
        fflush(stdin); // Liberar el teclado
        TAB; printf("Seleccione una opcion > ");
        scanf("%c",&opc_menuPrincipal);

        switch (opc_menuPrincipal)
        {
            case '1':{
                if( inicio_de_session == 0 ){
                    fnc_menu_iniciar_session();
                }else{
                    BORRAR_LA_PANTALLA;
                    SEPARADOR;
                    printf("Cerrando sesion."); SALTO_DE_LINEA;
                    printf("Hasta luego:  %s %s %s",Datos.N_tmp, Datos.Ap_tmp, Datos.Am_tmp); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                    inicio_de_session = 0;
                }
            }break;

        }

    }while ( opc_menuPrincipal != '0');
    

    // Mostrar mensaje cuando sale del programa
    SALTO_DE_LINEA;
    SEPARADOR;
    printf("ESTAS FUERA DEL PROGRAMA"); SALTO_DE_LINEA;
    SALTO_DE_LINEA;
    system("pause");
    return 0;
}