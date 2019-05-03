// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;
int inicio_de_session = 0;

struct Usuarios{
    int ID;
    char N_tmp[50];
    char Ap_tmp[50];
    char Am_tmp[50];
    char Fn_tmp[11];
    char D_tmp[250];
    char P_tmp[50];
    int Dep_tmp;
};

// Crear un usuario
struct Usuarios Datos;


void opciones_menu_principal();
void fnc_menu_iniciar_session();

// FUNCIONES
void opciones_menu_principal(){
    
    // Titulo
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    SEPARADOR;
    
    // Mostrar opciones distintos
    if( inicio_de_session != 0 ){
        DOBLE_TAB; printf("1 > Cerrar Session"); SALTO_DE_LINEA;
    }else{
        DOBLE_TAB; printf("1 > Iniciar Session"); SALTO_DE_LINEA;
    }

    // Deshabilitar opcines miestras usuarios sean 0
    if( inicio_de_session != 0 ){
        DOBLE_TAB; printf("2 > Transferencia"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("3 > Deposito"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("4 > Retiro de deposito"); SALTO_DE_LINEA;
    }

    // Opcion para salir
    DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;

}

void fnc_menu_iniciar_session(){
    int buscar_x_id;

    do{
        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Iniciar session"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
        SEPARADOR;

        if( inicio_de_session == 0 ){
        // Seleccionar una opcion
        SALTO_DE_LINEA;
        fflush(stdin); // Liberar el teclado
        TAB; printf("Introduzca el ID de la cuenta > ");
        scanf("%i",&buscar_x_id);
        }else{ buscar_x_id = 0; }
        
        if( buscar_x_id > 0 ){
            SALTO_DE_LINEA;
            printf("Iniciando Session");
            FILE *archivo = fopen(".%%CASTIyO%%","r");
            
            if( archivo == NULL){
                perror("Lo siento, no existe el archvio");
                exit(1);
            }

            char xCampos[250];
            int cantidad_cuentas;

            // Leer la primera linea
            fgets(xCampos,250,archivo);
            strtok(xCampos,"#");
            cantidad_cuentas = atoi(xCampos);

            if( cantidad_cuentas > 0){

                int i;
                // Buscando cuenta
                for( i = 1; i <= cantidad_cuentas; i++ ){
                    
                    // Obtener id de cuentas
                    // en la base de datos
                    fgets(xCampos,250,archivo);
                    strtok(xCampos,"~");
                    
                    // Iniciar session si existe la cuenta
                    if( atoi(xCampos) == buscar_x_id ){
                        inicio_de_session = atoi(xCampos);
                        
                        // Obtener el nombre
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.N_tmp,xCampos);

                        // Obtener apellido paterno
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.Ap_tmp,xCampos);

                        // Obtener apellido materno
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.Am_tmp,xCampos);

                        // Obtener fecha de nacimiento
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.Fn_tmp,xCampos);

                        // Obtener domicilio
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.D_tmp,xCampos);

                        // Obtener Pais
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        strcpy(Datos.P_tmp,xCampos);

                        // Obtener deposito
                        fgets(xCampos,250,archivo);
                        strtok(xCampos,"~");
                        Datos.Dep_tmp = atoi(xCampos);

                        // Obtener el separador
                        fgets(xCampos,250,archivo);
                        break;
                    }else{
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                        fgets(xCampos,250,archivo);
                    }
                }

                if( inicio_de_session != 0){
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Inicio de session exitosa."); SALTO_DE_LINEA;
                    printf("Bienvenido %s %s %s", Datos.N_tmp, Datos.Ap_tmp, Datos.Am_tmp); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }else{
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, fallo al iniciar session."); SALTO_DE_LINEA;
                    printf("Vuelva intentarlo mas tarde o"); SALTO_DE_LINEA;
                    printf("Verifique que la cuenta este registrado."); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }
            }else{
                printf("Lo siento, la base de datos no tiene registro.");
            }

            fclose(archivo);
        }


    }while( buscar_x_id != 0);
}