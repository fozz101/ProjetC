#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "fonctions.h"
enum{
ID,NOM,PRENOM,ADRESSE,MAIL,PHONE,COLUMNS
};
void formatSTR(char ch[]){int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]==' ')
ch[i]='_';
}
void deformat(char ch[]){int i;
for(i=0;i<strlen(ch);i++)
if(ch[i]=='_')
ch[i]=' ';
}

void Afficher_user (GtkWidget * liste,int r){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
user u[200];
char classe[30];
int i,n;
store=NULL;
n=getUsers(u);
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Identifiant",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  E-mail",renderer,"text",MAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  Num téléphone",renderer,"text",PHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);



if(n==0)
return;
else
{
for(i=0;i<n;i++)
{if(r==u[i].role){
gtk_list_store_append(store,&iter);
sprintf(classe,"%d\0",u[i].phone);
puts(classe);
gtk_list_store_set(store,&iter,ID,u[i].id,NOM,u[i].nom,PRENOM,u[i].prenom,ADRESSE,u[i].adresse,MAIL,u[i].mail,PHONE,classe,-1);}

}

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

int recherche(char id[20],int x){user t[200];
int n=getUsers( t);
for(int i=0;i<n;i++)
if((test(id,t[i].id)==1)&&(x==t[i].role))
return i;
return -1;
}


int getUsers(user t[200]){int i=0;
FILE* f=fopen("users.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",t[i].nom,t[i].prenom,t[i].id,t[i].mail,t[i].adresse,t[i].login,t[i].pass,&t[i].phone,&t[i].role,&t[i].cin,&t[i].classe)!=EOF){
deformat(t[i].nom);
deformat(t[i].prenom);
deformat(t[i].adresse);
i++;}
return i;
fclose(f);
}

void updateUsers(user t[200],int n){
int i;
FILE* f=fopen("users.txt","w");
for(i=0;i<n;i++)
{formatSTR(t[i].nom);
formatSTR(t[i].prenom);
formatSTR(t[i].adresse);
if((t[i].role==0)||(t[i].role==1))
t[i].classe=-1;
fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",t[i].nom,t[i].prenom,t[i].id,t[i].mail,t[i].adresse,t[i].login,t[i].pass,t[i].phone,t[i].role,t[i].cin,t[i].classe);}
fclose(f);
}

int test(char ch[20],char ch1[20])
{int i;
if(strlen(ch)!=strlen(ch1))
return 0;
for(i=0;i<strlen(ch);i++)
if(ch[i]!=ch1[i])
return 0;
return 1;
}

int verif(char log[20],char pw[20]){user u[200];
int i,n=getUsers(u);
for(i=0;i<n;i++)
if((test(log,u[i].login)==1)&&(test(pw,u[i].pass)==1))
return u[i].role;
return -1;
}

int modifUser(user uti){
user u[200];
int i,n=getUsers(u);
for(i=0;i<n;i++)
if(test(uti.id,u[i].id)==1)
{u[i]=uti;
updateUsers(u,n);
return 1;
}
return 0;
}

int supprime(char id[20]){
user u[200],x;
int i,n=getUsers(u);
for(i=0;i<n;i++)
if(test(id,u[i].id)==1){
x=u[i];
u[i]=u[n-1];
u[n-1]=x;
updateUsers(u,n-1);
return 1;
}
return 0;
}



int ajouter_Employe(user uti){
user u[200];
int i,n=getUsers(u);
for(i=0;i<n;i++){
if(test(u[i].id,uti.id)==1)
return 0;
else if(test(u[i].login,uti.login)==1)
return 2;
}
FILE* f=fopen("users.txt","a");
if((uti.role==0)||(uti.role==1))
uti.classe=-1;
formatSTR(uti.nom);
formatSTR(uti.prenom);
formatSTR(uti.adresse);
fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",uti.nom,uti.prenom,uti.id,uti.mail,uti.adresse,uti.login,uti.pass,uti.phone,uti.role,uti.cin,uti.classe);
fclose(f);
return 1;
}
