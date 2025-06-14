
#include "dataType.h"
#include "utilse.h"
#include "parsing.h"


int base(t_mainData data, int fdIn, int fdOut) {
  int status = EX_OK;
  t_setting programSetting;
  //
  bzero(&programSetting, sizeof(programSetting));
  programSetting.stdIn = fdIn;
  programSetting.stdOut = fdOut;
  programSetting.programeName = data.av[0];
  //
  const size_t argvLen = getArrayLen(data.av); // include program name
  //const size_t envLen  = getArrayLen(data.env);
  
  for (size_t i = 1; i < argvLen; i++) {
    const size_t lineSize = strlen(data.av[i]);
    if (strncmp(data.av[i], "--", 2) == 0 )                              // verbose
      printf("1 %zu\n", lineSize);
    else if (strncmp(data.av[i] , "-", 1) == 0 && data.av[i][1] != '\0') // flags like -xyz
      status = setFlag(data.av[i], lineSize, &programSetting);
    else
      printf("3 %zu\n", lineSize);
    if (programSetting.stopOnError && status)
      break ;
  }
  return status;
}


int main(int ac, const char* const* av, const char* const* env) {
  t_mainData data = {
    .ac = ac,
    .av = av,
    .env = env,
  };
  return base(data, STDIN_FILENO, STDOUT_FILENO);
}
