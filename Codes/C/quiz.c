#include <stdio.h>

struct Question {
    char question[200];
    char options[4][100];
    int correctOption; // 0-indexed
};

void loadQuestions(struct Question quiz[], int *total) {
    *total = 5;

    // Question 1
    snprintf(quiz[0].question, sizeof(quiz[0].question), "Which language is used for system programming?");
    snprintf(quiz[0].options[0], sizeof(quiz[0].options[0]), "HTML");
    snprintf(quiz[0].options[1], sizeof(quiz[0].options[1]), "Python");
    snprintf(quiz[0].options[2], sizeof(quiz[0].options[2]), "C");
    snprintf(quiz[0].options[3], sizeof(quiz[0].options[3]), "JavaScript");
    quiz[0].correctOption = 2;

    // Question 2
    snprintf(quiz[1].question, sizeof(quiz[1].question), "What does CPU stand for?");
    snprintf(quiz[1].options[0], sizeof(quiz[1].options[0]), "Central Process Unit");
    snprintf(quiz[1].options[1], sizeof(quiz[1].options[1]), "Central Processing Unit");
    snprintf(quiz[1].options[2], sizeof(quiz[1].options[2]), "Computer Power Unit");
    snprintf(quiz[1].options[3], sizeof(quiz[1].options[3]), "Central Power Unit");
    quiz[1].correctOption = 1;

    // Question 3
    snprintf(quiz[2].question, sizeof(quiz[2].question), "Which company created the C language?");
    snprintf(quiz[2].options[0], sizeof(quiz[2].options[0]), "IBM");
    snprintf(quiz[2].options[1], sizeof(quiz[2].options[1]), "Google");
    snprintf(quiz[2].options[2], sizeof(quiz[2].options[2]), "Bell Labs");
    snprintf(quiz[2].options[3], sizeof(quiz[2].options[3]), "Microsoft");
    quiz[2].correctOption = 2;

    // Question 4
    snprintf(quiz[3].question, sizeof(quiz[3].question), "Which symbol is used to include header files?");
    snprintf(quiz[3].options[0], sizeof(quiz[3].options[0]), "@");
    snprintf(quiz[3].options[1], sizeof(quiz[3].options[1]), "#");
    snprintf(quiz[3].options[2], sizeof(quiz[3].options[2]), "$");
    snprintf(quiz[3].options[3], sizeof(quiz[3].options[3]), "%%");
    quiz[3].correctOption = 1;

    // Question 5
    snprintf(quiz[4].question, sizeof(quiz[4].question), "What is the value of 2 + 2 * 2?");
    snprintf(quiz[4].options[0], sizeof(quiz[4].options[0]), "6");
    snprintf(quiz[4].options[1], sizeof(quiz[4].options[1]), "8");
    snprintf(quiz[4].options[2], sizeof(quiz[4].options[2]), "4");
    snprintf(quiz[4].options[3], sizeof(quiz[4].options[3]), "2");
    quiz[4].correctOption = 0;
}

void runQuiz(struct Question quiz[], int total) {
    int score = 0, answer;

    for (int i = 0; i < total; i++) {
        printf("\nQ%d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, quiz[i].options[j]);
        }

        printf("Your answer (1-4): ");
        scanf("%d", &answer);

        if (answer - 1 == quiz[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %s\n", quiz[i].options[quiz[i].correctOption]);
        }
    }

    printf("\nYour total score: %d out of %d\n", score, total);
}

int main() {
    struct Question quiz[10];
    int totalQuestions = 0;

    loadQuestions(quiz, &totalQuestions);
    runQuiz(quiz, totalQuestions);

    return 0;
}