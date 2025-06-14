
#ifndef  DATA_TYPE_H
# define DATA_TYPE_H

# include <error.h>
# include <sysexits.h>
# include <string.h>
# include <strings.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>


# ifndef COLORS
#  define COLORS
#  define CS  "\001"   //*start code
#  define CE  "\002\0" //*end   code
#  define RED    CS"\e[31m"CE
#  define GRN    CS"\e[32m"CE
#  define YEL    CS"\e[33m"CE
#  define BLU    CS"\e[34m"CE
#  define MAG    CS"\e[35m"CE
#  define CYN    CS"\e[36m"CE
#  define WHT    CS"\e[37m"CE
#  define ORG    CS"\e[38;5;202m"CE
#  define PIK    CS"\e[38;5;176m"CE
#  define RESET  CS"\e[0m\022"CE
#  define CLE    CS"\e[1;1H\x1b[2J"CE
#  define MAX_COLORLEN 20
# endif


typedef struct mainData {
  const int          ac;
  const char* const* av;
  const char* const* env;
  //
  //
} t_mainData;

typedef struct setting {
  int stdIn;
  int stdOut;
  const char* programeName;
  //
  int color;
  int stopOnError;
} t_setting;




#endif