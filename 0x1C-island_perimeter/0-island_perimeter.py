#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 10 08:20:12 2021

@author: Robinson Montes
"""


def add_border(grid):
    """ add horizontal zero padding """
    last_idx = len(grid[0]) + 1
    for row in grid:
        row.insert(0, 0)
        row.insert(last_idx, 0)


def transpose_grid(grid):
    """ matrix transpose"""
    return [[row[i] for row in grid] for i in range(len(grid[0]))]


def count_blocks(grid):
    """ count the perimeter for vertical match """
    count = 0
    for row in grid:
        for i in range(len(row)):
            if row[i] == 1 and row[i-1] == 0:
                count += 1
            if row[i] == 0 and row[i-1] == 1:
                count += 1
    return count


def island_perimeter(grid):
    """  returns the perimeter of the island described in grid
         grid is rectangular, with its width and height not exceeding 100
    """
    add_border(grid)

    # count blocks vertical axes
    perimeter = count_blocks(grid)

    # transpose to count horizontal blocks
    grid_t = transpose_grid(grid)
    add_border(grid_t)

    # count block horizontal axes (after transpose)
    perimeter += count_blocks(grid_t)

    return perimeter
