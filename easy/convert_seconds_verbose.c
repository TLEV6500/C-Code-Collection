#include <stdio.h>
#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24

int main() {
  int days, hours, minutes, seconds, input, remaining_seconds;
  const int SECONDS_IN_DAY = HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE;
  const int SECONDS_IN_HOUR = MINUTES_IN_HOUR * SECONDS_IN_MINUTE;

  // Fit the inputted seconds into whole days; using int division will remove excess seconds (fractional part)
  days = input / SECONDS_IN_DAY;

  // Calc the excess seconds not converted into days by subtracting from the total seconds (input);
  remaining_seconds = input - (days * SECONDS_IN_DAY);

  // Fit leftover seconds from previous calculation into whole hours
  hours = remaining_seconds / SECONDS_IN_HOUR;

  // Calc the excess seconds not converted into hours by subtracting from the previous leftover seconds
  remaining_seconds -= hours * SECONDS_IN_HOUR;

  // Fit new amount of leftover seconds into whole minutes
  minutes = remaining_seconds / SECONDS_IN_MINUTE;

  // Calc excess seconds not converted into minutes by subtracting from previous leftover seconds
  remaining_seconds -=  minutes * SECONDS_IN_MINUTE;

  // Whatever's left are just seconds that can't fit a single minute
  seconds = remaining_seconds;

  printf("%d days, %d hours, %d minutes, %d seconds", days, hours, minutes, seconds);
  return 0;
}
