#include <stdio.h>
#include <stdlib.h>

int SumOfDigits(int n) {
    int nSum = 0;
    do {
        nSum+= n%10;
    } while (n/=10);
    return nSum;
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int mas[n];

    for (int i = 0; i < n; i++) {
       mas[i] = rand() % 1000;
    }


    printf("Source array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", mas[i], ' ');
    }

    printf("\n");

    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if (SumOfDigits(mas[j + 1]) > SumOfDigits(mas[j])) {
                mas[j + 1] ^= mas[j] ^= mas[j + 1] ^= mas[j]; // обменивает значения в элементах массива
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", mas[i], ' ');
    }
}
