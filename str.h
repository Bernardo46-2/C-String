#ifndef _STR_H_
#define _STR_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * @brief My implementation of strings in C using linked lists (because I like linked lists)
 * @author Bernardo Marques Fernandes
 * @version 2.1.0
 */


// ========================================== Structs ========================================== //

typedef struct _StringCell_s _StringCell;
typedef struct _String_s String;
typedef struct _StringArray_s StringArray;

struct _StringCell_s{
    char __c;
    _StringCell* __next;
    _StringCell* __prev;
};

struct _String_s{
    size_t len;

    _StringCell* __first;
    _StringCell* __last;
    
    int (*is_empty)(const String* self);
    char (*first)(const String* self);
    char (*last)(const String* self);
    void (*push)(String* self, const char c);
    void (*push_chars)(String* self, const char* chars);
    void (*push_str)(String* self, const String* str);
    char (*get)(const String* self, size_t index);
    void (*set)(String* self, const size_t index, const char c);
    void (*print)(const String* self);
    void (*println)(const String* self);
    char* (*to_chars)(const String* self);
    int (*find)(const String* self, const char c);
    int (*contains)(const String* self, const char c);
    String (*substring)(const String* self, size_t start, size_t end);
    void (*trim)(String* self);
    void (*trim_left)(String* self);
    void (*trim_right)(String* self);
    int (*compare_to_str)(const String* self, const String* str);
    int (*compare_to_chars)(const String* self, const char* chars);
    int (*equals_str)(const String* self, const String* str);
    int (*equals_chars)(const String* self, const char* chars);
    StringArray (*split)(const String* self, const char c);
    void (*replace)(String* self, const char old, const char replacement);
    void (*replace_all)(String* self, const char old, const char replacement);
    int (*remove_str)(String* self, const String* str);
    int (*remove_chars)(String* self, const char* chars);
    char (*remove)(String* self, const size_t index);
    int (*remove_char)(String* self, const char c);
    int (*remove_all)(String* self, const char c);
    String (*drain)(String* self, const size_t start, const size_t end);
    void (*drain_and_free)(String* self, const size_t start, const size_t end);
    void (*reap)(String* self, const size_t start, const size_t end);
    void (*insert)(String* self, const size_t index, const char c);
    void (*insert_str)(String* self, const size_t index, const String* str);
    void (*insert_chars)(String* self, const size_t index, const char* chars);
    int (*find_str)(const String* self, const String* str);
    int (*find_chars)(const String* self, const char* chars);
    int (*contains_str)(const String* self, const String* str);
    int (*contains_chars)(const String* self, const char* chars);
    int (*starts_with_str)(const String* self, const String* str);
    int (*starts_with_chars)(const String*self, const char* chars);
    int (*ends_with_str)(const String* self, const String* str);
    int (*ends_with_chars)(const String* self, const char* chars);
    int* (*to_bytes)(const String* self);
    int (*parse_int)(const String* self);
    float (*parse_float)(const String* self);
    double (*parse_double)(const String* self);
    int (*parse_bool)(const String* self);
    void (*to_lowercase)(String* self);
    void (*to_uppercase)(String* self);
    void (*title)(String* self);
    void (*capitalize)(String* self);
    void (*clear)(String* self);
    String (*clone)(const String* self);
    void (*free)(String* self);
};

struct _StringArray_s{
    String* strs;
    size_t len;
    void (*free)(StringArray* self);
};


// ========================================== Prototypes ========================================== //

static _StringCell* strcell_new(const char);
static void strcell_free(_StringCell*);

String string_new();
String string_from(const char*);
String string_read(const char*, const size_t);
String string_read_line(const char*, const size_t);
String string_from_int(int);
String string_from_size_t(size_t);
String string_from_float(const float);
String string_from_double_with_precision(const double d, const int precision);
String string_from_double(const double);
String string_from_bool(const unsigned int);
String string_format(const char*, ...);

int str_is_empty(const String*);
char str_first(const String*);
char str_last(const String*);
void str_push(String*, const char);
void str_push_chars(String*, const char*);
void str_push_str(String*, const String*);
char str_get(const String*, const size_t);
void str_set(String*, const size_t, const char);
void str_print(const String*);
void str_println(const String*);
char* str_to_chars(const String*);
int str_find(const String*, const char);
int str_contains(const String*, const char);
String str_substring(const String*, size_t, size_t);
void str_trim(String*);
void str_trim_left(String*);
void str_trim_right(String*);
int str_compare_to_str(const String*, const String*);
int str_compare_to_chars(const String*, const char*);
int str_equals_str(const String*, const String*);
int str_equals_chars(const String*, const char*);
StringArray str_split(const String*, const char);
void str_replace(String*, const char, const char);
void str_replace_all(String*, const char, const char);
char str_remove(String*, const size_t);
int str_remove_char(String*, const char);
int str_remove_all(String*, const char);
String str_drain(String*, const size_t, const size_t);
void str_drain_and_free(String*, const size_t, const size_t);
void str_reap(String*, const size_t, const size_t);
int str_remove_str(String*, const String*);
int str_remove_chars(String*, const char*);
void str_insert(String*, const size_t, const char);
void str_insert_str(String*, const size_t, const String*);
void str_insert_chars(String*, const size_t, const char*);
int str_find_str(const String*, const String*);
int str_find_chars(const String*, const char*);
int str_starts_with_str(const String*, const String*);
int str_starts_with_chars(const String*, const char*);
int str_ends_with_str(const String*, const String*);
int str_ends_with_chars(const String*, const char*);
int str_contains_str(const String*, const String*);
int str_contains_chars(const String*, const char*);
int* str_to_bytes(const String*);
int str_parse_int(const String*);
float str_parse_float(const String*);
double str_parse_double(const String*);
int str_parse_bool(const String*);
void str_to_lowercase(String*);
void str_to_uppercase(String*);
void str_title(String*);
void str_capitalize(String*);
void str_clear(String*);
String str_clone(const String*);
void str_free(String*);

StringArray strarray_new();
void strarray_free(StringArray*);

static inline size_t str_strlen(const char*);
static void str_memory_test(const char*, const void*);
static void str_first_cell_test(const char*, const char*, const void*);
static void str_null_reference_test(const char*, const char*, const void*);
static void str_empty_test(const char*, const char*, const int);
static void str_index_out_of_bounds_test(const char*, const size_t, const size_t, const int);
static void str_invalid_index_test(const char*, const char*, const char*, const size_t, const size_t);
static void str_nan_test(const char*, const size_t, const char);
static void str_format_error(const char*, const char*, const char);


// ========================================== StringCell ========================================== //

/**
 * @brief Allocates a new StringCell for the linkedlist
 * 
 * @warning not intended for public use
 * 
 * @param c char that the cell will hold
 * @return allocated cell
 */
static _StringCell* strcell_new(const char c){
    _StringCell* self = (_StringCell*)malloc(sizeof(_StringCell));
    str_memory_test("_StringCell* strcell_new(const char c)", self);
    
    self->__c = c;
    self->__next = NULL;
    self->__prev = NULL;

    return self;
}

/**
 * @brief Frees a StringCell
 * 
 * @warning not intended for public use
 * 
 * @param self StringCell to be freed
 */
static void strcell_free(_StringCell* self){
    if(self != NULL){
        self->__next = NULL;
        self->__prev = NULL;
        free(self);
    }
}


// ========================================== String ========================================== //

/**
 * @brief Creates a new empty String
 * 
 * @return new String 
 */
String string_new(){
    String self;

    self.__first = strcell_new(' ');
    self.__last = self.__first;
    self.__last->__next = NULL;
    self.len = 0;

    self.is_empty = str_is_empty;
    self.first = str_first;
    self.last = str_last;
    self.push = str_push;
    self.push_chars = str_push_chars;
    self.push_str = str_push_str;
    self.get = str_get;
    self.set = str_set;
    self.print = str_print;
    self.println = str_println;
    self.to_chars = str_to_chars;
    self.find = str_find;
    self.contains = str_contains;
    self.substring = str_substring;
    self.trim = str_trim;
    self.trim_left = str_trim_left;
    self.trim_right = str_trim_right;
    self.compare_to_str = str_compare_to_str;
    self.compare_to_chars = str_compare_to_chars;
    self.equals_str = str_equals_str;
    self.equals_chars = str_equals_chars;
    self.split = str_split;
    self.replace = str_replace;
    self.replace_all = str_replace_all;
    self.remove = str_remove;
    self.remove_char = str_remove_char;
    self.remove_all = str_remove_all;
    self.remove_str = str_remove_str;
    self.remove_chars = str_remove_chars;
    self.drain = str_drain;
    self.drain_and_free = str_drain_and_free;
    self.reap = str_reap;
    self.insert = str_insert;
    self.insert_str = str_insert_str;
    self.insert_chars = str_insert_chars;
    self.find_str = str_find_str;
    self.find_chars = str_find_chars;
    self.starts_with_str = str_starts_with_str;
    self.starts_with_chars = str_starts_with_chars;
    self.ends_with_str = str_ends_with_str;
    self.ends_with_chars = str_ends_with_chars;
    self.contains_str = str_contains_str;
    self.contains_chars = str_contains_chars;
    self.to_bytes = str_to_bytes;
    self.parse_int = str_parse_int;
    self.parse_float = str_parse_float;
    self.parse_double = str_parse_double;
    self.parse_bool = str_parse_bool;
    self.to_lowercase = str_to_lowercase;
    self.to_uppercase = str_to_uppercase;
    self.title = str_title;
    self.capitalize = str_capitalize;
    self.clear = str_clear;
    self.clone = str_clone;
    self.free = str_free;

    return self;
}

/**
 * @brief Creates a new String from a given char array
 * 
 * @param chars char array to be copied into the new String
 * @return new String
 */
String string_from(const char* chars){
    String self = string_new();
    self.push_chars(&self, chars);
    return self;
}

/**
 * @brief Reads a new String from stdin
 * 
 * @param message what to print before reading String
 * @param len max length of the read String (it can be muted later by other methods)
 * @return new String
 */
String string_read(const char* message, const size_t len){
    char* str = (char*)malloc((len + 1) * sizeof(char));
    char fn_name[] = "String string_read(const char* message, const size_t len)";
    str_memory_test(fn_name, str);

    String self;

    printf("%s", message);
    scanf("%s", str);
    while(getchar() != '\n');

    self = string_from(str);

    if(str) free(str);
    return self;
}

/**
 * @brief Reads a new String from stdin, including spaces
 * 
 * @param message what to print before reading String
 * @param len max length of the read String (it can be muted later by other methods)
 * @return new String
 */
String string_read_line(const char* message, const size_t len){
    char* str = (char*)malloc((len + 1) * sizeof(char));
    char fn_name[] = "String string_read_line(const char* message, const size_t len)";
    str_memory_test(fn_name, str);

    String self;

    printf("%s", message);
    fgets(str, len + 1, stdin);

    self = string_from(str);

    if(self.__last->__c == '\n')
        self.remove(&self, self.len - 1);

    if(str) free(str);
    return self;
}

/**
 * @brief Creates a string from a given integer
 * 
 * @param n int to be used
 * @return String containing the given int
 */
String string_from_int(int n){
    String self = string_new();
    short negative = n < 0;

    if(negative){
        n = -n;
        self.push(&self, '-');
    }
    
    do{
        self.insert(&self, negative, n % 10 + 48);
        n /= 10;
    }while(n);

    return self;
}

/**
 * @brief Creates a string from a given size_t
 * 
 * @param n size_t to be used
 * @return String containing the given size_t
*/
String string_from_size_t(size_t n){
    String self = string_new();

    do{
        self.insert(&self, 0, n % 10 + 48);
        n /= 10;
    }while(n);

    return self;
}

/**
 * @brief Creates a string from a given float (with precision 3)
 * 
 * @param f float to be used
 * @return String containing the given float
 */
String string_from_float(const float f){
    return string_from_double((double)f);
}

/**
 * @brief Creates a string from a given double with
 * a given precision
 * 
 * @param d double to be used
 * @return String containing the given double
 */
String string_from_double_with_precision(const double d, const int precision){
    String self = string_new();
    short negative = d < 0;
    int n = (int)d;
    double f = d - n;

    if(negative){
        n = -n;
        self.push(&self, '-');
    }

    do{
        self.insert(&self, negative, n % 10 + 48);
        n /= 10;
    }while(n);

    self.push(&self, '.');

    for(int i = 0; i < precision; i++){
        f = (f - n) * 10;
        n = (int)f;
        self.push(&self, n + 48);
    }

    return self;
}

/**
 * @brief Creates a string from a given double (with precision 3)
 * 
 * @param d double to be used
 * @return String containing the given double
 */
String string_from_double(const double d){
    return string_from_double_with_precision(d, 3);
}

/**
 * @brief Creates a new string from a given boolean
 * 
 * @param b boolean to be used
 * @return String containing either "false" or "true"
 */
String string_from_bool(const unsigned int b){
    if(b == 0){
        return string_from("false");
    }else{
        return string_from("true");
    }
}

/**
 * @brief Creates a new String from a given format
 * 
 * @note Currently has support for: 
 * @note -- %% - %
 * @note -- %d - int
 * @note -- %ld - size_t
 * @note -- %f - float | double
 * @note -- %c - char
 * @note -- %s - char*
 * @note -- %S - String*
 * 
 * @param chars char array containing format
 * @param ... arguments to be inserted in string
 * @return new formatted String
 */
String string_format(const char* fmt, ...){
    char fn_name[] = "String string_format(const char* fmt, ...)";
    str_null_reference_test(fn_name, "fmt", fmt);
    
    String self = string_new();
    String tmp;
    va_list args;
    va_start(args, fmt);
    const char* ptr = fmt;

    while(*ptr){
        if(*ptr != '%'){
            self.push(&self, *ptr);
        }else{
            switch(*++ptr){
                case '%':
                    self.push(&self, '%');
                    break;
                
                case 'd':
                    tmp = string_from_int(va_arg(args, int));
                    self.push_str(&self, &tmp);
                    tmp.free(&tmp);
                    break;

                case 'f':
                    tmp = string_from_double(va_arg(args, double));
                    self.push_str(&self, &tmp);
                    tmp.free(&tmp);
                    break;
                
                case 'c':
                    self.push(&self, va_arg(args, int));
                    break;
                
                case 's':
                    self.push_chars(&self, va_arg(args, char*));
                    break;

                case 'S':
                    self.push_str(&self, va_arg(args, String*));
                    break;

                case 'l':
                    if(*++ptr == 'd'){
                        tmp = string_from_size_t(va_arg(args, size_t));
                        self.push_str(&self, &tmp);
                        tmp.free(&tmp);
                    }else{
                        str_format_error(fn_name, "l", *ptr);
                    }
                    break;

                default:
                    str_format_error(fn_name, "", *ptr);
            }
        }
        
        ptr++;
    }

    va_end(args);

    return self;
}

/**
 * @brief Returns whether a String is empty
 * 
 * @param self String to test
 * @return true if String is empty, false otherwise
 */
int str_is_empty(const String* self){
    char fn_name[] = "int is_empty(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    
    return self->__first == self->__last;
}

/**
 * @brief Returns the first char of a string (if not empty)
 * 
 * @param self String to get char
 * @return first char of the string
 */
char str_first(const String* self){
    char fn_name[] = "char first(const String *self)";
    str_null_reference_test(fn_name, "self", self);
    str_empty_test(fn_name, "self", self->is_empty(self));
    str_first_cell_test(fn_name, "self", self->__first);
    return self->__first->__next->__c;
}

/**
 * @brief Returns the last char of a string (if not empty)
 * 
 * @param self String to get char
 * @return last char of the string
 */
char str_last(const String* self){
    char fn_name[] = "char last(const String *self)";
    str_null_reference_test(fn_name, "self", self);
    str_empty_test(fn_name, "self", self->is_empty(self));
    return self->__last->__c;
}

/**
 * @brief Inserts a char at the end of the String
 * 
 * @param self String to be edited
 * @param c char to insert
 */
void str_push(String* self, const char c){
    char fn_name[] = "void push(String* self, const char c)";
    str_null_reference_test(fn_name, "self", self);
    
    self->__last->__next = strcell_new(c);
    self->__last->__next->__prev = self->__last;
    self->__last = self->__last->__next;
    self->len++;
}

/**
 * @brief Inserts a given substring at the end of String
 * 
 * @param self String to be edited
 * @param chars char array to be inserted
 */
void str_push_chars(String* self, const char* chars){
    char fn_name[] = "void push_chars(String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    
    size_t len = str_strlen(chars);
    _StringCell* ptr = self->__last;

    for(size_t i = 0; i < len; i++){
        ptr->__next = strcell_new(chars[i]);
        ptr->__next->__prev = ptr;
        ptr = ptr->__next;
    }

    self->len += len;
    self->__last = ptr;
    ptr = NULL;
}

/**
 * @brief Inserts a given substring at the end of String
 * 
 * @param self String to be edited
 * @param str substring to be inserted
 */
void str_push_str(String* self, const String* str){
    char fn_name[] = "void push_str(String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "str", str->__first);

    _StringCell* ptr1 = self->__last;
    _StringCell* ptr2 = str->__first->__next;

    while(ptr2 != NULL){
        ptr1->__next = strcell_new(ptr2->__c);
        ptr1->__next->__prev = ptr1;
        ptr1 = ptr1->__next;
        ptr2 = ptr2->__next;
    }

    self->len += str->len;
    self->__last = ptr1;
    ptr1 = NULL;
    ptr2 = NULL;
}

/**
 * @brief Returns char from a given index on the string
 * 
 * @param self String to get char
 * @param index where to get char
 * @return char from given index
 */
char str_get(const String* self, const size_t index){
    char fn_name[] = "char get(const String* self, const size_t index)";
    str_null_reference_test(fn_name, "self", self);
    str_empty_test(fn_name, "self", self->is_empty(self));
    str_index_out_of_bounds_test(fn_name, index, self->len, index >= self->len);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;
    char c = ' ';
    
    for(size_t i = 0; i < index; i++)
        ptr = ptr->__next;

    c = ptr->__c;
    ptr = NULL;

    return c;
}

/**
 * @brief Sets a character from a given index on the string to another character
 * 
 * @param self String to be edited
 * @param index index to change char
 * @param c char to be placed at index
 */
void str_set(String* self, const size_t index, const char c){
    char fn_name[] = "void set(String* self, const size_t index, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));
    str_index_out_of_bounds_test(fn_name, index, self->len, index >= self->len);

    _StringCell* ptr = self->__first->__next;

    for(size_t i = 0; i < index; i++) ptr = ptr->__next;

    ptr->__c = c;
    ptr = NULL;
}

/**
 * @brief Prints the string
 * 
 * @param self String to be printed
 */
void str_print(const String* self){
    if(self == NULL){
        printf("null");
    }else{
        char fn_name[] = "void print(const String* self)";
        str_first_cell_test(fn_name, "self", self->__first);

        _StringCell* ptr = self->__first->__next;

        while(ptr != NULL){
            printf("%c", ptr->__c);
            ptr = ptr->__next;
        }

        ptr = NULL;
    }
}

/**
 * @brief Prints the string with a line break `\\n` at the end
 * 
 * @param self String to be printed
 */
void str_println(const String* self){
    str_print(self);
    printf("\n");
}

/**
 * @brief Creates a char array from a String
 * 
 * @attention the char array is allocated in memory, so it needs to be eventually freed
 * 
 * @param self String to get the char array
 * @return char array with every char in the string
 */
char* str_to_chars(const String* self){
    char fn_name[] = "char* to_chars(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    char* str = (char*)malloc((self->len + 1) * sizeof(char));
    str_memory_test(fn_name, str);
    
    _StringCell* ptr = self->__first->__next;
    size_t i = 0;
    
    while(ptr != NULL){
        str[i++] = ptr->__c;
        ptr = ptr->__next;
    }

    str[i] = '\0';

    return str;
}

/**
 * @brief Searches the string for a given char
 * 
 * @param self String to be searched
 * @param c char searched
 * @return index of char if found, -1 otherwise
 */
int str_find(const String* self, const char c){
    char fn_name[] = "int find(const String* self, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    size_t index = 0;
    _StringCell* ptr = self->__first->__next;

    while(ptr != NULL && ptr->__c != c){
        ptr = ptr->__next;
        index++;
    }

    if(ptr == NULL) index = -1;
    ptr = NULL;

    return index;
}

/**
 * @brief Searches the string to find whether a given char is
 * present in the string
 * 
 * @param self String to be searched
 * @param c char searched
 * @return true if char is present, false otherwise
 */
int str_contains(const String* self, const char c){
    return str_find(self, c) != -1;
}

/**
 * @brief Takes a substring between two given index from String,
 * leaving original string intact
 * 
 * @see `String drain(String*, size_t, size_t)` for actually 
 * removing substring from string 
 * 
 * @param self String to take substring
 * @param start start index of substring (inclusive)
 * @param end end index of substring (exclusive)
 * @return substring between start and end indexes
 */
String str_substring(const String* self, size_t start, size_t end){
    char fn_name[] = "String substring(const String* self, size_t start, size_t end)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));
    str_invalid_index_test(fn_name, "start", "end", start, end);
    str_index_out_of_bounds_test(fn_name, end, self->len, start > self->len);

    String str = string_new();
    _StringCell* ptr1 = self->__first->__next;
    _StringCell* ptr2 = str.__first;

    for(size_t i = 0; i < start; i++)
        ptr1 = ptr1->__next;

    for(size_t i = start; i < end; i++){
        ptr2->__next = strcell_new(ptr1->__c);
        ptr2->__next->__prev = ptr2;

        ptr1 = ptr1->__next;
        ptr2 = ptr2->__next;
    }

    str.len = end - start;
    str.__last = ptr2;
    ptr1 = NULL;
    ptr2 = NULL;

    return str;
}

/**
 * @brief Removes spaces, `\\n`, `\\r` and `\\t` present at the start and end of the string
 * 
 * @param self String to be edited
 */
void str_trim(String* self){
    char fn_name[] = "void trim(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    
    if(!self->is_empty(self)){
        _StringCell* ptr = self->__last;

        while(ptr != self->__first && (ptr->__c == ' ' || ptr->__c == '\n' || ptr->__c == '\r' || ptr->__c == '\t')){
            ptr = ptr->__prev;
            strcell_free(ptr->__next);
            self->len--;
        }

        ptr->__next = NULL;
        self->__last = ptr;
        ptr = self->__first->__next;

        while(ptr != NULL && (ptr->__c == ' ' || ptr->__c == '\n' || ptr->__c == '\r' || ptr->__c == '\t')){
            ptr = ptr->__next;
            strcell_free(ptr->__prev);
            self->len--;
        }

        if(ptr != NULL) ptr->__prev = self->__first;
        self->__first->__next = ptr;

        ptr = NULL;
    }
}

/**
 * @brief Removes spaces, `\\n`, `\\r` and `\\t` present at the start of the string
 * 
 * @param self String to be edited
 */
void str_trim_left(String* self){
    char fn_name[] = "void trim_left(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    
    if(!self->is_empty(self)){
        _StringCell* ptr = self->__first->__next;

        while(ptr != NULL && (ptr->__c == ' ' || ptr->__c == '\n' || ptr->__c == '\r' || ptr->__c == '\t')){
            ptr = ptr->__next;
            strcell_free(ptr->__prev);
            self->len--;
        }

        if(ptr != NULL) ptr->__prev = self->__first;
        self->__first->__next = ptr;

        ptr = NULL;
    }
}

/**
 * @brief Removes spaces, `\\n`, `\\r` and `\\t` present at the end of the string
 * 
 * @param self String to be edited
 */
void str_trim_right(String* self){
    char fn_name[] = "void trim_right(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    
    if(!self->is_empty(self)){
        _StringCell* ptr = self->__last;

        while(ptr != self->__first && (ptr->__c == ' ' || ptr->__c == '\n' || ptr->__c == '\r' || ptr->__c == '\t')){
            ptr = ptr->__prev;
            strcell_free(ptr->__next);
            self->len--;
        }

        ptr->__next = NULL;
        self->__last = ptr;
    }
}

/**
 * @brief Compares two strings
 * 
 * @param self String to compare
 * @param str String to compare
 * @return less than 0 if self < chars, 0 if self == chars, more than 0 if self > chars
 */
int str_compare_to_str(const String* self, const String* str){
    char fn_name[] = "int compare_to_str(const String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "self", self->__first);
    str_first_cell_test(fn_name, "str", str->__first);

    _StringCell* ptr1 = self->__first->__next;
    _StringCell* ptr2 = str->__first->__next;
    int diff = 0;
    
    while(ptr1 != NULL && ptr2 != NULL && diff == 0){
        diff = ptr1->__c - ptr2->__c;
        ptr1 = ptr1->__next;
        ptr2 = ptr2->__next;
    }

    if(ptr1 != NULL && ptr2 == NULL) diff = ptr1->__c;
    else if(ptr1 == NULL && ptr2 != NULL) diff = ptr2->__c;

    return diff;
}

/**
 * @brief Compares two strings
 * 
 * @param self String to compare
 * @param chars char array to compare
 * @return less than 0 if self < chars, 0 if self == chars, more than 0 if self > chars
 */
int str_compare_to_chars(const String* self, const char* chars){
    char fn_name[] = "int compare_to_chars(const String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;
    size_t i = 0;
    size_t len = str_strlen(chars);
    int diff = 0;
    
    while(ptr != NULL && i < len && diff == 0){
        diff = ptr->__c - chars[i];
        ptr = ptr->__next;
        i++;
    }

    if(ptr != NULL && i == len) diff = ptr->__c;
    else if(ptr == NULL && i < len) diff = -chars[i];

    return diff;
}

/**
 * @brief Tests whether a string is equal to another
 * 
 * @param self String to test
 * @param str String to test
 * @return true if it is equal, false otherwise
 */
int str_equals_str(const String* self, const String* str){
    return str_compare_to_str(self, str) == 0;
}

/**
 * @brief Tests whether a string is equal to another
 * 
 * @param self String to test
 * @param chars char array to test
 * @return true if it is equal, false otherwise
 */
int str_equals_chars(const String* self, const char* chars){
    return str_compare_to_chars(self, chars) == 0;
}

/**
 * @brief Splits the string by an specific char, creating an 
 * array of Strings
 * 
 * @param self string to split
 * @param c char to delimit one string from another
 * @return struct `StringArray` containing all the substrings found
 * and how many were found  
 */
StringArray str_split(const String* self, const char c){
    char fn_name[] = "StringArray split(const String* self, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));
    
    _StringCell* ptr = self->__first->__next;
    _StringCell* start = NULL;
    size_t index = 0;
    StringArray sa = strarray_new();

    while(ptr != NULL && ptr->__c == c)
        ptr = ptr->__next;

    start = ptr;

    while(ptr != NULL){
        if(ptr->__c == c){
            do
                ptr = ptr->__next;
            while(ptr != NULL && ptr->__c == c);

            if(ptr != NULL){
                sa.len++;
                ptr = ptr->__next;
            }
        }else{
            ptr = ptr->__next;
        }
    }

    if(start != NULL) sa.len++;

    if(sa.len > 0){
        sa.strs = (String*)malloc(sa.len * sizeof(String));
        str_memory_test(fn_name, sa.strs);

        sa.strs[0] = string_new();
        ptr = start;

        while(ptr != NULL){
            if(ptr->__c == c){
                do
                    ptr = ptr->__next;
                while(ptr != NULL && ptr->__c == c);

                if(ptr != NULL){
                    sa.strs[++index] = string_new();
                    sa.strs[index].push(&sa.strs[index], ptr->__c);
                    ptr = ptr->__next;
                }
            }else{
                sa.strs[index].push(&sa.strs[index], ptr->__c);
                ptr = ptr->__next;
            }
        }
    }

    ptr = NULL;
    start = NULL;

    return sa;
}

/**
 * @brief Replaces the first occurrence of a given char by another
 * 
 * @param self String to be edited
 * @param old char to be replaced
 * @param replacement char to replace old one
 */
void str_replace(String* self, const char old, const char replacement){
    char fn_name[] = "void replace(String* self, const char old, const char replacement)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;

    while(ptr != NULL && ptr->__c != old) ptr = ptr->__next;
    if(ptr != NULL && ptr->__c == old) ptr->__c = replacement;

    ptr = NULL;
}

/**
 * @brief Replaces every occurrence of a given char by another
 * 
 * @param self String to be edited
 * @param old char to be replaced
 * @param replacement char to replace old one
 */
void str_replace_all(String* self, const char old, const char replacement){
    char fn_name[] = "void replace_all(String* self, const char old, const char replacement)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;

    while(ptr != NULL){
        if(ptr->__c == old) ptr->__c = replacement;
        ptr = ptr->__next;
    }
}

/**
 * @brief Removes a char from a given index from the string
 * 
 * @param self String to be edited
 * @param index index where to remove char
 * @return removed char
 */
char str_remove(String* self, const size_t index){
    char fn_name[] = "char remove(String* self, const size_t index)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_index_out_of_bounds_test(fn_name, index, self->len, index >= self->len);

    char c = ' ';

    if(index == self->len - 1){
        c = self->__last->__c;
        self->__last = self->__last->__prev;
        strcell_free(self->__last->__next);
        self->__last->__next = NULL;
    }else{
        _StringCell* ptr = self->__first->__next;

        for(size_t i = 0; i < index; i++)
            ptr = ptr->__next;

        c = ptr->__c;
        ptr->__prev->__next = ptr->__next;
        ptr->__next->__prev = ptr->__prev;
        strcell_free(ptr);
        ptr = NULL;
    }

    self->len--;

    return c;
}

/**
 * @brief Removes first occurrence of a given char in string
 * 
 * @param self String to be eddited
 * @param c char to be removed
 * @return true if char was found and removed, false otherwise
 */
int str_remove_char(String* self, const char c){
    char fn_name[] = "int remove_char(String* self, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;
    int removed = 0;

    while(ptr != NULL && ptr->__c != c) ptr = ptr->__next;

    if(ptr != NULL){
        if(ptr == self->__last){
            ptr = ptr->__prev;
            self->__last = ptr;
            strcell_free(ptr->__next);

            ptr->__next = NULL;
        }else{
            ptr->__prev->__next = ptr->__next;

            if(ptr != self->__last)
                ptr->__next->__prev = ptr->__prev;
            
            strcell_free(ptr);
        }

        self->len--;
        removed = 1;
        ptr = NULL;
    }

    return removed;
}

/**
 * @brief Removes all occurrences of a given char found in the string
 * 
 * @param self String to be edited
 * @param c char to be removed
 * @return how many chars were removed
 */
int str_remove_all(String* self, const char c){
    char fn_name[] = "int remove_all(String* self, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr1 = self->__first->__next;
    _StringCell* ptr2 = NULL;
    int removed = 0;

    while(ptr1 != NULL){
        if(ptr1->__c == c){
            ptr2 = ptr1;
            ptr1 = ptr1->__next;

            if(ptr2 == self->__last){
                ptr2 = ptr2->__prev;
                self->__last = ptr2;
                strcell_free(ptr2->__next);

                ptr2->__next = NULL;
                ptr2 = NULL;
            }else{
                ptr2->__prev->__next = ptr2->__next;

                if(ptr2 != self->__last)
                    ptr2->__next->__prev = ptr2->__prev;
                
                strcell_free(ptr2);
            }

            removed++;
        }else{
            ptr1 = ptr1->__next;
        }
    }

    self->len -= removed;
    ptr2 = NULL;

    return removed;
}

/**
 * @brief Searches the string for a given substring. If the
 * substring is present, removes it from the string
 * 
 * @param self String to be edited
 * @param str substring to be searched and removed 
 * @return true if substring was found and removed from string, false otherwise
 */
int str_remove_str(String* self, const String* str){
    char fn_name[] = "int remove_str(String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "self", self->__first);
    str_first_cell_test(fn_name, "str", str->__first);

    int removed = 0;
    
    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->__first->__next;
        _StringCell* ptr2 = self->__first->__next;
        _StringCell* ptr3 = str->__first->__next;

        while(ptr1 != NULL && ptr2 != NULL && !removed){
            if(ptr1->__c == ptr3->__c){
                ptr2 = ptr1->__next;
                ptr3 = ptr3->__next;

                while(ptr2 != NULL && ptr3 != NULL){
                    if(ptr2->__c == ptr3->__c){
                        ptr2 = ptr2->__next;
                        ptr3 = ptr3->__next;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr2 == NULL && ptr3 == NULL){
                    ptr1 = ptr1->__prev;
                    ptr2 = self->__last;
                    self->__last = ptr1;
                    
                    while(ptr2 != ptr1){
                        ptr2 = ptr2->__prev;
                        strcell_free(ptr2->__next);
                    }

                    self->__last->__next = NULL;
                    removed = 1;
                }else if(ptr3 == NULL){
                    ptr1 = ptr1->__prev;
                    ptr3 = ptr1->__next;
                    
                    while(ptr3 != ptr2){
                        ptr3 = ptr3->__next;
                        strcell_free(ptr3->__prev);
                    }

                    ptr1->__next = ptr2;
                    ptr2->__prev = ptr1;
                    removed = 1;
                }else{
                    ptr3 = str->__first->__next;
                    ptr2 = ptr1;
                    ptr1 = ptr1->__next;
                }
            }else{
                ptr1 = ptr1->__next;
            }
        }

        ptr1 = NULL;
        ptr2 = NULL;
        ptr3 = NULL;

        if(removed) self->len -= str->len;
    }

    return removed;
}

/**
 * @brief Searches the string for a given substring. If the
 * substring is present, removes it from the string
 * 
 * @param self String to be edited
 * @param chars char array to be searched and removed 
 * @return true if substring was found and removed from string, false otherwise
 */
int str_remove_chars(String* self, const char* chars){
    char fn_name[] = "int remove_chars(String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    str_first_cell_test(fn_name, "self", self->__first);

    int removed = 0;
    size_t len = str_strlen(chars);
    
    if(!self->is_empty(self) && len > 0 && self->len >= len){
        _StringCell* ptr1 = self->__first->__next;
        _StringCell* ptr2 = self->__first->__next;
        _StringCell* ptr3 = NULL;
        size_t index = 0;

        while(ptr1 != NULL && ptr2 != NULL && !removed){
            if(ptr1->__c == chars[index]){
                ptr2 = ptr1->__next;
                index++;

                while(ptr2 != NULL && index < len){
                    if(ptr2->__c == chars[index]){
                        ptr2 = ptr2->__next;
                        index++;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr2 == NULL && index == len){
                    ptr1 = ptr1->__prev;
                    ptr2 = self->__last;
                    self->__last = ptr1;
                    
                    while(ptr2 != ptr1){
                        ptr2 = ptr2->__prev;
                        strcell_free(ptr2->__next);
                    }

                    self->__last->__next = NULL;
                    removed = 1;
                }else if(index == len){
                    ptr1 = ptr1->__prev;
                    ptr3 = ptr1->__next;
                    
                    while(ptr3 != ptr2){
                        ptr3 = ptr3->__next;
                        strcell_free(ptr3->__prev);
                    }

                    ptr1->__next = ptr2;
                    ptr2->__prev = ptr1;
                    removed = 1;
                }else{
                    index = 0;;
                    ptr2 = ptr1;
                    ptr1 = ptr1->__next;
                }
            }else{
                ptr1 = ptr1->__next;
            }
        }

        ptr1 = NULL;
        ptr2 = NULL;
        ptr3 = NULL;

        if(removed) self->len -= len;
    }

    return removed;
}

/**
 * @brief Similar method to `substring` but instead of
 * returning a copy, it actually removes it from the string
 * 
 * @param self string to remove slice from
 * @param start where to start removing slice
 * @param end where to stop removing slice
 * @return slice between `start` and `end`
 */
String str_drain(String* self, const size_t start, const size_t end){
    char fn_name[] = "String drain(String* self, const size_t start, const size_t end)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_index_out_of_bounds_test(fn_name, start, self->len, start > self->len);
    str_invalid_index_test(fn_name, "start", "end", start, end);

    String str = string_new();
    _StringCell* ptr1 = self->__first->__next;
    _StringCell* ptr2 = NULL;

    for(size_t i = 0; i < start; i++)
        ptr1 = ptr1->__next;

    ptr2 = ptr1;

    for(size_t i = start; i < end - 1; i++)
        ptr2 = ptr2->__next;
    
    str.__first->__next = ptr1;
    str.__last = ptr2;
    
    ptr1 = ptr1->__prev;
    if(ptr2 != NULL) ptr2 = ptr2->__next;

    if(ptr2 == NULL){
        self->__last = ptr1;
        ptr1->__next = NULL;
    }else{
        ptr1->__next = ptr2;
        ptr2->__prev = ptr1;
    }

    str.__last->__next = NULL;
    str.__first->__next->__prev = str.__first;

    str.len = end - start;
    self->len -= str.len;
    ptr1 = NULL;
    ptr2 = NULL;

    return str;
}

/**
 * @brief Same as `drain`, but frees the substring instead
 * of returning it
 * 
 * @param self string to remove slice from
 * @param start where to start removing slice
 * @param end where to stop removing slice
 */
void str_drain_and_free(String* self, const size_t start, const size_t end){
    String str = str_drain(self, start, end);
    str_free(&str);
}

/**
 * @brief Removes the start and end of string, delimited 
 * by the given indexes
 * 
 * @param self String to be edited
 * @param start first index of the resulting string
 * @param end last index of the resulting string
 */
void str_reap(String* self, const size_t start, const size_t end){
    char fn_name[] = "void reap(String* self, const size_t start, const size_t end)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_index_out_of_bounds_test(fn_name, start, self->len, start > self->len);
    str_invalid_index_test(fn_name, "start", "end", start, end);
    
    _StringCell* ptr = self->__first->__next;

    for(size_t i = 0; i < start; i++){
        ptr = ptr->__next;
        strcell_free(ptr->__prev);
    }

    self->__first->__next = ptr;
    ptr->__prev = self->__first;

    ptr = self->__last;

    for(size_t i = self->len; i > end; i--){
        ptr = ptr->__prev;
        strcell_free(ptr->__next);
    }

    self->__last = ptr;
    self->__last->__next = NULL;

    self->len = end - start;
    ptr = NULL;
}

/**
 * @brief Inserts a char at specific index on the string, pushing
 * every other char forward one step
 * 
 * @param self string to insert char
 * @param index index where to insert char
 * @param c char to insert
 */
void str_insert(String* self, const size_t index, const char c){
    char fn_name[] = "void insert(String* self, const size_t index, const char c)";
    str_null_reference_test(fn_name, "self", self);
    str_index_out_of_bounds_test(fn_name, index, self->len, index > self->len);

    _StringCell* ptr = self->__first;
    _StringCell* tmp = strcell_new(c);

    for(size_t i = 0; i < index; i++) ptr = ptr->__next;

    tmp->__prev = ptr;
    tmp->__next = ptr->__next;

    tmp->__prev->__next = tmp;

    if(tmp->__next != NULL)
        tmp->__next->__prev = tmp;
    else
        self->__last = tmp;    

    self->len++;
    ptr = NULL;
    tmp = NULL;
}

/**
 * @brief Inserts a string at a specific index on the string
 * 
 * @param self String to be edited
 * @param index where to insert substring
 * @param str substring array to be inserted
 */
void str_insert_str(String* self, const size_t index, const String* str){
    char fn_name[] = "void insert_str(String* self, const size_t index, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "self", self->__first);
    str_first_cell_test(fn_name, "str", str->__first);
    str_index_out_of_bounds_test(fn_name, index, self->len, index > self->len);
    
    if(!str->is_empty(str)){
        if(index == self->len){
            self->push_str(self, str);
        }else{
            _StringCell* ptr1 = self->__first;
            _StringCell* ptr2 = NULL;
            _StringCell* ptr3 = str->__first->__next;

            for(size_t i = 0; i < index; i++) 
                ptr1 = ptr1->__next;

            ptr2 = ptr1->__next;

            for(size_t i = 0; i < str->len; i++){
                ptr1->__next = strcell_new(ptr3->__c);
                ptr1->__next->__prev = ptr1;
                ptr1 = ptr1->__next;
                ptr3 = ptr3->__next;
            }

            ptr1->__next = ptr2;
            ptr2->__prev = ptr1;

            ptr1 = NULL;
            ptr2 = NULL;
            ptr3 = NULL;

            self->len += str->len;
        }
    }
}

/**
 * @brief Inserts a char array at a specific index on the string
 * 
 * @param self String to be edited
 * @param index where to insert substring
 * @param chars char array to be inserted
 */
void str_insert_chars(String* self, const size_t index, const char* chars){
    char fn_name[] = "void insert_chars(String* self, const size_t index, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    str_index_out_of_bounds_test(fn_name, index, self->len, index > self->len);

    size_t len = str_strlen(chars);

    if(len > 0){
        if(index == self->len){
            self->push_chars(self, chars);
        }else{
            _StringCell* ptr1 = self->__first;
            _StringCell* ptr2 = NULL;
            size_t chars_index = 0;

            for(size_t i = 0; i < index; i++) 
                ptr1 = ptr1->__next;

            ptr2 = ptr1->__next;

            for(size_t i = 0; i < len; i++){
                ptr1->__next = strcell_new(chars[chars_index++]);
                ptr1->__next->__prev = ptr1;
                ptr1 = ptr1->__next;
            }

            ptr1->__next = ptr2;
            ptr2->__prev = ptr1;

            ptr1 = NULL;
            ptr2 = NULL;

            self->len += len;
        }
    }
}

/**
 * @brief Returns whether a given substring is present at the start
 * of the main String 
 * 
 * @param self String to test the start
 * @param str substring that can be present at the start of string
 * @return true if string ends with substring, false otherwise
 */
int str_starts_with_str(const String* self, const String* str){
    char fn_name[] = "int starts_with_str(const String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "self", self->__first);
    str_first_cell_test(fn_name, "str", str->__first);
    
    int starts_with = 0;

    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->__first->__next;
        _StringCell* ptr2 = str->__first->__next;

        while(ptr2 != NULL && ptr1->__c == ptr2->__c){
            ptr1 = ptr1->__next;
            ptr2 = ptr2->__next;
        }

        if(ptr2 == NULL)
            starts_with = 1;

        ptr1 = NULL;
        ptr2 = NULL;
    }

    return starts_with;
}

/**
 * @brief Returns whether a given substring is present at the start
 * of the main String 
 * 
 * @param self String to test the start
 * @param chars char array that can be present at the start of string
 * @return true if string ends with substring, false otherwise
 */
int str_starts_with_chars(const String* self, const char* chars){
    char fn_name[] = "int starts_with_chars(const String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    str_first_cell_test(fn_name, "self", self->__first);
    
    int starts_with = 0;
    size_t len = str_strlen(chars);

    if(!self->is_empty(self) && len > 0 && self->len >= len){
        _StringCell* ptr = self->__first->__next;
        size_t i = 0;

        while(i < len && ptr->__c == chars[i]){
            ptr = ptr->__next;
            i++;
        }

        if(i >= len)
            starts_with = 1;

        ptr = NULL;
    }

    return starts_with;
}

/**
 * @brief Returns whether a given substring is present at the end
 * of the main String 
 * 
 * @param self String to test the end
 * @param str substring that can be present at the end of string
 * @return true if string ends with substring, false otherwise
 */
int str_ends_with_str(const String* self, const String* str){
    char fn_name[] = "int ends_with_str(const String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    
    int ends_with = 0;

    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->__last;
        _StringCell* ptr2 = str->__last;

        while(ptr2 != str->__first && ptr1->__c == ptr2->__c){
            ptr1 = ptr1->__prev;
            ptr2 = ptr2->__prev;
        }

        if(ptr2 == str->__first)
            ends_with = 1;

        ptr1 = NULL;
        ptr2 = NULL;
    }

    return ends_with;
}

/**
 * @brief Returns whether a given substring is present at the end
 * of the main String 
 * 
 * @param self String to test the end
 * @param chars char array that can be present at the end of string
 * @return true if string ends with substring, false otherwise
 */
int str_ends_with_chars(const String* self, const char* chars){
    char fn_name[] = "int ends_with_chars(const String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);

    int ends_with = 0;
    size_t i = str_strlen(chars);

    if(!self->is_empty(self) && i > 0 && self->len >= i){
        _StringCell* ptr = self->__last;

        while(i > 0 && ptr->__c == chars[i - 1]){
            ptr = ptr->__prev;
            i--;
        }

        if(i == 0)
            ends_with = 1;

        ptr = NULL;
    }

    return ends_with;
}

/**
 * @brief Searches the string for a given substring and returns index
 * of the first character of the substring, if it was found, else -1
 * 
 * @param self String to search for substring
 * @param str substring searched
 * @return index of substring if found, -1 otherwise
 */
int str_find_str(const String* self, const String* str){
    char fn_name[] = "int find_str(const String* self, const String* str)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "str", str);
    str_first_cell_test(fn_name, "self", self->__first);
    str_first_cell_test(fn_name, "str", str->__first);

    int index = -1;
    
    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->__first->__next;
        _StringCell* ptr2 = self->__first->__next;
        _StringCell* ptr3 = str->__first->__next;

        while(ptr1 != NULL && ptr2 != NULL && ptr3 != NULL){
            index++;

            if(ptr1->__c == ptr3->__c){
                ptr2 = ptr1->__next;
                ptr3 = ptr3->__next;

                while(ptr2 != NULL && ptr3 != NULL){
                    if(ptr2->__c == ptr3->__c){
                        ptr2 = ptr2->__next;
                        ptr3 = ptr3->__next;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr3 != NULL){
                    ptr3 = str->__first->__next;
                    ptr2 = ptr1;
                    ptr1 = ptr1->__next;
                }
            }else{
                ptr1 = ptr1->__next;
            }
        }

        if(ptr3 != NULL) index = -1;

        ptr1 = NULL;
        ptr2 = NULL;
        ptr3 = NULL;
    }

    return index;
}

/**
 * @brief Searches the string for a given substring and returns index
 * of the first character of the substring, if it was found, else -1
 * 
 * @param self String to search for substring
 * @param chars char array searched
 * @return index of substring if found, -1 otherwise
 */
int str_find_chars(const String* self, const char* chars){
    char fn_name[] = "int find_chars(const String* self, const char* chars)";
    str_null_reference_test(fn_name, "self", self);
    str_null_reference_test(fn_name, "chars", chars);
    str_first_cell_test(fn_name, "self", self->__first);
    
    int index = -1;
    size_t len = str_strlen(chars);
    
    if(!self->is_empty(self) && len && self->len >= len){
        _StringCell* ptr1 = self->__first->__next;
        _StringCell* ptr2 = self->__first->__next;
        size_t i = 0;

        while(ptr1 != NULL && ptr2 != NULL && i < len){
            index++;

            if(ptr1->__c == chars[i]){
                ptr2 = ptr1->__next;
                i++;

                while(ptr2 != NULL && i < len){
                    if(ptr2->__c == chars[i]){
                        ptr2 = ptr2->__next;
                        i++;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(i < len){
                    i = 0;
                    ptr2 = ptr1;
                    ptr1 = ptr1->__next;
                }
            }else{
                ptr1 = ptr1->__next;
            }
        }

        if(i < len) index = -1;

        ptr1 = NULL;
        ptr2 = NULL;
    }

    return index;
}

/**
 * @brief Searches the string for a given substring
 * 
 * @param self String to search substring
 * @param str substring searched
 * @return true if substring is inside String, false otherwise
 */
int str_contains_str(const String* self, const String* str){
    return str_find_str(self, str) != -1;
}

/**
 * @brief Searches the string for a given substring
 * 
 * @param self String to search substring
 * @param chars char array searched
 * @return true if substring is inside String, false otherwise
 */
int str_contains_chars(const String* self, const char* chars){
    return str_find_chars(self, chars) != -1;
}

/**
 * @brief Creates a byte array containing the ascii value of
 * every character in the string.
 * @attention The length of the byte array is the same as of the string
 * 
 * @param self String to get the byte array
 * @return byte array
 */
int* str_to_bytes(const String* self){
    char fn_name[] = "int* to_bytes(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));
    
    int* bytes = (int*)malloc(self->len * sizeof(int));
    str_memory_test(fn_name, bytes);

    _StringCell* ptr = self->__first->__next;
    size_t i = 0;

    while(ptr != NULL){
        bytes[i++] = ptr->__c;
        ptr = ptr->__next;
    }

    return bytes;
}

/**
 * @brief Parses the string if it is a valid int
 * 
 * @param self String to be parsed
 * @return int value of string
 */
int str_parse_int(const String* self){
    char fn_name[] = "int parse_int(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));

    int n = 0;
    int negative = 0;
    size_t steps = 1;
    size_t index = self->len;
    _StringCell* ptr = self->__last;

    while(ptr != self->__first->__next){
        str_nan_test(fn_name, index, ptr->__c);
        
        n += (ptr->__c - 48) * steps;

        steps *= 10;
        index--;
        ptr = ptr->__prev;
    }

    ptr = self->__first->__next;
    
    if(ptr->__c == '-'){
        negative = 1;
    }else if(self->__first->__next->__c != '+'){
        str_nan_test(fn_name, index, ptr->__c);
        
        n += (ptr->__c - 48) * steps;
    }

    ptr = NULL;

    return negative ? n * -1 : n;
}

/**
 * @brief Parses the string if it is a valid float
 * 
 * @param self String to be parsed
 * @return float value of string
 */
float str_parse_float(const String* self){    
    return (float)str_parse_double(self);
}

/**
 * @brief Parses the string if it is a valid double
 * 
 * @param self String to be parsed
 * @return double value of string
 */
double str_parse_double(const String* self){
    char fn_name[] = "double parse_double(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    str_empty_test(fn_name, "self", self->is_empty(self));

    _StringCell* ptr = self->__first->__next;
    double d = 0.0;
    int negative = 0;
    double steps = 1;
    size_t index = 0;

    if(ptr->__c == '-'){
        negative = 1;
        ptr = ptr->__next;
    }else if(ptr->__c == '+'){
        ptr = ptr->__next;
    }

    while(ptr != NULL && ptr->__c != '.'){
        if(ptr->__c != '.') 
            str_nan_test(fn_name, index + 1, ptr->__c);
        
        d *= steps;
        d += ptr->__c - 48;
        steps *= 10;
        
        index++;
        ptr = ptr->__next;
    }

    if(ptr != NULL && ptr->__c == '.'){
        ptr = ptr->__next;
        steps = 0.1;
        index++;
    }

    while(ptr != NULL){
        str_nan_test(fn_name, index + 1, ptr->__c);

        d += (ptr->__c - 48) * steps;
        steps /= 10;

        index++;
        ptr = ptr->__next;
    }

    return negative ? d * -1 : d;
}

/**
 * @brief Parses the contend of the String if is a valid boolean
 * 
 * @param self String to be parsed
 * @return true if String is a valid true boolean, false otherwise
 */
int str_parse_bool(const String* self){
    char fn_name[] = "int parse_bool(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;
    int b = 0;

    if(ptr != NULL){
        if(self->len == 4 && 
          (ptr->__c == 'T' || ptr->__c == 't') &&
           ptr->__next != NULL && 
          (ptr->__next->__c == 'R' || ptr->__next->__c == 'r') &&
           ptr->__next->__next != NULL && 
          (ptr->__next->__next->__c == 'U' || ptr->__next->__next->__c == 'u') && 
           ptr->__next->__next->__next != NULL && 
          (ptr->__next->__next->__next->__c == 'E' || ptr->__next->__next->__next->__c == 'e')){

           b = 1;
        }else if(self->len == 1 && ptr->__c == '1') b = 1;
    }

    ptr = NULL;

    return b;
}

/**
 * @brief Turns every upper case letter in the string to lower case
 * 
 * @param self String to be edited
 */
void str_to_lowercase(String* self){
    char fn_name[] = "void lowercase(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    
    _StringCell* ptr = self->__first->__next;

    while(ptr != NULL){
        if('A' <= ptr->__c && ptr->__c <= 'Z'){
            ptr->__c += 32;
        }

        ptr = ptr->__next;
    }
}

/**
 * @brief Turns every lower case letter in the string to upper case
 * 
 * @param self String to be edited
 */
void str_to_uppercase(String* self){
    char fn_name[] = "void to_uppercase(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__first->__next;

    while(ptr != NULL){
        if('a' <= ptr->__c && ptr->__c <= 'z'){
            ptr->__c -= 32;
        }

        ptr = ptr->__next;
    }
}

/**
 * @brief Capitalizes every word on the string (e.g. `ab c def` -> `Ab C Def`)
 * 
 * @param self String to be titled
 */
void str_title(String* self){
    char fn_name[] = "void title(String* self)";
    str_null_reference_test(fn_name, "self", self);
    
    _StringCell* ptr = self->__first;

    while(ptr != NULL){
        do
            ptr = ptr->__next;
        while(ptr != NULL && (ptr->__c == ' ' || ptr->__c == '\r' || ptr->__c == '\n'));
        
        if(ptr != NULL){
            if('a' <= ptr->__c && ptr->__c <= 'z')
                ptr->__c -= 32;

            do
                ptr = ptr->__next;
            while(ptr != NULL && (ptr->__c != ' ' && ptr->__c != '\r' && ptr->__c != '\n'));
        }
    }
}

/**
 * @brief Capitalizes the string (e.g. `test` -> `Test`)
 * 
 * @param self String to be capitalized
 */
void str_capitalize(String* self){
    char fn_name[] = "void capitalize(String* self)";
    str_null_reference_test(fn_name, "self", self);

    _StringCell* ptr = self->__first;

    do
        ptr = ptr->__next;
    while(ptr != NULL && (ptr->__c == ' ' || ptr->__c == '\r' || ptr->__c == '\n'));

    if(ptr != NULL && 'a' <= ptr->__c && ptr->__c <= 'z')
        ptr->__c -= 32;

    ptr = NULL;
}

/**
 * @brief Deletes every char from the string, until it is empty
 * 
 * @param self String to be cleared
 */
void str_clear(String* self){
    char fn_name[] = "void clear(String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);

    _StringCell* ptr = self->__last;

    while(ptr != self->__first){
        ptr = ptr->__prev;
        strcell_free(ptr->__next);
    }

    strcell_free(ptr);
    ptr = NULL;
    self->__last = self->__first;
}

/**
 * @brief Creates a clone of a given String
 * 
 * @param self String to be cloned
 * @return clone of String
 */
String str_clone(const String* self){
    char fn_name[] = "String clone(const String* self)";
    str_null_reference_test(fn_name, "self", self);
    str_first_cell_test(fn_name, "self", self->__first);
    
    String str = string_new();
    str.push_str(&str, self);

    return str;
}

/**
 * @brief Frees the String assuming that `self`
 * is not allocated (i.e. the free(self) must be done manualy)
 * 
 * @param self String to be freed
 */
void str_free(String* self){
    if(self != NULL && !self->is_empty(self)){
        self->clear(self);

        self->__first = NULL;
        self->__last = NULL;

        self->is_empty = NULL;
        self->first = NULL;
        self->last = NULL;
        self->push = NULL;
        self->push_chars = NULL;
        self->push_str = NULL;
        self->get = NULL;
        self->set = NULL;
        self->print = NULL;
        self->println = NULL;
        self->to_chars = NULL;
        self->find = NULL;
        self->contains = NULL;
        self->substring = NULL;
        self->trim = NULL;
        self->trim_left = NULL;
        self->trim_right = NULL;
        self->compare_to_str = NULL;
        self->compare_to_chars = NULL;
        self->equals_str = NULL;
        self->equals_chars = NULL;
        self->split = NULL;
        self->replace = NULL;
        self->replace_all = NULL;
        self->remove = NULL;
        self->remove_char = NULL;
        self->remove_all = NULL;
        self->remove_str = NULL;
        self->remove_chars = NULL;
        self->drain = NULL;
        self->drain_and_free = NULL;
        self->reap = NULL;
        self->insert = NULL;
        self->insert_str = NULL;
        self->insert_chars = NULL;
        self->find_str = NULL;
        self->find_chars = NULL;
        self->starts_with_str = NULL;
        self->starts_with_chars = NULL;
        self->ends_with_str = NULL;
        self->ends_with_chars = NULL;
        self->contains_str = NULL;
        self->contains_chars = NULL;
        self->to_bytes = NULL;
        self->parse_int = NULL;
        self->parse_float = NULL;
        self->parse_double = NULL;
        self->parse_bool = NULL;
        self->to_lowercase = NULL;
        self->to_uppercase = NULL;
        self->title = NULL;
        self->capitalize = NULL;
        self->clear = NULL;
        self->clone = NULL;
        self->free = NULL;
    }
}


// ========================================== StringArray ========================================== //

/**
 * @brief Initializes a StringArray with 0 size
 * 
 * @return empty StringArray
 */
StringArray strarray_new(){
    StringArray sa;

    sa.free = strarray_free;
    sa.len = 0;
    sa.strs = NULL;

    return sa;
}

/**
 * @brief Frees every string in a StringArray, assuming that `self`
 * is not allocated (i.e. the free(self) must be done manualy)
 * 
 * @param self StringArray to be freed
 */
void strarray_free(StringArray* self){
    if(self != NULL){
        for(size_t i = 0; i < self->len; i++){
            if(&self->strs[i] != NULL){
                self->strs[i].free(&self->strs[i]);
            }
        }

        self->free = NULL;
    }
}


// ========================================== Other ========================================== //

/**
 * @brief The same exact implementation of `strlen` in `string.h`
 * I'm putting it here just so I don't have to include `string.h`
 * 
 * @param chars string to count the length
 * @return length of string
 */
static inline size_t str_strlen(const char* chars){
    size_t len = 0;

    while(chars[len]){
        len++;
    }

    return len;
}

/**
 * @brief Tests if a memory allocation was sucessful. If not, exits
 * the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param test allocated pointer
 */
static void str_memory_test(const char* fn, const void* test){
    if(test == NULL){
        printf("\nString error at:\n");
        printf("`%s`\n\n", fn);
        printf("-> failed to allocate memory\n");
        exit(1);
    }
}

/**
 * @brief Tests if a String* or char* is null. If it is, exits the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param arg name of the argument
 * @param test String to be tested
 */
static void str_null_reference_test(const char* fn, const char* arg, const void* test){
    if(test == NULL){
        printf("\nString error at:\n");
        printf("`%s`\n\n", fn);
        printf("-> argument `%s` is null\n", arg);
        exit(1);
    }
}

/**
 * @brief Tests if the first cell of the linked list of a String is null
 * The first cell is "empty" and should never be null. If if is, exits the
 * program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param arg name of the argument
 * @param test StringCell to be tested
 */
static void str_first_cell_test(const char* fn, const char* arg, const void* test){
    if(test == NULL){
        printf("\nString error at:\n");
        printf("`%s`\n\n", fn);
        printf("-> first cell of string `%s` is null\n", arg);
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String string_new()` to initialize a string\n");
        exit(1);
    }
}

/**
 * @brief Tests if a String* is empty. If it is, exits the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param arg name of the argument
 * @param empty boolean indicating if String is empty
 */
static void str_empty_test(const char* fn, const char* arg, const int empty){
    if(empty){
        printf("\nString error at:\n");
        printf("`%s`\n\n", fn);
        printf("-> string `%s` is empty\n", arg);
        exit(1);
    }
}

/**
 * @brief Tests if index is equal or greater then than length of String.
 * If it is, exits the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param index index to be tested
 * @param len length to be tested
 * @param test result of test
 */
static void str_index_out_of_bounds_test(const char* fn, const size_t index, const size_t len, const int test){
    if(test){
        printf("\nString error at: \n");
        printf("`%s`\n\n", fn);
        printf("-> index `%ld` invalid for length `%ld`\n", index, len);
        exit(1);
    }
}

/**
 * @brief Tests if a index is equal or greater than the other. If it is,
 * exits the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param i_name first index name
 * @param j_name second index name
 * @param i first index
 * @param j second index
 */
static void str_invalid_index_test(const char* fn, const char* i_name, const char* j_name, const size_t i, const size_t j){
    if(i > j){
        printf("\nString error at: \n");
        printf("`%s`\n\n", fn);
        printf("-> index `%s` (%ld) is higher than `%s` (%ld)\n", i_name, i, j_name, j);
        exit(1);
    }
}

/**
 * @brief Tests if a char is not a number. If not, exits the program
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param index index of char
 * @param c char to test
 */
static void str_nan_test(const char* fn, const size_t index, const char c){
    if(!('0' <= c && c <= '9')){
        printf("\nString error at:\n");
        printf("`%s`\n\n", fn);
        printf("-> char at index `%ld` (%c) is not a number\n", index - 1, c);
        exit(1);
    }
}

/**
 * @brief Exits the program due to an incorret formatting in string
 * 
 * @warning Not intended for public use
 * 
 * @param fn name of the function
 * @param prefix optional format prefix
 * @param c incorrect format
 */
static void str_format_error(const char* fn, const char* prefix, const char c){
    printf("\nString error at:\n");
    printf("`%s`\n\n", fn);
    printf("-> format `%%%s%c` is invalid\n", prefix, c);
    exit(1);
}

#endif
