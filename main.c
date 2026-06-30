#include <stdio.h>
#include <stdlib.h>

// Define the Player struct
typedef struct {
    char name[50];
    int hp;
    int level;
} Player;

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
    
    return 0;
}
