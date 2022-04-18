#!/bin/bash

# Declare an array and concatenate all the strings separated by a space

arr=("I" "eat" "all" "foods")

i=0
len=${#arr[@]}
string=""

until [ "$i" -gt "$len" ]; do
  string+=${arr[$i]}
  string+=" "

  ((i++))

done

echo "Final string is: $string"
  


