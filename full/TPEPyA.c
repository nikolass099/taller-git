#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TITULO 100
#define MAX_DESCRIPCION 500

typedef struct {
    char titulo [MAX_TITULO];
    char descripcion [MAX_DESCRIPCION];
    int estado;// 1: pendiente, 2: en progreso, 3: completada, 4: cancelada
    int prioridad; // 1: baja, 2: media, 3: alta
    int dificultad; // 1: fácil, 2: medio, 3: difícil
    int total;
} Tarea;

//funciones de menus

void menuagregar(Tarea lista[], int *total) {
    if (*total>= MAX_TITULO) {
        printf("No se pueden agregar mas tareas. limite alcanzado.\n");
    }
    printf ("\n -agregar nueva tarea-\n");
    
    while(getchar() != '\n');
    printf("ingrese titulo:");
    fgets(lista[*total].titulo, MAX_TITULO, stdin);
    lista[*total].titulo[strcspn(lista[*total].titulo, "\n")] = 0; // Elimina el salto de línea al final
    
    printf("descripcion [enter = sin descripcion]: ");
    fgets(lista[*total].descripcion, MAX_DESCRIPCION, stdin);
    lista[*total].descripcion[strcspn(lista[*total].descripcion, "\n")] = 0; 
    
    printf("ingrese estado: 1- pendiente, 2- en progreso, 3- completada, 4- cancelada: ");
    scanf("%d", &lista[*total].estado);
        
        if (lista[*total].estado < 1 || lista[*total].estado > 4) {
        printf("estado invalido, se asignara pendiente por defecto.\n");
        lista[*total].estado = 1;
        }

    printf("ingrese prioridad: 1- baja, 2- media, 3- alta: ");
    scanf("%d", &lista[*total].prioridad);
        if (lista[*total].prioridad < 1 || lista[*total].prioridad > 3) {
        printf("prioridad invalida, se asignara baja por defecto.\n");
        lista[*total].prioridad = 1;
        }
        
    printf("ingrese dificultad: 1- facil(*  ), 2- medio(** ), 3- dificil(***): ");
    scanf("%d", &lista[*total].dificultad);
        if (lista[*total].dificultad < 1 || lista[*total].dificultad > 3) {
        printf("dificultad invalida, se asignara facil por defecto.\n");
        lista[*total].dificultad = 1;
        }
            
    (*total)++; //incremento de la cantidad total de tareas.
    printf("\n su tarea se guardo con exito! \n");
}

int suma(int a, int b) {
    return a + b;
}


void menueditar(Tarea *lista[], int total) {
    char *estados[]         = { "", "pendiente", "en progreso", "completada", "cancelada" };
    char *prioridades[]     = { "", "baja", "media", "alta" };
    char *dificultades[]    = { "", "facil(*  )", "medio(** )", "dificil(***)" };
    char buffer[MAX_DESCRIPCION];
    char temp[10];
    int len;

    printf("\n-formulario de edicion de tarea-\n");
    
    while(getchar() != '\n'); // Limpiar el buffer de entrada antes de leer nuevas líneas

    printf("titulo: (actual: %s): ", lista[total]->titulo);
        fgets(lista[total]->titulo, MAX_TITULO, stdin);
        len = strlen(lista[total]->titulo);
    
    printf("descripcion: (actual: %s): ", lista[total]->descripcion);
        fgets(lista[total]->descripcion, MAX_DESCRIPCION, stdin);
        len = strlen(lista[total]->descripcion);

   do { 
        if (lista[total]->estado >= 1 && lista[total]->estado <= 4) {
            printf("estado actual: %s\n", estados[lista[total]->estado]);
        } else {
            printf("estado actual: invalido.\n");
        }    
        printf("opciones: 1- pendiente, 2- en progreso, 3- completada, 4- cancelada: ");
        fgets(temp, 10, stdin);
        lista[total]->estado = atoi(temp);
        if (lista[total]->estado < 1 || lista[total]->estado > 4) {
            printf("opcion invalida, intente de nuevo\n");
        }
    } while (lista[total]->estado < 1 || lista[total]->estado > 4);

   do {
        if (lista[total]->prioridad >= 1 && lista[total]->prioridad <= 3) {
            printf("prioridad actual: %s\n", prioridades[lista[total]->prioridad]);
        } else {
            printf("prioridad actual: invalida elegi una nueva\n");
        }
        printf("opciones: 1- baja, 2- media, 3- alta: ");
        fgets(temp, 10, stdin);
        lista[total]->prioridad = atoi(temp);
        if (lista[total]->prioridad < 1 || lista[total]->prioridad > 3) {
            printf("opcion invalida, intente de nuevo\n");
        }
    } while (lista[total]->prioridad < 1 || lista[total]->prioridad > 3);
   
    do {
        if (lista[total]->dificultad >= 1 && lista[total]->dificultad <= 3) {
            printf("dificultad actual: %s\n", dificultades[lista[total]->dificultad]);
        } else {
            printf("dificultad actual: invalida elegi una nueva\n");
        }
        printf("opciones: 1- facil(*  ), 2- medio(** ), 3- dificil(***): ");
        fgets(temp, 10, stdin);
        lista[total]->dificultad = atoi(temp);
        if (lista[total]->dificultad < 1 || lista[total]->dificultad > 3) {
            printf("opcion invalida, intente de nuevo\n");
        }
    } while (lista[total]->dificultad < 1 || lista[total]->dificultad > 3);


      printf("\n ¡tarea guardada con exito! \n");    
}

void menudetalles(Tarea *lista[], int total) {
    printf("\n-Detalles de la tarea-\n");
    
    if (strlen(lista[total]->titulo)> 0){
        printf("Titulo: %s\n", lista[total] ->titulo);
    
    }else{
        printf("titulo: (sin titulo)\n");
    
    }if (strlen(lista[total]->descripcion)> 0){
        printf("Descripcion: %s\n", lista[total]->descripcion);
    
    }else{
        printf("Descripcion: (sin descripcion)\n"); 
}

    if (lista[total]->estado == 1)             printf("Estado: pendiente\n");
        else if (lista[total]->estado == 2)    printf("Estado: en progreso\n");
        else if (lista[total]->estado == 3)    printf("Estado: completada\n");
        else if (lista[total]->estado == 4)    printf("Estado: cancelada\n");
        else                                   printf("Estado: desconocido\n");
    
    if (lista[total]->prioridad == 1)           printf("Prioridad: baja\n");
        else if (lista[total]->prioridad == 2)  printf("Prioridad: media\n");
        else if (lista[total]->prioridad == 3)  printf("Prioridad: alta\n");
        else                                    printf("Prioridad: desconocida\n");

    
    if (lista[total]->dificultad == 1)           printf("facil(*  )\n");
        else if (lista[total]->dificultad == 2)  printf("medio(** )\n");
        else if (lista[total]->dificultad == 3)  printf("dificil(***)\n");
        else                                     printf("desconocida\n");
    
    
    char buffer[10];
    do {
        printf("\npresione 'e' para editar la tarea o 'v' para volver: \n");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == 'e'){
            menueditar(lista, total);
            break;
        }
        else if (buffer[0] == 'v') {
            break;
        }else {
            printf("opcion invalida, intente de nuevo\n");
        }
    } while (1);
}



void menuvertareas(Tarea *lista, int total) {
    if (total == 0) {
        printf("\nNo hay tareas para mostrar.\n");
        return;
    }

   printf("\n --- lista de tareas ---\n");
   for (int i = 0; i < total; i++) {
    printf("\ntarea %d:\n", i + 1);
    printf("Titulo: %s\n", lista[i].titulo);
    printf("Descripcion: %s\n", lista[i].descripcion);
    
    // estado.
    if (lista[i].estado == 1)         printf("Estado: pendiente\n");
     else if (lista[i].estado == 2)   printf("Estado: en progreso\n");
     else if (lista[i].estado == 3)   printf("Estado: completada\n");
     else if (lista[i].estado == 4)   printf("Estado: cancelada\n");
     else                             printf("Estado: desconocido\n");
    
     //prioridad.
    if (lista[i].prioridad == 1)      printf("Prioridad: baja\n");
    else if (lista[i].prioridad == 2) printf("Prioridad: media\n");
    else if (lista[i].prioridad == 3) printf("Prioridad: alta\n");
    else                              printf("Prioridad: desconocida\n");

    //dificultad.
    if (lista[i].dificultad == 1)      printf("Dificultad: facil(*  )\n");
    else if (lista[i].dificultad == 2) printf("Dificultad: medio(** )\n");
    else if (lista[i].dificultad == 3) printf("Dificultad: dificl(***)\n");
    else                               printf("Dificultad: desconocida\n");

   }
}

void menuborrar(Tarea lista[], int *total) {
    if (*total == 0) {
        printf("\nNo hay tareas para borrar.\n");
        return;
    }

    int pos;
    menuvertareas(lista, &total);
    printf("\nIngrese el numero de la tarea que desea borrar: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *total) {
        printf ("Numero de tarea invalido. Solo hay %d tarea(s).\n", *total);
        return;
    }

    for (int i = pos - 1; i < *total - 1; i++) {
        lista[i] = lista[i +1];
    }
 
    (*total)--; // Decremento de la cantidad total de tareas.
    printf ("\nTarea borrada con exito!\n");
}

int main() {
    Tarea lista[MAX_TITULO];
    int total = 0;
    int opcion = 0;
    do {
        printf("\n-Menu principal-\n");
        printf("1. ver tareas\n");
        printf("2. agregar tarea\n");
        printf("3. borrar tarea\n");
        printf("4. editar tarea\n");
        printf("0. salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        

        switch (opcion) {
            case 1:
                menuvertareas(lista, &total);
                break;
            case 2:
                menuagregar(lista, &total);
                break;
            case 3:
                menuborrar(lista, &total);
                break;
            case 4:
                if (total == 0) {
                    printf("\nNo hay tareas para editar.\n");
                } else {
                    int pos;
                    menuvertareas(lista, &total);
                    printf("\nIngrese el numero de la tarea que desea editar: ");
                    scanf("%d", &pos);

                    if (pos < 1 || pos > total) {
                        printf("Numero de tarea invalido. Solo hay %d tarea(s).\n", total);
                    } else {
                        menueditar(lista, pos - 1);
                    }
                }
                break;    
            case 0:
                printf("saliendo del programa...\n");    
                break;
            default:
                printf("Opcion invalida, intente de nuevo.\n");
                break;    
        }
    } while (opcion != 0);
    return 0;
}