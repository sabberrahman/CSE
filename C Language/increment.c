#include<stdio.h>
int main()
{
    int a, b, c;
    a=9;
    b=++a;
    c=++b; 
    printf("%d %d %d", a,b,c);
    return 0;
}

// same result if we type --b=a++; || c=b++;

// b = ++a;: This line uses the pre-increment operator ++ on a. The value of a is first incremented to 10, and then that value is assigned to b. So, after this line, both a and b will have the value 10.

// c= ++ b --- after this line, b will be 11 and c will be 11.