#!/bin/bash

COUNTER=0
LISTSIZE=15
LISTSTRIDE=5

while [ $COUNTER -lt 14 ]; do
    ./benchmark $LISTSIZE $LISTSTRIDE
    let LISTSIZE=LISTSIZE*2
    let COUNTER=COUNTER+1
done
