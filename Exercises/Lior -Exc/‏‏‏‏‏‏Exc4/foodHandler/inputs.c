#include <stdio.h>
#define DAY_HOURS (24)
/**
 * @brief Prompts the user for their wake hour and validates it (1-22).
 * @return The validated wake hour.
 */
int getWakeHour() {
    int wake_hour;
    printf("Enter your wake hour (1-%d): ", DAY_HOURS - 1);
    while (scanf("%d", &wake_hour) != 1 || wake_hour < 1 || wake_hour > DAY_HOURS - 1)
        printf("Please insert valid input (1-%d): ", DAY_HOURS - 1);

    return wake_hour;
}

/**
 * @brief Prompts the user for their sleep hour and validates it.
 * @param wakeHour The user's wake hour, to ensure sleep > wake.
 * @return The validated sleep hour.
 */
int getSleepHour(int wakeHour) {
    int sleep_hour;
    
    printf("Enter your sleep hour (%d-%d): ", wakeHour + 1, DAY_HOURS);
    while (scanf("%d", &sleep_hour) != 1 || sleep_hour <= wakeHour || sleep_hour > DAY_HOURS)
        printf("Please insert valid input (%d-%d): ", wakeHour + 1, DAY_HOURS);
    
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