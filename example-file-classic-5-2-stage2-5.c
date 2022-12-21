#include <stdio.h>

FILE *rfp = NULL;

int main(int argc, char **argv, char **envp){
     int a;
     int b;
     int c;
     rfp = fopen("out-5-2-st2-5.txt", "a+");
     printf ("Enter first digit \n");
     scanf("%d", &a);
     printf ("Enter second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp,"%d %d %d\n",a,b,c);
     fflush(rfp);
     // while (1) {
     for (int i = 0; i < 3; ++i) {
       int d;
       int e;
       int f;
       freopen(NULL, "a+", rfp);
       printf ("Enter (2:%d) first digit \n",i);
       scanf("%d", &d);
       printf ("Enter (2:%d) second digit \n",i);
       scanf("%d", &e);
       f=d+e;
       fprintf(rfp,"%d %d %d\n",d,e,f);
       
     }
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