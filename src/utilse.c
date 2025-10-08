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

bool read_byte(int32_t flag, int32_t value) {
  return flag & value;
}

void showbits(int32_t var) {
  int index = 32;
  char s[index + 1];
  s[index] = 0;
  for (int i = 1; index > 0; i <<= 1) {
    index--;
    s[index] = read_byte(var, i) + '0';
  }
  printf("%s\n", s);
}

/*
  00000000000000000000000000001001| good
  11111111111111111111111111100000|
  00000000000000000000000000000000|
*/