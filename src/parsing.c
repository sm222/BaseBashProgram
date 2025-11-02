#include "dataType.h"
#include "utilse.h"
#include "flags.h"

const char* const flag_singile[] = {
  "c\tforce colors output",
  0x0,
};

# define AUTO_COLOR "AUTO_COLOR=TRUE"

int env_parsing(t_setting* setting) {
  for (int i = 0; setting->env[i]; i++) {
    if (strncmp(setting->env[i], AUTO_COLOR, strlen(AUTO_COLOR)) == 0) {
      set_byte(&setting->flags, setting_color, true);
      break ;
      // only one setting so break after we find it to optimise run time
    }
  }
  return 0;
}

static int set_single_value(t_setting* setting, int c) {
  if (c == 'c') {
    set_byte(&setting->flags, setting_color, true);
  }
  else if (c == 'h') {
    put_str_error(setting, RED, "todo: print help\n");
  }
  else {
    put_str_error(setting, RED, "%c: is unknow flag, call -h or --help to see the option\n", c);
    return 1;
  }
  return 0;
}

int parsing_get_single(t_setting* setting) {
  if (setting->current > setting->ac)
    return -1;
  if (setting->av[setting->current][0] == '-' && !setting->av[setting->current][1]) {
    put_str_error(setting, RED, "flag was call with not params\n");
    return 2;
  }
  const size_t len = strlen(setting->av[setting->current]);
  int error = 0;
  for (size_t i = 1; i < len; i++) {
    error = set_single_value(setting, setting->av[setting->current][i]);
    if (!read_byte(setting->flags, setting_continue_on_error) && error)
      break;
  }
  return error;
}


const char* const doubleFlags[] = {
  "COLOR",
  "TEXT=",
  "TT>",
  0x0
};

/*
static size_t get_end_str(const char*s , char* l) {
  size_t len = 0;
  for (; s[len]; len++) {
    size_t f = 0;
    while (l[f]) {
      if (l[f] == s[len])
        return len;
      f++;
    }
  }
  return len;
}
*/


static int set_double_value(t_setting *setting) {
  const char* s = setting->av[setting->current] + 2;
  printf("> %s\n", s);
  size_t len = 0;
  const char* w = doubleFlags[2];
  while (w[len] && (w[len] != 0 && w[len] != '>' && w[len] != '=')) {
    len++;
  }
  printf("%.*s\n", (int)len, w);
  return 0;
}

int parsing_get_double(t_setting *setting) {
  if (setting->current > setting->ac)
    return -1;
  if (setting->av[setting->current][1] == '-' && !setting->av[setting->current][2]) {
    put_str_error(setting, RED, "flag was call with not params\n");
    return 2;
  }
  return set_double_value(setting);
}