#!/usr/bin/python3
"""
This module provides a function to validate UTF-8 encoding.
It checks if a given data set represents a valid UTF-8 encoding
according to the UTF-8 encoding rules.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: A list of integers where each integer represents 1 byte of data
            (only the 8 least significant bits of each integer are considered)

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    # Number of bytes to process for the current character
    num_bytes_to_process = 0

    # Masks for checking the bit patterns
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    for byte in data:
        # Only consider the 8 least significant bits
        byte = byte & 0xFF

        # If we're not processing any bytes for the current character
        if num_bytes_to_process == 0:
            # Determine how many bytes the current character has

            # 1-byte character (0xxxxxxx)
            if byte >> 7 == 0:
                continue

            # 2-byte character (110xxxxx)
            elif byte >> 5 == 0b110:
                num_bytes_to_process = 1

            # 3-byte character (1110xxxx)
            elif byte >> 4 == 0b1110:
                num_bytes_to_process = 2

            # 4-byte character (11110xxx)
            elif byte >> 3 == 0b11110:
                num_bytes_to_process = 3

            # Invalid UTF-8 starting byte
            else:
                return False

        # If we're processing continuation bytes (10xxxxxx)
        else:
            # Check if the byte starts with 10
            if byte >> 6 != 0b10:
                return False

            # Decrement the number of bytes to process
            num_bytes_to_process -= 1

    # If we've processed all bytes and there are no pending bytes to process
    return num_bytes_to_process == 0
