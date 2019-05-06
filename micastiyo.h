// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;

struct Cuenta_Castiyo{
    int ID;
    char nombre_tmp[50];
    char apelldioPaterno_tmp[50];
    char apellidoMaterno_tmp[50];
    char fechaDNacimiento_tmp[11];
    char domicilio_tmp[250];
    char pais_tmp[50];
    char noDCuenta_tmp[50];
    int pinDCuenta_tmp;
    double estadoDCuenta_tmp;
    char bdActividades_temp[100];
    int _SESSION_;
    int posicionDDatos;
};

// Crear un usuario
struct Cuenta_Castiyo DatosCuenta;

void opciones_menu_principal();
void fnc_menu_iniciar_session();
void _verificar_cuenta_();
void _obtener_datos_de_la_cuenta_();

// FUNCIONES
void opciones_menu_principal(){
    
    if( DatosCuenta._SESSION_ == 1){
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apelldioPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Cerrar session"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("2 > Transferencia"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("3 > Deposito"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("4 > Retiro de deposito"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
    }else{
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Iniciar session"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
    }

}

void fnc_menu_iniciar_session(){

    do{
        
        BORRAR_LA_PANTALLA;
        
        if( DatosCuenta._SESSION_ == 0){
            TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
            TAB; printf("Iniciar session"); SALTO_DE_LINEA;
            SEPARADOR;
            DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
            SEPARADOR;

            // Capturar el no. de cuenta
            SALTO_DE_LINEA;
            fflush(stdin);
            TAB; printf("Introduzca tu NO. DE CUENTA: ");
            gets(DatosCuenta.noDCuenta_tmp);
        }else{
            strcpy(DatosCuenta.noDCuenta_tmp, "0");
        }
        
        if( strcmp( DatosCuenta.noDCuenta_tmp, "0" ) != 0 ){

            // Utentticacion
            int xPIN;
            fflush(stdin);
            TAB; printf("Introduzca tu PIN de la cuenta: ");
            scanf("%i", &xPIN);

            // Verificar la cuenta
            _verificar_cuenta_();

            if( DatosCuenta._SESSION_ == 0){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Fallo al inciar session!");SALTO_DE_LINEA;
                printf("El no. de cuenta no esta registrado");SALTO_DE_LINEA;
                printf("o verifique que tenga el siguiente formato: ");SALTO_DE_LINEA;
                printf("0521-X-XXXX-X");SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }else if( DatosCuenta.pinDCuenta_tmp != xPIN){
                DatosCuenta._SESSION_ = 0;
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Fallo al inciar session!"); SALTO_DE_LINEA;
                printf("El PIN introducido es incorrecto."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;                 
            }else{
                _obtener_datos_de_la_cuenta_();
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Inicio session correctamente!"); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA; 
            }
            
        }

    }while( strcmp( DatosCuenta.noDCuenta_tmp, "0" ) != 0 );

}

void _verificar_cuenta_(){
    char xCampos[250];
    int cantidad_usuarios, iFilas;

    FILE *bd_castiyo = fopen(".%%CASTIyO%%", "r");

    if( bd_castiyo == NULL){
        perror("Lo siento no tienen conexion con el banco");
        SALTO_DE_LINEA;
    }

    // Obtener la cantidad de usuarios registrados
    fgets(xCampos,250, bd_castiyo);
    strtok(xCampos,"#");
    cantidad_usuarios = atoi(xCampos);
    iFilas = cantidad_usuarios * 10;

    // Leer todas las lineas para confimar
    // que la cuenta existe
    int i;
    for(i=1; i <= iFilas; i++ ){
        
        fgets(xCampos, 250, bd_castiyo);
        strtok(xCampos, "~");
        
        if( strcmp(DatosCuenta.noDCuenta_tmp, xCampos) == 0){

            // Obtener PIN de la cuenta
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            DatosCuenta.pinDCuenta_tmp = atoi(xCampos);
            DatosCuenta._SESSION_ = 1;
            DatosCuenta.posicionDDatos = (i - 7) + 2;
            //printf("%i - %i\n", DatosCuenta.posicionDDatos, DatosCuenta.posicionDDatos + 9 );

            break;
        }

    }

    fclose(bd_castiyo);
}

void _obtener_datos_de_la_cuenta_(){
    FILE *bd_castiyo = fopen(".%%CASTIyO%%", "r");

    if( bd_castiyo == NULL){
        perror("Lo siento no existe el archivo");
        PAUSA;
    }

    char xCampos[250];
    int iFilas, cantidad_usuarios;
    fgets(xCampos, 250, bd_castiyo);
    strtok(xCampos,"#");
    cantidad_usuarios = atoi(xCampos);
    iFilas = cantidad_usuarios * 10;

    int i;
    for(i = 1; i <= iFilas; i++ ){
        if( i == DatosCuenta.posicionDDatos ){
            
            // Obtener el nombre
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.nombre_tmp,xCampos);

            // Obtener el apellido paterno
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.apelldioPaterno_tmp,xCampos);

            // Obtener el apellido materno
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.apellidoMaterno_tmp, xCampos);

            // Obtener la fecha
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.fechaDNacimiento_tmp, xCampos);

            // Obtener el domicilio
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.domicilio_tmp,xCampos);

            // Obtener el pais
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.pais_tmp, xCampos);

            // Obtener el no. de cuenta
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.noDCuenta_tmp, xCampos);

            // Obtener el PIN
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            DatosCuenta.pinDCuenta_tmp = atoi(xCampos);

            // Obtener el estado de cuenta
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            DatosCuenta.estadoDCuenta_tmp = atof(xCampos);

            // Obtener la base de datos de actividades
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.bdActividades_temp ,xCampos);

        }
    }

    fclose(bd_castiyo);
}