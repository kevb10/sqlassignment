#ifndef ORAFN_H

#define ORAFN_H

#include <sqlite3.h>

extern void ora_tan(sqlite3_context  *context,
                    int               argc,
                    sqlite3_value   **argv);
extern void my_monthname(sqlite3_context  *context,
                    int               argc,
                    sqlite3_value   **argv);
#endif
