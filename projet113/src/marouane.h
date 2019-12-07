#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

typedef struct {int jour,mois,annee;}date;
typedef struct
{int prix_par_jour;
int nbr_places,reste;
 date date_aller,date_retour;
 char marque[50],modele[50],climatiseur[4],id[50];	}voiture;



void formatSTR1(char ch[]);
void deformat1(char ch[]);
int lecture(voiture tablect[]);
int verif_id(char ID[50]);
int ajouter_voiture(voiture v);
int recherche_vouiture(int ja,int ma, int aa,int jr,int mr,int ar,int prix,char clim[5],int places,voiture tabrecherche[200]);







int rechercheid(char id[50]);
int test(char ch[50],char ch1[50]);
void updateVoiture(voiture v[200],int n);
int supprimevoiture(char id[50]);
int modifvoiture(voiture v);
void Affichervoiture (GtkWidget * liste,voiture tablect[], int n);
int recherche_vouiture_client (int ja,int ma, int aa,int jr,int mr,int ar,int prix,char clim[5],int places);

