#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "rand.h"


int main(int argc, char *argv[], char *envp[])
{
        char prompt[255];// On crée deux tableaux, 1 pour le prompt qui changera en fonction du 2eme
        char commande[255];// Le tableau ou on va ecrire les commandes
        *commande = 0;

        char *arg[] = {"hello",NULL};

        pid_t pid;



        system("clear");// On nettoie le Shell pour qu'il soit vide

        strcpy(prompt ,"\n[EXIASAVER] ");// On met la chaine de caractere [EXIASAVER] dans le tableau prompt
        printf("\n");

        printf(" oooo o   o  o    o    oooo    o   o    o  oooo  oooo\n");
        printf(" o     o o   o   o o   o      o o  o    o  o     o   o\n");
        printf(" oo     o    o  ooooo  oooo  ooooo  o  o   oo    oooo\n");
        printf(" o     o o   o  o   o     o  o   o  o  o   o     o  o \n");
        printf(" oooo o   o  o  o   o  oooo  o   o   oo    oooo  o   o\n\n");

        printf("         exiasaver\n (Lance un des trois ecran de veille aléatoire)\n");
        printf("         exiasaver 1\n (Lance lécran de veille fixe)\n");
        printf("         exiasaver 2\n (Lance lécran de veille dynamique)\n");
        printf("         exiasaver 3\n (Lance lécran de veille interatif)\n");
        printf("         exiasaver 2 -x,y\n (Lance lécran de veille dynamique et choisi les coordonnées de limage\n");
        printf("         exiasaver 3 -x,y,d\n (Lance lécran de veille interactif, choisi les coordonnées de limage et la direction vers laquelle elle se dirige de base (1=Haut,2=Bas,3=Droite,4=Gauche)\n");
        printf("         exiasaver -stat\n (Permet de voir les stats et lhistorique des commandes)\n");

        while(strcmp(commande, "exit") !=  0)// Tant que commande est différent de exit
        {

                printf("\nFaire ctrlC quitter le programme\n");

                printf("%s",prompt);//Ecris ce qu'on a copié dans le prompt
                fgets(commande, 256, stdin);//Recupere ce qu'écrit l'utilisateur
                commande[strcspn(commande, "\n")] = '\0';


                pid = fork();//Fork, on divise le processus en deux
                if (pid == 0)//Le processus fils exécute tout pendant que le processus pere reste actif
                {
                        if (strcmp(commande, "exiasaver") == 0)//Si l'utilisateur ecris "exiasaver"
                        {
                                printf("Vous avez choisi l'ecran de veille aléatoire\n");//Choisi un type d'écran de veille aléatoire
                                int a = nombreAleatoire();//A est un nombre aléatoire entre 1 et 3
								time_t heure;
								struct tm * timeinfo;

								time ( &heure );
								timeinfo = localtime ( &heure );

								FILE *f =fopen("history.txt", "a");
								if (f == NULL)
								{
								printf("error opening file!\n");
								exit(1);
								}

								fprintf(f,"exiasaver, %s", asctime(timeinfo));
								fclose(f);
                                switch(a)
                                {
                                        case 1:
                                                {
                                                        printf("Le type d'écran statique va se lancer\n");


                                                        printf("le programme s'exécute\n");
                                                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello","hello",arg,NULL);

                                                        printf("le programme est exécuté\n");
                                                }
                                                break;
                                        case 2:
                                                printf("Le type d'écran dynamique va se lancer\n");

                                                {
                                                        printf("le programme s'exécute\n");
                                                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello2","hello2",arg,NULL);
                                                        printf("le programme est exécuté\n");
                                                }
                                                break;
                                        case 3: 
                                                printf("Le type d'écran interactif va se lancer\n");
                                                {
                                                        printf("le programme s'exécute\n");
                                                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello3","hello3",arg,NULL);
                                                        printf("le programme est exécuté\n");

                                                }
                                                break;
                                }
                        }
                        if (strcmp(commande, "exiasaver 1") == 0)
                        {


                                {
                                        printf("le programme s'exécute\n");
                                        								time_t heure;
								struct tm * timeinfo;

								time ( &heure );
								timeinfo = localtime ( &heure );

								FILE *f =fopen("history.txt", "a");
								if (f == NULL)
								{
								printf("error opening file!\n");
								exit(1);
								}

								fprintf(f,"exiasaver 1, %s", asctime(timeinfo));
								fclose(f);
                                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello","hello",arg,NULL);

                                        printf("le programme est exécuté\n");

                                }

                        }
                        if (strcmp(commande, "exiasaver 2") == 0)
                        {


                                {
                                        printf("le programme s'exécute\n");
                                        								time_t heure;
								struct tm * timeinfo;

								time ( &heure );
								timeinfo = localtime ( &heure );

								FILE *f =fopen("history.txt", "a");
								if (f == NULL)
								{
								printf("error opening file!\n");
								exit(1);
								}

								fprintf(f,"exiasaver 2, %s", asctime(timeinfo));
								fclose(f);
                                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello2","hello2",arg,NULL);
                                        printf("le programme est exécuté\n");
                                }

                        }
                        if (strcmp(commande, "exiasaver 3") == 0)



                        {
                                printf("le programme s'exécute");
                                								time_t heure;
								struct tm * timeinfo;

								time ( &heure );
								timeinfo = localtime ( &heure );

								FILE *f =fopen("history.txt", "a");
								if (f == NULL)
								{
								printf("error opening file!\n");
								exit(1);
								}

								fprintf(f,"exiasave3, %s", asctime(timeinfo));
								fclose(f);
                                execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/hello3","hello3",arg,NULL);
                                printf("le programme est exécuté");

                        }


                }
                else
                {

                        wait(NULL);//Attends la fin du processus fils
                        printf("youpi\n");//Si cette ligne s'affiche c'est que le processus pere s'est terminéi
                        //Le processus pere etant dans la boucle while le programme retourn en haut jusqu'a ce que l'utilisateur decide d'écrire "exit"
                }
                if (strcmp(commande, "exiasaver -stat") == 0)

                {
                        printf("Le menu stat va se lancer");
                        								time_t heure;
								struct tm * timeinfo;

								time ( &heure );
								timeinfo = localtime ( &heure );

								FILE *f =fopen("history.txt", "a");
								if (f == NULL)
								{
								printf("error opening file!\n");
								exit(1);
								}

								fprintf(f,"exiasaver -stat, %s", asctime(timeinfo));
								fclose(f);
                        execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/stat","stat",arg,NULL);
                        printf("Le programme est exécuté\n");
                        EXIT_SUCCESS;
                } 




        }



        return 0;
}


