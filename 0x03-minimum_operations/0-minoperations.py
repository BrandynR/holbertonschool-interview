#!/usr/bin/python3
"""fewest operations needed"""


def minOperations(n):
    """calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    Args:
        n: characters to reach
    Returns:
        fewest needed number of  operations
    """

    Actual = 1
    num_of_ops = 0

    if type(n) is not int or n < 2:
        return 0

    while (Actual != n):

        if (n % Actual == 0):
            CopyAll = Actual
            Paste = Actual + CopyAll
            num_of_ops += 2

        else:
            Paste = Actual + CopyAll
            num_of_ops += 1

        Actual = Paste

    return num_of_ops
