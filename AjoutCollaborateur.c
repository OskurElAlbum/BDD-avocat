#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"

void AjoutCollaborateur(void){
    char nom[21];
    char prenom[21];
    char metier[10];
    char metierChoix='0';
    size_t fullsize=20;

    int ibcl;
    int ValidationCaractere;

    char validationInformation=0;
while(validationInformation!='1'){
    do
    {
        printf("\nEntrer le nom d'un Collaborateur (20 caractere max)\n");
        scanf("%s",&nom);
        /*ValidationCaractere=0;
        for(ibcl=0;ibcl<strlen(nom);ibcl++){
            if(((nom[ibcl]>=65)&&((nom[ibcl]<=90)))||(((nom[ibcl]>=97)&&(nom[ibcl]<=122)))){
                printf("%d",ibcl);
            }
            else{
                printf("et ouai %d\n",ibcl);
                ValidationCaractere=1;
            }
            printf("pb %d",ValidationCaractere);
        }*/
    }while((strlen(nom)>20))/*||(ValidationCaractere=1))*/;
    //printf("%d tt",ValidationCaractere);
    printf("%d",strlen(nom));
    printf("%s",nom);

    do
    {
        printf("\nEntrer le prenom d'un Collaborateur(20 caractere max)\n");
        scanf("%s",&prenom);
    }
    while(strlen(prenom)>20);
    printf("%d",strlen(prenom));
    printf("%s",prenom);

    printf("\nEntrer le numero corespondant a la proffession de votre collaborateur");
    printf("\n1.Avocat");
    printf("\n2.Clerc");
    while((metierChoix <'1')||(metierChoix >'2'))
        {
        printf("\n entree un nombre entre 1 et 2\n");
        scanf("%s",&metierChoix);
        }
    if(metierChoix=='1'){
        strcpy(metier,"Avocat");
    }
    else if(metierChoix=='2'){
        strcpy(metier,"Clerc");
        //metier="Clerc";
    }
    validationInformation=0;
    printf("Confirmer vous ?\n");
    printf("Nom:%s\n",nom);
    printf("Prenom:%s\n",prenom);
    printf("Metier:%s\n",metier);
    printf("1. OUI\n");
    printf("2. NON\n");
    while((validationInformation <'1')||(validationInformation >'2'))
        {
        scanf("%s",&validationInformation);
        }
}

    /*File*fic;
    fic=fopen("Collaborateur.txt","w");
    if (fic == NULL)
        {
            perror ("erreur de chargement de dossier");
            exit(1);
    }
    fprintf("%s %s %s\n",,,);
    fclose(fic);*/
}
