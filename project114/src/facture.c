#include "facture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum
{
	IDCLIENT,
	IDDEVIS,
	IDTYPE,
	TYPE,
	DATE,
	TARIF,
	TARIFSANSCODE,
	TARIFFINALE,
	COLUMNS
};

enum
{
	IDCLIENT1,
	IDFACTURE,
	IDTYPE1,
	TYPE1,
	DATE1,
	TARIF1,
	TARIFSANSCODE1,
	TARIFFINALE1,
	COLUMNS1
};


int getDevis(devis d[200])
{int i=0;
FILE* f=fopen("devis.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %f %f %f\n",d[i].idClient,d[i].idDevis,d[i].idType,d[i].type,d[i].date,&d[i].tarif,&d[i].tarifSansCode,&d[i].tarifFinale)!=EOF){
i++;}
return i;
fclose(f);
}


int getFacture(facture d[200])
{int i=0;
FILE* f=fopen("facture.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %f %f %f\n",d[i].idClient,d[i].idFacture,d[i].idType,d[i].type,d[i].date,&d[i].tarif,&d[i].tarifSansCode,&d[i].tarifFinale)!=EOF){
i++;}
return i;
fclose(f);
}



int rechercheDevis(char suivant[],char rech[])
{devis d[200];
int n=getDevis( d);
for(int i=0;i<n;i++)
{
if (strcmp(suivant,"Type")==0)
	{if(test(rech,d[i].type)==1)
		return i;}
else if (strcmp(suivant,"idType")==0)
	{if(test(rech,d[i].idType)==1)
		return i;}
else if (strcmp(suivant,"idDevis")==0)
	{if(test(rech,d[i].idDevis)==1)
		return i;}

}
return -1;
}

int rechercheFacture(char suivant[],char rech[])
{facture d[200];
int n=getFacture( d);
for(int i=0;i<n;i++)
{
if (strcmp(suivant,"Type")==0)
	{if(test(rech,d[i].type)==1)
		return i;}
else if (strcmp(suivant,"idType")==0)
	{if(test(rech,d[i].idType)==1)
		return i;}
else if (strcmp(suivant,"idFacture")==0)
	{if(test(rech,d[i].idFacture)==1)
		return i;}

}
return -1;
}

int AjoutDevis(devis d)
{
devis u[200];
int i,n=getDevis(u);
for(i=0;i<n;i++)
{
	if(test(u[i].idDevis,d.idDevis)==1)
		return 0; //EXISTE
	else if(test(u[i].idType,d.idType)==1)
		return 2; //EXISTE
}
FILE* f=fopen("devis.txt","a");
fprintf(f,"%s %s %s %s %s %f %f %f\n",d.idClient,d.idDevis,d.idType,d.type,d.date,d.tarif,d.tarifSansCode,d.tarifFinale);
fclose(f);
return 1;
}

int AjoutFacture(facture d)
{
facture u[200];
int i,n=getFacture(u);
for(i=0;i<n;i++)
{
	if(test(u[i].idFacture,d.idFacture)==1)
		return 0; //EXISTE
	else if(test(u[i].idType,d.idType)==1)
		return 2; //EXISTE
}
FILE* f=fopen("facture.txt","a");
fprintf(f,"%s %s %s %s %s %f %f %f\n",d.idClient,d.idFacture,d.idType,d.type,d.date,d.tarif,d.tarifSansCode,d.tarifFinale);
fclose(f);
return 1;
}

void regenDevis(devis d[200],int n)
{
int i;
FILE* f=fopen("devis.txt","w");
for(i=0;i<n;i++)
{
	fprintf(f,"%s %s %s %s %s %f %f %f\n",d[i].idClient,d[i].idDevis,d[i].idType,d[i].type,d[i].date,d[i].tarif,d[i].tarifSansCode,d[i].tarifFinale);
}

fclose(f);
}

void regenFacture(facture d[200],int n)
{
int i;
FILE* f=fopen("facture.txt","w");
for(i=0;i<n;i++)
{
	fprintf(f,"%s %s %s %s %s %f %f %f\n",d[i].idClient,d[i].idFacture,d[i].idType,d[i].type,d[i].date,d[i].tarif,d[i].tarifSansCode,d[i].tarifFinale);
}

fclose(f);
}

//AFFICHAGE DEVIS

void Afficher_Devis(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
devis d[200];
store=NULL;
int i,n;
char ch[20],ch1[20],ch2[20];
n=getDevis(d);
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes(" idClient", renderer, "text",IDCLIENT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idDevis", renderer, "text",IDDEVIS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idType", renderer, "text",IDTYPE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" Type", renderer, "text",TYPE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarif", renderer, "text",TARIF, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifSansCode", renderer, "text",TARIFSANSCODE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifFinale", renderer, "text",TARIFFINALE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


if(n==0)
    return;
 
else
  { 
for(i=0;i<n;i++)
   {
/*sprintf(ch,"%f\0",d[i].tarif);
sprintf(ch1,"%f\0",d[i].tarifSansCode);
sprintf(ch2,"%f\0",d[i].tarifFinale);*/
gcvt(d[i].tarif,7,ch);
gcvt(d[i].tarifSansCode,7,ch1);
gcvt(d[i].tarifFinale,7,ch2);

  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, IDCLIENT, d[i].idClient, IDDEVIS, d[i].idDevis, IDTYPE, d[i].idType,TYPE,d[i].type,DATE1,d[i].date,TARIF,ch,TARIFSANSCODE,ch1,TARIFFINALE,ch2, -1);}
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
  }
  }


//AFFICHAGE FACTURE
void Afficher_Facture(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
facture d[200];
store=NULL;
int i,n;
char ch[20],ch1[20],ch2[20];
n=getFacture(d);
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes(" idClient", renderer, "text",IDCLIENT1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idFacture", renderer, "text",IDFACTURE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idType", renderer, "text",IDTYPE1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" Type", renderer, "text",TYPE1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarif", renderer, "text",TARIF1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifSansCode", renderer, "text",TARIFSANSCODE1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifFinale", renderer, "text",TARIFFINALE1, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


if(n==0)
    return;
 
else
  { 
for(i=0;i<n;i++)
   {
/*sprintf(ch,"%f\0",d[i].tarif);
sprintf(ch1,"%f\0",d[i].tarifSansCode);
sprintf(ch2,"%f\0",d[i].tarifFinale);*/
gcvt(d[i].tarif,7,ch);
gcvt(d[i].tarifSansCode,7,ch1);
gcvt(d[i].tarifFinale,7,ch2);
  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, IDCLIENT1, d[i].idClient, IDFACTURE, d[i].idFacture, IDTYPE1, d[i].idType,TYPE1,d[i].type,DATE1,d[i].date,TARIF1,ch,TARIFSANSCODE1,ch1,TARIFFINALE1,ch2, -1);}
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
  }
  }


int suppressionDevis(char id[20])
{
devis u[200],x;
int i,n=getDevis(u);
for(i=0;i<n;i++)
	if(test(id,u[i].idDevis)==1)
	{
		x=u[i];
		u[i]=u[n-1];
		u[n-1]=x;
		regenDevis(u,n-1);
		return 1; //Saret Suppression
	}
return 0; //No Supp
}


int modifDevis(devis d){
devis u[200];
int i,n=getDevis(u);
for(i=0;i<n;i++)
if(test(d.idDevis,u[i].idDevis)==1)
{u[i]=d;
regenDevis(u,n);
return 1;
}
return 0;
}

int recherche_Devis(char suivant[],char rech[],devis tabrecherche[200])
{
devis tablect[200];
int i,n,j,k;
n=getDevis(tablect);
j=0;
if (strcmp(suivant,"Type")==0)
{
for (i=0;i<n;i++)

{
    if (strcmp(tablect[i].type,rech)==0)
        {
           tabrecherche[j]=tablect[i];
            j++;
        }
}
}
else if (strcmp(suivant,"IdType")==0)
{
for (i=0;i<n;i++)

{
    if (strcmp(tablect[i].idType,rech)==0)
        {
           tabrecherche[j]=tablect[i];
            j++;
        }
}
}
else if (strcmp(suivant,"IdDevis")==0)
{
for (i=0;i<n;i++)

{
    if (strcmp(tablect[i].idDevis,rech)==0)
        {
           tabrecherche[j]=tablect[i];
            j++;
        }
}
}
if (j==0)
return -1;

/*FILE *f=fopen("RechercheDevis.txt","w");


for(k=0;k<j;k++)
{

    formatSTR1(tabrecherche[k].marque);
    formatSTR1(tabrecherche[k].modele);
    formatSTR1(tabrecherche[k].climatiseur);
    formatSTR1(tabrecherche[k].id);
    fprintf(f,"%s %s %d %d %d %s %s\n", tabrecherche[k].marque, tabrecherche[k].modele, tabrecherche[k].prix_par_jour, tabrecherche[k].nbr_places, tabrecherche[k].reste, tabrecherche[k].climatiseur,tabrecherche[k].id);
}fclose(f);*/
return j;
}
void AfficherDevis(GtkWidget * liste,devis d[200],int n )
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
store=NULL;
int i;
char ch[20],ch1[20],ch2[20];
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();  
column = gtk_tree_view_column_new_with_attributes(" idClient", renderer, "text",IDCLIENT, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idDevis", renderer, "text",IDDEVIS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" idType", renderer, "text",IDTYPE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" Type", renderer, "text",TYPE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarif", renderer, "text",TARIF, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifSansCode", renderer, "text",TARIFSANSCODE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" tarifFinale", renderer, "text",TARIFFINALE, NULL); 
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


if(n==0)
    return;
 
else
  { 
for(i=0;i<n;i++)
   {
/*sprintf(ch,"%f\0",d[i].tarif);
sprintf(ch1,"%f\0",d[i].tarifSansCode);
sprintf(ch2,"%f\0",d[i].tarifFinale);*/
gcvt(d[i].tarif,7,ch);
gcvt(d[i].tarifSansCode,7,ch1);
gcvt(d[i].tarifFinale,7,ch2);

  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter, IDCLIENT, d[i].idClient, IDDEVIS, d[i].idDevis, IDTYPE, d[i].idType,TYPE,d[i].type,DATE1,d[i].date,TARIF,ch,TARIFSANSCODE,ch1,TARIFFINALE,ch2, -1);}
  gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
  g_object_unref (store);
  }
  }
}









