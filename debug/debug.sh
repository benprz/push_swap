#!/bin/sh

source $1

CURRENT_ARGS=""

for j in {0..125}
do
	CURRENT_ARGS+=" ${ARGS[j]}"
	echo $j
done

echo $CURRENT_ARGS
../push_swap $CURRENT_ARGS
