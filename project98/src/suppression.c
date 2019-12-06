#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"suppression.h"
#include"marouane.h"

int test1(char ch[20],char ch1[20])
{int i;
if(strlen(ch)!=strlen(ch1))
return 0;
for(i=0;i<strlen(ch);i++)
if(ch[i]!=ch1[i])
return 0;
return 1;
}

int getVoiture(voiture v[200])
{int i=0;
FILE* f=fopen("voiture.txt","r");
if(f!=NULL)
while(fscanf(f,"%s %s %f %d %d %s %s", v[i].marque, v[i].modele, &v[i].prix_par_jour, &v[i].nbr_places, &v[i].reste, v[i].climatiseur,v[i].id)!=EOF){
deformat1(v[i].marque);
deformat1(v[i].modele);
deformat1(v[i].climatiseur);
deformat1(v[i].id);
i++;}
return i;
fclose(f);
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
int n=getVoiture(v);
for(int i=0;i<n;i++)
if((test1(id,v[i].id)==1))
return i;
return -1;
}

int supprimevoiture(char id[20]){
voiture v[200],x;
int i,n=getVoiture(v);
for(i=0;i<n;i++)
if(test1(id,v[i].id)==1){
x=v[i];
v[i]=v[n-1];
v[n-1]=x;
updateVoiture(v,n-1);
return 1;
}
return 0;
}
