//Write a program to Create quiz application.
#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 4

// Structure to store a single question and its options
typedef struct {
    char question_text[150];
    char options[4][50];
    char correct_option;
} QuizQuestion;

int main() {
    // Array initialization containing the quiz database
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "What is the only country that is also a continent?",
            {"A. Canada", "B. Australia", "C. Russia", "D. Brazil"},
            'B'
        },
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. Java", "C. C", "D. C++"},
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
            'B'
        },
        {
            "What is the chemical symbol for water?",
            {"A. CO2", "B. H2O", "C. NaCl", "D. O2"},
            'B'
        }
    };

    char user_answer;
    int total_correct = 0;

    printf("=========================================\n");
    printf("     WELCOME TO THE C QUIZ GAME          \n");
    printf("=========================================\n\n");

    // Loop to display questions and validate inputs
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question_text);
        
        // Print the 4 multiple choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Get user input and skip lingering newline characters
        printf("Your Answer (A, B, C, or D): ");
        scanf(" %c", &user_answer);

        // Convert lowercase inputs to uppercase for safety 
        user_answer = toupper(user_answer);

        // Check if the answer matches the key
        if (user_answer == quiz[i].correct_option) {
            printf("\n✅ Correct!\n");
            total_correct++;
        } else {
            printf("\n❌ Incorrect! The right answer was %c.\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n\n");
    }

    // Final performance report metrics
    float percentage = ((float)total_correct / TOTAL_QUESTIONS) * 100;
    
    printf("=========================================\n");
    printf("               GAME OVER                 \n");
    printf("=========================================\n");
    printf("Total Questions : %d\n", TOTAL_QUESTIONS);
    printf("Correct Answers : %d\n", total_correct);
    printf("Your Score      : %.2f%%\n", percentage);
    printf("=========================================\n");

    return 0;
}
