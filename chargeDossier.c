#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chargeDossier.h"
#include "ajoutDossier.h"

Liste *listeDossier;
Liste_Collaborateur *Listecollaborateur;

Liste *chargeDossier(void)
{
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
        listeDossier=UtilisationDossier(fic);
        affichliste(listeDossier);
    }
    else if (etat =='2'){
        printf("Chargement fichier des Collaborateurs\n");
        Listecollaborateur=UtilisationCollaborateur(fic);
        supprimerCollaborateur(Listecollaborateur);
        affichlistec(Listecollaborateur);

    }
    else if(etat =='3'){
        printf("Chargement des fichier des Dossiers et des Collaborateurs\n");
        listeDossier=UtilisationDossier(fic);
        Listecollaborateur=UtilisationCollaborateur(fic);
    }
    printf("\ndossier chargee\n\n");
    return listeDossier;
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
void supprimerCollaborateur(Liste_Collaborateur *Listecollaborateur);
void supprimerCollaborateur(Liste_Collaborateur *Listecollaborateur){
    char Suppression[20];
    affichlistec(Listecollaborateur);
    printf("entrer le nom du Collaborateur a Supprimer\n");
    scanf("%s",Suppression);
    int i=0;
    Collaborateur *actuel = Listecollaborateur->premier;
    while (strcmp(actuel->Nom,Suppression)!=0)          //Affiche les informations du dossier
    {
        actuel = actuel->suivant;
        i++;
    }
    int iCompare=0;
    Collaborateur *precedent = Listecollaborateur->premier;
    while(iCompare!=i-1){
        precedent = precedent->suivant;
        iCompare++;
    }
        //Collaborateur *Supprimer = Listecollaborateur->premier;
        precedent->suivant = actuel->suivant;
        free(actuel);

    FILE * fic;
    fic=fopen("Collaborateur.txt","w");
    Collaborateur *listeSupprimer= Listecollaborateur->premier;
    int i2=0;
    while(listeSupprimer!=NULL){
            if(listeSupprimer->suivant==NULL)
        {
            fprintf(fic,"%s %s %s",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);// dernière ligne du fichier,on évite le retour à la ligne pour la dernière ligne.
        }
        else{
        fprintf(fic,"%s %s %s\n",listeSupprimer->Nom,listeSupprimer->Prenom,listeSupprimer->Metier);

        }
        listeSupprimer = listeSupprimer->suivant;
    }
    //fprintf(fic,"test");
    fclose(fic);
}
