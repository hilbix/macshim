#!/bin/bash
#
# cp --backup=t SRC DST
#
# This Works is placed under the terms of the Copyright Less License,
# see file COPYRIGHT.CLL.  USE AT OWN RISK, ABSOLUTELY NO WARRANTY.

OOPS() { { printf '%q OOPS:' "$(basename "$0")"; printf ' %q' "$@"; printf '\n'; } >&2; exit 23; }
o() { "$@" || OOPS exec "$?:" "$@"; }

back=false
force=
OPTS=()
ARGS=("$@")
while	case "$1" in
	(--backup=*)	back="${1#--backup=}";;
	(-b)		back=simple;;
	(-[fi])		force="$1"; OPTS+=("$1");;
	(-[RHLPnapvX]*)	OPTS+=("$1");;
	(--)		shift; false;;
	(-*)		OOPS unknown option "$1";;
	(*)		false;;
	esac
do
	shift
done

case "$back" in
(false|none|off)	back=;;
(numbered|t|true)	back=t;;
(existing|nil)		OOPS --backup=existing not supported;;
(simple|never)		back=s;;
(*)			OOPS unknown option variant "--backup=$back";;
esac

[ -z "$back" ] && exec /bin/cp "${OPTS[@]}" -- "$@"

case "${OPTS[*]}" in
(*R*)	OOPS --backup not yet supported with -R;;
esac

HERE="$(o dirname "$0")" || exit

[ 1 -lt "$#" ] || OOPS option -s needs: src.. target

TARG="${@:$#}"
FILE=""

copy()
{
if [ -e "$2" ]
then
	n=1
	e="~"
	[ t = "$back" ] && while e=".~$n~"; [ -e "$2$e" ]; do let n++; done
	o /bin/mv $force -- "$2" "$2$e"
fi
o /bin/cp "${OPTS[@]}" -- "$@"
}

if	[ -d "$TARG" ]
then
	for arg in "${@:1:$#-1}"
	do
		copy "$arg" "$TARG/${arg##*/}"
	done
else
	[ 2 -ge "$#" ] || OOPS "$TARG" must be an existing directory
	copy "$1" "$TARG"
fi

