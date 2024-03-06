#include <stdio.h>

int main() {
    int num, largest, smallest;

    printf("Enter the first number: ");
    scanf("%d", &num);
    largest = num;
    smallest = num;


    for (int i = 2; i <= 5; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num > largest) {
            largest = num;
        }

        if (num < smallest) {
            smallest = num;
        }
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;
}

