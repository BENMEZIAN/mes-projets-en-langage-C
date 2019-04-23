#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Voiture{
	char modele[20];
	int matricule;
	float kilometrage;
	int etat;                                                        
}Voiture;
    // prototypes des fonctions
void remplissage(Voiture voiture[],int *n);   
void afficher(Voiture voiture[],int n);
int louer(Voiture voiture[],int mat,int *n);
int retour(Voiture voiture[],int mat,int *n);
int etatvoiture(Voiture voiture[],int mat,int *n);
void etatParc(Voiture voiture[],int *n);      
void sauvegarder(Voiture voiture[],int *n);
void lire(Voiture voiture[],int *n);

int main(int argc, char *argv[]) {
	
	   Voiture voiture[40];
	   int n,mat,choix;

	  do{
	  	printf("---------VOICI LE MENU----------\n");
	    printf("1-remplissage de parc.\n");
	    printf("2-afficher de parc.\n");     
	    printf("3-louer une voiture.\n");
	    printf("4-retour une voiture.\n");
	    printf("5-retourner l'etat d'une voiture.\n");
	    printf("6-retourner l'etat du parc.\n");
	    printf("7-sauvegarder dans le fichier.\n");
	    printf("8-quitter\n");
	    printf("---------------------------------\n");
	    printf("donner votre choix:");
	   	scanf("%d",&choix);
	   	
	   		switch(choix){
	   			case 1:remplissage(voiture,&n); 
	   			break;
	   			case 2:afficher(voiture,n);                
	   			break;
	   			case 3:louer(voiture,mat,&n);
	   			break;
	   			case 4:retour(voiture,mat,&n);
	   			break;
	   			case 5:etatvoiture(voiture,mat,&n);
	   			break;
	   			case 6:etatParc(voiture,&n);
	   			break;
	   			case 7:sauvegarder(voiture,&n);
	   			break;
			   }
	    
	  }while(choix!=8); 
	   
	system("pause"); 	
	   
	return 0;
}

void remplissage(Voiture voiture[],int *n){   
	     int i;
	     
	      do{
	   	printf("donner le nombre de vehicule dans le parc:");
	    scanf("%d",&(*n));
	   }while(*n<=0);
	     
	 for(i=0;i<*n;i++){
	   	printf("donner les informations de la voiture num:%d\n",i+1);
	   	printf("donner le modele du voiture:");
	   	scanf("%s", voiture[i].modele);
	   	printf("donner le matricule du voiture:");
	   	scanf("%d",&voiture[i].matricule);
	   	printf("donner le kilometrage du voiture:");
	   	scanf("%f",&voiture[i].kilometrage);
	   	printf("donner l'etat initiale du voiture:");
	   	scanf("%d",&voiture[i].etat);
	   	printf("\n");
	   }
	   
	   
}

void afficher(Voiture voiture[],int n){
	int i;
	printf("***************************************\n");
	for(i=0;i<n;i++){
     	printf("* les informations de la voiture num :%d\n",i+1);
	   	printf("* le modele du voiture est:%s\n",voiture[i].modele);
	   	printf("* le matricule du voiture est:%d\n",voiture[i].matricule);
	   	printf("* le kilometrage du voiture est:%f kilometre\n",voiture[i].kilometrage);
	   	if(voiture[i].etat==0)
	     	printf("* la voiture est disponible\n");
	    else printf("* la voiture est en location\n");
	    if(i<n-1) printf("                              -----------------------------------------------------\n");
	   }
	   printf("***************************************\n\n");
}

int louer(Voiture voiture[],int mat,int *n){
	int i; float nbKM;
	 printf("donner le matricule de la voiture a louer:");
	 scanf("%d",&mat);
	 
	 for(i=0;i<*n;i++){
	 	 if(voiture[i].matricule==mat){
	 	 	if(voiture[i].etat==0){
	 	 		voiture[i].etat=1;
		   	  printf("la voiture de matricule %d est son etat est:%d.\n",voiture[i].matricule,voiture[i].etat);
		   	  printf("la voiture est devenu en location.\n");
			  printf("donner le kilometrage parcourus par la voiture:");
			  scanf("%f",&nbKM);
			        voiture[i].kilometrage=nbKM;
			  printf("le kilometrage parcourus par la voiture est:%f\n",voiture[i].kilometrage);	 	 		
			}
	     }
	 }
}

int retour(Voiture voiture[],int mat,int *n){
		int i;
		 printf("donner le matricule de la voiture a remettre disponible:");
	     scanf("%d",&mat);
   
    for(i=0;i<*n;i++){
	 	 if(voiture[i].matricule==mat){
	 	 	if(voiture[i].etat==1){
	 	 		 voiture[i].etat=0;
		         printf("la voiture de matricule %d est son etat est:%d.\n",voiture[i].matricule,voiture[i].etat);
		   	     printf("la voiture est devenu disponible.\n");
	    	     printf("cette voiture a parcourus:%f\n",voiture[i].kilometrage);
	    	 }
	      }
	}
}

int etatvoiture(Voiture voiture[],int mat,int *n){
	int i;
	 printf("donner le matricule de la voiture a voir son etat:");
	 scanf("%d",&mat);
	 
    for(i=0;i<*n;i++){
	 	 if(voiture[i].matricule==mat){
	 	 	if(voiture[i].etat==0){	
			      printf("la voiture de matricule %d est disponible.\n",voiture[i].matricule);
			  }else if(voiture[i].etat==1){
			  	  printf("la voiture de matricule %d est en location.\n",voiture[i].matricule);
			  }	
	       }	
    }
}

void etatParc(Voiture voiture[],int *n){
	int i,nbr=0,nbl=0; float nbkm=0;
	printf("le nombre des voitures est:%d\n",*n);
	for(i=0;i<*n;i++){
		if(voiture[i].etat==1){
			printf("le matricule est:%d est en location.\n",voiture[i].matricule);
			nbl=nbl+1;
		}else{
			printf("le matricule est:%d est disponible.\n",voiture[i].matricule);
			nbr=nbr+1;
		}
			printf("\n");
		nbkm=nbkm+voiture[i].kilometrage;
	}
	        nbkm=nbkm/(*n);
	printf("le nombre des voitures en location est:%d\n",nbl);	
	printf("le nombre des voitures disponible est:%d\n",nbr);
	printf("le kilometrage moyen de toutes les voitures ensembles est egale a:%f\n",nbkm);	
}

void sauvegarder(Voiture voiture[],int *n){
	
	 FILE *f;  int i, nbl=0,nbr=0;  float nbkm=0;

	 f=fopen("voitures1.bin","wb");  //  c'est un fichier binaire qu'il faut créer et non pas un fichier texte
	  if(f==NULL){
	    	printf("erreur"); exit(-1);
	 }
	    //------------------------------------------------------------------------------------
		for(i=0;i<*n;i++){
			if(voiture[i].etat==1){
				printf("le matricule est:%d est en location.\n",voiture[i].matricule);
				nbl=nbl+1;
			}
			else{
				printf("le matricule est:%d est disponible.\n",voiture[i].matricule);
				nbr=nbr+1;
			}
			printf("\n");
			nbkm=nbkm+voiture[i].kilometrage;
		}
		nbkm=nbkm/(*n);
	    // ------------------------------------------------------------------------------------
		fwrite(&n,sizeof(int),1,f);
	    fwrite(&nbl,sizeof(int),1,f);	
	    fwrite(&nbr,sizeof(int),1,f);
	    fwrite(&nbkm,sizeof(float),1,f);
			
		fclose(f);	
}
