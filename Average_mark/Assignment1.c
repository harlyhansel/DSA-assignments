#include <stdio.h>

int main() {
    float physics[4], chemistry[4], math[4];
    float avg_physics, avg_chemistry, avg_math, overall_avg;
    int i;
    const char* test_names[4] = {"Assignment", "Coursework", "Mid Term", "End Term"};

    // Input marks for Physics
    printf("Enter the marks for Physics (Assignment, Coursework, Mid Term, End Term):\n");
    for(i = 0; i < 4; i++) {
        printf("%s: ", test_names[i]);  // Display the corresponding test name
        scanf("%f", &physics[i]);
    }

    // Input marks for Chemistry
    printf("\nEnter the marks for Chemistry (Assignment, Coursework, Mid Term, End Term):\n");
    for(i = 0; i < 4; i++) {
        printf("%s: ", test_names[i]);  // Display the corresponding test name
        scanf("%f", &chemistry[i]);
    }

    // Input marks for Math
    printf("\nEnter the marks for Math (Assignment, Coursework, Mid Term, End Term):\n");
    for(i = 0; i < 4; i++) {
        printf("%s: ", test_names[i]);  // Display the corresponding test name
        scanf("%f", &math[i]);
    }

    // Calculate average for each subject
    avg_physics = (physics[0] + physics[1] + physics[2] + physics[3]) / 4;
    avg_chemistry = (chemistry[0] + chemistry[1] + chemistry[2] + chemistry[3]) / 4;
    avg_math = (math[0] + math[1] + math[2] + math[3]) / 4;

    // Calculate overall average
    overall_avg = (avg_physics + avg_chemistry + avg_math) / 3;

    // Output the results
    printf("\nAverage marks for each subject:\n");
    printf("Physics: %.2f\n", avg_physics);
    printf("Chemistry: %.2f\n", avg_chemistry);
    printf("Math: %.2f\n", avg_math);
    printf("\nOverall average: %.2f\n", overall_avg);

    return 0;
}
