#!/bin/bash

name='base'

files=$(ls src/*.c)


compileLine="cc -Wall -Werror -Wextra $files -o $name"

#

echo '|' $compileLine '|'

#

$compileLine