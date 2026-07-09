#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game entities
typedef struct {
    char name[50];
    int hp;
    int lvl;
    int key;  // 1 = has keycard
    int pots; // Healing potions
} Plyr;

typedef struct {
    char name[50];
    int hp;
    int dmg;
} Mob;

Plyr init_plyr() {
    Plyr p;
    strcpy(p.name, "Unknown");
    p.hp = 100;
    p.lvl = 1;
    p.key = 0;
    p.pots = 1; 
    return p;
}

int main() {
    Plyr p = init_plyr();
    Mob mob = {"Shadow Beast", 30, 5};

    printf("========================================\n");
    printf("[SYSTEM] INIT COMPLETE. WELCOME.\n");
    printf("========================================\n\n");

    printf("[SYSTEM] ENTER NAME:\n> ");
    scanf("%49s", p.name); 

    printf("\n========================================\n");
    printf("[SYSTEM] REGISTRATION COMPLETE. LUCK, %s.\n", p.name);
    printf("========================================\n\n");

    printf("You wake up in a dark room. Your head is pounding.\n");

    int room = 0;   // 0 = Start, 1 = Hallway, 2 = Exit
    int locked = 1; 
    int playing = 1;
    char cmd[50];   

    while (playing) {
        printf("\n> ");
        scanf("%49s", cmd);

        if (strcmp(cmd, "quit") == 0) {
            printf("\n[SYSTEM] SHUTTING DOWN...\n");
            playing = 0; 
        }
        else if (strcmp(cmd, "look") == 0) {
            if (room == 0) {
                printf("\nCold, bare metal room.\n");
                printf(locked ? "A heavy steel door is to the north.\n" : "The steel door is open.\n");
            } else if (room == 1) {
                printf("\nA freezing, dim hallway.\n");
                if (mob.hp > 0) {
                    printf("A terrifying %s blocks your path!\n", mob.name);
                } else {
                    printf("The %s's ashes cover the floor.\n", mob.name);
                    printf("A blast door glows with an EXIT sign ahead.\n");
                }
            }
        }
        else if (strcmp(cmd, "search") == 0) {
            if (room == 0 && p.key == 0) {
                printf("\nYou find a plastic rectangle.\n[SYSTEM] ACQUIRED: KEYCARD.\n");
                p.key = 1; 
            } else {
                printf("\nYou find nothing.\n");
            }
        }
        else if (strcmp(cmd, "open") == 0) {
            printf("Open what?\n> ");
            scanf("%49s", cmd); 

            if (strcmp(cmd, "door") == 0 && room == 0) {
                if (locked && p.key) {
                    printf("\n*BEEP* The steel door grinds open.\n");
                    locked = 0; 
                } else if (locked) {
                    printf("\nLocked tight. [SYSTEM] KEYCARD REQUIRED.\n");
                } else {
                    printf("\nAlready open.\n");
                }
            } else {
                printf("\nYou can't open that.\n");
            }
        }
        else if (strcmp(cmd, "stats") == 0) {
            printf("\n--- %s's STATS ---\nHP: %d/100 | LVL: %d\n-------------------\n", p.name, p.hp, p.lvl);
        }
        else if (strcmp(cmd, "inv") == 0 || strcmp(cmd, "items") == 0) {
            printf("\n--- INVENTORY ---\nPotions: %d\n", p.pots);
            if (p.key) printf("Security Keycard\n");
            printf("-----------------\n");
        }
        else if (strcmp(cmd, "go") == 0) {
            printf("Go where?\n> ");
            scanf("%49s", cmd);

            if (strcmp(cmd, "north") == 0 || strcmp(cmd, "hallway") == 0 || strcmp(cmd, "forward") == 0) {
                if (!locked && room == 0) {
                    printf("\nYou step into the freezing hallway.\n");
                    room = 1; 
                } else if (room == 1) {
                    if (mob.hp > 0) {
                        printf("\nThe %s blocks you!\n", mob.name);
                    } else {
                        printf("\nYou push through the blast door...\n");
                        room = 2; // Move to exit
                    }
                } else if (locked) {
                    printf("\nThe door blocks your path.\n");
                }
            } else {
                printf("\nYou can't go that way.\n");
            }

            // Victory Check
            if (room == 2) {
                printf("\n========================================\n");
                printf("[SYSTEM] ESCAPED. MISSION ACCOMPLISHED.\n");
                printf("[SYSTEM] CONGRATULATIONS, %s.\n", p.name);
                printf("========================================\n\n");
                playing = 0; 
            }
        }
        else if (strcmp(cmd, "attack") == 0) {
            if (room == 1 && mob.hp > 0) {
                printf("\nYou strike the %s!\n", mob.name);
                mob.hp -= 15;
                
                if (mob.hp <= 0) {
                    printf("\n[SYSTEM] %s DEFEATED. LEVELED UP.\n", mob.name);
                    p.lvl++;
                    p.hp = 100;
                } else {
                    p.hp -= mob.dmg; 
                    printf("%s has %d HP left.\nIt hits you for %d dmg! (HP: %d/100)\n", mob.name, mob.hp, mob.dmg, p.hp);
                    
                    if (p.hp <= 0) {
                        printf("\n[SYSTEM] CRITICAL ERROR: HP IS 0. GAME OVER.\n");
                        playing = 0; 
                    }
                }
            } else {
                printf("\nNothing to attack.\n");
            }
        }
        else if (strcmp(cmd, "use") == 0) {
            printf("Use what?\n> ");
            scanf("%49s", cmd);

            if (strcmp(cmd, "potion") == 0) {
                if (p.pots > 0 && p.hp < 100) {
                    p.hp = (p.hp + 40 > 100) ? 100 : p.hp + 40;
                    p.pots--;
                    printf("\nHealed! HP: %d/100. Potions left: %d\n", p.hp, p.pots);
                } else if (p.hp >= 100) {
                    printf("\nHP is already full!\n");
                } else {
                    printf("\nNo potions left!\n");
                }
            } else {
                printf("\nCan't use that.\n");
            }
        }
        else {
            printf("\nTry: look, search, open, go, stats, inv, attack, use, quit.\n");
        }
    }

    return 0;
}
