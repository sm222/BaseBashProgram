#include "dataType.h"
#include "utilse.h"
#include "flags.h"


# define AUTO_COLOR "AUTO_COLOR=on"

int env_parsing(t_setting* setting) {
  for (int i = 0; setting->env[i]; i++) {
    if (strncmp(setting->env[i], AUTO_COLOR, strlen(AUTO_COLOR)) == 0) {
      //setting->color = true;
      break ;
      // only one setting so break after we find it to optimise run time
    }
  }
  return 0;
}