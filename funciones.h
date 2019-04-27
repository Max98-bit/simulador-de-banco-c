void opciones_menu_principal(){
    TAB; printf("BANKO CASTIyO \\(*__*)/");                     SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("1 > Crear cuentas");                     SALTO_DE_LINEA;
    DOBLE_TAB; printf("2 > Buscar cuentas");                    SALTO_DE_LINEA;
    DOBLE_TAB; printf("3 > Modificar cuentas");                 SALTO_DE_LINEA;
    DOBLE_TAB; printf("4 > Eliminar cuentas");                  SALTO_DE_LINEA;
    DOBLE_TAB; printf("5 > Ver cuentas (%i)",contadorID);       SALTO_DE_LINEA;
    DOBLE_TAB; printf("6 > Transferencia");                     SALTO_DE_LINEA;
    DOBLE_TAB; printf("7 > Deposito");                          SALTO_DE_LINEA;
    DOBLE_TAB; printf("8 > Borrar base de datos");              SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Salir del programa");                SALTO_DE_LINEA;
}

void fnc_menu_crear_cuentas(){
    contadorID++;
    char c_campos[50];
    int campos_correcto = 0;

    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Crer cuentas"); SALTO_DE_LINEA;
    SEPARADOR;
    DOBLE_TAB; printf("Nota: Los depositos deben ser los siguientes: "); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Deposito 100, Deposito 200 "); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Deposito 500, Deposito 1000 "); SALTO_DE_LINEA;
    DOBLE_TAB; printf("Deposito 1500, Deposito 2000 "); SALTO_DE_LINEA;
    DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
    SEPARADOR;

    Usuarios[contadorID].ID = contadorID;

    // Capturar nombre [...]
    fflush(stdin); // Liberar teclado
    TAB; printf("Nombre: "); 
    gets(c_campos);
    // Volver al menu principal
    if( strcmp(c_campos,"0")  != 0 && atoi(c_campos) == 0 && strlen(c_campos) > 0){
    // [...] Capturar nombre
    campos_correcto++;
    strcpy(Usuarios[contadorID].Nombre, c_campos);
    SALTO_DE_LINEA;
    
    // Capturar apellido paterno
    fflush(stdin); // Liberar teclado
    TAB; printf("Apellido paterno: "); 
    gets(c_campos);
    if( strcmp(c_campos,"0") != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Apellido_paterno, c_campos);
    }else{
        TAB; printf("**Apellido paterno incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar apellido materno
    fflush(stdin); // Liberar teclado
    TAB; printf("Apellido materno: "); 
    gets(c_campos);
    if( strcmp(c_campos,"0")  != 0 && strlen(c_campos) > 0 && atoi(c_campos) == 0 ){
        campos_correcto++;
        strcpy(Usuarios[contadorID].Apellido_materno,c_campos);
    }else{
        TAB; printf("**Apellido materno incorrecto! \n");
    }
    SALTO_DE_LINEA;

    // Capturar el domicilio
    fflush(stdin); // Liberar teclado
    TAB; printf("Domicilio: "); 
    gets(c_campos);
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
    int iDeposito;
    TAB; printf("Deposito: "); 
    scanf("%i",&iDeposito);
    if( iDeposito == 100 || iDeposito == 200 || iDeposito == 500 ||
        iDeposito == 1000 || iDeposito == 1500 || iDeposito == 2000){
        campos_correcto++;
        Usuarios[contadorID].Deposito = iDeposito;
    }else{
        TAB; printf("**Deposito incorrecto! \n");
    }
    SALTO_DE_LINEA;

    if(campos_correcto == 6){
        printf("Usuario registrado exitosamente.");
        actualizar_base_de_datos();
        SALTO_DE_LINEA;
    }else{
        contadorID--;
        TAB; printf("Lo siento, fallo al registrar el usuario."); SALTO_DE_LINEA;
        TAB; printf("favor de introducir datos que sean correcto."); SALTO_DE_LINEA;
        SALTO_DE_LINEA;
    }

    PAUSA;
    } // Fin de if != 0 || > 0 || == 0
}

void fnc_menu_buscar_cuentas(){
    int opc_menu, i, Encontrado;

    do{
        BORRAR_LA_PANTALLA;
        Encontrado = 0;
        TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
        TAB; printf("Buscar cuentas"); SALTO_DE_LINEA;
        SEPARADOR;
        DOBLE_TAB; printf("1 > Buscar por ID"); SALTO_DE_LINEA;
        DOBLE_TAB; printf("2 > Buscar por NOMBRE"); SALTO_DE_LINEA;
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
                        TAB; printf("Usuario (ID): %i",Usuarios[i].ID); SALTO_DE_LINEA;
                        TAB; printf("Nombre: %s",Usuarios[i].Nombre); SALTO_DE_LINEA;
                        TAB; printf("Apellido paterno: %s",Usuarios[i].Apellido_paterno); SALTO_DE_LINEA;
                        TAB; printf("Apellido materno: %s",Usuarios[i].Apellido_materno); SALTO_DE_LINEA;
                        TAB; printf("Domicilio: %s",Usuarios[i].Domicilio); SALTO_DE_LINEA;
                        TAB; printf("Pais: %s",Usuarios[i].Pais); SALTO_DE_LINEA;
                        TAB; printf("Deposito: %i",Usuarios[i].Deposito); SALTO_DE_LINEA;
                        SEPARADOR;
                        Encontrado = 1;
                        break;
                    }else
                        Encontrado = 0;
                }

                if( Encontrado == 0){
                    TAB; printf("Lo siento, el usuario no existe"); SALTO_DE_LINEA;
                }

                getch();
            }break;

            // Buscar por nombre
            case 2:{
                fflush(stdin);
                char buscar_x_nombre[50];
                TAB; printf("Introduza el NOMBRE del usuario > ");
                gets(buscar_x_nombre);

                for(i=1; i <= contadorID; i++){
                    if( *Usuarios[i].Nombre == *buscar_x_nombre){
                        Encontrado++;
                        SALTO_DE_LINEA;
                        TAB; printf("Usuario (ID): %i", Usuarios[i].ID); SALTO_DE_LINEA;
                        TAB; printf("Nombre: %s", Usuarios[i].Nombre); SALTO_DE_LINEA;
                        TAB; printf("Apellido paterno: %s", Usuarios[i].Apellido_paterno); SALTO_DE_LINEA;
                        TAB; printf("Apelldio materno: %s", Usuarios[i].Apellido_materno); SALTO_DE_LINEA;
                        TAB; printf("Domicilio: %s", Usuarios[i].Domicilio); SALTO_DE_LINEA;
                        TAB; printf("Pais: %s", Usuarios[i].Pais); SALTO_DE_LINEA;
                        TAB; printf("Deposito: %i", Usuarios[i].Deposito); SALTO_DE_LINEA;
                        SEPARADOR;
                        
                    }
                }

                if( Encontrado == 0)
                SALTO_DE_LINEA;

                TAB; printf("Coincidencias encontrados %i.",Encontrado);
                SALTO_DE_LINEA;
                getch();
            }break;
        }

    }while( opc_menu != 0);
}

void fnc_menu_modificar_cuentas(){
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
                int buscar_x_id;
                printf("Introduzca el ID del usuario > ");
                scanf("%i",&buscar_x_id);
        
        if( buscar_x_id != 0){

                for(i=1; i <= contadorID; i++){
                    if(Usuarios[i].ID == buscar_x_id){
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
                        
                        actualizar_base_de_datos();
                        PAUSA;
                        Encontrado = 1;
                        break;
                    }else{
                        Encontrado = 0;
                    }
                }

            if( Encontrado == 0){
               BORRAR_LA_PANTALLA;
               TAB;
               printf("Lo siento, no existe ningun usuario con el id #%i",buscar_x_id);
               SALTO_DE_LINEA;
               getch();
            }

        }
}

void fnc_menu_ver_cuentas(){
    
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Ver cuentas"); SALTO_DE_LINEA;
    SEPARADOR;

    int i;
    for(i=1; i <= contadorID; i++){

        SALTO_DE_LINEA;
        TAB; printf("ID: %i",Usuarios[i].ID); SALTO_DE_LINEA;
        TAB; printf("Nombre: %s",Usuarios[i].Nombre); SALTO_DE_LINEA;
        TAB; printf("Apellido paterno: %s",Usuarios[i].Apellido_paterno); SALTO_DE_LINEA;
        TAB; printf("Apellido materno: %s",Usuarios[i].Apellido_materno); SALTO_DE_LINEA;
        TAB; printf("Domicilio: %s",Usuarios[i].Domicilio); SALTO_DE_LINEA;
        TAB; printf("Pais: %s",Usuarios[i].Pais); SALTO_DE_LINEA;
        TAB; printf("Deposito: %i",Usuarios[i].Deposito); SALTO_DE_LINEA;
        SEPARADOR;
    }

    PAUSA;
}

void fnc_transferencia_bancaria(){
    TAB; printf("BANKO CASTIyO \\(*__*)/"); SALTO_DE_LINEA;
    TAB; printf("Transferencia bancaria"); SALTO_DE_LINEA;
    SEPARADOR;
    PAUSA;
}

void fnc_deposito_de_cuentas(){
   int buscar_x_id;
   int i;
   int Encontrado;

   TAB; printf("BANKO CASTIyO \\(*__*)/");  SALTO_DE_LINEA;
   TAB; printf("Deposito de cuentas");  SALTO_DE_LINEA;
   SEPARADOR;
   DOBLE_TAB; printf("Solo se puede realizar los siguientes depositos:"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("Deposito $100, Deposito $200"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("Deposito $500, Deposito $1000"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("Deposito $1500, Deposito $2000"); SALTO_DE_LINEA;
   DOBLE_TAB; printf("0 > Volver al menu principal"); SALTO_DE_LINEA;
   SEPARADOR;

   fflush(stdin);
   TAB; printf("Introduza el id del usuario > ");
   scanf("%i", &buscar_x_id);

    if( buscar_x_id != 0 ){

        for(i=1; i <= contadorID; i++){
    
            if( Usuarios[i].ID == buscar_x_id){
           
                // Modificar / Capturar el deposito
                SALTO_DE_LINEA;
                fflush(stdin);
                int x_deposito;
                TAB; printf("Cuanto desea depositar? $");
                scanf("%i",&x_deposito);
                
                if( x_deposito == 100 || x_deposito == 200 || x_deposito == 500 || 
                    x_deposito == 1000 || x_deposito == 1500 || x_deposito == 2000){
                        BORRAR_LA_PANTALLA;
                        TAB; printf("BANKO CASTIyO \\(*__*)/");  SALTO_DE_LINEA;
                        TAB; printf("Deposito de cuentas");  SALTO_DE_LINEA;
                        TAB; printf("Socursal av. mexico calle: #7 ");  SALTO_DE_LINEA;
                        TAB; printf("Fecha: 26/04/2019");  SALTO_DE_LINEA;
                        SEPARADOR;
                        TAB; printf("Id de cuenta: %i",Usuarios[i].ID); SALTO_DE_LINEA;
                        TAB; printf("Estado de cuenta: %i",Usuarios[i].Deposito); SALTO_DE_LINEA;
                        TAB; printf("Deposito importado: %i",x_deposito); SALTO_DE_LINEA;
                        TAB; printf("Deposito sub-total: %i + %i", Usuarios[i].Deposito, x_deposito); SALTO_DE_LINEA;
                        TAB; printf("Deposito total: %i", Usuarios[i].Deposito + x_deposito); SALTO_DE_LINEA;
                        Usuarios[i].Deposito += x_deposito;

                        actualizar_base_de_datos();
            }else{
                BORRAR_LA_PANTALLA;
                TAB; printf("Lo siento, el deposito no se pudo realizar."); SALTO_DE_LINEA;
                TAB; printf("Vuelve a intentarlo mas tarde, o"); SALTO_DE_LINEA;
                TAB; printf("realize un deposito valido."); SALTO_DE_LINEA;
                SALTO_DE_LINEA;
            }

           PAUSA;
           Encontrado = 1;
           break;

       }// Fin del for
       else Encontrado = 0;
    
    } 

    // Cuando el usuario no existe
   if( Encontrado == 0){
        BORRAR_LA_PANTALLA;
        TAB;
        printf("Lo siento, no existe ningun usuario con el id #%i",buscar_x_id);
        SALTO_DE_LINEA;
        getch();
    }

    } // Fin del if !=0

} // Fin de la funcion

void actualizar_base_de_datos(){
    FILE *archivo = fopen(".%%CASTIyO%%","w");

    if( archivo == NULL){
        ferror("Error de archivo.\n");
        exit(1);
    }

    
    char xCampos[250];
    sprintf(xCampos,"%i#Warning: No borrar, ni modificar\n",contadorID);
    fputs(xCampos,archivo);

    int i;
    for(i=1; i <= contadorID; i++){
        // Guardar el nombre
        sprintf(xCampos,"%s~ Nombre: No borrar, ni modificar\n",Usuarios[i].Nombre);
        fputs(xCampos,archivo);

        // Guardar el apellido paterno
        sprintf(xCampos,"%s~ Apellido paterno: No borrar, ni modificar\n",Usuarios[i].Apellido_paterno);
        fputs(xCampos,archivo);

        // Guardar el apellido materno
        sprintf(xCampos,"%s~ Apellido materno: No borrar, ni modificar\n",Usuarios[i].Apellido_materno);
        fputs(xCampos,archivo);

        // Guardar el domicilio
        sprintf(xCampos,"%s~ Domicilio: No borrar, ni modificar\n",Usuarios[i].Domicilio);
        fputs(xCampos, archivo);

        // Guardar el pais
        sprintf(xCampos,"%s~ Pais: No borrar, ni modificar\n",Usuarios[i].Pais);
        fputs(xCampos,archivo);

        // Guardar el deposito
        sprintf(xCampos,"%i~ Deposito: No borrar, ni modificar\n",Usuarios[i].Deposito);
        fputs(xCampos,archivo);

        // Guardar separador
        sprintf(xCampos,"#######################################%i\n",Usuarios[i].ID);
        fputs(xCampos,archivo);
    }

    fclose(archivo);

    printf("\nBase de datos actualizados\n");
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
            // Obtener el nombre
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Nombre,xCampos);

            // Obtener el apellido paterno
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Apellido_paterno,xCampos);

            // Obtener el apellido materno
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Apellido_materno,xCampos);

            // Obtener el domicilio
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Domicilio,xCampos);

            // Obtener el pais
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            strcpy(Usuarios[i].Pais,xCampos);

            // Obtener el deposito
            fgets(xCampos,250,archivo);
            strtok(xCampos,"~");
            Usuarios[i].Deposito = atoi(xCampos);

            // Obtener el separador sin ninguna accion
            fgets(xCampos,250,archivo);
            Usuarios[i].ID = i;
        }

    }else{
        contadorID = 0;
    }

    fclose(archivo);
}