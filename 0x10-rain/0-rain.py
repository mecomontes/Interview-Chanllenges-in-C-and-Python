#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 12 18:00:12 2021

@author: Robinson Montes
"""


def rain(walls):
    """ calculate how much water will be retained after it rains.

    Arg:
        - walls: is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.
    """
    max_water = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        max_water = max_water + (min(left, right) - walls[i])

    return max_water
