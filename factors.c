#include <stdio.h>

int main (){
    int i=1,n;
    scanf("%d", &n);

    printf("the factors of %d are\n", n)
    // %d lekhte hobe %d er reference daoa lagbe -- n

    for ( i = 2; i <= n/2; i++)
    {
        if (n%i==0)
        {
           printf("%d\n" , i)
        }
        
    }
    return 0;
}

 /* starting from 2 (the smallest non-trivial factor) and going up to n / 2 
 
 (since any factor greater than n / 2 would have a corresponding factor less than n / 2). */ 