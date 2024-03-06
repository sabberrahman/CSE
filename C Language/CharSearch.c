
/* For reading a single character: Use scanf("%c", &ch); For reading a line of characters: 
Use fgets(str, sizeof(str), stdin);
 gets should be avoided: */

 #include <stdio.h>
 #include <string.h>
 

 int main (){
    char s[100];
   char find = "i"[0]; 

    fgets(s , sizeof(s), stdin);
    printf("what you typed is : %s", s);

    int length = strlen(s); 
   printf("The length of the string is: %d\n", length);

    int found = 0;

    for (int i = 0; i < length; i++)
    {
       if  (s[i] == find)
       {
        found++;
        break;
       }
       
    }
    
    printf("%d\n",found);
    
    if (found)
    {
      printf("found it !!!\n");
    } else {
        printf("didnt found\n");
    }
    return 0;
 }