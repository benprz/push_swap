#!/bin/sh

source $1

CURRENT_ARGS=""

for j in {0..499}
do
	CURRENT_ARGS+=" ${ARGS[j]}"
	echo $j
	../push_swap $CURRENT_ARGS
done
