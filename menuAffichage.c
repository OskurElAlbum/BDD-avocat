#include <stdio.h>
#include <stdlib.h>
#include "menuAffichage.h"


char affichageSelect_task(void){
    printf("gestion BDD Cabinet avocat");
    printf("\n\n MENU PRINCIPAL");
    printf("\nSelectionner parmi les actions suivantes");
    printf("\n 1. Charger un fichier");
    printf("\n 2. Ajouter un dossier");

    printf("\n 3. Cloturer un dossier");

    printf("\n 3. Supprimer un collaborateur");

    printf("\n 4. Modifier un dossier");
    printf("\n 5. Ajouter un collaborateur");
    printf("\n 6. Modifier un collaborateur");
    printf("\n 7. afficher la liste des dossiers suivis");
    printf("\n 8. statistique collaborateur");
    printf("\n 9. Afficher donnee d'un fichier");

    char state='0';

    while((state <'1')||(state >'9')){
            printf("\n entree un nombre entre 1 et 9\n");
            scanf("%c",&state);
            //printf("hello");
        }
    return state;
}
