
#include "dataType.h"
#include "utilse.h"
#include "parsing.h"
#include "flags.h"


# ifdef NAME_CHECK
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
# endif


static int base(t_mainData data, int fdIn, int fdOut) {
  int status = EX_OK;
  t_setting programSetting = {
    .stdIn        = fdIn,        //*
    .stdOut       = fdOut,       //
    .ac           = data.ac,     //
    .current      = 1,           // skip programe name
    .av           = data.av,     //
    .programeName = data.av[0],  // program name
    .flags        = 0,           // flag
    .env          = data.env,    //
    .flagValue    = NULL         //*
  };
  //
  # ifdef NAME_CHECK
  if (!test_name(data.av[0]))
    return 1;
  # endif
  env_parsing(&programSetting);
  for (; programSetting.current < programSetting.ac; programSetting.current++) {
    if (strncmp(programSetting.av[programSetting.current], "--", 2) == 0) {
      status = parsing_get_double(&programSetting);
    }
    else if (programSetting.av[programSetting.current][0] == '-') {
      status = parsing_get_single(&programSetting);
    }
    if (read_byte(programSetting.flags, setting_continue_on_error) && status)
      return status;
    // programe here
    put_str_error(&programSetting, RED, "code %d\n", status);
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
