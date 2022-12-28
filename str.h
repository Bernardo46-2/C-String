#ifndef _STR_H_
#define _STR_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief My implementation of strings in C using linked lists (because I like linked lists)
 * @author Bernardo Marques Fernandes
 * @version 1.0.2
 */


// ========================================== Structs ========================================== //

typedef struct _StringCell_t _StringCell;
typedef struct _String_t String;
typedef struct _StringArray_t StringArray;

struct _StringCell_t{
    char _c;
    _StringCell* _next;
    _StringCell* _prev;
    void (*_free)(_StringCell*);
};

struct _String_t{
    size_t len;
    _StringCell* _first;
    _StringCell* _last;
    bool (*is_empty)(const String* self);
    void (*push)(String* self, const char c);
    void (*push_chars)(String* self, const char* chars);
    void (*push_str)(String* self, const String* str);
    char (*nth)(const String* self, size_t index);
    void (*set)(String* self, const size_t index, const char c);
    void (*print)(const String* self);
    void (*println)(const String* self);
    char* (*to_chars)(const String* self);
    int (*find)(const String* self, const char c);
    bool (*contains)(const String* self, const char c);
    String (*substring)(const String* self, size_t start, size_t end);
    void (*trim)(String* self);
    int (*compare_to_str)(const String* self, const String* str);
    int (*compare_to_chars)(const String* self, const char* chars);
    bool (*equals_str)(const String* self, const String* str);
    bool (*equals_chars)(const String* self, const char* chars);
    StringArray (*split)(const String* self, const char c);
    void (*replace)(String* self, const char old, const char replacement);
    void (*replace_all)(String* self, const char old, const char replacement);
    bool (*remove_str)(String* self, const String* str);
    bool (*remove_chars)(String* self, const char* chars);
    char (*remove)(String* self, const size_t index);
    bool (*remove_char)(String* self, const char c);
    int (*remove_all)(String* self, const char c);
    String (*drain)(String* self, const size_t start, const size_t end);
    void (*drain_and_free)(String* self, const size_t start, const size_t end);
    void (*reap)(String* self, const size_t start, const size_t end);
    void (*insert)(String* self, const size_t index, const char c);
    void (*insert_str)(String* self, const size_t index, const String* str);
    void (*insert_chars)(String* self, const size_t index, const char* chars);
    int (*find_str)(const String* self, const String* str);
    int (*find_chars)(const String* self, const char* chars);
    bool (*contains_str)(const String* self, const String* str);
    bool (*contains_chars)(const String* self, const char* chars);
    bool (*starts_with_str)(const String* self, const String* str);
    bool (*starts_with_chars)(const String*self, const char* chars);
    bool (*ends_with_str)(const String* self, const String* str);
    bool (*ends_with_chars)(const String* self, const char* chars);
    int* (*to_bytes)(const String* self);
    int (*parse_int)(const String* self);
    float (*parse_float)(const String* self);
    double (*parse_double)(const String* self);
    bool (*parse_bool)(const String* self);
    void (*to_lowercase)(String* self);
    void (*to_uppercase)(String* self);
    void (*title)(String* self);
    void (*capitalize)(String* self);
    String (*clone)(const String* self);
    void (*free)(String* self);
};

struct _StringArray_t{
    String* strs;
    size_t len;
    void (*free)(StringArray* self);
};


// ========================================== Prototypes ========================================== //

_StringCell* __strcell_new(const char);
void __strcell_free(_StringCell*);

String str_new();
String str_from(const char*);
String str_read(const char*, const size_t);
String str_read_line(const char*, const size_t);
bool str_is_empty(const String*);
void str_push(String*, const char);
void str_push_chars(String*, const char*);
void str_push_str(String*, const String*);
char str_nth(const String*, const size_t);
void str_set(String*, const size_t, const char);
void str_print(const String*);
void str_println(const String*);
char* str_to_chars(const String*);
int str_find(const String*, const char);
bool str_contains(const String*, const char);
String str_substring(const String*, size_t, size_t);
void str_trim(String*);
int str_compare_to_str(const String*, const String*);
int str_compare_to_chars(const String*, const char*);
bool str_equals_str(const String*, const String*);
bool str_equals_chars(const String*, const char*);
StringArray str_split(const String*, const char);
void str_replace(String*, const char, const char);
void str_replace_all(String*, const char, const char);
char str_remove(String*, const size_t);
bool str_remove_char(String*, const char);
int str_remove_all(String*, const char);
String str_drain(String*, const size_t, const size_t);
void str_drain_and_free(String*, const size_t, const size_t);
void str_reap(String*, const size_t, const size_t);
bool str_remove_str(String*, const String*);
bool str_remove_chars(String*, const char*);
void str_insert(String*, const size_t, const char);
void str_insert_str(String*, const size_t, const String*);
void str_insert_chars(String*, const size_t, const char*);
int str_find_str(const String*, const String*);
int str_find_chars(const String*, const char*);
bool str_starts_with_str(const String*, const String*);
bool str_starts_with_chars(const String*, const char*);
bool str_ends_with_str(const String*, const String*);
bool str_ends_with_chars(const String*, const char*);
bool str_contains_str(const String*, const String*);
bool str_contains_chars(const String*, const char*);
int* str_to_bytes(const String*);
int str_parse_int(const String*);
float str_parse_float(const String*);
double str_parse_double(const String*);
bool str_parse_bool(const String*);
void str_to_lowercase(String*);
void str_to_uppercase(String*);
void str_title(String*);
void str_capitalize(String*);
String str_clone(const String*);
void str_free(String*);

StringArray strarray_new();
void strarray_free(StringArray*);

size_t __str_strlen(const char*);


// ========================================== _StringCell ========================================== //

/**
 * @brief Allocates a new StringCell for the linkedlist
 * 
 * @warning not intended for public use
 * 
 * @param c char that the cell will hold
 * @return allocated cell
 */
_StringCell* __strcell_new(const char c){
    _StringCell* self = (_StringCell*)malloc(sizeof(_StringCell));

    if(self == NULL){
        printf("\nString error at:\n");
        printf("\n`_StringCell* __strcell_new(const char c)`\n\n");
        printf("-> failed to allocate memory\n");
        exit(1);
    }
    
    self->_c = c;
    self->_next = NULL;
    self->_prev = NULL;

    self->_free = __strcell_free;

    return self;
}

/**
 * @brief Frees a StringCell
 * 
 * @warning not intended for public use
 * 
 * @param self StringCell to be freed
 */
void __strcell_free(_StringCell* self){
    if(self != NULL){
        self->_next = NULL;
        self->_prev = NULL;
        self->_free = NULL;

        free(self);
    }
}


// ========================================== String ========================================== //

/**
 * @brief Creates a new String
 * 
 * @return new String 
 */
String str_new(){
    String self;

    self._first = __strcell_new(' ');
    self._last = self._first;
    self._last->_next = NULL;
    self.len = 0;

    self.is_empty = str_is_empty;
    self.push = str_push;
    self.push_chars = str_push_chars;
    self.push_str = str_push_str;
    self.nth = str_nth;
    self.set = str_set;
    self.print = str_print;
    self.println = str_println;
    self.to_chars = str_to_chars;
    self.find = str_find;
    self.contains = str_contains;
    self.substring = str_substring;
    self.trim = str_trim;
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
String str_from(const char* chars){
    String self = str_new();
    size_t len = __str_strlen(chars);

    self.push_chars(&self, chars);

    return self;
}

/**
 * @brief Reads a new String from stdin
 * 
 * @param message what to print before reading String
 * @param max_len max length of String (it can be muted later by other methods)
 * @return new String
 */
String str_read(const char* message, const size_t max_len){
    char* str = (char*)malloc((max_len + 1) * sizeof(char));

    if(str == NULL){
        printf("\nString error at:\n");
        printf("\n`String str_read(const char* message, const size_t max_len)`\n\n");
        printf("-> failed to allocate memory\n");
        exit(1);
    }

    String self;

    printf("%s", message);
    scanf("%s", str);
    while(getchar() != '\n');

    self = str_from(str);

    if(str) free(str);
    return self;
}

/**
 * @brief Reads a new String from stdin, including spaces
 * 
 * @param message what to print before reading String
 * @param max_len max length of String (it can be muted later by other methods)
 * @return new String
 */
String str_read_line(const char* message, const size_t max_len){
    char* str = (char*)malloc((max_len + 1) * sizeof(char));

    if(str == NULL){
        printf("\nString error at:\n");
        printf("\n`String str_read_line(const char* message, const size_t max_len)`\n\n");
        printf("-> failed to allocate memory\n");
        exit(1);
    }
    
    String self;

    printf("%s", message);
    fgets(str, max_len + 1, stdin);

    self = str_from(str);

    if(self._last->_c == '\n')
        self.remove(&self, self.len - 1);

    if(str) free(str);
    return self;
}

/**
 * @brief Returns whether a String is empty
 * 
 * @param self String to test
 * @return true if String is empty, false otherwise
 */
bool str_is_empty(const String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("\n`bool is_empty(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    return self->_first == self->_last;
}

/**
 * @brief Inserts a char at the end of the String
 * 
 * @param self String to be edited
 * @param c char to insert
 */
void str_push(String* self, const char c){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("\n`void push(String* self, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(self != NULL){
        self->_last->_next = __strcell_new(c);
        self->_last->_next->_prev = self->_last;
        self->_last = self->_last->_next;
        self->len++;
    }
}

/**
 * @brief Inserts a given substring at the end of String
 * 
 * @param self String to be edited
 * @param chars char array to be inserted
 */
void str_push_chars(String* self, const char* chars){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("\n`void push_chars(String* self, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(chars == NULL){
        printf("\nString error at:\n");
        printf("\n`void push_chars(String* self, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }
    
    size_t len = __str_strlen(chars);
    _StringCell* ptr = self->_last;

    for(size_t i = 0; i < len; i++){
        ptr->_next = __strcell_new(chars[i]);
        ptr->_next->_prev = ptr;
        ptr = ptr->_next;
    }

    self->len += len;
    self->_last = ptr;
    ptr = NULL;
}

/**
 * @brief Inserts a given substring at the end of String
 * 
 * @param self String to be edited
 * @param str substring to be inserted
 */
void str_push_str(String* self, const String* str){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void push_str(String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(str == NULL){
        printf("\nString error at:\n");
        printf("`void push_str(String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`void push_str(String* self, const String* str)`\n\n");
        printf("-> first cell of string `str` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr1 = self->_last;
    _StringCell* ptr2 = str->_first->_next;

    while(ptr2 != NULL){
        ptr1->_next = __strcell_new(ptr2->_c);
        ptr1->_next->_prev = ptr1;
        ptr1 = ptr1->_next;
        ptr2 = ptr2->_next;
    }

    self->len += str->len;
    self->_last = ptr1;
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
char str_nth(const String* self, const size_t index){
    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`char nth(const String* self, const size_t index)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(index >= self->len){
        printf("\nString error at: \n");
        printf("`char nth(const String* self, const size_t index)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`char nth(const String* self, const size_t index)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    char c = ' ';
    
    for(size_t i = 0; i < index; i++)
        ptr = ptr->_next;

    c = ptr->_c;
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
    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`void set(String* self, const size_t index, const char c)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(index >= self->len){
        printf("\nString error at: \n");
        printf("`void set(String* self, const size_t index, const char c)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void set(String* self, const size_t index, const char c)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    for(size_t i = 0; i < index; i++) ptr = ptr->_next;

    ptr->_c = c;
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
        if(self->_first == NULL){
            printf("\nString error at:\n");
            printf("`void print(const String* self)`\n\n");
            printf("-> first cell of string `self` is null\n");
            printf("-> could this be because a constructor was not used?\n");
            printf("-> try using the method `String str_new()` to initialize a string\n");
            exit(1);
        }

        _StringCell* ptr = self->_first->_next;

        while(ptr != NULL){
            printf("%c", ptr->_c);
            ptr = ptr->_next;
        }

        ptr = NULL;
    }
}

/**
 * @brief Prints the string with a line break `\n` at the end
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`char* to_chars(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    char* str = (char*)malloc((self->len + 1) * sizeof(char));

    if(str == NULL){
        printf("\nString error at:\n");
        printf("\n`char* to_chars(const String* self)`\n\n");
        printf("-> failed to allocate memory\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`char* to_chars(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }
    
    _StringCell* ptr = self->_first->_next;
    size_t i = 0;
    
    while(ptr != NULL){
        str[i++] = ptr->_c;
        ptr = ptr->_next;
    }

    str[i] = '\0';
    ptr = NULL;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`size_t find(const String* self, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int find(const String* self, const char c)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    size_t index = 0;
    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL && ptr->_c != c){
        ptr = ptr->_next;
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
bool str_contains(const String* self, const char c){
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
 * @param start start index of substring
 * @param end end index of substring
 * @return substring between start and end indexes
 */
String str_substring(const String* self, size_t start, size_t end){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`String substring(const String* self, size_t start, size_t end)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(start > end){
        printf("\nString error at: \n");
        printf("`String substring(const String* self, size_t start, size_t end)`\n\n");
        printf("-> index `start` (%ld) is higher than `end` (%ld)\n", start, end);
        exit(1);
    }

    if(end > self->len){
        printf("\nString error at: \n");
        printf("`String substring(const String* self, size_t start, size_t end)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", end, self->len);
        exit(1);
    }

    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`String substring(const String* self, size_t start, size_t end)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`String substring(const String* self, size_t start, size_t end)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    String str = str_new();
    _StringCell* ptr = self->_first->_next;

    for(size_t i = 0; i < start; i++)
        ptr = ptr->_next;

    for(size_t i = start; i < end; i++){
        str.push(&str, ptr->_c);
        ptr = ptr->_next;
    }

    ptr = NULL;

    return str;
}

/**
 * @brief Removes spaces, `\\n` and `\\r` present at the start and end of the string
 * 
 * @param self base String
 */
void str_trim(String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`String* trim(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`String* trim(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(!self->is_empty(self)){
        _StringCell* ptr = self->_last;

        while(ptr != self->_first && (ptr->_c == ' ' || ptr->_c == '\n' || ptr->_c == '\r')){
            ptr = ptr->_prev;
            __strcell_free(ptr->_next);
            self->len--;
        }

        ptr->_next = NULL;
        self->_last = ptr;
        ptr = self->_first->_next;

        while(ptr != NULL && (ptr->_c == ' ' || ptr->_c == '\n' || ptr->_c == '\r')){
            ptr = ptr->_next;
            __strcell_free(ptr->_prev);
            self->len--;
        }

        if(ptr != NULL) ptr->_prev = self->_first;
        self->_first->_next = ptr;

        ptr = NULL;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_str(const String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(str == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_str(const String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr1 = self->_first->_next;
    _StringCell* ptr2 = str->_first->_next;
    int diff = 0;
    
    while(ptr1 != NULL && ptr2 != NULL && diff == 0){
        diff = ptr1->_c - ptr2->_c;
        ptr1 = ptr1->_next;
        ptr2 = ptr2->_next;
    }

    if(ptr1 != NULL && ptr2 == NULL) diff = ptr1->_c;
    else if(ptr1 == NULL && ptr2 != NULL) diff = ptr2->_c;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int compare_to_chars(const String* self, const char* chars)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    size_t i = 0;
    size_t len = __str_strlen(chars);
    int diff = 0;
    
    while(ptr != NULL && i < len && diff == 0){
        diff = ptr->_c - chars[i];
        ptr = ptr->_next;
        i++;
    }

    if(ptr != NULL && i == len) diff = ptr->_c;
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
bool str_equals_str(const String* self, const String* str){
    return str_compare_to_str(self, str) == 0;
}

/**
 * @brief Tests whether a string is equal to another
 * 
 * @param self String to test
 * @param chars char array to test
 * @return true if it is equal, false otherwise
 */
bool str_equals_chars(const String* self, const char* chars){
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`StringArray split(const String* self, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`StringArray split(const String* self, const char c)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`StringArray split(const String* self, const char c)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    _StringCell* start = NULL;
    size_t index = 0;
    StringArray sa = strarray_new();

    while(ptr != NULL && ptr->_c == c)
        ptr = ptr->_next;

    start = ptr;

    while(ptr != NULL){
        if(ptr->_c == c){
            do
                ptr = ptr->_next;
            while(ptr != NULL && ptr->_c == c);

            if(ptr != NULL){
                sa.len++;
                ptr = ptr->_next;
            }
        }else{
            ptr = ptr->_next;
        }
    }

    if(start != NULL) sa.len++;

    if(sa.len > 0){
        sa.strs = (String*)malloc(sa.len * sizeof(String));

        if(sa.strs == NULL){
            printf("\nString error at:\n");
            printf("\n`StringArray split(const String* self, const char c)`\n\n");
            printf("-> failed to allocate memory\n");
            exit(1);
        }

        sa.strs[0] = str_new();
        ptr = start;

        while(ptr != NULL){
            if(ptr->_c == c){
                do
                    ptr = ptr->_next;
                while(ptr != NULL && ptr->_c == c);

                if(ptr != NULL){
                    sa.strs[++index] = str_new();
                    sa.strs[index].push(&sa.strs[index], ptr->_c);
                    ptr = ptr->_next;
                }
            }else{
                sa.strs[index].push(&sa.strs[index], ptr->_c);
                ptr = ptr->_next;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void replace(String* self, const char old, const char replacement)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void replace(String* self, const char old, const char replacement)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL && ptr->_c != old) ptr = ptr->_next;
    if(ptr != NULL && ptr->_c == old) ptr->_c = replacement;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void replace_all(String* self, const char old, const char replacement)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void replace_all(String* self, const char old, const char replacement)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL){
        if(ptr->_c == old) ptr->_c = replacement;
        ptr = ptr->_next;
    }

    ptr = NULL;
}

/**
 * @brief Removes a char from a given index from the string
 * 
 * @param self String to be edited
 * @param index index where to remove char
 * @return removed char
 */
char str_remove(String* self, const size_t index){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`char remove(String* self, const size_t index)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(index >= self->len){
        printf("\nString error at:\n");
        printf("`char remove(String* self, const size_t index)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`char remove(String* self, const size_t index)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    char c = ' ';

    if(index == self->len - 1){
        c = self->_last->_c;
        self->_last = self->_last->_prev;
        self->_last->_free(self->_last->_next);
        self->_last->_next = NULL;
    }else{
        _StringCell* ptr = self->_first->_next;

        for(size_t i = 0; i < index; i++)
            ptr = ptr->_next;

        c = ptr->_c;
        ptr->_prev->_next = ptr->_next;
        ptr->_next->_prev = ptr->_prev;
        ptr->_free(ptr);
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
bool str_remove_char(String* self, const char c){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_char(String* self, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_char(String* self, const char c)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    bool removed = false;

    while(ptr != NULL && ptr->_c != c) ptr = ptr->_next;

    if(ptr != NULL && ptr->_c == c){
        if(ptr == self->_last){
            ptr = ptr->_prev;
            self->_last = ptr;
            ptr->_free(ptr->_next);

            ptr->_next = NULL;
            ptr = NULL;
        }else{
            ptr->_prev->_next = ptr->_next;

            if(ptr != self->_last)
                ptr->_next->_prev = ptr->_prev;
            
            ptr->_free(ptr);
        }

        self->len--;
        removed = true;
    }

    ptr = NULL;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int remove_all(String* self, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int remove_all(String* self, const char c)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr1 = self->_first->_next;
    _StringCell* ptr2 = NULL;
    int removed = 0;

    while(ptr1 != NULL){
        if(ptr1->_c == c){
            ptr2 = ptr1;
            ptr1 = ptr1->_next;

            if(ptr2 == self->_last){
                ptr2 = ptr2->_prev;
                self->_last = ptr2;
                ptr2->_free(ptr2->_next);

                ptr2->_next = NULL;
                ptr2 = NULL;
            }else{
                ptr2->_prev->_next = ptr2->_next;

                if(ptr2 != self->_last)
                    ptr2->_next->_prev = ptr2->_prev;
                
                ptr2->_free(ptr2);
            }

            self->len--;
            removed++;
        }else{
            ptr1 = ptr1->_next;
        }
    }

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
bool str_remove_str(String* self, const String* str){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(str == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* str)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* str)`\n\n");
        printf("-> first cell of string `str` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    bool removed = false;
    
    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->_first->_next;
        _StringCell* ptr2 = self->_first->_next;
        _StringCell* ptr3 = str->_first->_next;

        while(ptr1 != NULL && ptr2 != NULL && !removed){
            if(ptr1->_c == ptr3->_c){
                ptr2 = ptr1->_next;
                ptr3 = ptr3->_next;

                while(ptr2 != NULL && ptr3 != NULL){
                    if(ptr2->_c == ptr3->_c){
                        ptr2 = ptr2->_next;
                        ptr3 = ptr3->_next;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr2 == NULL && ptr3 == NULL){
                    ptr1 = ptr1->_prev;
                    ptr2 = self->_last;
                    self->_last = ptr1;
                    
                    while(ptr2 != ptr1){
                        ptr2 = ptr2->_prev;
                        ptr2->_free(ptr2->_next);
                    }

                    self->_last->_next = NULL;
                    removed = true;
                }else if(ptr3 == NULL){
                    ptr1 = ptr1->_prev;
                    ptr3 = ptr1->_next;
                    
                    while(ptr3 != ptr2){
                        ptr3 = ptr3->_next;
                        ptr3->_free(ptr3->_prev);
                    }

                    ptr1->_next = ptr2;
                    ptr2->_prev = ptr1;
                    removed = true;
                }else{
                    ptr3 = str->_first->_next;
                    ptr2 = ptr1;
                    ptr1 = ptr1->_next;
                }
            }else{
                ptr1 = ptr1->_next;
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
bool str_remove_chars(String* self, const char* chars){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_str(String* self, const String* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool remove_chars(String* self, const char* chars)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    bool removed = false;
    size_t len = __str_strlen(chars);
    
    if(!self->is_empty(self) && len > 0 && self->len >= len){
        _StringCell* ptr1 = self->_first->_next;
        _StringCell* ptr2 = self->_first->_next;
        _StringCell* ptr3 = NULL;
        size_t index = 0;

        while(ptr1 != NULL && ptr2 != NULL && !removed){
            if(ptr1->_c == chars[index]){
                ptr2 = ptr1->_next;
                index++;

                while(ptr2 != NULL && index < len){
                    if(ptr2->_c == chars[index]){
                        ptr2 = ptr2->_next;
                        index++;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr2 == NULL && index == len){
                    ptr1 = ptr1->_prev;
                    ptr2 = self->_last;
                    self->_last = ptr1;
                    
                    while(ptr2 != ptr1){
                        ptr2 = ptr2->_prev;
                        ptr2->_free(ptr2->_next);
                    }

                    self->_last->_next = NULL;
                    removed = true;
                }else if(index == len){
                    ptr1 = ptr1->_prev;
                    ptr3 = ptr1->_next;
                    
                    while(ptr3 != ptr2){
                        ptr3 = ptr3->_next;
                        ptr3->_free(ptr3->_prev);
                    }

                    ptr1->_next = ptr2;
                    ptr2->_prev = ptr1;
                    removed = true;
                }else{
                    index = 0;;
                    ptr2 = ptr1;
                    ptr1 = ptr1->_next;
                }
            }else{
                ptr1 = ptr1->_next;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`String drain(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(start > end){
        printf("\nString error at:\n");
        printf("`String drain(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> index `start` (%ld) is higher than `end` (%ld)\n", start, end);
        exit(1);
    }

    if(end > self->len){
        printf("\nString error at:\n");
        printf("`String drain(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", end, self->len);
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`String drain(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    String str = str_new();
    _StringCell* ptr1 = self->_first->_next;
    _StringCell* ptr2 = NULL;

    for(size_t i = 0; i < start; i++)
        ptr1 = ptr1->_next;

    ptr2 = ptr1;

    for(size_t i = start; i < end - 1; i++)
        ptr2 = ptr2->_next;
    
    str._first->_next = ptr1;
    str._last = ptr2;
    
    ptr1 = ptr1->_prev;
    if(ptr2 != NULL) ptr2 = ptr2->_next;

    if(ptr2 == NULL){
        self->_last = ptr1;
        ptr1->_next = NULL;
    }else{
        ptr1->_next = ptr2;
        ptr2->_prev = ptr1;
    }

    str._last->_next = NULL;
    str._first->_next->_prev = str._first;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void reap(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(start > end){
        printf("\nString error at:\n");
        printf("`void reap(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> index `start` (%ld) is higher than `end` (%ld)\n", start, end);
        exit(1);
    }

    if(end > self->len){
        printf("\nString error at:\n");
        printf("`void reap(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", end, self->len);
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void reap(String* self, const size_t start, const size_t end)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    for(size_t i = 0; i < start; i++){
        ptr = ptr->_next;
        ptr->_free(ptr->_prev);
    }

    self->_first->_next = ptr;
    ptr->_prev = self->_first;

    ptr = self->_last;

    for(size_t i = self->len; i > end; i--){
        ptr = ptr->_prev;
        ptr->_free(ptr->_next);
    }

    self->_last = ptr;
    self->_last->_next = NULL;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void insert(String* self, const size_t index, const char c)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(index > self->len){
        printf("\nString error at:\n");
        printf("`void insert(String* self, const size_t index, const char c)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    if(index == self->len){
        self->push(self, c);
    }else{
        _StringCell* ptr = self->_first;
        _StringCell* tmp = __strcell_new(c);

        for(size_t i = 0; i < index; i++) ptr = ptr->_next;

        tmp->_prev = ptr;
        tmp->_next = ptr->_next;

        tmp->_prev->_next = tmp;
        tmp->_next->_prev = tmp;

        self->len++;
        ptr = NULL;
        tmp = NULL;
    }
}

/**
 * @brief Inserts a string at a specific index on the string
 * 
 * @param self String to be edited
 * @param index where to insert substring
 * @param str substring array to be inserted
 */
void str_insert_str(String* self, const size_t index, const String* str){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void insert_str(String* self, const size_t index, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(str == NULL){
        printf("\nString error at:\n");
        printf("`void insert_str(String* self, const size_t index, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(index > self->len){
        printf("\nString error at:\n");
        printf("`void insert_str(String* self, const size_t index, const String* str)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`void insert_str(String* self, const size_t index, const String* str)`\n\n");
        printf("-> first cell of string `str` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(!str->is_empty(str)){
        if(index == self->len){
            self->push_str(self, str);
        }else{
            _StringCell* ptr1 = self->_first;
            _StringCell* ptr2 = NULL;
            _StringCell* ptr3 = str->_first->_next;

            for(size_t i = 0; i < index; i++) 
                ptr1 = ptr1->_next;

            ptr2 = ptr1->_next;

            for(size_t i = 0; i < str->len; i++){
                ptr1->_next = __strcell_new(ptr3->_c);
                ptr1->_next->_prev = ptr1;
                ptr1 = ptr1->_next;
                ptr3 = ptr3->_next;
            }

            ptr1->_next = ptr2;
            ptr2->_prev = ptr1;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void insert_chars(String* self, const size_t index, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`void insert_chars(String* self, const size_t index, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    if(index > self->len){
        printf("\nString error at:\n");
        printf("`void insert_chars(String* self, const size_t index, const char* chars)`\n\n");
        printf("-> index `%ld` invalid for length `%ld`\n", index, self->len);
        exit(1);
    }

    size_t len = __str_strlen(chars);

    if(len > 0){
        if(index == self->len){
            self->push_chars(self, chars);
        }else{
            _StringCell* ptr1 = self->_first;
            _StringCell* ptr2 = NULL;
            size_t chars_index = 0;

            for(size_t i = 0; i < index; i++) 
                ptr1 = ptr1->_next;

            ptr2 = ptr1->_next;

            for(size_t i = 0; i < len; i++){
                ptr1->_next = __strcell_new(chars[chars_index++]);
                ptr1->_next->_prev = ptr1;
                ptr1 = ptr1->_next;
            }

            ptr1->_next = ptr2;
            ptr2->_prev = ptr1;

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
bool str_starts_with_str(const String* self, const String* str){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_str(const String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(str == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_str(const String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `str` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    bool starts_with = false;

    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->_first->_next;
        _StringCell* ptr2 = str->_first->_next;

        while(ptr2 != NULL && ptr1->_c == ptr2->_c){
            ptr1 = ptr1->_next;
            ptr2 = ptr2->_next;
        }

        if(ptr2 == NULL)
            starts_with = true;

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
bool str_starts_with_chars(const String* self, const char* chars){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool starts_with_chars(const String* self, const char* chars)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    bool starts_with = false;
    size_t len = __str_strlen(chars);

    if(!self->is_empty(self) && len > 0 && self->len >= len){
        _StringCell* ptr = self->_first->_next;
        size_t i = 0;

        while(i < len && ptr->_c == chars[i]){
            ptr = ptr->_next;
            i++;
        }

        if(i >= len)
            starts_with = true;

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
bool str_ends_with_str(const String* self, const String* str){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool ends_with_str(const String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(str == NULL){
        printf("\nString error at:\n");
        printf("`bool ends_with_str(const String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    bool ends_with = false;

    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->_last;
        _StringCell* ptr2 = str->_last;

        while(ptr2 != str->_first && ptr1->_c == ptr2->_c){
            ptr1 = ptr1->_prev;
            ptr2 = ptr2->_prev;
        }

        if(ptr2 == str->_first)
            ends_with = true;

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
bool str_ends_with_chars(const String* self, const char* chars){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool ends_with_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`bool ends_with_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    bool ends_with = false;
    size_t i = __str_strlen(chars);

    if(!self->is_empty(self) && i > 0 && self->len >= i){
        _StringCell* ptr = self->_last;

        while(i > 0 && ptr->_c == chars[i - 1]){
            ptr = ptr->_prev;
            i--;
        }

        if(i == 0)
            ends_with = true;

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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int find_str(const String* self, const String* str)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(str == NULL){
        printf("\nString error at:\n");
        printf("`int find_str(const String* self, const String* str)`\n\n");
        printf("-> argument `str` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int find_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    if(str->_first == NULL){
        printf("\nString error at:\n");
        printf("`int find_str(const String* self, const String* str)`\n\n");
        printf("-> first cell of string `str` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    int index = -1;
    
    if(!self->is_empty(self) && !str->is_empty(str) && self->len >= str->len){
        _StringCell* ptr1 = self->_first->_next;
        _StringCell* ptr2 = self->_first->_next;
        _StringCell* ptr3 = str->_first->_next;

        while(ptr1 != NULL && ptr2 != NULL && ptr3 != NULL){
            index++;

            if(ptr1->_c == ptr3->_c){
                ptr2 = ptr1->_next;
                ptr3 = ptr3->_next;

                while(ptr2 != NULL && ptr3 != NULL){
                    if(ptr2->_c == ptr3->_c){
                        ptr2 = ptr2->_next;
                        ptr3 = ptr3->_next;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(ptr3 != NULL){
                    ptr3 = str->_first->_next;
                    ptr2 = ptr1;
                    ptr1 = ptr1->_next;
                }
            }else{
                ptr1 = ptr1->_next;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int find_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }
    
    if(chars == NULL){
        printf("\nString error at:\n");
        printf("`int find_chars(const String* self, const char* chars)`\n\n");
        printf("-> argument `chars` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int find_chars(const String* self, const char* chars)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    int index = -1;
    size_t len = __str_strlen(chars);
    
    if(!self->is_empty(self) && len && self->len >= len){
        _StringCell* ptr1 = self->_first->_next;
        _StringCell* ptr2 = self->_first->_next;
        size_t i = 0;

        while(ptr1 != NULL && ptr2 != NULL && i < len){
            index++;

            if(ptr1->_c == chars[i]){
                ptr2 = ptr1->_next;
                i++;

                while(ptr2 != NULL && i < len){
                    if(ptr2->_c == chars[i]){
                        ptr2 = ptr2->_next;
                        i++;
                    }else{
                        ptr2 = NULL;
                    }
                }

                if(i < len){
                    i = 0;
                    ptr2 = ptr1;
                    ptr1 = ptr1->_next;
                }
            }else{
                ptr1 = ptr1->_next;
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
bool str_contains_str(const String* self, const String* str){
    return str_find_str(self, str) != -1;
}

/**
 * @brief Searches the string for a given substring
 * 
 * @param self String to search substring
 * @param chars char array searched
 * @return true if substring is inside String, false otherwise
 */
bool str_contains_chars(const String* self, const char* chars){
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int* to_bytes(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`int* to_bytes(const String* self)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int* to_bytes(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }
    
    int* bytes = (int*)malloc(self->len * sizeof(int));

    if(bytes == NULL){
        printf("\nString error at:\n");
        printf("\n`int* to_bytes(const String* self)`\n\n");
        printf("-> failed to allocate memory\n");
        exit(1);
    }
    
    _StringCell* ptr = self->_first->_next;
    size_t i = 0;

    while(ptr != NULL){
        bytes[i++] = ptr->_c;
        ptr = ptr->_next;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`int parse_int(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`int parse_int(const String* self)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`int parse_int(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    int n = 0;
    bool negative = false;
    size_t steps = 1;
    size_t index = self->len;
    _StringCell* ptr = self->_last;

    while(ptr != self->_first->_next){
        if(!('0' <= ptr->_c && ptr->_c <= '9')){
            printf("\nString error at:\n");
            printf("`int parse_int(const String* self)`\n\n");
            printf("-> char at index `%ld` (%c) is not a number\n", index - 1, ptr->_c);
            exit(1);
        }

        n += (ptr->_c - 48) * steps;

        steps *= 10;
        index--;
        ptr = ptr->_prev;
    }

    ptr = self->_first->_next;
    
    if(ptr->_c == '-'){
        negative = true;
    }else if(self->_first->_next->_c != '+'){
        if(!('0' <= ptr->_c && ptr->_c <= '9')){
            printf("\nString error at:\n");
            printf("`int parse_int(const String* self)`\n\n");
            printf("-> char at index `%ld` (%c) is not a number\n", index - 1, ptr->_c);
            exit(1);
        }

        n += (ptr->_c - 48) * steps;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`double parse_double(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->is_empty(self)){
        printf("\nString error at:\n");
        printf("`double parse_double(const String* self)`\n\n");
        printf("-> string `self` is empty\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`double parse_double(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    double d = 0.0;
    bool negative = false;
    double steps = 1;
    size_t index = 0;

    if(ptr->_c == '-'){
        negative = true;
        ptr = ptr->_next;
    }else if(ptr->_c == '+'){
        ptr = ptr->_next;
    }

    while(ptr != NULL && ptr->_c != '.'){
        if(!('0' <= ptr->_c && ptr->_c <= '9') && ptr->_c != '.'){
            printf("\nString error at:\n");
            printf("`double parse_double(const String* self)`\n\n");
            printf("-> char at index `%ld` (%c) is not a number\n", index, ptr->_c);
            exit(1);
        }

        d *= steps;
        d += ptr->_c - 48;
        steps *= 10;
        
        index++;
        ptr = ptr->_next;
    }

    if(ptr != NULL && ptr->_c == '.'){
        ptr = ptr->_next;
        steps = 0.1;
        index++;
    }

    while(ptr != NULL){
        if(!('0' <= ptr->_c && ptr->_c <= '9')){
            printf("\nString error at:\n");
            printf("`double parse_double(const String* self)`\n\n");
            printf("-> char at index `%ld` (%c) is not a number\n", index, ptr->_c);
            exit(1);
        }

        d += (ptr->_c - 48) * steps;
        steps /= 10;

        index++;
        ptr = ptr->_next;
    }

    return negative ? d * -1 : d;
}

/**
 * @brief Parses the contend of the String if is a valid boolean
 * 
 * @param self String to be parsed
 * @return true if String is a valid true boolean, false otherwise
 */
bool str_parse_bool(const String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`bool parse_bool(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`bool parse_bool(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;
    bool b = false;

    if(ptr != NULL){
        if(self->len == 4 && 
          (ptr->_c == 'T' || ptr->_c == 't') &&
           ptr->_next != NULL && 
          (ptr->_next->_c == 'R' || ptr->_next->_c == 'r') &&
           ptr->_next->_next != NULL && 
          (ptr->_next->_next->_c == 'U' || ptr->_next->_next->_c == 'u') && 
           ptr->_next->_next->_next != NULL && 
          (ptr->_next->_next->_next->_c == 'E' || ptr->_next->_next->_next->_c == 'e')){

           b = true;
        }else if(self->len == 1 && ptr->_c == '1') b = true;
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
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void to_lowercase(String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void to_lowercase(String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL){
        if('A' <= ptr->_c && ptr->_c <= 'Z'){
            ptr->_c += 32;
        }

        ptr = ptr->_next;
    }
}

/**
 * @brief Turns every lower case letter in the string to upper case
 * 
 * @param self String to be edited
 */
void str_to_uppercase(String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void to_uppercase(String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`void to_uppercase(String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }

    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL){
        if('a' <= ptr->_c && ptr->_c <= 'z'){
            ptr->_c -= 32;
        }

        ptr = ptr->_next;
    }
}

/**
 * @brief Capitalizes every word on the string (i.e. `ab c def` -> `Ab C Def`)
 * 
 * @param self String to be titled
 */
void str_title(String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void title(String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    _StringCell* ptr = self->_first;

    while(ptr != NULL){
        do
            ptr = ptr->_next;
        while(ptr != NULL && (ptr->_c == ' ' || ptr->_c == '\r' || ptr->_c == '\n'));
        
        if(ptr != NULL){
            if('a' <= ptr->_c && ptr->_c <= 'z')
                ptr->_c -= 32;

            do
                ptr = ptr->_next;
            while(ptr != NULL && (ptr->_c != ' ' && ptr->_c != '\r' && ptr->_c != '\n'));
        }
    }
}

/**
 * @brief Capitalizes the string (i.e. `test` -> `Test`)
 * 
 * @param self String to be capitalized
 */
void str_capitalize(String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`void capitalize(String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    _StringCell* ptr = self->_first;

    do
        ptr = ptr->_next;
    while(ptr != NULL && (ptr->_c == ' ' || ptr->_c == '\r' || ptr->_c == '\n'));

    if(ptr != NULL && 'a' <= ptr->_c && ptr->_c <= 'z')
        ptr->_c -= 32;

    ptr = NULL;
}

/**
 * @brief Creates a clone of a given String
 * 
 * @param self String to be cloned
 * @return clone of String
 */
String str_clone(const String* self){
    if(self == NULL){
        printf("\nString error at:\n");
        printf("`String clone(const String* self)`\n\n");
        printf("-> argument `self` is null\n");
        exit(1);
    }

    if(self->_first == NULL){
        printf("\nString error at:\n");
        printf("`String clone(const String* self)`\n\n");
        printf("-> first cell of string `self` is null\n");
        printf("-> could this be because a constructor was not used?\n");
        printf("-> try using the method `String str_new()` to initialize a string\n");
        exit(1);
    }
    
    String str = str_new();
    _StringCell* ptr = self->_first->_next;

    while(ptr != NULL){
        str.push(&str, ptr->_c);
        ptr = ptr->_next;
    }

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
        _StringCell* ptr = self->_last;

        while(ptr != self->_first){
            ptr = ptr->_prev;
            ptr->_free(ptr->_next);
        }

        ptr->_free(ptr);
        ptr = NULL;

        self->_first = NULL;
        self->_last = NULL;

        self->is_empty = NULL;
        self->push = NULL;
        self->push_chars = NULL;
        self->push_str = NULL;
        self->nth = NULL;
        self->set = NULL;
        self->print = NULL;
        self->println = NULL;
        self->to_chars = NULL;
        self->find = NULL;
        self->contains = NULL;
        self->substring = NULL;
        self->trim = NULL;
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
size_t __str_strlen(const char* chars){
    size_t len = 0;

    while(chars[len]){
        len++;
    }

    return len;
}

#endif
