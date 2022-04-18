#!/bin/bash

# Declare an array and sum over all of the elements
arr=(1 2 3 4)

i=0
len=${#arr[@]}
sum=0

while [ "$i" -lt "$len" ]; do
  echo ${arr[$i]}
  ((sum+=${arr[$i]}))
  ((i++))

done

echo "Sum is $sum"
