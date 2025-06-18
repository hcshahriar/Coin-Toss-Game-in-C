#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // For toupper()

int main() {
    // Initialize random number generator with current time as seed
    srand(time(0));
    
    int wins = 0, losses = 0;
    char playAgain;
    
    printf("Welcome to the Coin Toss Game!\n");
    
    do {
        char userChoice;
        int tossResult;
        
        // Get user's choice (H for Heads, T for Tails)
        printf("\nChoose (H)eads or (T)ails: ");
        scanf(" %c", &userChoice); // Space before %c to skip any whitespace
        userChoice = toupper(userChoice);
        
        // Validate input
        while (userChoice != 'H' && userChoice != 'T') {
            printf("Invalid choice. Please enter H for Heads or T for Tails: ");
            scanf(" %c", &userChoice);
            userChoice = toupper(userChoice);
        }
        
        // Simulate coin toss (0 for Heads, 1 for Tails)
        tossResult = rand() % 2;
        
        // Display toss result
        printf("The coin landed on %s!\n", tossResult == 0 ? "Heads" : "Tails");
        
        // Determine if user won or lost
        if ((userChoice == 'H' && tossResult == 0) || 
            (userChoice == 'T' && tossResult == 1)) {
            printf("Congratulations! You won!\n");
            wins++;
        } else {
            printf("Sorry, you lost this round.\n");
            losses++;
        }
        
        // Display current score
        printf("\nCurrent Score - Wins: %d, Losses: %d\n", wins, losses);
        
        // Ask if user wants to play again
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
        
    } while (playAgain == 'Y');
    
    printf("\nFinal Score - Wins: %d, Losses: %d\n", wins, losses);
    printf("Thanks for playing! Goodbye!\n");
    
    return 0;
}
