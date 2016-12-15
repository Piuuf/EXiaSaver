#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int nombreAleatoire()
{
        const int MAX = 3, MIN = 1;
        int a = 0;
        srand(time(NULL));
        a = (rand() % (MAX - MIN + 1) + MIN);
        printf("%d\n",a); 
        return a;
}




