#!/bin/bash

# Take n input integers from the user and add them up
echo -n "Enter the number of integers you want to add: "
read n

sum=0

for (( i = 0; i < $n; i++ ));
  do
    read a
    ((sum+=a))
done

echo "Sum of the numbers entered is $sum"
