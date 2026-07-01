#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Player struct
typedef struct {
    char name[50];
    int hp;
    int level;
    int has_keycard; // 1 means they have it, 0 means they don't
} Player;

// Initialize player with default stats
Player init_player() {
    Player p;
    strcpy(p.name, "Unknown");
    p.hp = 100;
    p.level = 1;
    p.has_keycard = 0; // Player starts with no keycard
    return p;
}

int main() {
    printf("========================================\n");
    printf("[SYSTEM] INITIALIZATION COMPLETE.\n");
    printf("[SYSTEM] WELCOME, PLAYER.\n");
    printf("========================================\n\n");

    printf("You wake up in a dark room. Your head is pounding.\n");
    printf("A glowing blue interface hovers in the air in front of you.\n");

    // The Game Loop
    int door_locked = 1; // 1 means locked, 0 means unlocked
    int playing = 1;
    char command[50]; // Variable to store what the player types

    while (playing) {
        printf("\nWhat do you want to do?\n> ");
        scanf("%49s", command); // Reads up to 49 characters

        // 1. Check for quit
        if (strcmp(command, "quit") == 0) {
            printf("\n[SYSTEM] SHUTTING DOWN...\n");
            playing = 0; // This breaks the loop
        }
        // 2. Check for look
        else if (strcmp(command, "look") == 0) {
            printf("\nThe room is made of cold, bare metal.\n");
            printf("There is a heavy steel door to the north.\n");
        }
        // 3. Check for open
        else if (strcmp(command, "open") == 0) {
            printf("\nWhat do you want to open?\n> ");
            scanf("%49s", command); // Read the second word

            if (strcmp(command, "door") == 0) {
                if (door_locked == 1) {
                    printf("\nYou push against the heavy steel door. It's locked tight.\n");
                    printf("[SYSTEM] A KEYCARD IS REQUIRED.\n");
                } else {
                    printf("\nThe steel door grinds open, revealing a dark hallway.\n");
                }
            } else {
                printf("\nYou can't open that.\n");
            }
        }
        // 4. Handle unrecognized commands
        else {
            printf("\n[SYSTEM ERROR] Command not recognized. Try 'look', 'open', or 'quit'.\n");
        }
    }

    return 0;
}
