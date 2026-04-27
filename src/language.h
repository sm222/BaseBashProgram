#ifndef  LANGUAGE_H
# define LANGUAGE_H

typedef enum {
  language_english,
  language_french,
} t_language;

typedef enum {
  rename_prog,
} error_rename;

typedef enum {
  available_language,
  error_message,
} t_msg_type;


void set_run_time_language(t_language language);
int  get_run_time_language(void);
const char* get_msg(t_msg_type type, int section);





#endif