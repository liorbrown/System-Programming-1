# pragma once

/**
 * @brief Handles the logic for a single meal at a specific time.
 * @param currentTime The current hour of the meal.
 * @param meatToDairyWait The required wait time after meat.
 * @param lastMeatTime The time the user last ate meat (passed by value).
 * @return The updated time the user last ate meat.
 */
int processMealTime(int currentTime, int meatToDairyWait, int lastMeatTime);