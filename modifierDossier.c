#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supprimerCollaborateur.h"
#include "chargeDossier.h"
#include "modifierCollaborateur.h"

//modifie les champs d'un dossier spécifique
void modifierDossier(Liste *liste){
    char Modification[20];
    int ValidationNomDossier=0;
    int ValidationDateOuverture=0;
    int ValidationEtatDossier=0;
    int ValidationMetierClerc=0;
    int ValidationMetierAvocat=0;

    char ModificationMetier[20];

    affichliste(liste);
    printf("entrer le nom du Dossier a Modifier\n");

    Dossier *actuel;

    //sécuriter nom à modifier
    int ValidationNom=0;
    while(ValidationNom!=1){
        actuel = liste->premier;
        scanf("%s",&Modification);
        while((actuel!=NULL)&&(ValidationNom!=1)){
            if(strcmp(actuel->Nom_Dossier,Modification)==0){
                ValidationNom=1;
            }
            else{
               actuel= actuel->suivant;
            }
        }
    }

    //Affiche les informations du dossier
    while (strcmp(actuel->Nom_Dossier,Modification)!=0)
    {
        actuel = actuel->suivant;
    }
    afficheChamps(actuel);

    //cloturerDossier(liste);
    printf("Voulez-vous modifier le nom du dossier");
    ValidationNomDossier=validation();
    modificationNomDossier(ValidationNomDossier,actuel);

    printf("Voulez-vous modifier la date d'ouverture du dossier");
    ValidationDateOuverture=validation();
    modificationDateOuverture(ValidationDateOuverture,actuel);

    printf("Voulez-vous modifier l'etat du dossier");
    ValidationEtatDossier=validation();
    modificationEtatDossier(ValidationEtatDossier,actuel);

    printf("Voulez-vous modifier le nom de l'avocat en charge du dossier");
    ValidationMetierAvocat=validation();
    modificationMetierAvocat(ValidationMetierAvocat,actuel);

    printf("Voulez-vous modifier le nom du clerc en charge du dossier");
    ValidationMetierClerc=validation();
    modificationMetierClerc(ValidationMetierClerc,actuel);

    ecritureFichierDossier(liste);
}

//Affiche les champs du collaborateur
void afficheChamps(Dossier *dossier){
    printf("Nom dossier :%s\n",dossier->Nom_Dossier);
    printf("Date d'ouverture du dossier :%s\n",dossier->Date_ouverture);
    printf("Date de fermeture du dossier  :%s\n",dossier->Date_fermeture);
    printf("Etat du dossier :%s\n",dossier->Etat_Dossier);
    printf("Nom de l'avocat en charge du dossier :%s\n",dossier->Nom_avocat);
    printf("Nom du clerc en charge du dossier :%s\n",dossier->Nom_clerc);
    printf("\n");
}

//Modifie le champ nom
void modificationNomDossier(int ValidationNomDossier,Dossier *actuel){
    char ModificationNomDossier[20];

    if(ValidationNomDossier==1){
        printf("Entrer le nouveau nom du dossier\n");
        scanf("%s",&ModificationNomDossier);
        strcpy(actuel->Nom_Dossier,ModificationNomDossier);
        printf("Le nouveau nom du dossier est %s",actuel->Nom_Dossier);
        printf("\n");
    }
    else{
        printf("Le nom du dossier n'est pas modifier\n");
    }
}

//Modifie le champ prenom
void modificationDateOuverture(int ValidationDateOuverture,Dossier *actuel){


    if(ValidationDateOuverture==1){
        printf("Entrer la nouvelle date d'ouverture du dossier\n");
        testDate(actuel->Date_ouverture);
        printf("La nouvelle date d'ouverture est %s",actuel->Date_ouverture);
        printf("\n");
    }
    else{
        printf("La date d'ouverture n'est pas modifier\n");
    }
}

//Modifie le champ nom du métier de l'avocat
void modificationMetierAvocat(int ValidationMetierAvocat,Dossier *actuel){
    char ModificationMetierAvocat[20];

    if(ValidationMetierAvocat==1){
        printf("Entrer le nom du nouvel Avocat\n");
        scanf("%s",&ModificationMetierAvocat);
        strcpy(actuel->Nom_avocat,ModificationMetierAvocat);
        printf("Le nouvelle avocat est %s",actuel->Nom_avocat);
        printf("\n");
    }
    else{
        printf("L'avocat n'est pas modifier\n");
    }
}

//Modifie le champ nom du métier du clerc
void modificationMetierClerc(int ValidationMetierClerc,Dossier *actuel){
    char ModificationMetierClerc[20];

    if(ValidationMetierClerc==1){
        printf("Entrer le nom du nouveau Clerc\n");
        scanf("%s",&ModificationMetierClerc);
        strcpy(actuel->Nom_clerc,ModificationMetierClerc);
        printf("Le nouvelle clerc est %s",actuel->Nom_clerc);
        printf("\n");
    }
    else{
        printf("Le Clerc n'est pas modifier\n");
    }
}

//Réecrie le fichier des dossiers
void ecritureFichierDossier(Liste *liste){
    FILE * fic;
    fic=fopen("Dossier.txt","w");
    Dossier *actuel= liste->premier;
    while(actuel!=NULL){
            if(actuel->suivant==NULL)
        {
            fprintf(fic,"%s %s %s %s %s %s",actuel->Nom_Dossier,actuel->Date_ouverture,actuel->Date_fermeture,actuel->Etat_Dossier,actuel->Nom_avocat,actuel->Nom_clerc);//on évite le retour à la ligne pour la dernière ligne.
        }
        else{
        fprintf(fic,"%s %s %s %s %s %s\n",actuel->Nom_Dossier,actuel->Date_ouverture,actuel->Date_fermeture,actuel->Etat_Dossier,actuel->Nom_avocat,actuel->Nom_clerc);

        }
        actuel = actuel->suivant;
    }
    fclose(fic);
}

//Modifie l'état du dossier et permet de le cloturer
void modificationEtatDossier(int ValidationEtatDossier,Dossier *actuel){
    char ModificationEtatDossier=0;

    if(ValidationEtatDossier==1){
        printf("Entrer le nouvelle Etat du dossier\n");
        printf("1. en cours\n");
        printf("2. annule\n");
        printf("3. cloture\n");

        while((ModificationEtatDossier <'1')||(ModificationEtatDossier >'3')){
            scanf("%c",&ModificationEtatDossier);
        }
        if(ModificationEtatDossier=='1'){
            strcpy(actuel->Etat_Dossier,"en_cours");
        }
        else if(ModificationEtatDossier=='2'){
                printf("oka");
            strcpy(actuel->Etat_Dossier,"annule");
        }
        else if(ModificationEtatDossier=='3'){
            strcpy(actuel->Etat_Dossier,"cloture");
            printf ("Entrer la date de cloture du dossier : ");
            testDate(actuel->Date_ouverture);
        }
    }
    else{
        printf("L'état du dossier n'est pas modifie\n");
    }
}

void testDate(char *date);
void testDate(char *date)
{
    int flag = 1 ;
    while (flag == 1)
    {
        flag = 0;
        if ((date[0] > 0x34)||(date[0] < 0x30)) flag = 1;
        if ((date[1] > 0x39)||(date[1] < 0x30)) flag = 1;
        if (date[2] != 0x2F ) flag = 1;
        if ((date[3] > 0x31)||(date[3] < 0x30)) flag = 1;
        if ((date[4] > 0x39)||(date[4] < 0x30)) flag = 1;
        if (date[5] != 0x2F ) flag = 1;
        if ((date[6] > 0x39)||(date[6] < 0x30)) flag = 1;
        if ((date[7] > 0x39)||(date[7] < 0x30)) flag = 1;
        if ((date[8] > 0x39)||(date[8] < 0x30)) flag = 1;
        if ((date[9] > 0x39)||(date[9] < 0x30)) flag = 1;
        if (date[10] != 0x00 ) flag = 1;
        if (flag == 1 )
        {
            printf ("\nveuiller rentrer la date au format JJ/MM/AAAA : ");
            scanf ("%s",date);
        }

    }
}
