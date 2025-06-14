#include "dataType.h"

#define ERR_MSG "%s: unknown flag "

void flagsError(const char flag, t_setting* programSetting) {
  if (programSetting->color)
    fprintf(stderr, ERR_MSG "%s%c%s\n", programSetting->programeName, RED, flag, RESET);
  else
    fprintf(stderr, ERR_MSG "%c\n", programSetting->programeName, flag);
}

int setFlag(const char* line, const size_t n, t_setting* programSetting) {
  size_t i = 1;
  int status = 0;
  while (i < n) {
    if (line[i] == 'c') {
      programSetting->color = 1;
    }
    else if (line[i] == 's') {
      programSetting->stopOnError = 1;
    }
    else {
      status = 1;
      flagsError(line[i], programSetting);
      break ;
    }
    i++;
  }
  return status;
}