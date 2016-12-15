#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/ioctl.h>



int LARGEUR; //Largeur de l'image;
int HAUTEUR; // Hauteur de l'image;
char* nom; // variables dans lequel le nom de l'image à ouvrir sera stockés

//-------------------------------------//
//		affichage de l'image	       //
//-------------------------------------//

void lire_image(char **T , char *NOM)
{
	FILE* fichier;
	fichier = fopen(NOM,"r");//assigne à fichier l'adresse et le nom de l'iamge à ouvrir
	printf("l'image s'appelle : %s\n", NOM);
	printf("%s \n", fichier);

//remplissage du tableau
	if(fichier != NULL)
	{
		printf("affichage\n");
		fflush(stdout);
		for(int j = HAUTEUR -1; j>=0; j--)
		{
			for(int i=0; i<LARGEUR; i++)
			{
				fgets(&T[j][i], sizeof *T ,fichier);
				*T[strcspn(*T, "\n")] = '\0';
				if(T[j][i]==0)
					printf(" ");//assigne un caractère vide pour chaque 0 dans le code de l'image
				if(T[j][i]==1)
					printf("\u2588");//assigne un caractère plein pour chaque 1  dans le code de l'image
			}
		printf("\n");
		}
	}
	else
	{
		printf("impossible d'ouvrir l'image nommé %s\n", NOM);
		if (errno==ENOENT)
			printf("%s : fichier inexistant\n", NOM);
	}
	char c;
	c = getchar();
	putchar(c);
	fclose(fichier);
}


//-------------------------------//
//		 image à ouvrir		     //
//-------------------------------//

int aleat()
{
	srand(time(NULL));
	int Aleat;
	Aleat = rand()%(6-1)+1;
	switch(Aleat)
	{
	case 1:
		nom = "image_fixe/champi.pgm";
		break;
	case 2:
		nom = "image_fixe/fantom.pgm";
		break;
	case 3:
		nom = "image_fixe/Space_invaders/pbm";
		break;
	case 4:
		nom = "image_fixe/ULTIME.ppm";
		break;
	case 5:
		nom = "image_fixe/yingyang.pbm";
		break;
	}
	return *nom;
}

//--------------------------//
//	    fonction main	    //
//--------------------------//

int main()
{
	printf("initialisation du programme...\n");
	fflush(stdout);
	char Nom[30];
	char** T;
	printf ("inserer la hauteur et la largeur de l'image\n");
	scanf("%d\n", &HAUTEUR);
	scanf("%d\n", &LARGEUR);

	struct winsize w;
	ioctl(0,TIOCGWINSZ, &w);
	w.ws_row = (w.ws_row-HAUTEUR)/2;//défini la taille d'une ligne
	w.ws_col = (w.ws_col-LARGEUR)/2;//defini la taille d'une colonne

	//allocation de la mémoire
	T = (char**) malloc(LARGEUR*sizeof(char*));
	for(int k = 0; k <LARGEUR; k++)
	{
		T[k] = (char*) malloc(HAUTEUR*sizeof(char));
	}
	printf("Tableau alloué\n");
	fflush(stdout);
	aleat(Nom);
	lire_image(T, nom);
	for(int k = 0; k <LARGEUR; k++)
	{
		free(T[k]);
	}
	free(T);
	return 0;
}
