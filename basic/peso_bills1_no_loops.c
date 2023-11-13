/*  Problem Statement (paraphrased): 
    Make a program that takes input in pesos and counts the least number of bills and coins that exactly fits the input amount.
    Peso Bills: 1000, 500, 200, 100, 50, 20
    Peso Coins: 10, 5, 1
    Centavo Coins: 25, 1
    Restrictions: Do not use loops and other higher-level concepts in the C programming language.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    // q stands for quotient for the division of currency
    double q;
    // bc is a 2D array containing the value of each bill/coin paired with a counter for each to use with the input value
    int bc[11][2];
    // pi is for the integer part of the peso, pc is for the centavos part (in integer form)
    // i is used as a counter to simulate the process of a for loop
    int pi, pc, i=0;

    printf("Enter PESO amount (00.00): ");
    scanf("%d.%d", &pi,&pc);

    // Initialize array of bills and coins as well as their counters
    // Each array element must be initialized separately since direct initialization (i.e. arr[]={...}) will make the values immutable
    // Separate arrays for the currency values and the counters can be used to solve immutability, but I stuck with this for fewer variables
    bc[i][0] = 1000;
    ++i;
    bc[i][0] = 500;
    ++i;
    bc[i][0] = 200;
    ++i;
    bc[i][0] = 100;
    ++i;
    bc[i][0] = 50;
    ++i;
    bc[i][0] = 20;
    ++i;
    bc[i][0] = 10;
    ++i;
    bc[i][0] = 5;
    ++i;
    bc[i][0] = 1;
    ++i;
    bc[i][0] = 25;
    ++i;
    bc[i][0] = 1;
    // Don't forget to reset counter i = 0, because you are iterating again from index 0
    i=0;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    ++i;
    bc[i][1] = 0;
    // Don't forget to reset counter i = 0, because you are iterating again from index 0
    i=0;
    // pi is being counted for the individual bills/coins here, starting from the largest value, 1k
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=1;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=2;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=3;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=4;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=5;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=6;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=7;
    q = (double) pi / (double)bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pi -= bc[i][1]*bc[i][0];
    }
    ++i; //i=8;
    // Peso coins are being counted here, so there is no need to divide by anything
    // I know, doing this means that I didn't have to include 1-peso values in the above array, but for the sake of completeness, I did
    bc[i][1] = pi;
    ++i; //i=9;
    // Centavo values are now being counted here, note that pi was replaced by pc
    q = pc / bc[i][0];
    if (q >= 1)
    {
        bc[i][1] = (int) floor(q);
        pc -= bc[i][1]*bc[i][0];
    }
    ++i; //i=10;
    // Single centavos are left, so might as well directly assign it to the respective indexed element
    bc[i][1] = pc;

    // Another loop-like process is done here for displaying the results
    i = 0;
    printf("%d.%d Pesos is equivalent to these denominations: \n", pi, pc);
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Bills: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Coins: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Coins: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Peso Coins: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Centavo Coin: %d\n", bc[i][0], bc[i][1]);
    ++i;
    printf("%d Centavo Coin: %d\n", bc[i][0], bc[i][1]);

    return 0;
}
