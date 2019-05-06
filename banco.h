// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;
int contadorID=0;

struct Registros{
    int ID;
    char Nombre[50];
    char Apellido_paterno[50];
    char Apellido_materno[50];
    char Fecha_de_nacimiento[11];
    char Domicilio[250];
    char Pais[50];
    double Deposito;
    char No_cuenta[50];
    int Pin_cuenta;
    char file_act[50];
}Usuarios[50];

void inicializar_programa();
void fnc_mostrar_datos_de_usuarios(int i);
void opciones_menu_principal();
void fnc_menu_crear_cuentas();
void fnc_menu_buscar_cuentas();
void fnc_menu_modificar_cuentas();
void fnc_menu_eliminar_cuentas();
void fnc_menu_ver_cuentas();
void fnc_menu_retirar_deposito();
void fnc_transferencia_bancaria();
void fnc_deposito_de_cuentas();
void crear_bd_actividades(int id_cuenta);
void _generador_de_cuenta_(int id_cuenta);
void _registrar_actividad_(int id_cuenta,char cAsunto[200], char cDescripcion[200], int tipoDeOperacion);
void actualizar_base_de_datos();

// TIPOS DE ACTIVIDADES
// 100 - Cuenta creado
// 101 - Compra
// 200 - Deposito
// 301 - Transferencia enviado
// 302 - Transferencia recibido
// 400 - Retiro de deposito

// FUNCIONES 
void fnc_mostrar_datos_de_usuarios(int i){
    SEPARADOR;
    TAB; printf("Usuario (ID): %i",Usuarios[i].ID);
        SALTO_DE_LINEA;
    TAB; printf("No. Cuenta: %s",Usuarios[i].No_cuenta);
        SALTO_DE_LINEA;
    TAB; printf("PIN: ******");
        SALTO_DE_LINEA;
    TAB; printf("Nombre: %s",Usuarios[i].Nombre);
        SALTO_DE_LINEA;
    TAB; printf("Apellido paterno: %s",Usuarios[i].Apellido_paterno);
        SALTO_DE_LINEA;
    TAB; printf("Apellido materno: %s",Usuarios[i].Apellido_materno);
        SALTO_DE_LINEA;
    TAB; printf("Fecha de nacimiento: %s",Usuarios[i].Fecha_de_nacimiento);
        SALTO_DE_LINEA;
    TAB; printf("Domicilio: %s",Usuarios[i].Domicilio);
        SALTO_DE_LINEA;
    TAB; printf("Pais: %s",Usuarios[i].Pais);
        SALTO_DE_LINEA;
    TAB; printf("Estado de cuenta: $%.2lf",Usuarios[i].Deposito);
        SALTO_DE_LINEA;
    //TAB; printf("mi archivo: >> %s <<",Usuarios[i].file_act);
    //  SALTO_DE_LINEA;
}

void opciones_menu_principal(){
    TAB; printf("BANKO CASTIyO \\(*__*)/");                     SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("1 > Crear cuentas");                     SALTO_DE_LINEA;
    
    // Deshabilitar opcines miestras usuarios sean 0
    if( contadorID != 0 ){
        DOBLE_TAB; printf("2 > Buscar cuentas");                    SALTO_DE_LINEA;
        DOBLE_TAB; printf("3 > Modificar cuentas");                 SALTO_DE_LINEA;
        DOBLE_TAB; printf("4 > Eliminar cuentas");                  SALTO_DE_LINEA;
        DOBLE_TAB; printf("5 > Ver cuentas (%i)",contadorID);       SALTO_DE_LINEA;
        DOBLE_TAB; printf("6 > Transferencia");                     SALTO_DE_LINEA;
        DOBLE_TAB; printf("7 > Deposito");                          SALTO_DE_LINEA;
        DOBLE_TAB; printf("8 > Retiro de deposito");                SALTO_DE_LINEA;
        //DOBLE_TAB; printf("9 > Borrar base de datos");              SALTO_DE_LINEA;
    }

    DOBLE_TAB; printf("0 > Salir del programa");                SALTO_DE_LINEA;
}

void fnc_menu_crear_cuentas(){
    inicializar_programa();
    contadorID++;
    char c_campos[50];
    int i, campos_correcto = 0;

    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Crer cuentas"); SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("Nota:"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Los depositos deben ser multiplos de 100"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("es decir, de $100 en $100."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("El formate de la fecha de nacimiento es dd/mm/aaaa."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
    SEPARADOR;

    // Capturar nombre [...]
    SALTO_DE_LINEA;
    fflush(stdin); // Liberar teclado
    TAB; printf("Nombre: ");  gets(c_campos);
    // Volver al menu principal
    if( strcmp(c_campos,"0")  != 0 && atoi(c_campos) == 0 && strlen(c_campos) > 0){
    // [...] Capturar nombre
        campos_correcto++;
        strcpy(Usuarios[contadorID].Nombre, c_campos);
    SALTO_DE_LINEA;
    
    // Capturar apellido paterno
    fflush(stdin); // Liberar teclado
    TAB; printf("Apellido paterno: "); gets(c_campos);
    if( strcmp(c_campos,"0") != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Apellido_paterno, c_campos);
    }else{
        TAB; printf("**Apellido paterno incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar apellido materno
    fflush(stdin); // Liberar teclado
    TAB; printf("Apellido materno: "); gets(c_campos);
    if( strcmp(c_campos,"0")  != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Apellido_materno,c_campos);
    }else{
        TAB; printf("**Apellido materno incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar la fecha de nacimiento
    fflush(stdin);
    TAB; printf("Fecha de nacimiento: "); gets(c_campos);
    int cantidad_de_Separadores = 0;
    int cantidad_de_Letras = strlen(c_campos);
    int cantidad_de_Numeros = 0;
    
    // Buscar 2 separadores (/) de la fecha de nacimiento
    for( i = 0; i <= cantidad_de_Letras; i++){
        
        // Existe un separador el la posicion 2 o/y posicion 5 
        if( c_campos[i] == '/' && (  i == 2 || i == 5   ) )
            cantidad_de_Separadores++;

        // Verificar que cada digito sea numerico
        if( isdigit(c_campos[i]) )
            cantidad_de_Numeros++;
    }

    if( strlen(c_campos) == 10 && cantidad_de_Separadores == 2 && cantidad_de_Numeros == 8 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Fecha_de_nacimiento, c_campos);
    }else{
        TAB; printf("**Fecha de nacimiento incorrecto! \n");
    }
     SALTO_DE_LINEA;

    // Capturar el domicilio
    fflush(stdin); // Liberar teclado
    TAB; printf("Domicilio: "); gets(c_campos);
    if( strcmp(c_campos,"0")  != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Domicilio, c_campos);
    }else{
        TAB; printf("**Domicilio incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar Pais
    fflush(stdin); // Liberar teclado
    TAB; printf("Pais: "); 
    gets(c_campos);
    if( strcmp(c_campos,"0")  != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Pais,c_campos);
    }else{
        TAB; printf("**Pais incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar deposito
    fflush(stdin); // Liberar teclado
    double iDeposito;
    TAB; printf("Deposito: "); 
    scanf("%lf",&iDeposito);

    if( ( (int) iDeposito % 100) == 0){
        campos_correcto++;
        Usuarios[contadorID].Deposito = iDeposito;
    }else{
        TAB; printf("**Deposito incorrecto! \n");
    }
    SALTO_DE_LINEA;

    if(campos_correcto == 7){
        Usuarios[contadorID].ID = contadorID;

        SEPARADOR;
        printf("Usuario registrado exitosamente."); SALTO_DE_LINEA;
        _generador_de_cuenta_(contadorID);
        crear_bd_actividades(contadorID);
        actualizar_base_de_datos(); SALTO_DE_LINEA;
        printf("No. Cuenta: %s",Usuarios[contadorID].No_cuenta); SALTO_DE_LINEA;
        printf("PIN: %i",Usuarios[contadorID].Pin_cuenta); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
    }else{
        contadorID--;
        SEPARADOR;
        printf("Lo siento, fallo al registrar el usuario."); SALTO_DE_LINEA;
        printf("favor de introducir datos que sean correcto."); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
    }

    } // Fin de if != 0 || > 0 || == 0
}

void fnc_menu_buscar_cuentas(){
    int opc_menu, i, Encontrado;

    do{
        inicializar_programa();
        BORRAR_LA_PANTALLA;
        Encontrado = 0;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Buscar cuentas"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Buscar por ID"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("2 > Buscar por NO. DE CUENTA"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("3 > Buscar por NOMBRE"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
        SEPARADOR;

        fflush(stdin);
        TAB; printf("Seleccione una opcion > ");
        scanf("%i",&opc_menu);

        switch(opc_menu){
            // Buscar por id
            case 1:{
            fflush(stdin);
            int buscar_x_id;
            TAB; printf("Introduzca el ID del usuario > ");
            scanf("%i",&buscar_x_id);
                for(i=1; i <= contadorID; i++){
                    if(Usuarios[i].ID == buscar_x_id ){
                        SALTO_DE_LINEA;
                        fnc_mostrar_datos_de_usuarios(i);
                        SALTO_DE_LINEA;
                        Encontrado = 1;
                        break;
                    }else
                        Encontrado = 0;
                }

                if( Encontrado == 0){
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, el usuario no existe"); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                }

                PAUSA;
            }break;
            // Buscar por numero de cuenta
            case 2:{
                fflush(stdin);
                char buscar_x_NoCuenta[50];
                TAB; printf("Introduza el NO. DE CUENTA del usuario > ");
                gets(buscar_x_NoCuenta);

                for(i=1; i <= contadorID; i++){
                    if( strcmp(buscar_x_NoCuenta, Usuarios[i].No_cuenta)  == 0){
                        SALTO_DE_LINEA;
                        fnc_mostrar_datos_de_usuarios(i);
                        SALTO_DE_LINEA;
                        Encontrado++;
                        break;
                    }
                }

                if( Encontrado == 0){
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, el usuario no existe"); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                }

                PAUSA;
            }break;
            // Buscar por nombre
            case 3:{
                fflush(stdin);
                char buscar_x_nombre[50];
                TAB; printf("Introduza el NOMBRE del usuario > ");
                gets(buscar_x_nombre);

                for(i=1; i <= contadorID; i++){
                    if( *Usuarios[i].Nombre == *buscar_x_nombre){
                        SALTO_DE_LINEA;
                        fnc_mostrar_datos_de_usuarios(i);
                        Encontrado++;      
                    }
                }

                if( Encontrado >= 0){
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Coincidencias encontrados %i.",Encontrado); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }
            }break;
        }

    }while( opc_menu != 0);
}

void fnc_menu_modificar_cuentas(){
    inicializar_programa();
    int i;
    int Encontrado; 
    char xModificar[50]; 

        TAB; printf("BANKO CASTIyO \\(*__*)/");  SALTO_DE_LINEA;
        TAB; printf("Modificar cuentas");  SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("0 > Volver");  SALTO_DE_LINEA;
        SEPARADOR;

        // Buscar usuario
        fflush(stdin);
        char buscar_x_NoCuenta[50];
        printf("Introduzca el NO. DE CUENTA del usuario > ");
        gets(buscar_x_NoCuenta);
        
        if( strcmp(buscar_x_NoCuenta, "0") != 0 ){

                for(i=1; i <= contadorID; i++){
                    if( strcmp(Usuarios[i].No_cuenta, buscar_x_NoCuenta) == 0 ){
                        BORRAR_LA_PANTALLA;

                        // Modificar nombre
                        fflush(stdin);
                        TAB; printf("Nombre: %s",Usuarios[i].Nombre); SALTO_DE_LINEA;
                        TAB; printf("Nuevo nombre / Intro para no modificar: ");
                        gets(xModificar);
                        if( strlen(xModificar) > 0 && 
                            atoi(xModificar) == 0 &&
                            strcmp(xModificar,"0") != 0)
                            strcpy(Usuarios[i].Nombre, xModificar);
                        else{
                            TAB; printf("**Nombre no modificado!");
                            SALTO_DE_LINEA;
                        }


                        // Modificar apelldio paterno
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("Apellido paterno: %s", Usuarios[i].Apellido_paterno); SALTO_DE_LINEA;
                        TAB; printf("Nuevo apellido paterno / Intro para no modificar: ");
                        gets(xModificar);
                        if( strlen(xModificar) > 0 && 
                            atoi(xModificar) == 0 &&
                            strcmp(xModificar,"0") != 0)
                            strcpy(Usuarios[i].Apellido_paterno, xModificar);
                        else{
                            TAB; printf("**Apellido paterno no modificado!");
                            SALTO_DE_LINEA;
                        }

                        // Modificar apelldio materno
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("Apellido materno: %s", Usuarios[i].Apellido_materno); SALTO_DE_LINEA;
                        TAB; printf("Nuevo apellido materno / Intro para no modificar: ");
                        gets(xModificar);
                        if( strlen(xModificar) > 0 && 
                            atoi(xModificar) == 0 &&
                            strcmp(xModificar,"0") != 0)
                            strcpy(Usuarios[i].Apellido_materno, xModificar);
                        else{
                            TAB; printf("**Apellido materno no modificado!");
                            SALTO_DE_LINEA;
                        }

                        // Modificar fecha de nacimiento
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("Fecha de naciento: %s",Usuarios[i].Fecha_de_nacimiento); SALTO_DE_LINEA;
                        TAB; printf("Nuevo fecha de nacimiento / Intro para no modificar:");
                        gets(xModificar);
                        int xi, cantidad_de_Letras = strlen(xModificar), cantidad_de_Numeros = 0, cantidad_de_Separadores = 0;

                        // Buscar separadores y verificar cada digito
                        for( xi = 0; xi <= cantidad_de_Letras; xi++ ){
                            if( xModificar[xi] == '/' && ( xi == 2 || xi == 5 ) )
                                cantidad_de_Separadores++;

                            if( isdigit(xModificar[xi]) )
                                cantidad_de_Numeros++;
                        }

                        if( strlen(xModificar) == 10 && cantidad_de_Separadores == 2 && cantidad_de_Numeros == 8 ){
                            strcpy(Usuarios[i].Fecha_de_nacimiento,xModificar);
                        }else{
                            TAB; printf("**Fecha de nacimiento no modificado!");
                            SALTO_DE_LINEA;
                        }
                    
                        // Modificar el domicilio
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("Domicilio: %s",Usuarios[i].Domicilio); SALTO_DE_LINEA;
                        TAB; printf("Nuevo domicilio / Intro para no modificar: "); 
                        gets(xModificar);
                        if( strlen(xModificar) > 0 && 
                            atoi(xModificar) == 0 &&
                            strcmp(xModificar,"0") != 0)
                            strcpy(Usuarios[i].Domicilio, xModificar);
                        else{
                            TAB; printf("**Domicilio no modificado!");
                            SALTO_DE_LINEA;
                        }

                        // Modificar el pais
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("Pais: %s", Usuarios[i].Pais); SALTO_DE_LINEA;
                        TAB; printf("Nuevo pais / Intro para no modificar: ");
                        gets(xModificar);
                        if( strlen(xModificar) > 0 && 
                            atoi(xModificar) == 0 &&
                            strcmp(xModificar,"0") != 0)    
                            strcpy(Usuarios[i].Pais,xModificar);
                        else{
                            TAB; printf("**Pais no modificado!");
                            SALTO_DE_LINEA;
                        }

                        // Modificar el PIN
                        int xPIN;
                        SALTO_DE_LINEA;
                        fflush(stdin);
                        TAB; printf("PIN: %i", Usuarios[i].Pin_cuenta); SALTO_DE_LINEA;
                        TAB; printf("Nuevo PIN / Intro para no modificar: ");
                        scanf("%i",&xPIN);
                        sprintf(xModificar,"%i", xPIN);

                        if( strlen(xModificar) == 6 ){
                            Usuarios[i].Pin_cuenta = xPIN;
                        }else{
                            TAB; printf("**PIN no modificado!");
                            SALTO_DE_LINEA;
                        }
                        
                        Encontrado = 1;
                        SALTO_DE_LINEA;
                        SEPARADOR;
                        printf("Registro actualizado exitosamente."); SALTO_DE_LINEA;
                        actualizar_base_de_datos(); SALTO_DE_LINEA;
                        SALTO_DE_LINEA;
                        PAUSA;
                        break;
                    }else{
                        Encontrado = 0;
                    }
                }

            if( Encontrado == 0){
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, usuario no registrado."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }

        }
}

void fnc_menu_eliminar_cuentas(){
    char buscar_x_NoCuenta[50];
    int i, Encontrado;

    do{
        inicializar_programa();
        BORRAR_LA_PANTALLA;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Eliminar cuentas"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
        SEPARADOR;

        // Capturar el id del usuario
        fflush(stdin);
        TAB; printf("Introduzca el NO. DE CUENTA del usuario > ");
        gets(buscar_x_NoCuenta);

        if( strcmp(buscar_x_NoCuenta, "0") != 0 ){

        for(i=1; i <= contadorID ; i++){
            if( strcmp(buscar_x_NoCuenta , Usuarios[i].No_cuenta) == 0 ){
                SALTO_DE_LINEA;
                fnc_mostrar_datos_de_usuarios(i);
                Encontrado = Usuarios[i].ID;
                break;
            }else
                Encontrado = 0;            
        }

        if( Encontrado > 0){
            
            SALTO_DE_LINEA;
            fflush(stdin);
            int conf_cuenta;
            printf("Introduzca el PIN del la cuenta > ");
            scanf("%i",&conf_cuenta);

            if( conf_cuenta == Usuarios[Encontrado].Pin_cuenta ){

                if( Usuarios[Encontrado].Deposito == 0){
                    
                    // Eliminar el archivo de actividades
                    remove(Usuarios[Encontrado].file_act);
                    
                    for( i = Encontrado; i < contadorID; i++ ){

                        // Tipo entero
                        Usuarios[i].ID = Usuarios[i+1].ID - 1;
                        Usuarios[i].Deposito = Usuarios[i+1].Deposito;
                        Usuarios[i].Pin_cuenta = Usuarios[i+1].Pin_cuenta;

                        // Tipo string
                        strcpy(Usuarios[i].Nombre,Usuarios[i+1].Nombre);
                        strcpy(Usuarios[i].Apellido_paterno,Usuarios[i+1].Apellido_paterno);
                        strcpy(Usuarios[i].Apellido_materno,Usuarios[i+1].Apellido_materno);
                        strcpy(Usuarios[i].Domicilio,Usuarios[i+1].Domicilio);
                        strcpy(Usuarios[i].Pais,Usuarios[i+1].Pais);
                        strcpy(Usuarios[i].file_act, Usuarios[i+1].file_act);
                        strcpy(Usuarios[i].No_cuenta, Usuarios[i+1].No_cuenta);
    
                    }
                   
                    contadorID--;
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("El usuario se elimino correctamente!"); SALTO_DE_LINEA;
                    actualizar_base_de_datos(); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;

                }else{
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, la solicitud fue rechazada."); SALTO_DE_LINEA
                    printf("El estado de cuenta del usuario sigue activo,"); SALTO_DE_LINEA;
                    printf("favor de retirar el deposito o intentelo de nuevo."); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }

            }else{
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Solicitud cancelada."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }

        }
        
        if( Encontrado == 0){
            SALTO_DE_LINEA;
            SEPARADOR;
            printf("El usuario no existe."); SALTO_DE_LINEA;
            SALTO_DE_LINEA;
            PAUSA;
        }

        }// Fin if ( != 0)

    }while( strcmp(buscar_x_NoCuenta, "0") != 0);
}

void fnc_menu_ver_cuentas(){

    inicializar_programa();
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Ver cuentas"); SALTO_DE_LINEA;
    SEPARADOR;

    int i;
    for(i=1; i <= contadorID; i++){
        fnc_mostrar_datos_de_usuarios(i);
        SALTO_DE_LINEA;
    }

    PAUSA;
}

void fnc_transferencia_bancaria(){
    char c_CuentaRemitente[50], c_CuentaDestinatario[50];
    int i, cRe = 0, cDe = 0;

    inicializar_programa();
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Transferencia bancaria"); SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("Nota:"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Las transaciones deber ser de 100 en 100."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Las cuentas no deben del remitente y destinario no debe coincidir."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Verifique que las cuentas tenga el formato 0521-X-XXXX-X."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Verifique que la cuenta remitente tenga fondos suficientes."); SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
    SEPARADOR;

    // Capturar el id de la cuenta remitente
    fflush(stdin);
    TAB; printf("Introduzca el NO. DE CUENTA (remitente) > ");
    gets(c_CuentaRemitente);

    if( strcmp(c_CuentaRemitente,"0") != 0){

        for(i = 1; i <= contadorID; i++){
            if( strcmp(c_CuentaRemitente, Usuarios[i].No_cuenta) == 0 ){
                SALTO_DE_LINEA;
                fnc_mostrar_datos_de_usuarios(i);
                if( Usuarios[i].Deposito >= 100)
                    cRe = Usuarios[i].ID;
                else
                    cRe = 0;
                break;
            } else cRe = 0;
        }

        // Preguntar si cuenta remitente existe
        if( cRe >= 1 ){
            SALTO_DE_LINEA;
            fflush(stdin);
            double iTrasferencia;
            TAB; printf("Introduzca la cantidad de la transferencia > ");
            scanf("%lf",&iTrasferencia);

            if( (iTrasferencia != 0) && (( (int) iTrasferencia % 100) == 0) &&
                ( iTrasferencia <= Usuarios[cRe].Deposito  &&
                Usuarios[cRe].Deposito != 0) ){
                
                fflush(stdin);
                TAB; printf("Introduzca el NO. DE CUENTA (destinatario) > ");
                gets(c_CuentaDestinatario);
                
                if( strcmp(c_CuentaDestinatario, c_CuentaRemitente) != 0 ){
                    
                    for(i=0; i <= contadorID; i++ ){
                        if( strcmp(c_CuentaDestinatario, Usuarios[i].No_cuenta) == 0 ){
                            cDe = Usuarios[i].ID;
                            break;
                        }
                    }

                    // Preguntar si la cuenta destinario existe
                    if( cDe >= 1){
                        BORRAR_LA_PANTALLA;
                        
                        // Remitente
                        SEPARADOR;
                        TAB; printf("Estado de cuenta del remitente"); SALTO_DE_LINEA;

                        // Mostrar estado de cuenta del remitente
                        fnc_mostrar_datos_de_usuarios(cRe);  
                        
                        // Mostrar datos de la tranferencia
                        SALTO_DE_LINEA;
                        TAB; printf("Tranferido: %.2f", iTrasferencia); SALTO_DE_LINEA;
                        TAB; printf("Sub-total: %.2f - %.2f",Usuarios[cRe].Deposito, iTrasferencia); SALTO_DE_LINEA;
                        TAB; printf("Total: %.2f",Usuarios[cRe].Deposito - iTrasferencia); SALTO_DE_LINEA; 
                        Usuarios[cRe].Deposito -= iTrasferencia;    
                        SALTO_DE_LINEA;

                        // destinarario
                        SEPARADOR;
                        TAB; printf("Estado de cuenta del destinatario"); SALTO_DE_LINEA;

                        // Mostrar estado de cuenta del destinatario
                        fnc_mostrar_datos_de_usuarios(cDe); 
                        
                        // Mostrar datos de la tranferencia
                        SALTO_DE_LINEA;  
                        TAB; printf("Tranferido: %.2f", iTrasferencia); SALTO_DE_LINEA;
                        TAB; printf("Sub-total: %.2f + %.2f",Usuarios[cDe].Deposito, iTrasferencia); SALTO_DE_LINEA;
                        TAB; printf("Total: %.2f",Usuarios[cDe].Deposito + iTrasferencia); SALTO_DE_LINEA;
                        Usuarios[cDe].Deposito += iTrasferencia;

                        // Registrar actividad Remitente
                        char xAsunto[100];
                        sprintf(xAsunto, "Transferencia enviado: %s", Usuarios[cDe].No_cuenta);
                        char xDescripcion[100];
                        sprintf(xDescripcion, "Monto: (-) $%.2lf", iTrasferencia);
                        _registrar_actividad_(Usuarios[cRe].ID,  xAsunto, xDescripcion, 301);

                        // Registrar actividad Destinatario
                        sprintf(xAsunto,"Transferecia recibido: %s", Usuarios[cRe].No_cuenta);
                        sprintf(xDescripcion,"Monto: (+) $%.2lf", iTrasferencia);
                        _registrar_actividad_(Usuarios[cDe].ID, xAsunto, xDescripcion, 302);

                        // Mostrar mensaje cuando la transferencia se ralizo con exito
                        SALTO_DE_LINEA;
                        SEPARADOR;
                        printf("La solicitud se realizo exitosamente."); SALTO_DE_LINEA;
                        actualizar_base_de_datos(); SALTO_DE_LINEA;
                        SALTO_DE_LINEA;
                        PAUSA;

                    }else{

                        SALTO_DE_LINEA;
                        SEPARADOR;
                        printf("Lo siento, la solicitud fue rechazada."); SALTO_DE_LINEA;
                        printf("La cuenta del  destinatario no esta registrado."); SALTO_DE_LINEA;
                        SALTO_DE_LINEA;
                        PAUSA;

                    }

                }else{
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, la solicitud fue rechazada."); SALTO_DE_LINEA;
                    printf("La cuenta del remitente es igual al destinatario."); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }

            }else{
                
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, la solicitud fue rechazada."); SALTO_DE_LINEA;
                printf("La cantidad introducida es incorrecto o"); SALTO_DE_LINEA;
                printf("verifique que la cuenta remitente tenga fondos suficientes."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;

            }

        }else{
            
            SALTO_DE_LINEA;
            SEPARADOR;
            printf("Lo siento, la solicitud fue rechazada."); SALTO_DE_LINEA;
            printf("Compruebe que la cuenta remitente sea correctos y"); SALTO_DE_LINEA;
            printf("que tenga un estado de cuenta igual o mayor $100."); SALTO_DE_LINEA;
            SALTO_DE_LINEA;
            PAUSA;

        }
    }// Fin del if( != 0)
} // Fin de la funcion

void fnc_deposito_de_cuentas(){
   char buscar_x_NoCuenta[50];
   int i, Encontrado = 0;

    inicializar_programa();
   TAB; printf("BANKO CASTIyO \\(*__*)/");  SALTO_DE_LINEA;
   TAB; printf("Deposito de cuentas");  SALTO_DE_LINEA;
   SEPARADOR;
   DOBLE_TAB; printf("Nota:"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("Los depositos deben ser de 100 en 100"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
   SEPARADOR;

   fflush(stdin);
   TAB; printf("Introduza el NO. DE CUENTA del usuario > ");
   gets(buscar_x_NoCuenta);

    if( strcmp(buscar_x_NoCuenta, "0") != 0 ){

        for(i=1; i <= contadorID; i++){
            if( strcmp(buscar_x_NoCuenta, Usuarios[i].No_cuenta) == 0 ){
                 // Mostrar datos del usuario
                SALTO_DE_LINEA;
                fnc_mostrar_datos_de_usuarios(i);
                SALTO_DE_LINEA;

                
                // Modificar / Capturar el deposito
                fflush(stdin);
                double x_deposito;
                TAB; printf("Cuanto desea depositar? $");
                scanf("%lf",&x_deposito);
                
                if( ( (int) x_deposito % 100 == 0) && (x_deposito != 0) ){
                        BORRAR_LA_PANTALLA;
                        TAB; printf("BANKO CASTIyO \\(*__*)/");  SALTO_DE_LINEA;
                        TAB; printf("Deposito de cuentas");  SALTO_DE_LINEA;
                        TAB; printf("Socursal av. mexico calle: #7 ");  SALTO_DE_LINEA;
                        TAB; printf("Fecha: 26/04/2019");  SALTO_DE_LINEA;
                        fnc_mostrar_datos_de_usuarios(i);
                        SALTO_DE_LINEA;
                        TAB; printf("Importado: %.2f",x_deposito); SALTO_DE_LINEA;
                        TAB; printf("Sub-total: %.2f + %.2f", Usuarios[i].Deposito, x_deposito); SALTO_DE_LINEA;
                        TAB; printf("Total: %.2f", Usuarios[i].Deposito + x_deposito); SALTO_DE_LINEA;
                        Usuarios[i].Deposito += x_deposito;

                        // Registrar actividad
                        char cAsunto[100];
                        sprintf(cAsunto, "Deposito: Solicitud aprobada");
                        char cDescripcion[100];
                        sprintf( cDescripcion, "Monto: (+) %.2lf", x_deposito );
                        _registrar_actividad_(Usuarios[i].ID, cAsunto, cDescripcion, 200);

                        SALTO_DE_LINEA;
                        SEPARADOR;
                        printf("La solicitud se realizo exitosamente."); SALTO_DE_LINEA;
                        actualizar_base_de_datos(); SALTO_DE_LINEA;
                        SALTO_DE_LINEA;
                        PAUSA;
            }else{
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("Lo siento, el deposito no se pudo realizar."); SALTO_DE_LINEA;
                printf("Vuelve a intentarlo mas tarde, o"); SALTO_DE_LINEA;
                printf("realize un deposito valido."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA;
            }

           Encontrado = 1;
           break;

       }// Fin del for
       else Encontrado = 0;
    
    } 

    // Cuando el usuario no existe
   if( Encontrado == 0){
        SALTO_DE_LINEA;
        SEPARADOR;
        printf("Lo siento, el usuario no existe."); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
    }

    } // Fin del if !=0

} // Fin de la funcion

void fnc_menu_retirar_deposito(){
    char buscar_x_NoCuenta[50];
    int i, Encontrado;

    do{ 
        inicializar_programa();   
        BORRAR_LA_PANTALLA;
        Encontrado = 0;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Retirar deposito"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("Nota: "); SALTO_DE_LINEA;
        DOBLE_TAB; printf("Los depositos de retiro deben ser de 100 en 100"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
        SEPARADOR;

        // Seleccionar opcion o buscar id
        fflush(stdin);
        TAB; printf("Introduzca el NO. DE CUENTA del usuario > ");
        gets(buscar_x_NoCuenta);

            // Volver o seguir con el paso siguiente
            if( strcmp(buscar_x_NoCuenta, "0") != 0){

                // Buscar al usuario por medio de No de cuenta
                for(i = 0; i <= contadorID; i++){

                    // Usuario encontrado o localizado
                    if( strcmp( buscar_x_NoCuenta, Usuarios[i].No_cuenta ) == 0 ){
                        
                        // Mostrar datos del usuario
                        SALTO_DE_LINEA;
                        fnc_mostrar_datos_de_usuarios(i);
                        SALTO_DE_LINEA;
                        
                        // Retirar el deposito
                        fflush(stdin); // Liberar el teclado
                        double iRetirar;
                        TAB; printf("Cuanto desea retirar? >$"); 
                        scanf("%lf",&iRetirar);

                        if( iRetirar != 0 && ( ((int)iRetirar % 100) == 0 ) && 
                            (( Usuarios[i].Deposito - iRetirar ) >= 0) ){
                            SALTO_DE_LINEA;
                            TAB; printf("Retiro de deposito: %.2f",iRetirar); SALTO_DE_LINEA;
                            TAB; printf("Sub-total: %.2f - %.2f",Usuarios[i].Deposito, iRetirar); SALTO_DE_LINEA;
                            TAB; printf("Total: %.2f",Usuarios[i].Deposito - iRetirar); SALTO_DE_LINEA;
                            Usuarios[i].Deposito -= iRetirar;
                            
                            // Registrar actividad
                            char cAsunto[100];
                            sprintf(cAsunto, "Retiro deposito: Solicitud aprobada");
                            char cDescripcion[100];
                            sprintf(cDescripcion,"Monto: (-) $%.2lf", iRetirar);
                            _registrar_actividad_(Usuarios[i].ID, cAsunto, cDescripcion, 400);

                            SALTO_DE_LINEA;
                            SEPARADOR;
                            printf("La solicitud se realizo exitosamente!"); SALTO_DE_LINEA;
                            actualizar_base_de_datos(); SALTO_DE_LINEA;
                            SALTO_DE_LINEA;
                            PAUSA;

                        }else{
                            
                            SALTO_DE_LINEA;
                            SEPARADOR;
                            printf("Lo siento, hubo un error al retira el deposito."); SALTO_DE_LINEA;
                            printf("favor de introducir deposito de retiro valido."); SALTO_DE_LINEA;
                            SALTO_DE_LINEA;
                            PAUSA;
                        
                        }
                        
                        Encontrado = 1;
                        break;
                    
                    // Usuario no localizado o sin existencia
                    }else
                        Encontrado = 0;
                } // Fin del for

                // Mostrar mensaje cuando el usuario no existe
                if( Encontrado == 0){
                    SALTO_DE_LINEA;
                    SEPARADOR;
                    printf("Lo siento, el usuario no esta registrado"); SALTO_DE_LINEA;
                    SALTO_DE_LINEA;
                    PAUSA;
                }

            } // Fin del if( buscar_x_id != 0 )

    }while( strcmp(buscar_x_NoCuenta, "0") != 0);


}

void _generador_de_cuenta_(int id_cuenta){

    int i, l=0;
    char _4numeros[5];   
    char nc[50];
    char *cf = Usuarios[id_cuenta].Fecha_de_nacimiento;
    
     // Generar Nomero de cuenta
    for(i = 0; i < 11; i++){
        if( isdigit(cf[i]) && l < 4 ){
            _4numeros[l++] = cf[i]; 
        }
    }
    sprintf(nc,"0521-%i-%s-%i",id_cuenta,_4numeros,id_cuenta);
    strcpy(Usuarios[id_cuenta].No_cuenta, nc);
    
    int _6ns[6], nR; char _6numeros[7]; time_t t;
    srand((unsigned) time(&t));
    // Generar pin por defecto
    for(i = 1; i <= 6; i++){
        nR = rand() % 8 + 1;
        _6ns[i] = nR;
    }
    sprintf(_6numeros,"%i%i%i%i%i%i",
    _6ns[1],_6ns[2],_6ns[3],
    _6ns[4],_6ns[5],_6ns[6]);
    Usuarios[id_cuenta].Pin_cuenta = atoi(_6numeros);
    
}

void crear_bd_actividades(int id_cuenta){
    
    // Crear el nombre del archivo
    char nFile[50]; 
    sprintf(nFile,"%%%%reg/.%%%%%s",Usuarios[id_cuenta].No_cuenta);
    strcpy(Usuarios[id_cuenta].file_act, nFile);

    // Crear la fecha
    time_t cf; time(&cf);
    char *Fecha = ctime(&cf);
    strtok (Fecha,"\n");

    // Crear el archivo
    FILE *actividades = fopen(nFile,"w");
    // Crear registros
    char cRegistro[250];

    // Registrar Indice por defecto
    sprintf(cRegistro,"1# : No borrar, ni modificar\n");
    fputs(cRegistro,actividades);

    // Registrar el tipo de actividad
    fputs("100~ : No borrar, ni modificar\n",actividades);

    // Registrar Fechar
    sprintf(cRegistro,"%s~ : No borrar, ni modificar\n",Fecha);
    fputs(cRegistro, actividades);

    // Registrar remitente
    sprintf(cRegistro,"Banco: CASTIyO~ : No borrar, ni modificar\n");
    fputs(cRegistro, actividades);

    // Registrar asunto
    sprintf(cRegistro,"Cuenta: Creado~ : No borrar, ni modificar\n");
    fputs(cRegistro, actividades);

    // Registrar descripcion
    sprintf(cRegistro,"Deposito: %.2f~ : No borrar, ni modificar\n",
    Usuarios[id_cuenta].Deposito);
    fputs(cRegistro, actividades);

    // Registar nombre del archivo de actividades
    sprintf(cRegistro,"%i~##########################################################\n", Usuarios[id_cuenta].ID);
    fputs(cRegistro, actividades);

    // Cerrar el archivo
    fclose(actividades);
}

void _registrar_actividad_(int id_cuenta, char cAsunto[100], char cDescripcion[100], int tipoDeOperacion){
    char xCampos[250]; 
    int iBuffer, iFilas, iActividades , i;

    // Obtener la fecha
    char cFecha[50];
    time_t f; time(&f);
    sprintf(cFecha,"%s",ctime(&f));
    strtok(cFecha,"\n");

    FILE *bd_actividades = fopen(Usuarios[id_cuenta].file_act, "r+");

    // Obtener la cantidad de actividades registrados
    fgets(xCampos,250,bd_actividades); strtok(xCampos,"#");
    
    if( Usuarios[id_cuenta].Deposito > 0){
        iActividades = atoi(xCampos);    
        iFilas = iActividades * 6;
    }else{
        iActividades = 1; 
        iFilas = iActividades * 6;
    }

    // Obtener el final del archivo o buffer
    for(i=1; i <= iFilas; i++){
        fgets(xCampos,250,bd_actividades);
        iBuffer = ftell(bd_actividades);
    }
    
    // Posicionar la final del buffer del archivo
    // y aumentar la cantidad de actividades 
    fseek(bd_actividades, iBuffer, SEEK_SET);
    iActividades++;

    // Registrar el tipo de operacion
    sprintf(xCampos,"%i~ : No borrar, ni modificar\n", tipoDeOperacion);
    fputs(xCampos, bd_actividades);

    // Registrar Fecha
    sprintf(xCampos, "%s~ : No borrar, ni modificar\n", cFecha);
    fputs(xCampos,bd_actividades);

    // Registrar Remitente
    sprintf(xCampos,"Banco: CASTIyO~ : No borrar, ni modificar\n");
    fputs(xCampos,bd_actividades);

    // Registrar Asunto
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", cAsunto);
    fputs(xCampos, bd_actividades);

    // Registrar Descripcion
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", cDescripcion);
    fputs(xCampos, bd_actividades);

    // Registrar Separador
    fputs("############################################################\n", bd_actividades);
    
    // Registar el nuevo cantidad de actividades
    rewind(bd_actividades);
    sprintf(xCampos,"%i# : No borrar, ni modificar", iActividades);
    fputs(xCampos,bd_actividades);

    fclose(bd_actividades);
}

void actualizar_base_de_datos(){
    FILE *archivo = fopen(".%%CASTIyO%%","w");

    if( archivo == NULL){
        perror("Error de archivo.\n");
        exit(1);
    }

    
    char xCampos[250];
    sprintf(xCampos,"%i#Warning: No borrar, ni modificar\n",contadorID);
    fputs(xCampos,archivo);

    int i;
    for(i=1; i <= contadorID; i++){
        Usuarios[i].ID = i; // Dar un indice
        
        // Guardar el nombre
        sprintf(xCampos,"%s~ Nombre: No borrar, ni modificar\n",Usuarios[i].Nombre);
        fputs(xCampos,archivo);

        // Guardar el apellido paterno
        sprintf(xCampos,"%s~ Apellido paterno: No borrar, ni modificar\n",Usuarios[i].Apellido_paterno);
        fputs(xCampos,archivo);

        // Guardar el apellido materno
        sprintf(xCampos,"%s~ Apellido materno: No borrar, ni modificar\n",Usuarios[i].Apellido_materno);
        fputs(xCampos,archivo);

        // Guardar la fecha de nacimiento
        sprintf(xCampos,"%s~ Fecha de nacimiento: No borrar, ni modificar\n", Usuarios[i].Fecha_de_nacimiento);
        fputs(xCampos, archivo);

        // Guardar el domicilio
        sprintf(xCampos,"%s~ Domicilio: No borrar, ni modificar\n",Usuarios[i].Domicilio);
        fputs(xCampos, archivo);

        // Guardar el pais
        sprintf(xCampos,"%s~ Pais: No borrar, ni modificar\n",Usuarios[i].Pais);
        fputs(xCampos,archivo);

        // Guardar el numero de la cuenta
        sprintf(xCampos,"%s~ No. Cuenta: No borrar, ni modificar\n",Usuarios[i].No_cuenta);
        fputs(xCampos,archivo);

        // Guardar el pin de la cuenta
        sprintf(xCampos,"%i~ PIN: No borrar, ni modificar\n",Usuarios[i].Pin_cuenta);
        fputs(xCampos,archivo);

        // Guardar el deposito
        sprintf(xCampos,"%.2f~ Deposito: No borrar, ni modificar\n",Usuarios[i].Deposito);
        fputs(xCampos,archivo);

        // Guardar separador
        sprintf(xCampos,"%s~##############################%i\n",Usuarios[i].file_act, Usuarios[i].ID);
        fputs(xCampos,archivo);
    }

    fclose(archivo);

    printf("Base de datos actualizados.");
}

void inicializar_programa(){
    FILE *archivo = fopen(".%%CASTIyO%%","r");

    if( archivo == NULL){
        perror("Error de archivo.\n");
        exit(1);
    }

    char xCampos[250];
    // Capturar la primera linea
    fgets(xCampos,250,archivo); 
    // Recortar hasta el #
    strtok(xCampos,"#");
    int x_users = atoi(xCampos);
    if( x_users > 0){
        contadorID = x_users;
        
        int i;
        for(i=1; i <= contadorID; i++){
            Usuarios[i].ID = i; // Dar un indice

            // Obtener el nombre
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Nombre, xCampos);

            // Obtener el apellido paterno
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Apellido_paterno, xCampos);

            // Obtener el apellido materno
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Apellido_materno, xCampos);

            // Obtener la fecha de nacimieto
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Fecha_de_nacimiento, xCampos);

            // Obtener el domicilio
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Domicilio, xCampos);

            // Obtener el pais
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Pais, xCampos);

            // Obtener el numero de la cuenta
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].No_cuenta,xCampos);

            // Obtener el pin de la cuenta
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            Usuarios[i].Pin_cuenta = atoi(xCampos);            
            
            // Obtener el deposito
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            Usuarios[i].Deposito = atof(xCampos);

            // Obtener el nombre del archivo
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].file_act, xCampos);
        }

    }else{
        contadorID = 0;
    }

    fclose(archivo);
}