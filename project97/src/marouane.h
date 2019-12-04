#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

typedef struct {int jour,mois,annee;}date;
typedef struct
{float prix_par_jour;
int nbr_places,reste;
 date date_aller,date_retour;
 char marque[10],modele[10],climatiseur[4],id[20];	}voiture;



void formatSTR1(char ch[]);
void deformat1(char ch[]);
int lecture(voiture tablect[]);
int verif_id(char ID[20]);
int ajouter_voiture(voiture v);








int rechercheid(char id[20]);
int test(char ch[20],char ch1[20]);
void updateVoiture(voiture v[200],int n);
int supprimevoiture(char id[20]);
int modifvoiture(voiture v);
void Affichervoiture (GtkWidget * liste,voiture tablect[], int n);
