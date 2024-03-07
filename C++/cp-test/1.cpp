// problem 282A 
// 3 , +sad --- output 1
#include <stdio.h>

int main() {
    int n, i, x = 0;
    scanf("%d", &n); // Read the number of statements

    for (i = 0; i < n; i++) {
        char operation;
        scanf("%c%c", &operation); // Read the operation and discard X

        switch (operation) {
            case '+':
                x++;
                break;
            case '-':
                x--;
                break;
            default:
                // Handle invalid input (optional)
                break;
        }
    }

    printf("%d\n", x); // Print the final value

    return 0;
}

