#!/usr/bin/python3

def minOperations(n):
    """calculates the fewest number of operations needed to result in exactly n H characters in the file
    Args:
        n: characters to reach
    Returns:
        fewest needed number of  operations
    """
    sum = 0
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            sum += i
    if n > 1:
        sum += n
    return sum
