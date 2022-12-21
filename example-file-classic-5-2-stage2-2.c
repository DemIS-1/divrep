#include <stdio.h>

FILE *rfp = NULL;

void f1(void){
     int d;
     int e;
     int f;
     freopen(NULL, "a+", rfp);
     printf ("Enter (2) first digit \n");
     scanf("%d", &d);
     printf ("Enter (2) second digit \n");
     scanf("%d", &e);
     f=d+e;
     fprintf(rfp,"%d %d %d\n",d,e,f);
     fflush(rfp);
}

int main(int argc, char **argv, char **envp){
     int a;
     int b;
     int c;
     rfp = fopen("out-5-2-st2-2.txt", "a+");
     printf ("Enter first digit \n");
     scanf("%d", &a);
     printf ("Enter second digit \n");
     scanf("%d", &b);
     c=a+b;
     fprintf(rfp,"%d %d %d\n",a,b,c);
     fflush(rfp);
     f1();
     fflush(rfp);
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