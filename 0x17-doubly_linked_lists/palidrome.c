#include <stdio.h>

int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }

    return (originalNum == reversedNum);
}

int main() {
    int largestPalindrome = 0;
    int i, j;
    FILE *file;

    for (i = 999; i >= 100; i--) {
        for (j = 999; j >= 100; j--) {
            int product = i * j;
            if (product > largestPalindrome && isPalindrome(product)) {
                largestPalindrome = product;
            }
        }
    }

    file = fopen("102-result", "w");
    fprintf(file, "%d", largestPalindrome);
    fclose(file);

    return 0;
}
