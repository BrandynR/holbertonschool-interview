#!/usr/bin/python3
""" Calculates perimeter of and island """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """
    is_per = 0
    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == 1:
                if row == 0 or grid[row - 1][column] == 0:
                    is_per += 1
                if column == 0 or grid[row][column - 1] == 0:
                    is_per += 1
                if row == len(grid) - 1 or grid[row + 1][column] == 0:
                    is_per += 1
                if column == len(grid[row]) - 1 or grid[row][column + 1] == 0:
                    is_per += 1
    return is_per
