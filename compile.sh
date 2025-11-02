#!/bin/env bash

name='base'

files=$(ls src/*.c)

safety=" -D NAME_CHECK "

rule=" --std=c99 -g -D PROG_NAME=\"$name\" $safety "
compileLine="cc $rule -Wall -Werror -Wextra  $files  -o $name"

#
version="1.0.0"
#

av=$1

str1=${av:0:1}


length=${#av}

if [[ "$str1" == "-" ]]; then
  for i in {1..{$length}}; do
  echo $i
  str2=${av:$i:$i}
    if [[ "$str2" == "v" ]]; then
      bash --version
      exit 0
    elif [[ "$str2" == "t" ]]; then
      echo ttt
      exit 0
    else
      echo 'bad args' $str2
      exit 1
    fi
  done
fi

# first_char=${string:0:1}


# code

echo '|' $compileLine '|'

$compileLine

exit 0
