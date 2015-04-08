//
//  my_monthname.c
//
//
//  Created by Kevin Manase on 4/6/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sqlite3.h>



extern void my_monthname(sqlite3_context  *context,
                         int               argc,
                         sqlite3_value   **argv){
    
    char *str =  (char *)sqlite3_value_text(argv[1]);
  /*  char *str2 = strdup(str);
  */
    
    char *month_char;
    char *day_char;
    char *year_char;
    
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    
    
    if (str == NULL)
    {
        sqlite3_result_null(context);
    }
    
    if (3 != sscanf(str, "%c/%c/%c",
                    year_char, month_char, day_char)) {
        sqlite3_result_error(context, "monthname - invalid number of arguments", -1);
    } else {
        int month = atoi(month_char);
        int day = atoi(day_char);
        int year = atoi(year_char);
        // Check whether at least one parameter is null
        if ((sqlite3_value_type(argv[0]) == SQLITE_NULL)
            || (sqlite3_value_type(argv[1]) == SQLITE_NULL)) {
            sqlite3_result_null(context);
            return;
        }
        // Check whether the length is a positive value
        if (sqlite3_value_numeric_type(argv[1]) != SQLITE_INTEGER) {
            sqlite3_result_error(context, "monthname - invalid format. Please use YYYY-MM-DD", -1);
            return;
        }
        sqlite3_result_text(context, months[month], strlen(months[month]), SQLITE_STATIC);
    }
}
