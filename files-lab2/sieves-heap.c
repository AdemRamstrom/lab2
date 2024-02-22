#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

void print_sieves(int n);
void print_number(int n, int column);

int main(int argc, char *argv[]) {
    if(argc == 2)
        print_sieves(atoi(argv[1]));
    else
        printf("Please state an integer number.\n");
    return 0;
}

void print_number(int n, int column) {
    if(column % COLUMNS == 0) printf("\n");
    printf("%10d ", n);
}

void print_sieves(int n) {
    if (n < 2)
        return;

    char *primes = (char *)malloc((n+1) * sizeof(char));
    if (primes == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    primes[0] = primes[1] = 0; // 0 and 1 are not primes

    for (int i = 2; i <= n; i++)
        primes[i] = 1; // Assume all numbers are primes initially

    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == 1) {
            // If primes[p] is not changed, then it is a prime
            for (int i = p * p; i <= n; i += p)
                primes[i] = 0; // Update all multiples of p
        }
    }

    int column = 0;
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            print_number(i, column);
            column++;
        }
    }

    free(primes); // Free the allocated memory
}
