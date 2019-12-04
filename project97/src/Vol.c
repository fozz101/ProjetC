#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtkclist.h>
#include<gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "Vol.h"
/*jihen*/
int remplir_tab_avec_la_liste_des_vols(Vol tab[500])
{ int m;
 FILE* f=fopen("Vol.txt","r");
if (f!=NULL)
 while (fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d %d %d %d\n" , tab[m].identifiant,tab[m].origine,tab[m].destination,tab[m].compagnie,&tab[m].date.jours,&tab[m].date.mois,&tab[m].date.annee,tab[m].heure_dep,tab[m].heure_arriv,tab[m].aeroport_dep,tab[m].aeroport_arriv,&tab[m].prix,&tab[m].nbre_de_places,&tab[m].classe,&tab[m].etats) !=EOF)
m++;
return m;
fclose(f);
}

void verif_vol_dispo(Vol tab[],Vol d,Vol x2[500],int m,int *q)
{int i;
for (i=0;i<m;i++)
if ( (strcmp(tab[i].origine,d.origine)==0) && (strcmp(tab[i].destination,d.destination)==0) && (tab[i].nbre_de_places>=d.nbre_de_places) && (tab[i].date.jours==d.date.jours) && (tab[i].date.mois==d.date.mois) && (tab[i].date.annee==d.date.annee) && (tab[i].classe==d.classe) && (tab[i].etats==0)
)
{x2[*q]=tab[i];
(*q)++;}
}

void ajouter_tab_ret_ds_fichier(Vol x3[],int c)
{FILE* f=fopen("fich_temp_ret.txt","w");
int i;
for(i=0;i<c;i++)
{formatSTR(x3[i].identifiant);
formatSTR(x3[i].compagnie);
formatSTR(x3[i].heure_dep);
formatSTR(x3[i].heure_arriv);
formatSTR(x3[i].aeroport_dep);
formatSTR(x3[i].aeroport_arriv);
fprintf(f,"%s %s %s %s %s %s %d %d\n",x3[i].identifiant,x3[i].compagnie,x3[i].heure_dep,x3[i].heure_arriv,x3[i].aeroport_dep,x3[i].aeroport_arriv,x3[i].prix,x3[i].nbre_de_places);
} fclose(f);}
ajouter_tab_all_ds_fichier(Vol x4[],int b)
{FILE* f=fopen("fich_temp_all.txt","w");
int i;
for(i=0;i<b;i++)
{formatSTR(x4[i].identifiant);
formatSTR(x4[i].compagnie);
formatSTR(x4[i].heure_dep);
formatSTR(x4[i].heure_arriv);
formatSTR(x4[i].aeroport_dep);
formatSTR(x4[i].aeroport_arriv);
fprintf(f,"%s %s %s %s %s %s %d %d\n",x4[i].identifiant,x4[i].compagnie,x4[i].heure_dep,x4[i].heure_arriv,x4[i].aeroport_dep,x4[i].aeroport_arriv,x4[i].prix,x4[i].nbre_de_places);
} fclose(f);
}

void ajouter_tab_tous_ds_fichier(Vol x5[],int k)
{FILE* f=fopen("fich_temp_tous.txt","w");
int i;
for(i=0;i<k;i++)
{formatSTR(x5[i].identifiant);
formatSTR(x5[i].compagnie);
formatSTR(x5[i].heure_dep);
formatSTR(x5[i].heure_arriv);
formatSTR(x5[i].aeroport_dep);
formatSTR(x5[i].aeroport_arriv);
fprintf(f,"%s %s %s %s %s %s %d %d\n",x5[i].identifiant,x5[i].compagnie,x5[i].heure_dep,x5[i].heure_arriv,x5[i].aeroport_dep,x5[i].aeroport_arriv,x5[i].prix,x5[i].nbre_de_places);
} fclose(f);
}

enum
{
IDENTIFIANT,
COMPAGNIE,
HEURE_DEP,
HEURE_ARRIV,
AEROPORT_DEP,
AEROPORT_ARRIV,
PRIX,
NBRE_DE_PLACES,
COLUMNS,
};
void afficher_tous_les_vol1(GtkWidget *liste,Vol u[],int n)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
int i;
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  compagnie",renderer,"text",COMPAGNIE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  heure_dep",renderer,"text",HEURE_DEP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  heure_arriv",renderer,"text",HEURE_ARRIV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  aeroport_dep",renderer,"text",AEROPORT_DEP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  aeroport_arriv",renderer,"text",AEROPORT_ARRIV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  nbre_de_places",renderer,"text",NBRE_DE_PLACES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



if(n==0)
return;
else
{ char ch[500],ch1[500];
for(i=0;i<n;i++)
{ sprintf(ch,"%d\0",u[i].prix);
sprintf(ch1,"%d\0",u[i].nbre_de_places);
gtk_list_store_append(store,&iter);
puts(ch);
puts(ch1);
gtk_list_store_set(store,&iter,IDENTIFIANT,u[i].identifiant,COMPAGNIE,u[i].compagnie,HEURE_DEP,u[i].heure_dep,HEURE_ARRIV,u[i].heure_arriv,AEROPORT_DEP,u[i].aeroport_dep,AEROPORT_ARRIV,u[i].aeroport_arriv,PRIX,ch,NBRE_DE_PLACES,ch1,-1);}




gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

}

int verif_ID_vol(Vol h)
{ int m,test=0;Vol s1[500];
FILE* f=fopen("fich_temp_all.txt","r");
if (f!=NULL)
 while ((fscanf(f,"%s",s1[m].identifiant)!=EOF)&& (test=0));
 { if (strcmp(s1[m].identifiant,h.identifiant)==0)
{ test=1;
}
m++;}
return test;}
int verif_ID_vol1(Vol h1)
{ int m,test1=0;Vol s[500];
FILE* f=fopen("fich_temp_ret.txt","r");
if (f!=NULL)
 while ((fscanf(f,"%s",s[m].identifiant)!=EOF)&& (test1==0))
 { if (strcmp(s[m].identifiant,h1.identifiant)==0)
{ test1=1;
}
m++;}
return test1;}
/*

void afficher_tous_les_vol2(GtkWidget *liste)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
char identifiant[20],compagnie[20],heure_dep[20],heure_arriv[20],aeroport_dep[20],aeroport_arriv[20];
int prix,nbre_de_places;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  compagnie",renderer,"text",COMPAGNIE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  heure_dep",renderer,"text",HEURE_DEP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  heure_arriv",renderer,"text",HEURE_ARRIV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  aeroport_dep",renderer,"text",AEROPORT_DEP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  aeroport_arriv",renderer,"text",AEROPORT_ARRIV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  nbre_de_places",renderer,"text",NBRE_DE_PLACES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("fich_temp_ret.txt","r");

if(f==NULL)
return;
else
{
while (fscanf (f, "%s %s %s %s %s %s %s %s\n",identifiant,compagnie,heure_dep,heure_arriv,aeroport_dep,aeroport_arriv,prix,nbre_de_places) !=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANT,identifiant,COMPAGNIE,compagnie,HEURE_DEP,heure_dep,HEURE_ARRIV,heure_arriv,PRIX,prix,NBRE_DE_PLACES,nbre_de_places,-1);
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
} */
