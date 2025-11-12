#include <stdio.h>
#include "meal.h"

#define PIZZA ('p')
#define STEAK ('s')
#define APPLE ('a')

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
 * @return The updated time the user last ate meat.
 */
int processMealTime(int currentTime, int meatToDairyWait, int lastMeatTime) {

    int is_valid = 0;
    char food;

    while (!is_valid) {
        is_valid = 1;

        printf("\nThe time is %d, what would you like to eat now?\n", currentTime);
        printf("'%c': 🥩 | '%c': 🍕 | '%c': 🍎: ", STEAK, PIZZA, APPLE);
        
        scanf(" %c", &food);
        
        switch (food)
        {
        case PIZZA:
            if (!isPizzaAllowed( currentTime, meatToDairyWait, lastMeatTime)) {
                printf("🛑 Constraint Broken: You must wait %d hours after meat before having dairy.\n",
                        meatToDairyWait);
                is_valid = 0;
                }

            break;
        case STEAK:
            lastMeatTime = currentTime;

            break;
        case APPLE:
            break;
        default:
            printf("❌ Invalid input. Please choose '%c', '%c', or '%c'.\n", STEAK, PIZZA, APPLE);
            is_valid = 0;

            break;
        }
    }
    
    return lastMeatTime;
}