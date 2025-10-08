# include "dataType.h"
#include "flags.h"

size_t getArrayLen(const char* const* array) {
  size_t i = 0;
  if (!array)
    return 0;
  while (array[i]) { i++; }
  return i;
}

int  int_strlen(const char* s) {
  int i = 0;
  if (!s)
    return -1;
  while (s[i])
    i++;
  return i;
}

void put_str(const char* str, int fd, bool nl) {
  write(fd, str, strlen(str));
  if (nl)
    write(fd, "\n", 1);
}

void put_str_nl(const char* str, int fd) {
  put_str(str, fd, true);
}

void set_byte(int32_t* flag, int32_t val, bool status) {
  if (!flag)
    return ;
  status ? (*flag |= val) : (*flag ^= val);
}

void showbits(int32_t var) {
  int index = 32 + 4;
  char s[index + 1];
  s[index] = 0;
  for (int j = 0; j < 4; j++) {
    index--;
    s[index] = '|';
    for (int i = 0; i < 8; i++) {
      index--;
      s[index] = (var & 1) + '0';
      var >>= 1;
    }
  }
  printf("%s\n", s);
}

