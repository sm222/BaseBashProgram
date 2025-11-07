#include "dataType.h"
#include "utilse.h"


static bool valid_end(const char* s) {
  if (!s || (*s == '=' && s[1] == 0))
    return false;
  return true;
}

static int demo_err(t_setting* setting, const char* data) {
  put_str_error(setting, RED, "%s: demo%s missing value", setting->av[0], data ? data : "");
  put_str_error(setting, RED, "ex: --demo=value");
  return 1;
}

int demo(t_setting* setting, const char* data) {
  if (valid_end(data))
    return demo_err(setting, data);
  printf("hi %s\n", data);
  return 0;
}

static int help_err(t_setting* setting, const char* data) {
  (void)setting;
  (void)data;
  return 1;
}

int  help(t_setting* setting, const char* data) {
  (void)setting;
  printf(">>%s\n", data);
  return 0;
  help_err(setting, data);
}