#!/usr/bin/python3
"""
Lockboxes
"""


def canUnlockAll(boxes):
    """
    check if all the boxes can be opened.
    """

    open = [False] * len(boxes)
    open[0] = True
    Res = [0]


    while Res:
        current_box = Res.pop(0)

        for key in boxes[current_box]:
            if 0 <= key < len(boxes) and not open[key]:
                open[key] = True
                Res.append(key)

    return all(open)
