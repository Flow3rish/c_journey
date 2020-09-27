#!/bin/bash

OUTPUT=$(script --return --quiet -c "gcc -o \"${1%.*}\" $1" /dev/null | tee /dev/tty)
# script command preservers the color formatting of a terminal

if  [ -z "$OUTPUT" ]; then 
./${1%.*};
fi
