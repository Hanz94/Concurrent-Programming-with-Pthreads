
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "timer.h"

#define M 100
#define maximun_num 65535


void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (32767 / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(){
int vektor[M];    
 double start, finish, elapsed;
 int a[100];

 
 for (int i = 0; i < 100 ; i++) {
     a[i]=i;
 }
 shuffle(a,100);
for (int i = 0; i < 100; i++) {
     printf("%i\n",a[i]);
 }
 
}

