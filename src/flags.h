#ifndef __FLAGS__
# define __FLAGS__

enum valueArg {
  e_bool,
  e_next,
  e_equal,
};

typedef struct s_flagValue {
  struct s_flagValue* next;
  int                 flag;
  char*               value;
} t_flagValue;


#endif