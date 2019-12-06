
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"marouane.h"

enum caracteristique_voiture
{
MARQUE,
MODELE,
NBR_PLACE,
CLIMATISEUR,
PRIX,
ID,
RESTE,
JOUR_ALLER,
MOIS_ALLER,
ANNEE_ALLER,
JOUR_RETOUR,
MOIS_RETOUR,
ANNEE_RETOUR,
};


void formatSTR1(char ch[])
{int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]==' ')
ch[i]='_';
}
void deformat1(char ch[])
{int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]=='_')
ch[i]=' ';
}




int lecture(voiture tablect[500])
{int i=0;
FILE* f=fopen("voiture.txt","r");
if(f==NULL) return 0;
else
{while (fscanf(f,"%s %s %f %d %d %s %s", tablect[i].marque, tablect[i].modele, &tablect[i].prix_par_jour, &tablect[i].nbr_places, &tablect[i].reste, tablect[i].climatiseur,tablect[i].id)!=EOF)
{
deformat1(tablect[i].marque);
deformat1(tablect[i].modele);
deformat1(tablect[i].climatiseur);
deformat1(tablect[i].id);

i++;}}
fclose(f);
return i;
}


int verif_id(char ID[20])
{
    voiture tablect[100];
    int n=lecture(tablect);
    for (int i=0; i<n; i++)
    {
        if (!strcmp(ID,tablect[i].id)) return 1; //existe
    }
    return 0;//n'existe pas

}


int ajouter_voiture(voiture v)
{
voiture tablect[100];
if (verif_id(v.id)==0)
{
FILE *f=fopen("voiture.txt","a");

formatSTR1(v.marque);
formatSTR1(v.modele);
formatSTR1(v.climatiseur);
formatSTR1(v.id);
fprintf(f,"%s %s %f %d %d %s %s\n", v.marque, v.modele, v.prix_par_jour, v.nbr_places, v.reste, v.climatiseur,v.id);
fclose(f);
return 1;
}
return 0;
}






















int test1(char ch[20],char ch1[20])
{int i;
if(strlen(ch)!=strlen(ch1))
return 0;
for(i=0;i<strlen(ch);i++)
if(ch[i]!=ch1[i])
return 0;
return 1;
}



void updateVoiture(voiture v[200],int n){
int i;
FILE* f=fopen("voiture1.txt","w");
for(i=0;i<n;i++)
{formatSTR1(v[i].marque);
formatSTR1(v[i].modele);
formatSTR1(v[i].climatiseur);
formatSTR1(v[i].id);
fprintf(f,"%s %s %f %d %d %s %s\n", v[i].marque, v[i].modele, v[i].prix_par_jour, v[i].nbr_places, v[i].reste, v[i].climatiseur,v[i].id);}
fclose(f);
}

int rechercheid(char id[20])
{voiture v[200];
int n=lecture(v);
for(int i=0;i<n;i++)
if((test1(id,v[i].id)==1)) return i;
return -1;
}

int supprimevoiture(char id[20])
{
voiture v[200],x;
int i,n=lecture(v);
for(i=0;i<n;i++)
    if(test1(id,v[i].id)==1)
        {
        x=v[i];
        v[i]=v[n-1];
        v[n-1]=x;
        updateVoiture(v,n-1);
        return 1;
        }
return 0;
}

int modifvoiture(voiture v){
voiture tablect[200];
int i,n=lecture(tablect);
for(i=0;i<n;i++)
if(test(v.id,tablect[i].id)==1)
{tablect[i]=v;
updateVoiture(tablect,n);
return 1;
}
return 0;
}

/*
void Affichervoiture (GtkWidget * liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
voiture tablect[200];
char classe[30],ch[30];
int i,n;
store=NULL;
n=lecture(tablect);
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Modele",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Places",renderer,"text",NBR_PLACE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Climatiseur",renderer,"text",CLIMATISEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



if(n==0)
return;
else
{
for(i=0;i<n;i++)

gtk_list_store_append(store,&iter);
sprintf(classe,"%d\0",tablect[i].nbr_places);

gtk_list_store_append(store,&iter);
sprintf(classe,"%f\0",tablect[i].climatiseur);


gtk_list_store_set(store,&iter,MARQUE,tablect[i].marque,MODELE,tablect[i].modele,NBR_PLACE,tablect[i].nbr_places,CLIMATISEUR,tablect[i].climatiseur,PRIX,tablect[i].prix,ID,tablect[i].id,-1);




gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
*/
