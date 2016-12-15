#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[])
{
        char prompt2[255];
        char commande2[255];
        *commande2 = 0;
        char *arg[] = {"stat",NULL};

        pid_t pid;

        strcpy(prompt2, "\n[EXIASAVER_STAT] ");
        system("clear");

        printf("\n");
        printf("exiasaver historique\n (Donne lhistorique des commandes lancées)\n");
        printf("exiasaver pourcent\n (Pourcentage de type d'écran lancé)\n");
        printf("exiasaver N\n (Nombre de chaque type d'écran lancé)\n");
        printf("Ecrire exit pour revenir au menu précédent)\n");
        printf("Faire ctrlC pour quiiter lexiasaver\n");

        while(strcmp(commande2,"exit") != 0)
        {
                printf("%s",prompt2);
                fgets(commande2,256,stdin);
                commande2[strcspn(commande2, "\n")] = '\0';

                pid = fork();
                if (pid == 0)
                {
                        if (strcmp(commande2,"exiasaver historique") == 0)
                        {
                                printf("Le fichier historique se lance\n");
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

								fprintf(f,"exiasaver historique, %s", asctime(timeinfo));
								fclose(f);
                                execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/historique","historique",arg,NULL);

                        }
                        if (strcmp(commande2,"exiasaver pourcent") == 0)
                        {
                                printf("Le fichier exiasaverpo se lance\n");
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

								fprintf(f,"exiasaver pourcent, %s", asctime(timeinfo));
								fclose(f);
                                execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/exiasaverpo","exiasaverpo",arg,NULL);
                        }
                        if (strcmp(commande2,"exiasaver N") == 0)
                        {
                                printf("Le fichier exiasavern va se lancer\n");
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

								fprintf(f,"exiasaver N, %s", asctime(timeinfo));
								fclose(f);
                                execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/exiasavern","exiasavern",arg,NULL);
                        }
     
                }
                else
                {
                        wait(NULL);
                }
        }
        if(strcmp(commande2,"statexit") != 0)
        {
                printf("Retour au menu principal");
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

								fprintf(f,"statexit %s", asctime(timeinfo));
								fclose(f);
                execl("/home/ghislain/EXIASAVER_HOME/EXIASAVER_SHELL/exiaSaver","exiaSaver",arg,NULL);
        }
        return 0;
}

