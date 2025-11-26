#!/usr/bin/env python3

import sys

def main():
    try:
        for line in sys.stdin:
            sys.stdout.write(line)
    except KeyboardInterrupt:
        exit(130)

if __name__ == "__main__":
    main()
