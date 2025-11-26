#!/usr/bin/env python3

import sys
import shutil

def usage():
    sys.stderr.write("Usage: cat [file]\n")
    sys.exit(1)

if len(sys.argv) > 2:
    usage()

if len(sys.argv) == 2:
    try:
        with open(sys.argv[1], 'rb') as f:
            shutil.copyfileobj(f, sys.stdout.buffer)
    except OSError as e:
        sys.stderr.write(f"{sys.argv[1]}: {e.strerror}\n")
        sys.exit(1)
else:
    try:
        shutil.copyfileobj(sys.stdin.buffer, sys.stdout.buffer)
    except OSError:
        sys.exit(1)
