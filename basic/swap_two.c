#include <stdio.h>

int main() {
  int a = 0, b = 0;
  int aTmp, bTmp; // For resetting before using different methods.
  printf("Swap two numbers: ");
  scanf("%d %d", &a, &b);
  printf("Before swapping: a = %d, b = %d", a, b);
  aTmp = a;
  bTmp = b;

  // Using XOR operator, using only two variables, one-liner version;
  a ^= b ^= a ^= b;
  // Program flow is described as: a ^= (b ^= (a ^= b));.

  printf("\n\nUsing one-liner \"a ^= b ^= a ^= b\"");
  printf("\na = %d, b = %d", a, b);

  // Using XOR operator, two variables, expanded version;
  a = aTmp, b = bTmp;

  a ^= b;
  b ^= a;
  a ^= b;

  printf("\n\nUsing three-liner \"a ^= b; b ^= a; a ^= b;\"");
  printf("\na = %d, b = %d", a, b);

  // Using regular arithmetic, two variables, expanded version;
  a = aTmp, b = bTmp;

  a += b;
  b = a - b;
  a -= b;

  printf("\n\nUsing three-liner \"a += b; b = a - b; a -= b;\"");
  printf("\na = %d, b = %d", a, b);

  return 0;
}