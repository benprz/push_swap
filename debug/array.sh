#!/bin/sh

RANDOM=$$
#a=$1
a=0

generate_array()
{
	ARGS=""
	k=0
	while [ "$k" -lt "$a" ]
	do
		ARGS+="$RANDOM "
		((k=k+1))
	done
}

for j in {0..1000}
do
	echo "\n************ $j ***************\n"
	i=0
	a=$j
	while [ "$i" -lt "100" ]
	do
		generate_array
		../push_swap $ARGS
		((i=i+1))
	done
	echo "\n*******************************\n\n\n"
done
