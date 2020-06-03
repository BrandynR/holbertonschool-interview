#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


def print_10_lines():
    """
    Prints file size as well as dictionary of status
    """
    print("File size: {}".format(file_size))
    for key, value in sorted(dict.items()):
        if (value != 0):
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    lines = 1
    file_size = 0
    dict = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
        }
    try:
        for line in sys.stdin:
            try:
                status = line.split(" ")[-2]
                size = line.split(" ")[-1]
                file_size += int(size)
                dict[status] += 1
            except Exception:
                continue
            if lines % 10 == 0:
                print_10_lines()
            lines += 1

    except KeyboardInterrupt:
        print_10_lines()
        raise

    print_10_lines()
