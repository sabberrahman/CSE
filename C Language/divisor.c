#include <stdio.h>
#include <stdlib.h>

int main (){
    int a , b ,c ;

    printf("enter two numbers :");
    scanf("%d%d", &a,&b);

    // find the minimum number
    if (a > b)
    {
        c = b;
    } else {
        c = a; 
    };

// find GCD 
 while (c >=1)
 {
   if (a % c ==0 && b % c ==0)
   {
    int GCB = c ;
    break; // exit the loop when GCD IS FOUND
   }
   c--;
 };

 // find LCD USING THR FORMULA 

 int LCB = abs(a * b) / c ; // 12 ,18 ==> 36

 printf(" Least Common Multiples of %d & %d numbers is: %d",a ,b , LCB);
  return 0 ;
}

/*The GCD of two numbers is the largest positive integer that is a divisor of both numbers.
A divisor is a number that can divide another number without a remainder. */ 

/* Find the GCD of 12 and 18:
The divisors of 12 are 1, 2, 3, 4, 6, and 12.
The divisors of 18 are 1, 2, 3, 6, 9, and 18.
The largest number that appears in both lists is 6.
Therefore, the GCD of 12 and 18 is 6 */


 /* LCM(12, 18) = |12 * 18| / GCD(12, 18)
              = 216 / 6
              = 36 */

 /* The LCM of two numbers is the smallest positive integer that is a multiple of both numbers.

The multiples of 8 are 8, 16, 24, 32, ....
The multiples of 12 are 12, 24, 36, 48, ....
The smallest number that appears in both lists is 24.
Therefore, the LCM of 8 and 12 is 24. */

// key words are == DIVISOR , MULTIPLES
