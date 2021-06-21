#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 16 08:00:12 2021

@author: Robinson Montes
"""


def validUTF8(data):
    """
    Determines if a data set represents a valid UTF-8
    UTF could be until 4 bytes, managing them as UTF encode
    Return: True if is a valid UTF-8 encoding or False
    """
    n_bytes = 0

    for n in data:
        byte = format(n, '#010b')[-8:]
        if n_bytes == 0:
            if byte[0] == '1':
                n_bytes = len(byte.split('0')[0])
            if n_bytes > 4 or n_bytes == 1:
                return False
            if n_bytes == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        n_bytes -= 1

    if n_bytes != 0:
        return False
    return True
