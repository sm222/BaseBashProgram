#ifndef  UTILSE_H
# define UTILSE_H

# include "dataType.h"

size_t getArrayLen(const char* const* array);
void   help(int i[2]);

//
void put_str(const char* str, int fd, bool nl);
void put_str_nl(const char* str, int fd);
//


#endif