#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """ validate utf-8"""

    bin_10 = 0
    for bit in data:
        bit = '{0:08b}'.format(bit)[-8:]
        if bin_10 != 0:
            bin_10 -= 1
            if not bit.startswith('10'):
                return False
        elif bit[0] == '1':
            bin_10 = len(bit.split('0')[0])
            if bin_10 == 1 or bin_10 > 4:
                return False
            bin_10 -= 1
    if bin_10 != 0:
        return False
    return True
