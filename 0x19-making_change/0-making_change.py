#!/usr/bin/python3
"""
Determine the fewest number of coins
needed to meet a given total
"""


def makeChange(coins, total):
    """Determine fewest number of coins """
    cents = 0
    all_coins = 0

    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while all_coins + coin <= total:
            all_coins += coin
            cents += 1
        if all_coins == total:
            return cents
    return -1
