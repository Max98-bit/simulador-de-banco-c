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
    char Domicilio[100];
    char Pais[50];
    int Deposito;
}Usuarios[20];
