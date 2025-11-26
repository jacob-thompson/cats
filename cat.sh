#!/bin/sh

if [ "$#" -gt 1 ]; then
  printf 'Usage: cat [file]\n' >&2
  exit 1
fi

if [ "$#" -eq 1 ]; then
  if [ ! -r "$1" ]; then
    printf '%s: No such file or directory\n' "$1" >&2
    exit 1
  fi
  /bin/cat -- "$1" || exit 1
else
  /bin/cat || exit 1
fi

exit 0
