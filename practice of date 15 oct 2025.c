#include <stdio.h>
#include <stdlib.h>  // rand() ke liye
#include <time.h>    // time() seed ke liye

int main() {
    char player, computer;
    int rounds = 0, player_score = 0, comp_score = 0;

    srand(time(NULL));  // Random seed on!

    printf("Rock-Paper-Scissors Game! 5 rounds khelenge. Enter R/P/S: 🔥\n");

    while (rounds < 5) {
        // Computer choice
        int rand_choice = rand() % 3;
        if (rand_choice == 0) computer = 'R';
        else if (rand_choice == 1) computer = 'P';
        else computer = 'S';

        printf("\nRound %d: Aapka choice (R/P/S): ", rounds + 1);
        scanf(" %c", &player);  // Space se extra input clear

        printf("Computer: %c | Aap: %c\n", computer, player);

        if (player == computer) {
            printf("Tie! Koi nahi jeeta. 🤝\n");
        } else if ((player == 'R' && computer == 'S') || 
                   (player == 'S' && computer == 'P') || 
                   (player == 'P' && computer == 'R')) {
            printf("Aap jeete round! 🏆\n");
            player_score++;
        } else {
            printf("Computer jeeta! 😈\n");
            comp_score++;
        }

        rounds++;
    }

    printf("\nFinal Score: Tu %d | Computer %d\n", player_score, comp_score);
    if (player_score > comp_score) printf("Overall aap boss! 🎉\n");
    else if (comp_score > player_score) printf("Computer ne thok diya! 😂\n");
    else printf("Draw! Next time revenge lena. ⚔️\n");

    return 0;
}