# include "language.h"

static t_language selectLenguage = language_english;


void set_run_time_language(t_language language) {
  # ifdef RUNTIME_LANGUAGE
    selectLenguage = DEFINE_LANGUAGE;
    (void)language;
  # else
    selectLenguage = language;
  # endif
}

int  get_run_time_language(void) {
  return selectLenguage;
}


const char* const rename_error_mess[] = {
  "error: program was renamed!",
  "erreur: le programme a été renommé!",
  0x0,
};


const char* const* const language_error_message[] = {
  rename_error_mess,
  0x0
};



/*
*
*
*/

const char* const languages[] = {
  "English",
  "Français",
  0x0
};


const char* const* const available_languages[] = {
  languages,
  0x0
};


///
const char* const* const* const language_string[] = {
  available_languages,
  language_error_message,
  0x0,
};


/*
* not safe
*/
const char* get_msg(t_msg_type type, int section) {
  return language_string[type][section][selectLenguage];
}