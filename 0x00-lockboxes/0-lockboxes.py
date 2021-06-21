#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec  11 8:24:21 2020

@author: Robinson Montes
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened

    Parameters
    - Box (list of ints): list with keys for boxes.

    Return
     True if all boxes were opened, or False if not.
    """
    for key in range(1, len(boxes) - 1):
        res = False
        for index in range(len(boxes)):
            res = key in boxes[index] and key != index
            if res:
                break
        if res is False:
            return res
    return True
