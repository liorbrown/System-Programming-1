#include <stdio.h>

/**
 * @brief Prompts the user for their wake hour and validates it (1-22).
 * @return The validated wake hour.
 */
int getWakeHour() {
    int wake_hour;
    printf("Enter your wake hour (1-22): ");
    while (scanf("%d", &wake_hour) != 1 || wake_hour < 1 || wake_hour > 22)
        printf("Please insert valid input (1-22): ");

    return wake_hour;
}

/**
 * @brief Prompts the user for their sleep hour and validates it.
 * @param wakeHour The user's wake hour, to ensure sleep > wake.
 * @return The validated sleep hour.
 */
int getSleepHour(int wakeHour) {
    int sleep_hour;
    
    printf("Enter your sleep hour (%d-23): ", wakeHour + 1);
    while (scanf("%d", &sleep_hour) != 1 || sleep_hour <= wakeHour || sleep_hour > 23)
        printf("Please insert valid input (%d-23): ", wakeHour + 1);
    
    return sleep_hour;
}

/**
 * @brief Prompts the user for their fasting gap and validates it (> 0).
 * @return The validated fasting gap.
 */
int getFastingGap() {
    int fasting_gap;
    printf("Enter your fasting gap: ");
    while (scanf("%d", &fasting_gap) != 1 || fasting_gap <= 0)
        printf("Please insert positive integer: ");

    return fasting_gap;
}

/**
 * @brief Prompts the user for the meat-to-dairy wait time (>= 0).
 * @return The validated wait time.
 */
int getMeatToDairyWait() {
    int meat_to_dairy_wait;
    printf("Enter your waiting time from meat to dairy: ");
    while (scanf("%d", &meat_to_dairy_wait) != 1 || meat_to_dairy_wait < 0)
        printf("Please insert non-negative integer: ");
    
    return meat_to_dairy_wait;
}

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
        printf("'s': 🥩 | 'p': 🍕 | 'a': 🍎: ");
        
        scanf(" %c", &food);
        
        switch (food)
        {
        case 'p':
            if (!isPizzaAllowed( currentTime, meatToDairyWait, lastMeatTime)) {
                printf("🛑 Constraint Broken: You must wait %d hours after meat before having dairy.\n",
                        meatToDairyWait);
                is_valid = 0;
                }

            break;
        case 's':
            lastMeatTime = currentTime;

            break;
        case 'a':
            break;
        default:
            printf("❌ Invalid input. Please choose 'S', 'P', or 'A'.\n");
            is_valid = 0;

            break;
        }
    }
    
    return lastMeatTime;
}

// This program simulates a day's eating schedule 😋
// The program gets from user 4 integers
//  1) Wake hour
//  2) Sleep hour
//  3) Fasting gap
//  4) Waiting time from meat to dairy (Can be zero, we are liberal 🤗)
//  (Ensure: 0 <= Wake hour < Sleep hour < 24)
// For each meal, the program asks: "the time is *****, what would you like to eat now?"
//  1) 'S' 🥩
//  2) 'P' 🍕
//  3) 'A' 🍎
// Validation: If the input is wrong or not allowed (violates constraints), the program prompts the user to choose again
int main() {

    // --- Variable Declarations ---
    int last_meat_time = 0; // 0 indicate that not eat meat

    // --- Input Collection ---
    int wake_hour = getWakeHour();
    int sleep_hour = getSleepHour(wake_hour);
    int fasting_gap = getFastingGap();
    int meat_to_dairy_wait = getMeatToDairyWait();

    // --- Main Meal Loop ---
    printf("\n--- Good morning 🌈 ---\n");

    for (int current_time = wake_hour; 
        current_time < sleep_hour; 
        current_time += fasting_gap)
        last_meat_time = processMealTime(current_time, meat_to_dairy_wait, last_meat_time);
    

    printf("\n--- Good night 🌆 and Sleep tight 😴 ---\n");

    return 0; // Indicate successful execution
}