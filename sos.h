// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;

struct Registro_de_compra{
    // Datos internos
    char Sucursal[50];
    char Nombre_producto[50];
    char Fecha[50];
    float Total_Apagar;
    float IVA_producto;
    float Costo_producto;
    int Cantidad_producto;
    char Cuenta_castiyo[50];
    int Existe_cuentaCastiyo;
    
    // Datos externos 
    int exPIN_cuentaCastiyo;
    double exEstado_cuentaCastiyo; // (#)
    char exActividades_cuentaCastiyo[100];
    int exLinea_estadoCuenta;
};

struct Registro_de_compra Productos;
void opciones_menu_principal();
void fnc_menu_comprar_con_tarjeta();
void fnc_menu_comprar_en_efectivo();
void fnc_verificar_cuenta();
void fnc_actualizar_base_de_datos_castiyo();
void fnc_registrar_actividad();

void opciones_menu_principal(){
    
    // Titulo
    TAB; printf("TIENDA SOS \\(*+*)/"); SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("1 > Comprar con tarjeta"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("2 > Comprar en efectivo"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;

}

void fnc_menu_comprar_con_tarjeta(){

    // Titulo
    strcpy(Productos.Sucursal,"Sucursal: Tienda SOS");
    TAB; printf("TIENDA SOS \\(*+*)/"); SALTO_DE_LINEA;
    TAB; printf("Comprar con tarjeta"); SALTO_DE_LINEA;
    SEPARADOR;

    SALTO_DE_LINEA;
    fflush(stdin);
    TAB; printf("Introduzca el nombre del producto: ");
    gets(Productos.Nombre_producto);
    
    // Verificar que tenga 5 letras o mas
    if(strlen( Productos.Nombre_producto ) <= 5 ){
        SALTO_DE_LINEA;
        SEPARADOR;
        printf("***Nombre del producto incorrecto!."); SALTO_DE_LINEA;
        printf("favor de introducir un nombre mayor a 5 caracteres"); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
        strcpy(Productos.Nombre_producto,"0");
    }

    if( strcmp(Productos.Nombre_producto,"0") != 0){

        // Capturar el costo del producto
        fflush(stdin);
        TAB; printf("Introduzca el costo del producto (16%% IVA): ");
        scanf("%f",&Productos.Costo_producto);

        // Calcular el valor absoluto
        if( Productos.Costo_producto < 0)
            Productos.Costo_producto *= (-1);

        // Capturar la cantidad de producto
        fflush(stdin);
        TAB; printf("Introduzca la cantidad de productos: ");
        scanf("%i",&Productos.Cantidad_producto);

        // Capturar la cuenta del usuario
        fflush(stdin);
        TAB; printf("Introduzca la cuenta CASTIyO: ");
        gets(Productos.Cuenta_castiyo);

        // Verificar si el usuario existe
        Productos.Existe_cuentaCastiyo = 0;
        fnc_verificar_cuenta();

        // Capturar el PIN
        fflush(stdin);
        int xPIN;
        TAB; printf("Introduzca el PIN: ");
        scanf("%i", &xPIN);

        // Calcular total a pagar
        Productos.Total_Apagar = Productos.Costo_producto * Productos.Cantidad_producto;

        if( Productos.Total_Apagar > 0 &&
            Productos.Existe_cuentaCastiyo == 1 &&
            Productos.exPIN_cuentaCastiyo == xPIN &&
            Productos.exEstado_cuentaCastiyo >= Productos.Total_Apagar){
       
            // Calcular IVA 16%
            Productos.IVA_producto = (Productos.Total_Apagar / 100) * 16;

            // Calcular el Sub total
            float subTotal = Productos.Total_Apagar - Productos.IVA_producto;

            // Mostrar datos de la compra
            SALTO_DE_LINEA;
            TAB; printf("Sucursal: %s", Productos.Sucursal); SALTO_DE_LINEA;
            TAB; printf("Nombre del producto: %s", Productos.Nombre_producto); SALTO_DE_LINEA;
            TAB; printf("Precio: %.2f", Productos.Costo_producto); SALTO_DE_LINEA;
            TAB; printf("Cantidad: %i", Productos.Cantidad_producto); SALTO_DE_LINEA;
            TAB; printf("Sub-total: %.2f", subTotal); SALTO_DE_LINEA;
            TAB; printf("IVA: %.2f", Productos.IVA_producto); SALTO_DE_LINEA;
            TAB; printf("Total: %.2f", Productos.Total_Apagar); SALTO_DE_LINEA;

            // Se realiza la compra
            Productos.exEstado_cuentaCastiyo -= Productos.Total_Apagar;
            fnc_actualizar_base_de_datos_castiyo();
            fnc_registrar_actividad();

            SALTO_DE_LINEA;
            SEPARADOR;
            printf("SOLICITUD APROBADA"); SALTO_DE_LINEA;
            SALTO_DE_LINEA;
            PAUSA;            
        }else{
            SALTO_DE_LINEA;
            SEPARADOR;
            printf("SOLICITUD RECHAZADA"); SALTO_DE_LINEA;
            SALTO_DE_LINEA;
            PAUSA;
        }

    } // Fin del if ( != 0 )

} // Fin fnc_comprar_con_tarjeta()

void fnc_verificar_cuenta(){
    FILE *bd_castiyo = fopen(".%%CASTIyO%%","r");

    if( bd_castiyo == NULL ){
        perror("Lo siento, no existe la base de datos.");
        exit(1);
    }

    int cantidad_de_cuentas;
    char estado_de_cuenta[250];
    char xCampos[250];
    
    // Capturar la cantidad de usuarios registrados
    fgets(estado_de_cuenta,250,bd_castiyo);
    strtok(estado_de_cuenta,"#");
    cantidad_de_cuentas = atoi(estado_de_cuenta) * 10;
    
    // Obtener la cuenta
    int i;
    for(i = 1; i <= (cantidad_de_cuentas - 1); i++){
        fgets(xCampos,250, bd_castiyo);
        strtok(xCampos,"~");
        if( strcmp(xCampos, Productos.Cuenta_castiyo) == 0){
            Productos.Existe_cuentaCastiyo = 1;
            Productos.exLinea_estadoCuenta = i + 2;
            
            // Obtener el PIN
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos,"~");
            Productos.exPIN_cuentaCastiyo = atoi(xCampos);
            //printf("%i\n", Productos.exPIN_cuentaCastiyo);

            // Obtener el estado de cuenta
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos,"~");
            Productos.exEstado_cuentaCastiyo = atof(xCampos);
            //printf("%lf\n", Productos.exEstado_cuentaCastiyo);

            // Obtener la base de datos actividades
            fgets(xCampos, 250, bd_castiyo);
            strtok(xCampos,"~");
            strcpy(Productos.exActividades_cuentaCastiyo, xCampos);
            //printf("%s\n", Productos.exActividades_cuentaCastiyo);
            
            break;
        }
    }
}

void fnc_registrar_actividad(){
    
    // Obtener la fecha
    time_t fecha_registro; time(&fecha_registro);
    char *xFecha = ctime(&fecha_registro); strtok(xFecha,"\n");
    strcpy(Productos.Fecha, xFecha);
   
    // Abrir el archivo de registros
    FILE *registros = fopen(Productos.exActividades_cuentaCastiyo,"r+");

    if( registros == NULL ){
        perror("Lo siento, no existe el archivo");
        exit(1);
    }

    char xCampos[250];
    int cantidad_de_actividades;
    int end,i,fp;
    
    // Capturar la primera linea
    fgets(xCampos, 250, registros);
    strtok(xCampos, "#"); // Recortar
    cantidad_de_actividades = atoi(xCampos);  // Convertir char a int
    
    end = cantidad_de_actividades * 5;
    for( i = 1; i <= end; i++ ){
        fgets(xCampos,250,registros);
        fp = ftell(registros);
    }

    // Aumentar el registro
    cantidad_de_actividades++;
    // Introducir el fin de linea del archivo
    fseek ( registros , fp , SEEK_SET );
    
    // Registrar Fecha
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n", Productos.Fecha);
    fputs(xCampos, registros);
    
    // Registrar Remitente
    sprintf(xCampos,"%s~ : No borrar, ni modificar\n",Productos.Sucursal);
    fputs(xCampos, registros);

    // Registrar Asunto
    sprintf(xCampos,"Compra: %s~ : No borrar, ni modificar\n",Productos.Nombre_producto);
    fputs(xCampos, registros);

    // Registrar descripcion
    sprintf(xCampos,"Monto: (-) %.2f~ : No borrar, ni modificar\n",Productos.Total_Apagar);
    fputs(xCampos, registros);

    // Registrar separador
    fputs("###############################################################\n", registros);

    // Regresar al inicio de linea del archivo
    rewind(registros);
    // Registrar la cantidad de registros
    sprintf(xCampos,"%i# Registros: No borrar, ni modificar\n",cantidad_de_actividades);
    fputs(xCampos,registros);

    fclose(registros);
}

void fnc_actualizar_base_de_datos_castiyo(){
    
    // VARIABLES GLOBALES
    int iBuffer, Mul;
    char registro[250];
    char actualizar[250];
    sprintf(actualizar,"%.2f~ Deposito: No borrar, ni modificar",
    Productos.exEstado_cuentaCastiyo);

    // Abrir archivo para lectura y escritura
    FILE *archivo_registro = fopen(".%%CASTIyO%%","r+");

    // Continuar solo si existe la base datos
    if( archivo_registro == NULL ){
        perror("Lo siento, no existe la actividad");
        exit(1);
    }

    // Capturar la cantidad de usurios registrados
    fgets(registro, 250, archivo_registro);
    strtok(registro,"#");
    Mul = Productos.exLinea_estadoCuenta;
    
    // Obtener la posicion (al final del Buffer) donde esta 
    // el estado de cuenta de cada Usuario
    int i;
    for(i = 1; i <= Mul; i++){
        fgets(registro,250, archivo_registro);
        iBuffer = ftell(archivo_registro) - 2;
    }

    // Posicionar al inicio del buffer donde esta
    // el estado de cuenta de cada Usuario
    int registroBuffer = strlen(registro) - 1;
    int actualizarBuffer = strlen(actualizar);
    fseek(archivo_registro, (iBuffer - registroBuffer), SEEK_SET);
    
    // Actulizar el deposito
    if( actualizarBuffer >= registroBuffer ){
        
        strcat(actualizar, "\n");
        fputs(actualizar, archivo_registro);
    
    }else{
        
        int iBufferFaltante = (registroBuffer - actualizarBuffer);
        for(i = 1; i <= iBufferFaltante; i++)
            strcat(actualizar,"*");
        
        strcat(actualizar,"\n");
        fputs(actualizar, archivo_registro);
    
    }

    fclose(archivo_registro);
}

void fnc_menu_comprar_en_efectivo(){
    
    // Titulo
    strcpy(Productos.Sucursal,"Tienda SOS");
    TAB; printf("TIENDA SOS \\(*+*)/"); SALTO_DE_LINEA;
    TAB; printf("Comprar con tarjeta"); SALTO_DE_LINEA;
    SEPARADOR;

    SALTO_DE_LINEA;
    fflush(stdin);
    TAB; printf("Introduzca el nombre del producto: ");
    gets(Productos.Nombre_producto);

    // Verificar nombre del producto
    if( *Productos.Nombre_producto <= 5){
        SALTO_DE_LINEA;
        SEPARADOR;
        printf("***Nombre del producto incorrecto!."); SALTO_DE_LINEA;
        printf("favor de introducir un nombre mayor a 5 caracteres"); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
        strcpy(Productos.Nombre_producto,"0");
    }

    if( strcmp(Productos.Nombre_producto,"0") != 0){
        
        // Capturar el costo del producto
        fflush(stdin);
        TAB; printf("Introduzca el costo del producto (16%% IVA): $");
        scanf("%f",&Productos.Costo_producto);

        // Capturar la cantidad de producto
        fflush(stdin);
        TAB; printf("Introduzca la cantidad de productos: ");
        scanf("%i",&Productos.Cantidad_producto);

        // Calcular el total a pagar
        Productos.Total_Apagar = (Productos.Costo_producto * Productos.Cantidad_producto);
        
        // Mostrar total a pagar
        SEPARADOR;
        TAB; printf("Total a pagar: >> $%.2f <<",Productos.Total_Apagar); SALTO_DE_LINEA;
            
        // Capturar el importe
        fflush(stdin);
        float xImporte;
        TAB; printf("Introduzca el importe: $");
        scanf("%f",&xImporte);

        if( Productos.Total_Apagar > 0 &&
            xImporte >= Productos.Total_Apagar ){
                
                // Calcular IVA( 16% )
                Productos.IVA_producto = (Productos.Total_Apagar / 100) * 16;
                float subTotal = Productos.Total_Apagar - Productos.IVA_producto;

                // Mostrar datos de la compra
                SEPARADOR;
                SALTO_DE_LINEA;
                TAB; printf("Sucursal: %s", Productos.Sucursal); SALTO_DE_LINEA;
                TAB; printf("Nombre del producto: %s", Productos.Nombre_producto); SALTO_DE_LINEA;
                TAB; printf("Precio: %.2f", Productos.Costo_producto); SALTO_DE_LINEA;
                TAB; printf("Cantidad: %i", Productos.Cantidad_producto); SALTO_DE_LINEA;
                TAB; printf("Sub-total: %.2f", subTotal); SALTO_DE_LINEA;
                TAB; printf("IVA: %.2f", Productos.IVA_producto); SALTO_DE_LINEA;
                TAB; printf("Total: %.2f", Productos.Total_Apagar); SALTO_DE_LINEA;
                printf("- - - - - - - - - - - - - - - - - - - - -"); SALTO_DE_LINEA;
                TAB; printf("Importe: %.2f", xImporte); SALTO_DE_LINEA;
                TAB; printf("Cambio: %.2f",  xImporte - Productos.Total_Apagar); SALTO_DE_LINEA;
                
                SALTO_DE_LINEA;
                SEPARADOR;
                printf("COMPRA APROBADA"); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA; 

        }else{

                SALTO_DE_LINEA;
                SEPARADOR;
                printf("COMPRA CANCELADA"); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
                PAUSA; 

        } // Fin del if >= Total_Apagar

    } // Fin del if != 0

} // Fin fnc_comprar_en_efectivo()
