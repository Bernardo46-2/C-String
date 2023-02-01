#include "str.h"

int main(){
    String str1 = string_from("-a-bc  d - e- ");
    str1.println(&str1);
    StringArray strs = str1.split(&str1, ' ');
    char* chars = NULL;

    printf("%ld\n", strs.len);

    for(int i = 0; i < strs.len; i++){
        chars = strs.strs[i].to_chars(&strs.strs[i]);
        printf("'%s'\n", chars);
        free(chars);
    }

    String str2 = string_from("test");
    String str3 = string_from(" yo");
    str2.push_str(&str2, &str3);

    printf("%c %c\n", str2.get(&str2, 2), str2.get(&str2, 6));

    chars = str2.to_chars(&str2);
    printf("'%s'\n", chars);
    free(chars);

    str3.free(&str3);
    str3 = str2.clone(&str2);

    str2.capitalize(&str2);
    str3.title(&str3);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", chars);
    free(chars);

    chars = str3.to_chars(&str3);
    printf("'%s'\n", chars);
    free(chars);

    str2.free(&str2);
    str3.free(&str3);

    str2 = string_from("abcdefghi");
    str3 = str2.drain(&str2, 8, 9);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", chars);
    free(chars);
    
    chars = str3.to_chars(&str3);
    printf("'%s'\n", chars);
    free(chars);

    str1.free(&str1);
    str1 = string_from("abcdefghij");
    str1.reap(&str1, 0, 8);

    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    str1.free(&str1);
    str1 = string_from("  asd   \r\n");
    str1.trim(&str1);

    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    str2.free(&str2);
    str2 = str1.substring(&str1, 1, 3);

    chars = str2.to_chars(&str2);
    printf("'%s' %ld\n", chars, str2.len);
    free(chars);

    str1.free(&str1);
    str2.free(&str2);
    str3.free(&str3);

    str1 = string_from_size_t(121);
    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    str2 = string_from_double_with_precision(2.5, 6);
    chars = str2.to_chars(&str2);
    printf("'%s' %ld\n", chars, str2.len);
    free(chars);

    str3 = string_from_bool(0);
    chars = str3.to_chars(&str3);
    printf("'%s' %ld\n", chars, str3.len);
    free(chars);

    str1.free(&str1);
    str2.free(&str2);
    str3.free(&str3);

    str1 = string_from("  asd  ");
    str2 = str1.clone(&str1);
    str3 = str1.clone(&str1);
    str2.trim_left(&str2);
    str3.trim_right(&str3);

    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    chars = str2.to_chars(&str2);
    printf("'%s' %ld\n", chars, str2.len);
    free(chars);

    chars = str3.to_chars(&str3);
    printf("'%s' %ld\n", chars, str3.len);
    free(chars);

    str1.trim(&str1);
    printf("%c %c\n", str1.first(&str1), str1.last(&str1));
    str1.free(&str1);

    str2.free(&str2);
    str2 = string_from("yo");

    str1 = string_format("abc - %d%% - %ld - %f - %s - %c - %S\ndid it work?", 23, 100000000000, 2.5, "test", 'a', &str2);
    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    str1.remove_char(&str1, 'b');
    chars = str1.to_chars(&str1);
    printf("'%s' %ld\n", chars, str1.len);
    free(chars);

    str1.free(&str1);
    str2.free(&str2);
    str3.free(&str3);

    return 0;
}
