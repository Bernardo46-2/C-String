# C-String

My implementation of strings in C using linked lists (because I like linked lists)

## How to use

- Methods prefixed with `string_` are constructors and should always be used when initializing a string

- Methods prefixed with `str_` act upon a initialized string and can be called directly or from their respective pointers inside the struct string (thus not needing the `str_` prefix)

- Structs and attributes prefixed with `_` or `__` are supposed to be protected/private and should not be used directly

- Methods that interact with another string have two different implementations: one for interacting with a char* and other for a String* (e.g. `str_compare_to_str(const String*, const String*)` and `str_compare_to_chars(const String*, const char*)`)

- Everything is written in a single .h file due to laziness but it's all organized to be really easy to move the functions implementations to a .c file if one wishes to do so

- What each method does is documented on the .h file
