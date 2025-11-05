#include <stdio.h>
#include "inputs.h"
#include "meal.h"

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