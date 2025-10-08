#ifndef __FLAGS__
# define __FLAGS__

//  flags like -xyz

//  single
/*
format
-a             -    what it dose
^^ flag
| one dash
*/

# define DEVFLAG 1 // use only to work on base

enum valueArg {
  e_bool,
  e_next,
  e_equal,
};


#endif