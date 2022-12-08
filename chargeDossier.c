#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"



struct Double_liste *chargeDossier(void)
{
    Liste *listeDossier;
    Liste_Collaborateur *Listecollaborateur;
    Double_liste * Doubleliste = malloc(sizeof(*Doubleliste));

    char etat='0';
    printf("Entrer les fichier que vous voulez charger\n");
    printf("1. Fichier dossier\n");
    printf("2. Fichier collaborateur\n");
    printf("3. Fichier dossier et collaborateur\n");
    while((etat <'1')||(etat >'3')){
            printf("\n entree un nombre entre 1 et 3\n");
            scanf("%s",&etat);
    }
    FILE * fic;
    if (etat =='1'){
        printf("Chargement du fichier des Dossiers\n");
        Doubleliste->Liste_Dossier=UtilisationDossier(fic);
        affichliste(Doubleliste->Liste_Dossier);
        //Doubleliste->Liste_Dossier=listeDossier;
    }
    else if (etat =='2'){
        printf("Chargement fichier des Collaborateurs\n");
        Doubleliste->Liste_Collabo/*Listecollaborateur*/=UtilisationCollaborateur(fic);
        affichlistec(Doubleliste->Liste_Collabo);

        //Doubleliste->Liste_Collabo=Listecollaborateur;
        /*//printf("ouai");
        //printf("%s",Doubleliste->Liste_Collabo);
        Collaborateur *actuel = Doubleliste->Liste_Collabo->premier;
        affichlistec(Doubleliste->Liste_Collabo);*/
        //printf("%s\n", actuel->Nom);

    }
    else if(etat =='3'){
        printf("Chargement des fichier des Dossiers et des Collaborateurs\n");
        Doubleliste->Liste_Dossier=UtilisationDossier(fic);
        Doubleliste->Liste_Collabo=UtilisationCollaborateur(fic);

        //Doubleliste->Liste_Dossier=listeDossier->premier;

        //Doubleliste->Liste_Collabo=Listecollaborateur;
    }
    printf("\ndossier chargee\n\n");
    //printf("%s",Doubleliste->Liste_Collabo);
    return /*Listecollaborateur*/Doubleliste;
}


Liste *UtilisationDossier(FILE * fic)
{
    fic=fopen("Dossier.txt","r");
    if (fic == NULL)
        {
            perror ("erreur de chargement de dossier");
            exit(1);
    }
    Liste *liste = malloc(sizeof(*liste));
    Dossier *dossier = malloc(sizeof(*dossier));

    Dossier *nouveau;
    int iPremier=0;
    while(!feof(fic)){
        nouveau = malloc(sizeof(*nouveau));
        fscanf(fic,"%s %s %s %s %s %s",nouveau->Nom_Dossier,
                                        nouveau->Date_ouverture,
                                        nouveau->Date_fermeture,
                                        nouveau->Etat_Dossier,
                                        nouveau->Nom_avocat,
                                        nouveau->Nom_clerc);
        if(iPremier==0){
           nouveau->suivant=NULL;
           iPremier++;
           //printf("bjr");
           }
        else{
            nouveau->suivant=liste->premier;
        }
        liste->premier=nouveau;
    }
    fclose(fic);

    return liste;
}

void affichliste(Liste *liste);

void affichliste(Liste *liste){
    Dossier *actuel = liste->premier;
    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom_Dossier);
        actuel = actuel->suivant;
    }
}






Liste_Collaborateur *UtilisationCollaborateur(FILE * fic)
{
    fic=fopen("Collaborateur.txt","r");
    if (fic == NULL)
        {
            perror ("erreur de chargement de dossier");
            exit(1);
    }
    Liste_Collaborateur *liste = malloc(sizeof(*liste));
    Collaborateur *collaborateur = malloc(sizeof(*collaborateur));

    Collaborateur *nouveau;
    int ipremier=0;
    while(!feof(fic)){
        nouveau = malloc(sizeof(*nouveau));
        fscanf(fic,"%s %s %s",nouveau->Nom,
                               nouveau->Prenom,
                               nouveau->Metier);
        if(ipremier==0){
           nouveau->suivant=NULL;
           ipremier++;
           }
        else{
            nouveau->suivant=liste->premier;
        }
        liste->premier=nouveau;
    }
    fclose(fic);
    return liste;
}

void affichlistec(Liste_Collaborateur *liste);

void affichlistec(Liste_Collaborateur *liste){

    Collaborateur *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%s\n", actuel->Nom);
        actuel = actuel->suivant;
    }
}
