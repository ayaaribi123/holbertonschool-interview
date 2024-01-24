 #!/usr/bin/python3
"""
Lockboxes
"""


def canUnlockAll(boxes):
    """
    Check if all the boxes can be opened.
    """

    is_open = [False] * len(boxes)
    is_open[0] = True

    to_visit = [0]

    while to_visit:
        current_box = to_visit.pop(0)

        for key in boxes[current_box]:
            if 0 <= key < len(boxes) and not is_open[key]:
                is_open[key] = True
                to_visit.append(key)

    return all(is_open)
