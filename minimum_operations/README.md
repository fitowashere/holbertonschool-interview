#!/usr/bin/python3
"""
This module provides a function to calculate the minimum number of operations
needed to result in exactly `n` H characters in a text file.
"""


def minOperations(n):
    if n < 2:
        return 0
    operations = 0
    factor = 2
    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
    return operations
    