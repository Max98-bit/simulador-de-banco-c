// VARIABLES GLOBALES
#define BORRAR_LA_PANTALLA system("cls");
#define DOBLE_TAB printf("\t#\t");
#define TAB printf("\t");
#define SALTO_DE_LINEA printf("\n");
#define SEPARADOR printf("========================================\n");
#define PAUSA system("pause");

char opc_menuPrincipal;

struct Registro_de_productos{
    char Sucursal[50];
    char Nombre_producto[50];
    int ID_castiyo;
    int Dep_castiyo;
    float Costo_producto;
};

struct Registro_de_actividad{
    int ID;
    int ID_castiyo;
    char Sucursal[50];
    char Nombre_producto[50];
    float Costo_producto;
};

struct CASTIyO{
    int ID;
    char Nombre[50];
    char Apellido_paterno[50];
    char Apellido_materno[50];
    char Fecha_de_nacimiento[11];
    char Domicilio[250];
    char Pais[50];
    int Deposito;
};

struct Registro_de_productos Productos;
//struct Registro_de_actividad Actividades;
//struct CASTIyO Cuentas;
void opciones_menu_principal();
int fnc_verificar_cuenta(int id_cuenta);
void fnc_menu_comprar();
void fnc_actualizar_base_de_datos_castiyo();


void opciones_menu_principal(){
    
    // Titulo
    TAB; printf("TIENDA SOS \\(*+*)/"); SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("1 > Comprar"); SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Salir del programa"); SALTO_DE_LINEA;

}

void fnc_menu_comprar(){

    // Titulo
    TAB; printf("TIENDA SOS \\(*+*)/"); SALTO_DE_LINEA;
    TAB; printf("Comprar"); SALTO_DE_LINEA;
    SEPARADOR;

    fflush(stdin);
    SALTO_DE_LINEA;
    TAB; printf("Introduzca el nombre del producto: ");
    gets(Productos.Nombre_producto);
    
    if( *Productos.Nombre_producto != '0'){

        // Capturar el costo del producto
        TAB; printf("Introduzca el costo del producto: ");
        scanf("%f",&Productos.Costo_producto);

        // Capturar la cuenta del usuario
        TAB; printf("Introduzca la cuenta CASTIyO: ");
        scanf("%i",&Productos.ID_castiyo);

        // Verificar si el usuario existe o tiene 
        if( fnc_verificar_cuenta( Productos.ID_castiyo ) == Productos.ID_castiyo &&
            Productos.Dep_castiyo >= Productos.Costo_producto ){
                Productos.ID_castiyo = fnc_verificar_cuenta(Productos.ID_castiyo);
                fnc_actualizar_base_de_datos_castiyo();
                TAB; printf("COMPRA APROBADA"); SALTO_DE_LINEA;
                TAB; printf("Cantidad dep: %i", Productos.Dep_castiyo); SALTO_DE_LINEA;

        }else{
            TAB; printf("COMPRA RECHAZADA"); SALTO_DE_LINEA;
        }

        SALTO_DE_LINEA;
        PAUSA;
    }
} // Fin fnc_comprar()

int fnc_verificar_cuenta(int id_cuenta){
    FILE *archivo = fopen(".%%CASTIyO%%","r");

    if( archivo == NULL){
        perror("Lo siento, no hay conexion al banco.");
        exit(1);
    }

    char leerDatos[250];
    int cantidad_de_cuentas;
    int Encotrado = 0;
    int _id;
    // Leer la primera linea
    fgets(leerDatos,250,archivo);
    strtok(leerDatos,"#");
    cantidad_de_cuentas = atoi(leerDatos);

    if( cantidad_de_cuentas > 0){
        int i;
        for(i = 1; i <= cantidad_de_cuentas; i++){
            fgets(leerDatos,250,archivo);
            strtok(leerDatos,"~");

            if( atoi(leerDatos) == id_cuenta){
                _id = atoi(leerDatos);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);

                // Obtener el deposito
                fgets(leerDatos,250,archivo);
                strtok(leerDatos,"~");
                Productos.Dep_castiyo = atoi(leerDatos);

                Encotrado = 1;
                return _id;
            }else{
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
                fgets(leerDatos,250,archivo);
            }


        }

        if( Encotrado == 0)
            return 0;
    }
    fclose(archivo);
    
}// Fin fnc_verificar_cuenta()

void fnc_actualizar_base_de_datos_castiyo(){
    
    // VARIABLES GLOBALES
    long int size;
    char registro[250];
    char xActualizar[250];
    int Mul = Productos.ID_castiyo * 9;
    sprintf(xActualizar,"%i~ Deposito: No borrar, ni modificar", Productos.Dep_castiyo - (int) Productos.Costo_producto);
    int letras_act = strlen(xActualizar)+1;

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
    for(i=1; i < Mul ; i++ ){
        // Capturar el contenido del archivo por filas
        fgets(registro,250,archivo_registro);
        // Capturar la posicion del contenido del archivo
        // previamente capturado 
        size = ftell (archivo_registro);
    }

    // Preguntar si las letras al actualizar el contenido del archivo es mayor
    // que el contenido previamente capturado, de ser asi 
    // introducir el contenido al archivo de lo contrario vamos a modificar el contenido
    if( letras_act >= strlen(registro) ){

        // Introducir el contenido con la posicion previamente obtenido
        fseek ( archivo_registro , size , SEEK_SET );
        fputs(xActualizar,archivo_registro);
    
    }else{ 
        
        // Restar el contenido obtenido previamente
        // con el contenido a actualizar
        int letras_faltantes = strlen(registro) - letras_act;

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