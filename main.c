#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Player struct
typedef struct {
    char name[50];
    int hp;
    int level;
} Player;

// Initialize player with default stats
Player init_player() {
    Player p;
    p.hp = 100;
    p.level = 1;
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
    int playing = 1;
    char command[50]; // Variable to store what the player types
    
    while (playing) {
        printf("\nWhat do you want to do?\n> ");
        scanf("%49s", command); // Reads up to 49 characters
        
        if (strcmp(command, "quit") == 0) {
            printf("\n[SYSTEM] SHUTTING DOWN...\n");
            playing = 0; // This breaks the loop
        } 
        else if (strcmp(command, "look") == 0) {
            printf("\nThe room is made of cold, bare metal.\n");
            printf("There is a heavy steel door to the north.\n");
        } 
        else {
            printf("\n[SYSTEM ERROR] Command not recognized. Try 'look' or 'quit'.\n");
        }
    }
    
    return 0;
}
