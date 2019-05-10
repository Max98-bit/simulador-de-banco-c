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
        SALTO_DE_LINEA;
        fflush(stdin); // Liberar el teclado
        TAB; printf("Seleccione una opcion > ");
        scanf("%c",&opc_menuPrincipal);

        switch (opc_menuPrincipal)
        {
            case '1':{
                if( DatosCuenta._SESSION_ == 1 )
                    fnc_menu_cerrar_session();
                else
                    fnc_menu_iniciar_session();
            }break;

            case '2':{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_mis_datos();
            }break;

            case '3':{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_transferencias_enviados();
            }break;

            case '4':{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_transferencias_recibidos();
            }break;

            case '5':{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_depositos();
            }break;

            case '6':{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_retiro_de_depositos();
            }break;

            case '7':{
                if( DatosCuenta._SESSION_ == 1)
                fnc_menu_transferencia();

            }break;

            case '8':{
                if( DatosCuenta._SESSION_ == 1)
                fnc_menu_deposito();
            }break;

            case '9':{
                if( DatosCuenta._SESSION_ == 1 )
                fnc_menu_retiro_deposito();
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