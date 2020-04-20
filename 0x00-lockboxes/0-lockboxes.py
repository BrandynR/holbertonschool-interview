#!/usr/bin/python3


def canUnlockAll(boxes):
    """Determine whether allKeys for all boxes are accessible """
    
    boxlength = len(boxes)

    if boxlength == 0:
        return True
    indexes = [False] * boxlength
    indexes[0] = True
    x = [0]

    while x:
        for key in boxes[x.pop()]:
            if key > 0 and key < boxlength and not indexes[key]:
                indexes[key] = True
                x.append(key)

    return all(indexes)
