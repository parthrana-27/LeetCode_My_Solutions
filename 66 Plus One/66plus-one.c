#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int n = digitsSize;
    
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1; 
            *returnSize = n;
            return digits;   
        }     
        digits[i] = 0;
    }
    int* newDigits = (int*)malloc((n + 1) * sizeof(int));
    newDigits[0] = 1; 
    for (int i = 1; i <= n; i++) {
        newDigits[i] = 0;  
    }
    *returnSize = n + 1;  
    return newDigits;   
}
