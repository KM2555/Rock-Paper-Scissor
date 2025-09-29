#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const unsigned WINNING_SCORE = 5;

// String constants
const char WELCOME[] =
    "Welcome to 🪨 🗒️ ✂️ 🦎 🖖 !\n"
    "(s) Single player\n"
    "(e) Exit\n";
const char SELECT_MENU_ITEM[] = "Select an option: ";
const char SELECT_SHAPE[] =
    "Select a shape:\n"
    "1🪨  || 2🗒️  || 3✂️  || 4🦎  || 5🖖 : ";
const char AGENT_PLAYED[] = "Agent: %d\n";
const char STARTING_GAME[] = "Starting game 🎉";
const char EXITING_GAME[] = "Bye 👋";
const char GAME_SHAPE_KEY_DOES_NOT_EXIST[] =
    "❌ Shape key %c does not exist. Try again.\n";
const char HUMAN_REPR[] = "👫 Human";
const char AGENT_REPR[] = "🤖 Agent";
const char SCORE_STATUS[] = "👫:🤖  %d:%d\n";
const char MENU_USE_RIGHT_KEYS[] = "Use the keys `s`, or `e`.";

// Enum for the shapes
typedef enum { ROCK, LIZARD, SCISSORS, PAPER, SPOCK, SHAPE_COUNT } shape_t;

int main() {
    srand(time(NULL)); // Seed for random generator
    printf("%s", WELCOME);

    int input = 0;

    // Menu loop
    do {
        printf("%s", SELECT_MENU_ITEM);
        input = getchar();

        // Clear input buffer
        while (getchar() != '\n');
        
        if (input == 's') {
            printf("%s\n", STARTING_GAME);
        } else if (input == 'e') {
            printf("%s\n", EXITING_GAME);
            return 0;
        } else {
            printf("%s\n", MENU_USE_RIGHT_KEYS);
        }
    } while (input != 's');

    // Game setup
    unsigned human_score = 0, agent_score = 0;

    while (human_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
        shape_t human_shape, agent_shape;

        printf("%s", SELECT_SHAPE);

        int ch = getchar();
        // Validate input: should be '1', '2', '3', '4', '5'
        if (ch < '1' || ch > '5') {
            printf(GAME_SHAPE_KEY_DOES_NOT_EXIST, ch);
            // Flush remaining characters
            while (getchar() != '\n');
            continue;
        }
        human_shape = ch - '1'; // '1' maps to 0, etc.

        while (getchar() != '\n'); // Flush input buffer

        agent_shape = (rand() % 5) + 1; // Generates 1 to 5
        printf(AGENT_PLAYED, agent_shape);

        // Determine winner
bool doesWin(int playerChoice, int opponentChoice) {
    switch (playerChoice) {
        case 1: // Rock
            return (opponentChoice == 3 || opponentChoice == 4);
        case 2: // Paper
            return (opponentChoice == 1 || opponentChoice == 5);
        case 3: // Scissors
            return (opponentChoice == 2 || opponentChoice == 4);
        case 4: // Lizard
            return (opponentChoice == 2 || opponentChoice == 5);
        case 5: // Spock
            return (opponentChoice == 1 || opponentChoice == 3);
        default:
            return false;
    }
}

// Usage after getting human_shape and agent_shape
if (doesWin(human_shape, agent_shape)) {
    human_score++;
} else if (doesWin(agent_shape, human_shape)) {
    agent_score++;
} // else tie


    // Announce winner after game ends
    if (human_score > agent_score)
        printf("%s won!\n", HUMAN_REPR);
    else if (agent_score > human_score)
        printf("%s won!\n", AGENT_REPR);
    else
        printf("It's a draw!\n");

    return 0;
}
