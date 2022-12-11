#include <stdio.h>

struct Double_liste *chargeDossier(void);
struct Liste *UtilisationDossier(FILE * fic);
void affichliste(struct Liste *liste);
struct Liste_Collaborateur *UtilisationCollaborateur(FILE * fic);
void affichlistec(struct Liste_Collaborateur *liste);

typedef struct Dossier Dossier;

//Type structure d'un dossier
struct Dossier{
char Nom_Dossier[20];
char Date_ouverture[20];
char Date_fermeture[20];
char Etat_Dossier[20];
char Nom_avocat[20];
char Nom_clerc[20];
struct Dossier* suivant;
};

//Type structure de la liste des dossier
typedef struct Liste Liste;
struct Liste
{
    Dossier *premier;
};

//type structure d'un collaborateur
typedef struct Collaborateur Collaborateur;
struct Collaborateur{
char Nom[20];
char Prenom[20];
char Metier[20];
struct Collaborateur* suivant;
};

//Type structure de la liste des collaborateur
typedef struct Liste_Collaborateur Liste_Collaborateur;
struct Liste_Collaborateur
{
    Collaborateur *premier;
};

//Type structure contenant la liste des dosssiers et des collaborateurs
typedef struct Double_Liste Double_liste;
struct Double_Liste{
   Liste * Liste_Dossier;
   Liste_Collaborateur * Liste_Collabo;
};
