#!/bin/bash

STDOUT() { local e=$?; printf '%q' "$1"; [ 1 -lt "$#" ] && printf ' %q' "${@:2}"; printf '\n'; return $e; };
STDERR() { STDOUT "$@" >&2; };
OOPS() { STDERR "$@"; exit 23; };

TMP="$(mktemp -d)" || OOPS mktemp failed;
trap 'rm -rf "$TMP"' 0	# cleanup

echo "Tests: Not yet implemented"

