#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[50];
    int choice, ans, lifeline = 1, quit = 0;
    int money[10] = {1000, 2000, 5000, 10000, 20000, 40000, 80000, 160000, 320000, 640000};
    int i;

    printf("===== WELCOME TO KAUN BANEGA CROREPATI =====\n");
    printf("Enter your name: ");
    gets(name);

    printf("\nHello %s, let's start the game!\n", name);
    printf("You have 1 lifeline (50-50).\n\n");

    // Questions
    char q[10][200] = {
        "What is the capital of India?",
        "Which planet is known as Red Planet?",
        "In computer, CPU stands for?",
        "Who is known as Father of Nation in India?",
        "Which festival is called festival of lights?",
        "Which is the largest mammal?",
        "Who wrote Ramayana?",
        "Which city is called Pink City?",
        "Which is the national fruit of India?",
        "Which year did India get independence?"
    };

    char opt[10][4][100] = {
        {"Mumbai", "New Delhi", "Kolkata", "Chennai"},
        {"Earth", "Mars", "Venus", "Jupiter"},
        {"Central Processing Unit", "Computer Part Unit", "Central Peripheral Unit", "Control Program Unit"},
        {"Subhash Chandra Bose", "Bhagat Singh", "Mahatma Gandhi", "Jawaharlal Nehru"},
        {"Holi", "Eid", "Diwali", "Pongal"},
        {"Elephant", "Blue Whale", "Giraffe", "Dinosaur"},
        {"Tulsidas", "Valmiki", "Kalidas", "Ved Vyas"},
        {"Delhi", "Jaipur", "Agra", "Patna"},
        {"Banana", "Apple", "Mango", "Grapes"},
        {"1942", "1947", "1950", "1930"}
    };

    int correct[10] = {2,2,1,3,3,2,2,2,3,2};  // correct answers (1-based index)

    for (i = 0; i < 10; i++) {
        printf("\nQ%d for Rs.%d: %s\n", i+1, money[i], q[i]);
        printf("1. %s\n2. %s\n3. %s\n4. %s\n", opt[i][0], opt[i][1], opt[i][2], opt[i][3]);

        if (lifeline == 1) {
            printf("Do you want to use 50-50 lifeline? (1.Yes  2.No): ");
            scanf("%d", &choice);
            if (choice == 1) {
                lifeline = 0;
                printf("Remaining options:\n");
                printf("%d. %s\n", correct[i], opt[i][correct[i]-1]);
                int other = (correct[i] == 1) ? 2 : 1; // just show one wrong option
                printf("%d. %s\n", other, opt[i][other-1]);
            }
        }

        printf("Enter your answer (1-4) or 0 to quit: ");
        scanf("%d", &ans);

        if (ans == 0) {
            quit = 1;
            if (i == 0) printf("You quit with Rs.0\n");
            else printf("You quit with Rs.%d\n", money[i-1]);
            break;
        }

        if (ans == correct[i]) {
            printf("Correct Answer! You won Rs.%d\n", money[i]);
        } else {
            printf("Wrong Answer! Correct was %d. %s\n", correct[i], opt[i][correct[i]-1]);
            if (i < 4) printf("You leave with Rs.0\n");
            else if (i < 8) printf("You leave with Rs.10000\n");
            else printf("You leave with Rs.320000\n");
            break;
        }

        if (i == 9) {
            printf("Congratulations %s! You are the Crorepati!\n", name);
        }
    }

    printf("\n===== GAME OVER =====\n");
    return 0;
}

