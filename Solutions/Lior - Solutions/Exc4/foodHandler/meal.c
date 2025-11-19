#include <stdio.h>

/**
 * @brief Checks if pizza allowed
 * @param currentTime The current hour of the meal.
 * @param meatToDairyWait The required wait time after meat.
 * @param lastMeatTime The time the user last ate meat (passed by value).
 * @return 1 - if allowed, 0 - Otherwise
 */
int isPizzaAllowed(int currentTime, int meatToDairyWait, int lastMeatTime){
    return (!lastMeatTime || (currentTime - lastMeatTime >= meatToDairyWait));
}

/**
 * @brief Handles the logic for a single meal at a specific time.
 * @param currentTime The current hour of the meal.
 * @param meatToDairyWait The required wait time after meat.
 * @param lastMeatTime The time the user last ate meat (passed by value).
 */
void processMealTime(int currentTime, int meatToDairyWait, int *lastMeatTime) {

    int is_valid = 0;
    char food;

    while (!is_valid) {
        is_valid = 1;

        printf("\nThe time is %d, what would you like to eat now?\n", currentTime);
        printf("'s': 🥩 | 'p': 🍕 | 'a': 🍎: ");
        
        scanf(" %c", &food);
        
        switch (food)
        {
        case 'p':
            if (!isPizzaAllowed( currentTime, meatToDairyWait, *lastMeatTime)) {
                printf("🛑 Constraint Broken: You must wait %d hours after meat before having dairy.\n",
                        meatToDairyWait);
                is_valid = 0;
                }

            break;
        case 's':
            *lastMeatTime = currentTime;

            break;
        case 'a':
            break;
        default:
            printf("❌ Invalid input. Please choose 'S', 'P', or 'A'.\n");
            is_valid = 0;

            break;
        }
    }
}