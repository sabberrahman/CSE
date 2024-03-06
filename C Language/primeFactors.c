/* primeFators-->  */

#include <stdio.h>

int main()
{
    int i, j, num, c;

    printf("Enter any number to print Prime factors: ");
    scanf("%d", &num);

    printf("All Prime Factors of %d are: \n", num);

    for(i=2; i<=num; i++)
    {
        if(num%i==0) //checking if i is a factor or not
        {
            c = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)// checking if i is prime or not
                {
                    c = 0;
                    break;
                }
            }


            if(c==1)
            {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
