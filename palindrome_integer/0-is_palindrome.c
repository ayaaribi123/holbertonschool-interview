#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n) {
    unsigned long reversed = 0, original = n;

    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return (original == reversed);
}
