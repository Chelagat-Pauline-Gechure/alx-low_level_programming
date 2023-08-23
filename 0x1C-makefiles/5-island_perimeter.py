#!/usr/bin/python3
""" Module that calculates the perimeter of an island in a grid. """


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    grid is a list of list of integers:

    """
    grid_perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[i])):
            if grid[x][y] == 1:
                if x == 0 or grid[x - 1][y] == 0:
                    grid_perimeter += 1
                if x == len(grid) - 1 or grid[x + 1][y] == 0:
                    grid_perimeter += 1
                if y == 0 or grid[x][y - 1] == 0:
                    grid_perimeter += 1
                if y == len(grid[x]) - 1 or grid[x][y + 1] == 0:
                    grid_perimeter += 1
    return (grid_perimeter)