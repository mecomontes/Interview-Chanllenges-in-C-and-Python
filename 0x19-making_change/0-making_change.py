#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jun 21 08:23:12 2021

@author: Robinson Montes
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins needed to
        meet a given amount total
    :param coins: list of the values of the coins in your possession
    :param total: mone amount
    :return: number of coins
    """

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    sum = 0
    i = 0
    counter = 0
    num_coins = len(coins)
    while sum < total and i < num_coins:
        while coins[i] <= total - sum:
            sum += coins[i]
            counter += 1
            if sum == total:
                return counter
        i += 1
    return -1
