#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "hotel.h"



//ajout
void ajoutoffre(hotel x);
FILE* f=fopen("hotel.txt","a")
if(f!=NULL)
fprintf(f,"%s %s %s %d %d %s %d %s %d %d %d %d %d %d  \n",x.nomhotel,x.idhotel,x.adresse,x.tarad,x.tarenf,x.saison,x.nbetoile,x.typechambre,x.de.jour,x.de.mois,x.de.annee,x.a.jour,x.a.mois,x.a.annee);

fclose(f);
}
//modification
void modifier(hotel x ,reserver_hotel y)
{
scanf("%s",x.nomhotel);
scanf("%d",&x.nbetoile);
scanf("%d",x.pension);
scanf("%d",&y.nbchambre);
scanf("%s",y.typechambre);
scanf("%s",y.saison);
scanf("%d",&y.tarenf);
scanf("%d",&y.tarad);
fprintf("%s %d %d %d %d %d %s %s %d %d \n",x.nomhotel,x.nbetoile,x.pension,y.nbchambre,y.typechambre,y.saison,y.tarenf,y.tarad);

}



//recherche
void recherche(reserver_hotel y,hotel x);
{
FILE* f=fopen("hotel.txt","r");

fscanf("%s %d %d %d %d %d %d %d %d %d",y.destination,&y.de.jour,&y.de.mois,&y.de.annee,&y.a.jour,&y.a.mois,&y.a.annee,&x.nbchambre,&x.nbenf,&x.nbad);
if ((y.destination == x.adresse)&& (de.jour==x.de.jour)&& (de.mois==x.de.mois)&& (de.annee==x.de.annee)&& (nbchambre==x.nbchambre)&& (nbenf==x.nbenf)&& (nbad==x.nbad))
fprinf("%s %d %d %d %d %d %d %d %d %d",y.destination,y.de.jour,y.de.mois,y.de.annee,y.a.jour,y.a.mois,y.a.anneee,y.nbchambre,y.nbenf,y.nbad);
fclose(f);
}
//ajouter_reservation:
void ajouterreservation(reserver_hotel x);
FILE* f;
f=fopen("reservation.txt","a+");
if(f!=NULL)
{
fprintf("%s %s %d %d %d %s %d %d %d %d %d %d %d %f",id_client,x.idreservation,&x.tarad,&x.tarenf,x.saison,&x.nbchambre,x.de.jour,x.de.mois,x.de.annee,x.a.jour,x.a.mois,x.a.annee,&x.tarfinal);
fclose(f);


}


//tariffinal:
float tarif_final(hotel x,reserver_hotel y)
{float resultat;
if (reserver_hotel.saison=="hiver")
resultat=((hotel.tarad*hotel.nb_ad)+(hotel.tarenf*hotel.nb_enf))*reserver_hotel.nbchambre*0.6;
else if (reserver_hotel.saison=="printemps")
resultat=((hotel.tarad*hotel.nb_ad)+(hotel.tarenf*hotel.nb_enf))*reserver_hotel.nbchambre*0.7;
else if (reserver_hotel.saison=="automne")
resultat=((hotel.tarad*hotel.nb_ad)+(hotel.tarenf*hotel.nb_enf))*reserver_hotel.nbchambre*0.8;
else if (reserver_hotel.saison=="ete")
resultat=((hotel.tarad*hotel.nb_ad)+(hotel.tarenf*hotel.nb_enf))*reserver_hotel.nbchambre;
return resultat;


}







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

//afficher hotel:
int getHotels(hotel d[200])
{int i=0;
FILE* f=fopen("hotel.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %d %s\n",d[i].nomhotel,d[i].adresse,d[i].idhotel,d[i].nbetoile,d[i].desc)!=EOF){
i++;}
return i;
fclose(f);
}





//afficher reservation:
int getreservation(reserver_hotel d[200])
{int i=0;
FILE* f=fopen("reservation.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %s %d %s\n",d[i].idreservation,d[i].tarad,d[i].tarenf,d[i].nb_ad,d[i].nb_enf,d[i].saison,d[i].nbchambre,d[i].typechambre,d[i].de,d[i].a,d[i]tarfinal)!=EOF){
i++;}
return i;
fclose(f);
}



// Afficher un hotel 


void afficher_h(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

char hotel.idhotel[20] ;
char hotel.nomhotel [20] ;
char hotel.adresse [20] ;
char hotel.nbetoiles [20];
char hotel.desc[200];
store=NULL ;

FILE *f;
store = gtk_tree_view_get_model(liste);
if(store==NULL)


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     hotel.idhotel",renderer,"text",DESTINATION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     hotel.nomhotel",renderer,"text",NOM_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("hotel.adresse    ",renderer,"text",ID_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     hotel.nbetoiles",renderer,"text",NBRE_ETOILES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     hotel.desc",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("/home/bilel/Desktop/projetfinal/src/hotel.txt","r");

if (f==NULL)
{
  return ;}
else 
{
  f =fopen("/home/bilel/Desktop/projetfinal/src/hotel.txt","a+") ;
while ((fscanf(f,"%s %s %s %s \n",destination,nom_hotel,id_hotel,nbre_etoiles)!=EOF))
{
gtk_list_store_append(store,&iter);

gtk_list_store_set (store,&iter,DESTINATION,hotel.idhotel,NOM_HOTEL,hotel.nom_hotel,ID_HOTEL,hotel.adresse,NBRE_ETOILES,hotel.nbetoiles,COLUMNS,hotel.desc -1);}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
//partie suplementaire:
//ajout hotel
void ajouter_h(Hotel1 h) 
{     
   FILE *f ;       
   f=fopen("/home/bilel/Desktop/projetfinal/src/hotel.txt","a+") ;
   if (f!=NULL) 
   { 
   fprintf(f,"%s %s %s %s %s \n",h.idhotel,h.nomhotel,h.adresse,h.nbetoiles,h.desc);
fclose(f);
}
}
enum 
{ 

    DESTINATION,
    NOM_HOTEL,
    ID_HOTEL,
    NBRE_ETOILES,
    COLUMNS,
COLUMNS1,
COLUMNS2,
COLUMNS3,
COLUMNS4,
COLUMNS5,
COLUMNS6,
COLUMNS7,
COLUMNS8,
};
// Afficher un reservation 


void afficher_r(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

char id.reservation[20] ;
char tarad [20] ;
char tarenf [20] ;
char nb_ad [20];
char nb_enf[200];
char typechambre[20];
char de;
char a;
char tarfinal;
store=NULL ;

FILE *f;
store = gtk_tree_view_get_model(liste);
if(store==NULL)


{renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     id.reservation",renderer,"text",DESTINATION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     tarad",renderer,"text",NOM_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("tarenf   ",renderer,"text",ID_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nb_ad",renderer,"text",NBRE_ETOILES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nb_enf",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     saison",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nbchambre",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     typechambre",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     de",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 
renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     a",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 

renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     tarfinal",renderer,"text",COLUMNS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","r");
}
if (f==NULL)
{
  return ;}
else 
{
  f =fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","a+") ;
while ((fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",idreservation,tarad,tarenf,nb_ad,nb_enf,saison,nbchambre,typechambre,de,a,tarfinal)!=EOF))
{
gtk_list_store_append(store,&iter);

gtk_list_store_set (store,&iter,DESTINATION,idreservation,NOM_HOTEL,tarad,ID_HOTEL,tarenf,NBRE_ETOILES,nb_ad,COLUMNS,nb_enf,COLUMNS1,saison,COLUMNS2,nbchambre,COLUMNS3,typechambre,COLUMNS4,de,COLUMNS5,a,COLUMNS6,tarfinal, -1);}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

// supprimer un hotel




void supprimer_h(char ho[200])
{ Hotel1 h;
  FILE *f,*g;
 f=fopen("/home/bilel/Desktop/projetfinal/src/hotel.txt","r");
 g=fopen("/home/bilel/Desktop/projetfinal/src/hotel1.txt","w");
if ((f!=NULL)&&(g!=NULL))
{while (fscanf(f,"%s %s %s %s %s\n",h.nomhotel,h.adresse,h.idhotel,h.nbetoiles,h.desc)!= EOF)
{ if (strcmp(ho,h.id_hotel)==0){continue;}
else
fprintf(g,"%s %s %s %s %s \n",h.nomhotel,h.adresse,h.idhotel,h.nbetoiles,h.desc);
}
}
fclose(f);
fclose(g);
remove("/home/bilel/Desktop/projetfinal/src/hotel.txt");
rename("/home/bilel/Desktop/projetfinal/src/hotel1.txt","/home/bilel/Desktop/projetfinal/src/hotel.txt");
}

// supprimer reservation




void supprimer_r(char ho[200])
{ reservation1 h;
  FILE *f,*g;
 f=fopen("/home/bilel/Desktop/projetfinal/src/reservation.txt","r");
 g=fopen("/home/bilel/Desktop/projetfinal/src/reservation1.txt","w");
if ((f!=NULL)&&(g!=NULL))
{while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",h.idreservation,h.tarad,h.tarenf,h.nb_ad,h.nb_enf,h.saison,h.nbchambre,h.typechambre,h.de,h.a,h.tarfinal)!= EOF)
{ if (strcmp(ho,h.idreservation)==0){continue;}
else
fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s\n",h.idreservation,h.tarad,h.tarenf,h.nb_ad,h.nb_enf,h.saison,h.nbchambre,h.typechambre,h.de,h.a,h.tarfinal);
}
}
fclose(f);
fclose(g);
remove("/home/bilel/Desktop/projetfinal/src/reservation.txt");
rename("/home/bilel/Desktop/projetfinal/src/reservation1.txt","/home/bilel/Desktop/projetfinal/src/reservation.txt");
}

