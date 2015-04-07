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
    char *month_char = strtok(str, "/.- ");
    char *day_char = strtok(NULL, "/.- ");
    char *year_char = strtok(NULL, "/.- ");
    
    char *themonth = NULL;
        
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    
    int month = atoi(month_char);
    int day = atoi(day_char);
    int year = atoi(year_char);
    
    if (argc != 1){
        sqlite3_result_error(context, "monthname - invalid number of arguments", -1);
    } else {
        // Check whether at least one parameter is null
        if ((sqlite3_value_type(argv[0]) == SQLITE_NULL)
            || (sqlite3_value_type(argv[1]) == SQLITE_NULL)) {
            sqlite3_result_null(context);
            return;
        }
        // Check whether the length is a positive value
        if ((sqlite3_value_numeric_type(argv[1]) != SQLITE_INTEGER)
            || ((len = sqlite3_value_int(argv[1])) <= 0)) {
            sqlite3_result_error(context, "monthname - invalid format. Please use mm/dd/yyyy", -1);
            return;
        }
        themonth = (char *)sqlite3_malloc(sizeof(char)*128);
        themonth = months[month];
        sqlite3_result_text(context, themonth, strlen(themonth)+256, free);
    }
}
