#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>


void ajouter_reclamation(reclamation c)
{
int i;
 FILE *f;
 f=fopen("reclamation.txt","a+");
 if(f!=NULL)
 {
for(i=0;i<strlen(c.rec);i++)
if(c.rec[i]==' ')
c.rec[i]='_';
fprintf(f,"%s %s %d %d %d %s \n",c.id,c.type,c.jour,c.mois,c.annee,c.rec);
 fclose(f);
 }

}

void afficher_reclamation(GtkWidget *liste)
{

enum
{	ID,
	TYPE ,
	DATE,
	REC,
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char type[30];
char jour[20];
char mois[20];
char annee[20];
char rec[30];
int i;
store =NULL;
char ch[40];
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(4,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("reclamation.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	//f=fopen("src/reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",id,type,jour,mois,annee,rec)!=EOF)
		{
for(i=0;i<strlen(rec);i++)
if(rec[i]=='_')
rec[i]=' ';
			gtk_list_store_append(store,&iter);
sprintf(ch,"%s/%s/%s\0",jour,mois,annee);
			gtk_list_store_set(store,&iter,ID,id,TYPE,type,DATE,ch,REC,rec,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}
void bhsformat(char ch[400]){
int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]==' ')
ch[i]='_';
}

void bhsdeformat(char ch[400]){
int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]=='_')
ch[i]=' ';
}

void supprimer_reclamation(char id[])
{
reclamation c;
FILE *f;
FILE *f1;
f=fopen("reclamation.txt","r+");
f1=fopen("reclamationtemp.txt","w+");
if((f!=NULL) && (f1!=NULL))
{while(fscanf(f,"%s %s %d %d %d %s \n",c.id,c.type,&c.jour,&c.mois,&c.annee,c.rec)!=EOF)
{
if(strcmp(id,c.id)!=0)
fprintf(f1,"%s %s %d %d %d %s \n",c.id,c.type,c.jour,c.mois,c.annee,c.rec);
}
}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("reclamationtemp.txt","reclamation.txt"); 
}
void ajouter_repense(char id[],char rep[])
{

 FILE *f;
 f=fopen("repense.txt","a+");
 if(f!=NULL)
 {bhsformat(rep);
 fprintf(f,"%s %s \n",id,rep);
 
 }
fclose(f);
}
enum
{	ID1,
REC1,DATE1,
	REP1,
	COLUMNS1
};



void afficher_repense(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
reclamation c;
char id[100];
char rep[100],date[30];
store =NULL;

FILE *f,*f1;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REP1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("repense.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	
		while(fscanf(f,"%s %s \n",id,rep)!=EOF)
		{f1=fopen("reclamation.txt","r");
while(fscanf(f1,"%s %s %d %d %d %s \n",c.id,c.type,&c.jour,&c.mois,&c.annee,c.rec)!=EOF)
if(strcmp(id,c.id)==0)
break;
bhsdeformat(c.rec);
bhsdeformat(rep);
			gtk_list_store_append(store,&iter);
sprintf(date,"%d/%d/%d\0",c.jour,c.mois,c.annee);
			gtk_list_store_set(store,&iter,ID1,id,REC1,c.rec,DATE1,date,REP1,rep,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}

void recherchebh (char mat[20]){
reclamation c;
FILE *f;
FILE *f1;
char a[20];
f=fopen("reclamation.txt","r");
f1=fopen("temp.txt","a+");
while (fscanf(f,"%s %s %d %d %d %s \n",a,c.type,&c.jour,&c.mois,&c.annee,c.rec)!=EOF)
	{
if(strcmp(mat,a)==0)
fprintf(f1,"%s %s %d %d %d %s \n",a,c.type,c.jour,c.mois,c.annee,c.rec);
	}
fclose(f);
fclose(f1);
rename("temp.txt","reclamationsrech.txt");

}

void afficher_recherche(GtkWidget *liste)
{

enum
{	ID,
	TYPE ,
	JOUR,
	MOIS,
	ANNEE,
	REC,
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char type[30];
char jour[20];
char mois[20];
char annee[20];
char rec[30];

store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("reclamationsrech.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("reclamationsrech.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",id,type,jour,mois,annee,rec)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,id,TYPE,type,JOUR,jour,MOIS,mois,ANNEE,annee,REC,rec,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}

