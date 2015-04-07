#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <sqlite3ext.h>

#include "orafn.h"

SQLITE_EXTENSION_INIT1

extern int sqlite3_extension_init(sqlite3                     *db,
                                  char                       **pzErrMsg,
                                  const sqlite3_api_routines  *pApi) {
  SQLITE_EXTENSION_INIT2(pApi)
  (void)setlocale(LC_ALL, "en_US.UTF-8");
  sqlite3_create_function(db, "tan", 1, SQLITE_UTF8,
                            0, ora_tan, 0, 0);
  // -1 means variable number of arguments
  sqlite3_create_function(db, "monthname", 1, SQLITE_UTF8,
                            0, my_monthname, 0, 0);
  return 0;
}
