#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING 
} row_type;


typedef union {
    int intValue;
    float floatValue;
    double doubleValue;
    char stringValue[50];
} row_union;


typedef struct {
    char name[50];
    row_type type;
    row_union value;
} final_row;
