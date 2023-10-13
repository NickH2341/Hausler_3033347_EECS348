#include <stdio.h>

void printCombinations(int touchdowns, int twoPointConversions, int fieldGoals, int safeties) {
    printf("%d TD + %d 2pt, %d 3pt FG, %d Safety\n", touchdowns, twoPointConversions, fieldGoals, safeties);
}

void findCombinations(int score) {
    for (int touchdowns = 0; touchdowns * 6 <= score; touchdowns++) {
        for (int twoPointConversions = 0; twoPointConversions * 2 <= touchdowns * 6; twoPointConversions++) {
            int tdPoints = touchdowns * 6;
            int td2Points = twoPointConversions * 2;

            for (int fieldGoals = 0; fieldGoals * 3 <= score - (tdPoints + td2Points); fieldGoals++) {
                int fgPoints = fieldGoals * 3;
                int remainingScore = score - (tdPoints + td2Points + fgPoints);

                if (remainingScore >= 0 && remainingScore % 2 == 0) {
                    int safeties = remainingScore / 2;
                    printCombinations(touchdowns, twoPointConversions, fieldGoals, safeties);
                }
            }
        }
    }
}

int main() {
    while (1) {
        int score;
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        findCombinations(score);
    }

    return 0;
}
