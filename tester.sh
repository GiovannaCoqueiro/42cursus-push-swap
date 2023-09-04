#!/bin/bash

count=100
operations=0
total=0
for i in $(seq $count); do
./push_swap $(shuf -i 0-5000 -n 500) | wc -l >> result
done
echo $count " combinations // 500 Numbers" >> report
echo "===" >> report
echo "MAX" >> report
cat result | sort -n | tail -1 >> report
echo "MIN" >> report
cat result | sort -n | head -1 >> report
echo "MED" >> report
awk '{total += $1; operations++} END {print total/operations}' result >> report