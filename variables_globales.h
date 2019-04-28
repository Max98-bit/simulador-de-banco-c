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
    char Fecha_de_nacimiento[50];
    char Domicilio[250];
    char Pais[50];
    int Deposito;
}Usuarios[50];

void fnc_mostrar_datos_de_usuarios(int i);
void opciones_menu_principal();
void fnc_menu_crear_cuentas();
void fnc_menu_buscar_cuentas();
void fnc_menu_modificar_cuentas();
void  fnc_menu_eliminar_cuentas();
void fnc_menu_ver_cuentas();
void fnc_transferencia_bancaria();
void fnc_deposito_de_cuentas();
void fnc_menu_retirar_deposito();
void actualizar_base_de_datos();
void inicializar_programa();