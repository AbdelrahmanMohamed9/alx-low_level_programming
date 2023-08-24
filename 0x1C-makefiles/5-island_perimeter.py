#!/usr/bin/python3
''' Define function to measure the perimeter of an island `grid` '''


def island_perimeter(grid):
    '''return the perimeter of an island
    the grid represents water by 0 and land by 1
    Args:
        grid (list): the list of list of integers representing an island
    Returns:
        a perimeter of the island defined in grid
    '''
    prmeter = 0

    if grid != []:
        rows = len(grid)
        cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                if (i - 1) < 0 or grid[i - 1][j] == 0:
                    prmeter += 1
                if (i + 1) == rows or grid[i + 1][j] == 0:
                    prmeter += 1
                if (j - 1) < 0 or grid[i][j - 1] == 0:
                    prmeter += 1
                if (j + 1) == cols or grid[i][j + 1] == 0:
                    prmeter += 1

    return (prmeter)
