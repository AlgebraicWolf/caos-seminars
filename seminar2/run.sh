#!/usr/bin/env bash

# os_name=$(uname -o)
# arch_name=`uname -m`

# echo "Running $os_name on $arch_name"

# echo "Received $# arguments: $*"
# echo "$0"

# f() {
#   echo "Called f" 
#   return 0
# }

# g() {
#   echo "Called g"
#   return 5
# }

# h() {
#   echo "Called h"
#   return 0
# }

# f || h

read x
read y

if [ $x -eq $y ]
then
  echo "$x is equal to $y"
elif [ $x -lt $y ]
then
  echo "$x is less than $y"
else
  echo "$x is greater than $y"
fi

result=$(echo "$x/$y" | bc -l)

echo "The sum of $x and $y is $result"

# while read line
# do
#   echo $line | wc -c
# done

# IFS="@"

# for item in $(echo "I@love@@@@@@CA   OS")
# do
#   echo $item
# done
