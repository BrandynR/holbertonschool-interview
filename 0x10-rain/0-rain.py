#!/usr/bin/python3
"""rain module"""


def rain(walls):
    """calculate how much water will be retained after it rains
    Args: walls:  is a list of non-negative integers
    Returns: Integer indicating total amount of rainwater retained
    """
    left_wall = water = lmax = rmax = 0
    right_wall = len(walls) - 1

    while left_wall < right_wall:
        if walls[left_wall] < walls[right_wall]:
            if walls[left_wall] < lmax:
                water += lmax - walls[left_wall]
            else:
                lmax = walls[left_wall]
            left_wall += 1
        else:
            if walls[right_wall] < rmax:
                water += rmax - walls[right_wall]
            else:
                rmax = walls[right_wall]
            right_wall -= 1
    return water
