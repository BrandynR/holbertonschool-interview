#!/usr/bin/python3
"""Return winner of Prime Game """


def isWinner(x, nums):
    """Deterimines the name of the player that won the most rounds"""
    if not nums or x < 1:
        {
            return None
        }
    n = max(nums)
    
