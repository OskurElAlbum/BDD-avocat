#include <stdio.h>
#include <stdlib.h>
#include "menuAffichage.h"


char affichageSelect_task(void){                                //Affichage des fonctions utilisable
    printf("\ngestion BDD Cabinet avocat");
    printf("\n\n MENU PRINCIPAL");
    printf("\nSelectionner parmi les actions suivantes");
    printf("\n 1. Afficher donnee d'un dossier");
    printf("\n 2. afficher la liste des dossiers suivis par un collaborateur");
    printf("\n 3. Ajouter un dossier");
    printf("\n 4. Modifier un dossier");
    printf("\n 5. Ajouter un collaborateur");
    printf("\n 6. Modifier un collaborateur");
    printf("\n 7. supprimer un collaborateur");
    printf("\n 8. sauvegarder un fichier");
    printf("\n\n entree un nombre entre 1 et 8\n");
    char state='0';

    while((state <'1')||(state >'8')){

            scanf("%c",&state);
        }
    return state;
}
