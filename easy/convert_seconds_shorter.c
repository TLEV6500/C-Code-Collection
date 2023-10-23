#include <stdio.h>

int main() {
  int d, h, m, s;
  const int S_TO_M = 60, S_TO_H = S_TO_M * 60, S_TO_D = S_TO_H * 24;
  printf("Enter the number of seconds: ");
  scanf("%d", &s);

  // Fit s into whole days through division of S_TO_D (seconds in a day)
  d = s / S_TO_D;

  // s is reassigned the leftover seconds from d (remainder) and is then used to calc h
  h = (s %= S_TO_D) / S_TO_H;

  // s is reassigned the leftover seconds from h (remainder) and is then used to calc m
  m = (s %= S_TO_H) / S_TO_M;

  // s is reassigned the leftover seconds from m (remainder) which are the smallest divisions of time
  s %= S_TO_M;

  printf("%d days, %d hours, %d minutes, %d seconds", d, h, m, s);
  return 0;
}
