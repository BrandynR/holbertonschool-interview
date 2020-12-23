#!/usr/bin/python3
"""0-pascal_triangle module"""


def pascal_triangle(n):
    """returns a list of lists of integers representing the Pascal’s triangle
    Args:
        n: height of Pascal's triangle
    Returns: Pascal's triangle
    """
    if n <= 0:
        return []

    pascals = []
    for i in range(n):
        sub = [1] * (i + 1)
        for j in range(i - 1):
            sub[j + 1] = pascals[i - 1][j] + pascals[i - 1][j + 1]
        pascals.append(sub)
    return pascals
