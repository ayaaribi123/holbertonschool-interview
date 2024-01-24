#!/usr/bin/python3
"""
Minimum Operations
"""


def CheckNum(n):
    """
    Checks if a number is premium
    """
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def minOperations(n):
    """
    defines minimum operations
    """
    even = 2
    j = 0
    if n < 2:
        return 0
    while(n != 1):
        if (CheckNum(even)):
            if (n % even == 0):
                n = n / even
                j = j + even
            else:
                even += 1
    return j
