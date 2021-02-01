#!/bin/bash
$ ./solver.sh 1-0-3-1=15-1-21
./solver $1 $2 $3 $4 $5 | sort | uniq
