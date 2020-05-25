#!/bin/bash
for F in $*
do
	echo ${F%.*}
done
