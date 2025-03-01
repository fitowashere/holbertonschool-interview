#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n;
    unsigned long reversed = 0;

    /* Reverse the number */
    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    /* Check if the reversed number equals the original */
    return (original == reversed);
}
