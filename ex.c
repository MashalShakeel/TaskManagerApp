#include <stdio.h>

int main() {
    char y1[9];       // Uninitialized array
    char y2[9] = "";  // Array initialized with an empty string

    // Print the strings
    printf("y1: %s\n", y1);  // Undefined behavior
    printf("y2: %s\n", y2);  // Valid, prints an empty string

    return 0;
}
