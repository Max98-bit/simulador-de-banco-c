#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <time.h>
#include "micastiyo.h"

int main(){
    char opc_menuPrincipal[3];
    
    do{
        if( DatosCuenta._SESSION_ == 1)
        _obtener_mis_datos_de_la_cuenta_();

        BORRAR_LA_PANTALLA;
        opciones_menu_principal();
        SEPARADOR;

        // Seleccionar una opcion
        SALTO_DE_LINEA;
        fflush(stdin); // Liberar el teclado
        TAB; printf("Seleccione una opcion > ");
        gets(opc_menuPrincipal);

        switch (atoi(opc_menuPrincipal))
        {
            case 1:{
                if( DatosCuenta._SESSION_ == 1 )
                    fnc_menu_cerrar_session();
                else
                    fnc_menu_iniciar_session();
            }break;

            case 2:{
                if( DatosCuenta._SESSION_ == 1)
                    fn_menu_ver_mis_datos();
            }break;

            case 3:{
                if( DatosCuenta._SESSION_ == 1)
                    _ver_actividades_("301", "Ver transacciones enviados");
            }break;

            case 4:{
                if( DatosCuenta._SESSION_ == 1)
                    _ver_actividades_("302", "Ver transacciones recibidos");
            }break;

            case 5:{
                if( DatosCuenta._SESSION_ == 1)
                    _ver_actividades_("200", "Ver depositos");
            }break;

            case 6:{
                if( DatosCuenta._SESSION_ == 1)
                    _ver_actividades_("400","Ver retiro de deposito");
            }break;

            case 7:{
                if( DatosCuenta._SESSION_ == 1)
                    _ver_actividades_("101","Ver mas actividades");

            }break;

            case 8:{
                if( DatosCuenta._SESSION_ == 1)
                fnc_menu_transferencia();

            }break;

            case 9:{
                if( DatosCuenta._SESSION_ == 1)
                fnc_menu_deposito();
            }break;

            case 10:{
                if( DatosCuenta._SESSION_ == 1 )
                fnc_menu_retiro_deposito();
            }break;

        }

    }while (  strcmp( opc_menuPrincipal, "0") !=  0);
    

    // Mostrar mensaje cuando sale del programa
    SALTO_DE_LINEA;
    SEPARADOR;
    printf("ESTAS FUERA DEL PROGRAMA"); SALTO_DE_LINEA;
    SALTO_DE_LINEA;
    system("pause");
    return 0;
}