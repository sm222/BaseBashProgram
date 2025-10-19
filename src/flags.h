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


int          fv_add_last(t_flagValue** list, int flag, const char* value);
int          fv_free(t_flagValue** list);
void         fv_print(t_flagValue* list);


#endif