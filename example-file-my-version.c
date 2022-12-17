#include <stdio.h>

FILE *rfp = NULL;

void f1(FILE *rfp2){
     int a;
     int b;
     int c;
     //freopen(NULL, "a+", rfp2);
     printf ("Enter (2) first digit \n");
     scanf("%d", &a);
     printf ("Enter (2) second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp2,"%d %d %d\n",a,b,c);
     fflush(rfp2);
}

int main(int argc, char **argv, char **envp){
     int a;
     int b;
     int c;
     rfp = fopen("out-my.txt", "a+");
     printf ("Enter first digit \n");
     scanf("%d", &a);
     printf ("Enter second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp,"%d %d %d\n",a,b,c);
     fflush(rfp);
     f1(rfp);
     //ffflush(rfp);
     printf ("Enter (3) first digit \n");
     scanf("%d", &a);
     printf ("Enter (3) second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp,"%d %d %d\n",a,b,c);
     fflush(rfp);
     fprintf(rfp,"=================\n");
     fclose(rfp);
}