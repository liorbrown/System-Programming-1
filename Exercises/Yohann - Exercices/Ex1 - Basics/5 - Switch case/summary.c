#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nb_players;

    puts("Enter number of players (0 to quit):");
    while (printf("> "), fflush(stdout), scanf("%d", &nb_players) == 1)
    {
        if (nb_players == 0)
        {
            puts("Goodbye.");
            return 0;
        }

        switch (nb_players)
        {
        case 1:
            puts("Solitaire — single-player card/puzzle game.");
            break;

        case 2:
            puts("Chess or Checkers — classic two-player board games.");
            break;

        case 3:
            puts("Uno — great for three players.");
            // break; // !!!
        case 4:
            if (nb_players == 4)
                puts("Team games (2v2), 4-player board games.");
            else
                puts("For 3–4 players consider party/team games.");
            break;

        case 5:
        case 6:
        case 7:
        case 8:
            puts("Party games (e.g. Mafia, Codenames) — works well for 5–8 players.");
            break;

        default:
            puts("No suggestion for that number. Enter 0–8.");
            break;
        }
    }

    return 0;
}