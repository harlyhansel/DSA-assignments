#include <stdio.h>

int main() {
    int N, X;
    
    // This asks for the number of domestic animals
    printf("Enter the number of domestic animals\n");
    scanf("%d", &N);

    // An array to store domestic animal names
    char domestic[N][50];

    // Input domestic animals
    printf("Enter the names of %d domestic animals:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Domestic animal %d: ", i + 1);
        scanf("%s", domestic[i]);
    }

    // This asks for the number of wild animals
    printf("Enter the number of wild animals\n");
    scanf("%d", &X);

    // An array to store wild animal names
    char wild[X][50];

    // Input wild animals
    printf("Enter the names of %d wild animals\n", X);
    for (int i = 0; i < X; i++) {
        printf("Wild animal %d: ", i + 1);
        scanf("%s", wild[i]);
    }

    // Output for the list of animals (both domestic and wild)
    printf("\nList of animals (Domestic + Wild):\n");

    // Domestic animals
    printf("\nDomestic Animals:\n");
    for (int i = 0; i < N; i++) {
        printf("%s\n", domestic[i]);
    }

    // Wild animals
    printf("\nWild Animals:\n");
    for (int i = 0; i < X; i++) {
        printf("%s\n", wild[i]);
    }

    return 0;
}
