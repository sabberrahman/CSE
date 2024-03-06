#include <stdio.h>

int main(){
    int a[9];
    int j= 8; //check

    for (int i=0 ; i<9 ; i++){
        scanf("input 10 digits %d", &a[i])
    }

 int found = 0;
    for (int k = 0; i <  9; k++)
    {
      if( a[k]== j){
        found++;
        break;
      }
    }

    if (found ==1 )
    {
       printf("we Got It\n")
    } else {
        printf("NOT Found\n")
    }
    return 0;
}