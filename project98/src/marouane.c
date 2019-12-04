
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
RESTE,
ID,
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
