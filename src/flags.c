# include "flags.h"
# include <stdlib.h>
# include <string.h>

static char* __strdup(const char* s) {
  if (!s)
    return NULL;
  size_t i = strlen(s);
  char *str = calloc(i + 1, sizeof(*str));
  if (!str)
    return NULL;
  memmove(str, s, i + 1);
  return str;
}

static t_flagValue* fv_add(int flag, const char* value) {
  t_flagValue* f = calloc(1, sizeof(*f));
  if (f) {
    f->flag = flag;
    f->value = __strdup(value);
    if (!f->value) {
      free(f);
      f = NULL;
    }
  }
  return f;
}

int fv_add_last(t_flagValue** list, int flag, const char* value) {
  if (!list)
    return -1;
  if (!(*list)) {
    *list = fv_add(flag, value);
    if (!(*list))
      return -2;
  }
  else {
    t_flagValue *tmp = (*list);
    for (; tmp && tmp->next; tmp = tmp->next) { }
    tmp->next = fv_add(flag, value);
    if (!tmp->next)
      return -2;
  }
  return 0;
}

int fv_free(t_flagValue** list) {
  if (!list)
    return -1;
  for (t_flagValue* tmp = (*list); tmp; ) {
    free(tmp->value);
    t_flagValue *t = tmp->next;
    free(tmp);
    tmp = t;
  }
  return 0;
}

# include <stdio.h>
void fv_print(t_flagValue* list) {
  for ( ; list; list = list->next) {
    printf("[%d]%s\n", list->flag, list->value);
  }
}