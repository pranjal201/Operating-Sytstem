//Factorial of 20
#include<pthread.h>
#include<stdio.h>
unsigned long fact[4];
void *fact_fn(int *arg){
    long id= (long)arg;
    int start=id*5;
    fact[id]=1;
    int i=1;
    while(i<=5){
    fact[id]*=(start+i);
    i++;
    }
        printf("%lu\n",fact [id]);
    
}

void main(){
pthread_t f1,f2,f3,f4;


pthread_create(&f1,NULL,fact_fn,(int *)0);
pthread_create(&f2,NULL,fact_fn,(int *)1);
pthread_create(&f3,NULL,fact_fn,(int *)2);
pthread_create(&f4,NULL,fact_fn,(int *)3);

pthread_join(f1,NULL);
    pthread_join(f2,NULL);
        pthread_join(f3,NULL);
            pthread_join(f4,NULL);

printf("Factorial 20! = %lu\n", fact[0]*fact[1]*fact[2]*fact[3]);
}
//OUTPUT----------------------
/*
120
30240
360360
1860480
Factorial 20! = 2432902008176640000
*/
