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
    int lastMeatTime = 0; // 0 indicate that not eat meat

    // --- Input Collection ---
    int wakeHour = getWakeHour();
    int sleepHour = getSleepHour(wakeHour);
    int fastingGap = getFastingGap();
    int meatToDairyWait = getMeatToDairyWait();

    // --- Main Meal Loop ---
    printf("\n--- Good morning 🌈 ---\n");

    for (int currentTime = wakeHour; currentTime < sleepHour; currentTime += fastingGap)
        lastMeatTime = processMealTime(currentTime, lastMeatTime, meatToDairyWait);

    printf("\n--- Good night 🌆 and Sleep tight 😴 ---\n");

    return 0; // Indicate successful execution
}