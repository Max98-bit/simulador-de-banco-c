// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;

struct Registro_de_compra{
    char Sucursal[50]; // *
    char Nombre_producto[50]; // *   
    char Fecha[50]; // *
    float Total_Apagar; // *  
    int Cuenta_castiyo; // * 
    float IVA_producto;
    float Costo_producto;
    int Cantidad_producto;
    double Dep_castiyo;
    int cantidad_de_registros;
};

struct Registro_de_compra Productos;
void opciones_menu_principal();
void fnc_menu_comprar_con_tarjeta();
void fnc_menu_comprar_en_efectivo();
int fnc_verificar_cuenta();
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
    
    if(strlen( Productos.Nombre_producto ) <= 5 ){
        SALTO_DE_LINEA;
        SEPARADOR;
        printf("***Nombre del producto incorrecto!."); SALTO_DE_LINEA;
        printf("favor de introducir un nombre mayor a 5 caracteres"); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
        PAUSA;
        strcpy(Productos.Nombre_producto,"0");
    }

    if( *Productos.Nombre_producto != '0'){

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
        scanf("%i",&Productos.Cuenta_castiyo);

        // Calcular total a pagar
        Productos.Total_Apagar = Productos.Costo_producto * Productos.Cantidad_producto;

        // Verificar si el usuario existe
        int verifiar = fnc_verificar_cuenta();
        if( verifiar == 1 && Productos.Dep_castiyo >= Productos.Total_Apagar ){
       
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
            Productos.Dep_castiyo -= Productos.Total_Apagar;
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

    if( *Productos.Nombre_producto != 0){
        
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

        if( xImporte >= Productos.Total_Apagar ){
                
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

void fnc_registrar_actividad(){
    
    // Obtener la fecha
    time_t fecha_registro; time(&fecha_registro);
    char *xFecha = ctime(&fecha_registro); strtok(xFecha,"\n");
    strcpy(Productos.Fecha, xFecha);
   
    // Abrir el archivo de registros
    char nFiles[50];
    sprintf(nFiles,"%%%%reg/.%%%%%i",Productos.Cuenta_castiyo);
    FILE *registros = fopen(nFiles,"rw+");

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
    sprintf(xCampos,"%s~ Remitente: No borrar, ni modificar\n",Productos.Sucursal);
    fputs(xCampos, registros);

    // Registrar Asunto
    sprintf(xCampos,"Compra: %s~ Asunto: No borrar, ni modificar\n",Productos.Nombre_producto);
    fputs(xCampos, registros);

    // Registrar descripcion
    sprintf(xCampos,"Monto: %.2f~ Descripcion: No borrar, ni modificar\n",Productos.Total_Apagar);
    fputs(xCampos, registros);

    // Registrar separador
    fputs("################################################\n", registros);

    // Regresar al inicio de linea del archivo
    rewind(registros);
    // Registrar la cantidad de registros
    sprintf(xCampos,"%i# Registros: No borrar, ni modificar\n",cantidad_de_actividades);
    fputs(xCampos,registros);

    fclose(registros);
}

int fnc_verificar_cuenta(){
    FILE *bd_castiyo = fopen(".%%CASTIyO%%","r");

    if( bd_castiyo == NULL ){
        perror("Lo siento, no existe la base de datos.");
        exit(1);
    }

    char cantidad_de_cuentas[250];
    char estado_de_cuenta[250];
    fgets(cantidad_de_cuentas,250,bd_castiyo);
    strtok(cantidad_de_cuentas,"#");
    

    if(  Productos.Cuenta_castiyo <= atoi(cantidad_de_cuentas) &&
         Productos.Cuenta_castiyo != 0){
        
        // Nos regresamos al inicio del archivo
        rewind(bd_castiyo);

        // Recorrer las filas necesarias hasta llegar al deposito
        // en la base de datos de CASTIyO
        int i, Multiplo = Productos.Cuenta_castiyo * 9; 
        for( i = 1; i <= Multiplo; i++ ){
            fgets(estado_de_cuenta,250,bd_castiyo);
        }

        // Cortar la cadena de texto hasta donde encuentre el simbolo (~)
        strtok(estado_de_cuenta,"~");
        // El texto sobrante se conviente en un numero
        // y se pasa a la variables Productos.Dep_castiyo
        Productos.Dep_castiyo = atoi(estado_de_cuenta);

    }
    fclose(bd_castiyo);

    if(  Productos.Cuenta_castiyo <= atoi(cantidad_de_cuentas) &&
         Productos.Cuenta_castiyo != 0){
        return 1;
    }else{
        return 0;
    }
}

void fnc_actualizar_base_de_datos_castiyo(){
    
    // VARIABLES GLOBALES
    long int size;
    char registro[250];
    char xActualizar[250];
    int Mul = Productos.Cuenta_castiyo * 9;
    sprintf(xActualizar,"%.2f~ Deposito: No borrar, ni modificar", Productos.Dep_castiyo);

    // Abrir archivo para lectura y escritura
    FILE *archivo_registro = fopen(".%%CASTIyO%%","rw+");

    // Comprar si existe el archivo
    if( archivo_registro == NULL ){
        perror("Lo siento, no existe la actividad");
        exit(1);
    }

    // Recorrer el archivo para capturar
    // el contenido y la posicion
    int i;
    for(i=1; i <= Mul ; i++ ){
        // Capturar el contenido del archivo por filas
        fgets(registro,250,archivo_registro);
        // Capturar la posicion del contenido del archivo
        // previamente capturado 
        size = ftell (archivo_registro) - 2;
    }
    int letras_reg = strlen(registro) - 1;
    int letras_act = strlen(xActualizar);
    
    // Calcular la posicion
    size -= letras_reg;

    // Preguntar si las letras al actualizar el contenido del archivo es mayor
    // que el contenido previamente capturado, de ser asi 
    // introducir el contenido al archivo de lo contrario vamos a modificar el contenido
    if( letras_act >= letras_reg ){

        // Concatenar el contenido el la ultima posicion con un salto de linea
        //if( letras > letras_faltantes)
        strcat(xActualizar, "\n");

        // Introducir el contenido con la posicion previamente obtenido
        fseek ( archivo_registro , size , SEEK_SET );
        fputs(xActualizar,archivo_registro);
    
    }else{ 
        
        // Restar el contenido obtenido previamente
        // con el contenido a actualizar
        int letras_faltantes = letras_reg - letras_act;

        // Modificar el contenido
        for(i = 1; i <= letras_faltantes; i++){
                // Concatenamos el contenido con un (*)
                strcat(xActualizar, "*");
        }

        // Concatenar el contenido el la ultima posicion con un salto de linea
        strcat(xActualizar, "\n");

        // Introducir el contenido modificado con la posicion previamente obtenido
        fseek ( archivo_registro , size , SEEK_SET );
        fputs(xActualizar,archivo_registro);
 
    }

    fclose(archivo_registro);
}

/* void fnc_actualizar_base_de_datos_castiyo(){

    FILE *bd_castiyo = fopen(".%%CASTIyO%%","rw+");

    if( bd_castiyo == NULL){
        perror("No existe la base de datos\n");
        exit(1);
    }

    char xCampos[250];
    int iUsuarios;
    
    // Leer todas las lineas que existan
    int i, ifp,iTotalCampos = Productos.Cuenta_castiyo * 9;
    for(i=1; i <= iTotalCampos; i++){
        fgets(xCampos,250,bd_castiyo);
        ifp = ftell(bd_castiyo);
    }

    // Seleccionar la posicion a modificar
    fseek( bd_castiyo, ifp - strlen(xCampos) - 1, SEEK_SET );
    
    // Recortar el texto despues del simbolo (~)
    char *xTxT = strchr(xCampos, '~');
    strtok(xTxT,"\n");
    
    // Salvar el deposito original
    sprintf(xCampos,"%.2f",Productos.Dep_castiyo);
    
    // Concatenar(Juntar) deposito con el texto recortado
    strncat(xCampos, xTxT, 250);
    
    // Guardarlo al archivo
    fputs(xCampos,bd_castiyo);

    fclose(bd_castiyo);
} */