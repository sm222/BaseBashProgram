
#include "dataType.h"
#include "utilse.h"
#include "parsing.h"

static bool test_name(const char* name) {
  # if (SYSTYPE == SYS_LINUX) || (SYSTYPE == SYS_MAC)
    const char sep = '/';
  # endif
  # if SYSTYPE == SYS_WIN
    const char sep = '\\';
  # endif
  # if SYSTYPE == -1 // safety
    const char sep = '/';
  # endif
  const char* cut = strrchr(name, sep);
  if (!cut || !cut[0]) {
    return false;
  }
  const size_t nameLen = strlen(cut);
  if (nameLen < 1) {
    return false;
  }
  if (strcmp(cut + 1, PROG_NAME) != 0) {
    put_str_nl("error: program was rename!", STDERR_FILENO);
    return false;
  }
  return true;
}


static int base(t_mainData data, int fdIn, int fdOut) {
  int status = EX_OK;
  t_setting programSetting = {
    fdIn,       //*
    fdOut,      //
    data.ac,    //
    data.av,    //
    data.av[0], // program name
    true,       // stop on error
    false,      // color
    data.env    //*
  };
  //
  # ifdef NAME_CHECK
    if (!test_name(data.av[0]))
      return 1;
  # endif
  env_parsing(&programSetting);
  for (int i = 1; i < programSetting.ac; i++) {
    if (programSetting.stopOnError && status)
      break;
  }
  // programe here
  return status;
}


int main(int ac, const char* const* av, const char* const* env) {
  t_mainData data = {
    .ac = ac,
    .av = av,
    .env = env,
  };
  const int error = base(data, STDIN_FILENO, STDOUT_FILENO);
  return error;
}
