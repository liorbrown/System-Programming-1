/**
 * @brief Prompts the user for their wake hour and validates it (1-22).
 * @return The validated wake hour.
 */
int getWakeHour();

/**
 * @brief Prompts the user for their sleep hour and validates it.
 * @param wakeHour The user's wake hour, to ensure sleep > wake.
 * @return The validated sleep hour.
 */
int getSleepHour(int wakeHour);

/**
 * @brief Prompts the user for their fasting gap and validates it (> 0).
 * @return The validated fasting gap.
 */
int getFastingGap();

/**
 * @brief Prompts the user for the meat-to-dairy wait time (>= 0).
 * @return The validated wait time.
 */
int getMeatToDairyWait();