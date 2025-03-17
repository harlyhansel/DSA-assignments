#include <stdio.h>

int main() {
    // Initialize a 2D array with 6 names
    char names[3][2][20] = {
        {"Adam", "Eugene"},
        {"Okwere", "Shallon"},
        {"Khalid", "Blessing"}
    };

    // Traverse and print the names
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%s\n", names[i][j]);
        }
    }

    return 0;
}