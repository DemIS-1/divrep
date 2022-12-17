#include <stdio.h>
#include <sys/time.h>

FILE *rfp = NULL;
double t0 = 0, t1 = 0;

void tim1(void){
  //time_delay1
  int i = 0;
  long j;
  t0 = clock();
  printf("tim1 (%d)\n", t0);
  for (i=0, j=0; i<1000000000; i++)
    j += i;
  t1 = clock();
  printf("tim1 (%.0fs)\n", (double)(t1 - t0) / CLOCKS_PER_SEC);
}

void tim2(int count){
  //time_delay2
  int i = 0;
  long j;
  t0 = clock();
  printf("tim2 (%d)\n", t0);
  for (i=0, j=0; i<count; i++){
    printf("i:%d\r",i);
    j += i;
  }
  printf("\n");
  t1 = clock();
  printf("tim2 (%.0fs)\n", (t1 - t0) / 275);
}

int pause(int level){
     char val;

     printf("   Level_%d . Check FMT on file out-5-3.txt. Press 'enter'...\n", level);
     while(val=getchar()){
       switch(val){
        case '\n': scanf("%*[^\n]%*c"); goto to_exit;
        default: break;
       }
     }
     to_exit:
}

void f1(void){
     int a;
     int b;
     int c;
     freopen(NULL, "a+", rfp);
     printf ("(2) Enter first digit \n");
     scanf("%d", &a); /* Get first data from keyboard, stdin  */
     printf ("(2) Enter second digit \n");
     scanf("%d", &b); /* Get second data from keyboard, stdin */
     c=a+b;           /* Just some calculate */
     fprintf(rfp,"%d %d %d\n",a,b,c);
     //fflush(rfp); /* We flush rfp. We see after that FMT changes is not. */
}

int main(int argc, char **argv, char **envp){
     int a;
     int b;
     int c;

     rfp = fopen("out-5-3.txt", "a+"); /* We open file to create or append */

     printf ("(1) Enter first digit \n");
     scanf("%d", &a); /* Get first data from keyboard, stdin  */
     printf ("(1) Enter second digit \n");
     scanf("%d", &b); /* Get second data from keyboard, stdin */
     c=a+b;       /* Just some calculate */

     fprintf(rfp,"%d %d %d\n",a,b,c); /* Write to file */
     pause(1);    // show: Level_1

     //fflush(rfp); /* flush data from rfp-stream to file */
     pause(2);    // show: Level_2

     f1();        /* We call other function to write data to file rfp */
     pause(3);    // show: Level_3
     //fflush(rfp); /* flush data from rfp-stream to file */

     printf ("(3) Enter first digit \n");
     scanf("%d", &a); /* Get first data from keyboard, stdin */
     printf ("(3) Enter second digit \n");
     scanf("%d", &b); /* Get second data from keyboard, stdin */
     c=a+b;       /* Just some calculate */

     fprintf(rfp,"%d %d %d\n",a,b,c); /*  */
     pause(4);    // show: Level_4

     //fflush(rfp); /* flush data from rfp-stream to file */
     pause(5);    // show: Level_5

     fprintf(rfp,"=================\n"); /* write end data string */
     pause(6);    // show: Level_6

     fclose(rfp); /* close file */
     pause(7);    // show: Level_7
}