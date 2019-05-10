// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

struct Cuenta_Castiyo{
    int ID;
    char nombre_tmp[50];
    char apellidoPaterno_tmp[50];
    char apellidoMaterno_tmp[50];
    char fechaDNacimiento_tmp[11];
    char domicilio_tmp[250];
    char pais_tmp[50];
    char noDCuenta_tmp[50];
    int pinDCuenta_tmp;
    double estadoDCuenta_tmp;
    char bdActividades_temp[250];
    int _SESSION_;
    int posicionDDatos;
};

// Crear un usuario
struct Cuenta_Castiyo DatosCuenta;

void _mostrar_datos_();
void opciones_menu_principal();
void fnc_menu_iniciar_session();
void fnc_menu_cerrar_session();
void fn_menu_ver_mis_datos();
void fnc_menu_transferencia();
void fnc_menu_deposito();
void fnc_menu_retiro_deposito();
void _verificar_mi_cuenta_();
void _obtener_mis_datos_de_la_cuenta_();
void _actualizar_mi_estado_de_cuenta_();
int _verificar_cuentas(char xCuenta[50]);
void _realizar_transaccion_(double deposito, int posicion);
void _ver_actividades_(char ctipo[10], char ctitulo[100]);
void _registrar_actividad_(char get_noDeCuenta[250],
int get_tipoProceso,
char get_remitente[250],
char get_Asunto[250],
char get_Descripcion[250]);

// FUNCIONES
void _mostrar_datos_(){
    TAB; printf("No. de cuenta: %s", DatosCuenta.noDCuenta_tmp); SALTO_DE_LINEA;
    TAB; printf("PIN: %i", DatosCuenta.pinDCuenta_tmp); SALTO_DE_LINEA;
    TAB; printf("Nombre: %s", DatosCuenta.nombre_tmp); SALTO_DE_LINEA;
    TAB; printf("Apellido paterno: %s", DatosCuenta.apellidoPaterno_tmp); SALTO_DE_LINEA;
    TAB; printf("Apellido materno: %s", DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
    TAB; printf("Fecha de nacimiento: %s", DatosCuenta.fechaDNacimiento_tmp); SALTO_DE_LINEA;
    TAB; printf("Domicilio: %s", DatosCuenta.domicilio_tmp); SALTO_DE_LINEA;
    TAB; printf("Pais: %s", DatosCuenta.pais_tmp); SALTO_DE_LINEA;
}

void opciones_menu_principal(){
    
    if( DatosCuenta._SESSION_ == 1){
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apellidoPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Cerrar session"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("2 > Ver mi datos"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("3 > Ver transferencias enviados"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("4 > Ver transferencias recibidos"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("5 > Ver depositos"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("6 > Ver retiro de depositos"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("7 > Ver mas actividades"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("8 > Transferencia"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("9 > Deposito"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("10 > Retiro de deposito"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
    }else{
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Iniciar session"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
    }

}

void fnc_menu_iniciar_session(){
    char opc_iniciarSession[50] = "0";

    do{
        
        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Iniciar session"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;
        SEPARADOR;

        // Capturar el no. de cuenta
        SALTO_DE_LINEA;
        fflush(stdin);
        TAB; printf("Introduzca tu NO. DE CUENTA: ");
        gets(opc_iniciarSession);
        
        if( strcmp( opc_iniciarSession, "0" ) != 0 ){
            
            strcpy( DatosCuenta.noDCuenta_tmp, opc_iniciarSession);
            
            // Utentticacion
            int xPIN;
            fflush(stdin);
            TAB; printf("Introduzca tu PIN de la cuenta: ");
            scanf("%i", &xPIN);

            // Verificar la cuenta
            _verificar_mi_cuenta_();

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
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Inicio session correctamente!"); SALTO_DE_LINEA;
                _obtener_mis_datos_de_la_cuenta_();
                SALTO_DE_LINEA;
                PAUSA;
                break;
            }
            
        }

    }while( strcmp( opc_iniciarSession, "0" ) != 0 );

}

void fnc_menu_cerrar_session(){
    BORRAR_LA_PANTALLA;
    SEPARADOR;
    printf("Cerrando sesion."); SALTO_DE_LINEA;
    SALTO_DE_LINEA;

    strcpy(DatosCuenta.nombre_tmp,"");
    strcpy(DatosCuenta.apellidoPaterno_tmp,"");
    strcpy(DatosCuenta.apellidoMaterno_tmp,"");
    strcpy(DatosCuenta.bdActividades_temp,"");
    strcpy(DatosCuenta.noDCuenta_tmp,"");
    strcpy(DatosCuenta.pais_tmp,"");
    strcpy(DatosCuenta.domicilio_tmp,"");
    strcpy(DatosCuenta.fechaDNacimiento_tmp,"");
    DatosCuenta.pinDCuenta_tmp = 0;
    DatosCuenta.estadoDCuenta_tmp = 0;
    DatosCuenta.posicionDDatos = 0;
    DatosCuenta._SESSION_ = 0;

    PAUSA;
}

void fnc_menu_transferencia(){
    double dTransferencia;
    do{
        if( DatosCuenta._SESSION_ == 1)
        _obtener_mis_datos_de_la_cuenta_();

        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apellidoPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
        DOBLE_TAB; printf(">>> Transferencia <<<"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("Instrucciones: "); SALTO_DE_LINEA;
        DOBLE_TAB; printf("La cantidad debe ser multiplo de 100."); SALTO_DE_LINEA;
        DOBLE_TAB; printf("La cuenta debe estar registrado."); SALTO_DE_LINEA;
        DOBLE_TAB; printf("Introducir su PIN para confirmar la transaccion."); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Volver la menu principal"); SALTO_DE_LINEA;
        SEPARADOR;

        SALTO_DE_LINEA;
        fflush(stdin);
        TAB; printf("Escribe la cantidad de la transferencia: $");
        scanf("%lf", &dTransferencia );

        if( dTransferencia != 0  && dTransferencia >= 100 ){
            
            fflush(stdin);
            char opc_transferencia[50];
            TAB; printf("Escribe la cuenta (destinatario): ");
            gets(opc_transferencia);

            fflush(stdin);
            int xPIN;
            TAB; printf("Escribe el PIN para confirmar: ");
            scanf("%i", &xPIN);


            int getPosicion = _verificar_cuentas( opc_transferencia );

            if( strcmp(opc_transferencia, DatosCuenta.noDCuenta_tmp) == 0){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, la cuenta son identicas."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }else if( getPosicion < 1 ){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, la cuenta no esta registrado."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }else if( ( (int) dTransferencia % 100) != 0 ){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, la cantidad de transferencia son incorrectos."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }else if( DatosCuenta.estadoDCuenta_tmp < dTransferencia ){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, no tiene fondo suficiente."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }else if(xPIN != DatosCuenta.pinDCuenta_tmp){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, PIN incorrecto."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }else{

                // Mostrar datos de la tranferencia
                SALTO_DE_LINEA;
                TAB; printf("Transferido: %.2lf", dTransferencia); SALTO_DE_LINEA;
                TAB; printf("Sub-total: %.2lf - %.2lf",DatosCuenta.estadoDCuenta_tmp, dTransferencia); SALTO_DE_LINEA;
                TAB; printf("Total: %.2lf",DatosCuenta.estadoDCuenta_tmp - dTransferencia); SALTO_DE_LINEA; 
                
                SALTO_DE_LINEA;
                SEPARADOR;        
                char xDescripcion[250], xAsunto[250]; 
                // Registros del destinario
                sprintf(xAsunto, "Transferencia recibido: %s", DatosCuenta.noDCuenta_tmp);
                sprintf(xDescripcion, "Monto: (+) $%.2lf", dTransferencia);
                _realizar_transaccion_(dTransferencia, getPosicion);
                _registrar_actividad_(opc_transferencia, 302, "Banco: CASTIyO", xAsunto, xDescripcion);

                // Registros del remitente
                DatosCuenta.estadoDCuenta_tmp -= dTransferencia;    
                sprintf(xAsunto, "Transferencia enviado: %s", opc_transferencia);
                sprintf(xDescripcion, "Monto: (-) $%.2lf", dTransferencia);
                _actualizar_mi_estado_de_cuenta_();
                _registrar_actividad_( DatosCuenta.noDCuenta_tmp, 301, "Banco: CASTIyO", xAsunto, xDescripcion);

                printf("La solicitud se realizo con exito.");
                SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }
            PAUSA;
        }

    }while( dTransferencia != 0 );
}

void fnc_menu_deposito(){
    double opc_deposito;
    do{
        if( DatosCuenta._SESSION_ == 1)
        _obtener_mis_datos_de_la_cuenta_();

        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apellidoPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
        DOBLE_TAB; printf(">>> Deposito <<<"); SALTO_DE_LINEA;
        SEPARADOR;

        SALTO_DE_LINEA;
        fflush(stdin);
        TAB; printf("Cuanto desea depositar?: $");
        scanf("%lf", &opc_deposito);

        if( (int) opc_deposito != 0 &&
            ((int)opc_deposito % 100) == 0 &&
            opc_deposito >= 100 ){
            
            int xPIN;
            TAB; printf("Introduzca el PIN: ");
            scanf("%i", &xPIN);

            if( DatosCuenta.pinDCuenta_tmp != xPIN){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, PIN incorrecto."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }else{

                // Mostrar datos del deposito
                SALTO_DE_LINEA;
                TAB; printf("Importe: %.2lf", opc_deposito); SALTO_DE_LINEA;
                TAB; printf("Sub-total: %.2lf + %.2lf",DatosCuenta.estadoDCuenta_tmp, opc_deposito); SALTO_DE_LINEA;
                TAB; printf("Total: %.2lf",DatosCuenta.estadoDCuenta_tmp + opc_deposito); SALTO_DE_LINEA;

                SALTO_DE_LINEA;
                SEPARADOR;
                
                // Registrar deposito
                DatosCuenta.estadoDCuenta_tmp += opc_deposito;
                char xDescripcion[250];
                sprintf(xDescripcion,"Monto: (+) $%.2lf",opc_deposito);
                _actualizar_mi_estado_de_cuenta_();
                _registrar_actividad_(DatosCuenta.noDCuenta_tmp, 200, "Banco: CASTIyO", "Deposito: Solicitud aprobada", xDescripcion);
                printf("La solicitud se realizo con exito."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;

            }
        }

    }while( (int) opc_deposito != 0 );

}

void fnc_menu_retiro_deposito(){
    double opc_retiro_deposito;
    do{
        if( DatosCuenta._SESSION_ == 1)
        _obtener_mis_datos_de_la_cuenta_();

        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apellidoPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
        DOBLE_TAB; printf(">>> Retiro de deposito <<<"); SALTO_DE_LINEA;
        SEPARADOR;

        SALTO_DE_LINEA;
        fflush(stdin);
        TAB; printf("Cuanto desea retirar?: $");
        scanf("%lf", &opc_retiro_deposito);

        if( (int)opc_retiro_deposito != 0 &&
            ((int)opc_retiro_deposito % 100) == 0 &&
            opc_retiro_deposito >= 100 ){
            
            int xPIN;
            TAB; printf("Introduzca el PIN: ");
            scanf("%i", &xPIN);

            if( opc_retiro_deposito > DatosCuenta.estadoDCuenta_tmp ){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, no tiene fondo suficiente."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }else if( DatosCuenta.pinDCuenta_tmp != xPIN){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, PIN incorrecto."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }else{
                
                // Mostrar datos del deposito
                SALTO_DE_LINEA;
                TAB; printf("Retiro: %.2lf", opc_retiro_deposito); SALTO_DE_LINEA;
                TAB; printf("Sub-total: %.2lf - %.2lf",DatosCuenta.estadoDCuenta_tmp, opc_retiro_deposito); SALTO_DE_LINEA;
                TAB; printf("Total: %.2lf",DatosCuenta.estadoDCuenta_tmp - opc_retiro_deposito); SALTO_DE_LINEA;

                SALTO_DE_LINEA;
                SEPARADOR;

                // Registrar retiro de deposito
                DatosCuenta.estadoDCuenta_tmp -= opc_retiro_deposito;
                char xDescripcion[250];
                sprintf(xDescripcion,"Monto: (-) $%.2lf",opc_retiro_deposito);
                _actualizar_mi_estado_de_cuenta_();
                _registrar_actividad_(DatosCuenta.noDCuenta_tmp, 400, "Banco: CASTIyO", "Retiro deposito: Solicitud aprobada", xDescripcion);
                printf("La solicitud se realizo con exito."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }
        }

    }while( (int) opc_retiro_deposito != 0 );

}

void _ver_actividades_(char ctipo[10], char ctitulo[100]){
    char opc_proceso;
    int Resultado;
    do{
        if( DatosCuenta._SESSION_ == 1)
        _obtener_mis_datos_de_la_cuenta_();

        Resultado = 0;
        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        printf("Bienvenido: %s %s %s",
        DatosCuenta.nombre_tmp,
        DatosCuenta.apellidoPaterno_tmp,
        DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
        printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
        DOBLE_TAB; printf(">>> %s <<<",ctitulo); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
        SEPARADOR;
        SALTO_DE_LINEA;
        
        FILE *bd_actividades = fopen(DatosCuenta.bdActividades_temp,"r");
        char xCampos[250];
        int cantidad_actividades, iFilas;

        fgets(xCampos, 250, bd_actividades);
        strtok(xCampos, "~");
        cantidad_actividades = atoi(xCampos);
        iFilas = cantidad_actividades * 6;

        int i;
        for( i=1; i <= iFilas; i++){
            fgets(xCampos, 250, bd_actividades);
            strtok(xCampos, "~");
            if( strcmp(xCampos, ctipo) == 0 ){
                
                // Obtener la fecha
                fgets(xCampos, 250, bd_actividades);
                strtok( xCampos, "~");
                printf("Fecha: %s\n",xCampos);

                // Obtener la remitente
                fgets(xCampos, 250, bd_actividades);
                strtok( xCampos, "~");
                printf("%s\n",xCampos);

                // Obtener la asunto
                fgets(xCampos, 250, bd_actividades);
                strtok( xCampos, "~");
                printf("%s\n",xCampos);

                // Obtener la descripcion
                fgets(xCampos, 250, bd_actividades);
                strtok( xCampos, "~");
                printf("%s\n",xCampos);

                // Obtener el separador
                fgets(xCampos, 250, bd_actividades);
                printf("\n");

                Resultado = Resultado + 1; 
            } 
        }
        fclose(bd_actividades);
        
        if( Resultado == 0){
            TAB; printf("No tiene registros aun."); SALTO_DE_LINEA;
        }

        SALTO_DE_LINEA;
        fflush(stdin);
        TAB; printf("Selecciona una opcion > ");
        scanf("%c",&opc_proceso);

    }while( opc_proceso != '0' );

}

void _verificar_mi_cuenta_(){
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
            DatosCuenta.posicionDDatos = i - 6;

            break;
        }

    }

    fclose(bd_castiyo);
}

void _obtener_mis_datos_de_la_cuenta_(){
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
    if( DatosCuenta.posicionDDatos > 1)
    DatosCuenta.posicionDDatos -= 1;

    for(i = 1; i <= iFilas; i++ ){

        if( DatosCuenta.posicionDDatos > 1)
            fgets(xCampos, 250, bd_castiyo); 

        if( DatosCuenta.posicionDDatos == i ){
            
            // Obtener el nombre
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.nombre_tmp,xCampos);

            // Obtener el apellido paterno
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos, "~");
            strcpy(DatosCuenta.apellidoPaterno_tmp,xCampos);

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

            break;
        }
    }

    if( DatosCuenta.posicionDDatos > 1)
    DatosCuenta.posicionDDatos += 1;

    fclose(bd_castiyo);
}

int _verificar_cuentas(char xCuenta[50]){
    FILE *bd_castiyo = fopen(".%%CASTIYO%%","r");
    char xCampos[250];
    int cantidad_usuarios, iFilas, iExiste = 0;
    fgets(xCampos, 250, bd_castiyo);
    strtok(xCampos, "#");
    cantidad_usuarios = atoi(xCampos);
    iFilas = cantidad_usuarios * 10; 

    int i;
    for(i = 1; i <= iFilas; i++ ){
        fgets( xCampos,250, bd_castiyo);
        strtok(xCampos,"~");
        if( strcmp(xCuenta , xCampos) == 0){
            iExiste = i;
            break;
        }else{
            iExiste = 0;
        }
    }    
    fclose(bd_castiyo);

    if( iExiste > 1)
        return iExiste;
    else
        return 0;
}

void _realizar_transaccion_(double deposito, int posicion){
    FILE *bd_castiyo = fopen(".%%CASTIyO%%", "rw+");
    char xCampos[250], sbufferINT[250];
    int iBuffer, bufferOUT, bufferINT;
    double estadoDCuenta;
    
    // Obtener cantidad de usuarios registrados
    fgets(xCampos, 250, bd_castiyo);

    int i;
    for( i = 1; i <= (posicion+2); i++ ){
        fgets(xCampos, 250, bd_castiyo);
        iBuffer = ftell(bd_castiyo) - 2;
    }

    bufferOUT = strlen(xCampos) - 1;
    strtok( xCampos, "~");
    estadoDCuenta = atof(xCampos);
    sprintf(sbufferINT, "%.2lf~ Deposito: No borrar, ni modificar",
    deposito + estadoDCuenta );
    bufferINT = strlen(sbufferINT);

    fseek( bd_castiyo, (iBuffer - bufferOUT), SEEK_SET );
    if( bufferINT >= bufferOUT ){
        strcat(sbufferINT, "\n");
        fputs(sbufferINT, bd_castiyo);
    }else{
        int iBufferFaltante = bufferOUT - bufferINT;
        for(i = 1; i <= iBufferFaltante; i++){
            strcat(sbufferINT, "*");
        }
        strcat( sbufferINT,"\n");
        fputs(sbufferINT, bd_castiyo);
    }

    fclose(bd_castiyo);

}

void fn_menu_ver_mis_datos(){ 
    
    if( DatosCuenta._SESSION_ == 1)
    _obtener_mis_datos_de_la_cuenta_();

    BORRAR_LA_PANTALLA;
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    printf("Bienvenido: %s %s %s",
    DatosCuenta.nombre_tmp,
    DatosCuenta.apellidoPaterno_tmp,
    DatosCuenta.apellidoMaterno_tmp); SALTO_DE_LINEA;
    printf("Estado de cuenta: %.2lf", DatosCuenta.estadoDCuenta_tmp); SALTO_DE_LINEA;
    DOBLE_TAB; printf(">>> Mis datos <<<"); SALTO_DE_LINEA;
    SEPARADOR;
    _mostrar_datos_();
    SEPARADOR;
    SALTO_DE_LINEA;
    PAUSA;
}

void _actualizar_mi_estado_de_cuenta_(){
    FILE *bd_castiyo = fopen(".%%CASTIyO%%", "rw+");
    char xCampos[250], sbufferINT[250];
    int iBuffer, bufferOUT, bufferINT;
    
    // Obtener cantidad de usuarios registrados
    fgets(xCampos, 250, bd_castiyo);

    int i;
    for( i = 1; i <= (DatosCuenta.posicionDDatos+8); i++ ){
        fgets(xCampos, 250, bd_castiyo);
        iBuffer = ftell(bd_castiyo) - 2;
    }

    bufferOUT = strlen(xCampos) - 1;
    sprintf(sbufferINT, "%.2lf~ Deposito: No borrar, ni modificar",
    DatosCuenta.estadoDCuenta_tmp);
    bufferINT = strlen(sbufferINT);

    fseek( bd_castiyo, (iBuffer - bufferOUT), SEEK_SET );
    if( bufferINT >= bufferOUT ){
        strcat(sbufferINT, "\n");
        fputs(sbufferINT, bd_castiyo);
    }else{
        int iBufferFaltante = bufferOUT - bufferINT;
        for(i = 1; i <= iBufferFaltante; i++){
            strcat(sbufferINT, "*");
        }
        strcat( sbufferINT,"\n");
        fputs(sbufferINT, bd_castiyo);
    }

    fclose(bd_castiyo);
}

void _registrar_actividad_( char get_noDeCuenta[250],
int get_tipoProceso,
char get_remitente[250],
char get_Asunto[250],
char get_Descripcion[250]){
    
    char xCampos[250], nombreFILE[250];
    int iBuffer, iFilas, cantidad_actividades;

    // Nombre de la base de datos
    sprintf(nombreFILE,"%%%%reg/.%%%%%s", get_noDeCuenta);

    // Obtener la fecha
    char xFecha[100]; time_t f; time(&f);
    sprintf(xFecha, "%s", ctime(&f));
    strtok(xFecha, "\n");

    FILE *bd_actividades = fopen(nombreFILE, "rw+");

    fgets(xCampos,250, bd_actividades);
    strtok(xCampos, "#");
    cantidad_actividades = atoi(xCampos);
    iFilas = cantidad_actividades * 6;

    int i;
    for(i = 0; i <= iFilas; i++ ){
        fgets(xCampos, 250, bd_actividades);
        iBuffer = ftell(bd_actividades);
    }
     // Registrar cantidad de actividades
    cantidad_actividades++;
    rewind(bd_actividades);
    sprintf(xCampos,"%i#", cantidad_actividades);
    fputs(xCampos, bd_actividades);

    fseek( bd_actividades, iBuffer, SEEK_SET );
    
    // Registrar tipo de proceso
    sprintf(xCampos,"%i~ : No borrar, ni modificar\n", get_tipoProceso);
    fputs(xCampos, bd_actividades);
    
    // Registrar fecha
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", xFecha);
    fputs(xCampos, bd_actividades);

    // Registrar remitente
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", get_remitente);
    fputs(xCampos, bd_actividades);

    // Registrar asunto
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", get_Asunto);
    fputs(xCampos, bd_actividades);

    // Registrar descripcion
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", get_Descripcion);
    fputs(xCampos, bd_actividades);

    // Registrar separacion
    fputs("###############################################################\n", bd_actividades);

    fclose(bd_actividades);
}