#!/bin/env bash


# setup
name='base'

files=$(ls src/*.c)


# cc setup
safety=" -D NAME_CHECK "

ccVar="--std=c99 -g -Wall -Werror -Wextra "

rule=" $ccVar -D PROG_NAME=\"$name\" $safety "
compileLine="cc $rule  $files  -o $name"

# projet version
version="1.0.0"
#

av=$1

str1=${av:0:1}


length=${#av}

i=1

if [[ "$str1" == "-" ]]; then
  while [ $i -lt $length ]
  do
  str2=${av:$i:1} # substr of 1
    if [[ "$str2" == "v" ]]; then
      bash --version
      echo - - -
      cc --version
      exit 0
    elif [[ "$str2" == "e" ]]; then
      cat $0
      exit 0
    elif [[ "$str2" == "h" ]]; then
      echo 'Help -'
      echo ' -v show bash vertion user and cc '
      echo ' -e print the file using cat '
      echo ' -h show this message '
      echo ' -l list the files use by cc '
      exit 0
    elif [[ "$str2" == "l" ]]; then
      echo Files - - -
      for f in $files; do
        echo $f
      done
      echo - - - - - -
    else
      echo 'unknow flag -' $str2
      echo "try $0 -h"
      exit 1
    fi
  ((i++))
  done
fi

# run code
echo '|' $compileLine '|'

$compileLine

exit 0


main() {
  
}