#include <stdio.h>

FILE *rfp = NULL;

int main(int argc, char **argv, char **envp)
{    int a;
     int b;
     int c;
     rfp = fopen("out-4.txt", "a+");
     printf ("Enter first digit \n");
     scanf("%d", &a);
     printf ("Enter second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp,"%d %d %d\n",a,b,c);
     fclose(rfp);
}