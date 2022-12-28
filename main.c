#include "str.h"

int main(){
    String str1 = str_from("-a-bc  d - e- ");
    StringArray strs = str1.split(&str1, ' ');
    char* chars = NULL;

    printf("%ld\n", strs.len);

    for(int i = 0; i < strs.len; i++){
        chars = strs.strs[i].to_chars(&strs.strs[i]);
        printf("'%s'\n", chars);
        free(chars);
    }

    String str2 = str_from("test");
    String str3 = str_from(" yo");
    str2.push_str(&str2, &str3);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", chars);
    free(chars);
    
    str3.free(&str3);
    str3 = str2.clone(&str2);

    str2.capitalize(&str2);
    str3.title(&str3);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", str2.to_chars(&str2));
    free(chars);

    chars = str3.to_chars(&str3);
    printf("'%s'\n", str3.to_chars(&str3));
    free(chars);

    str2.free(&str2);
    str3.free(&str3);

    str2 = str_from("abcdefghi");
    str3 = str2.drain(&str2, 8, 9);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", str2.to_chars(&str2));
    free(chars);
    
    chars = str3.to_chars(&str3);
    printf("'%s'\n", str3.to_chars(&str3));
    free(chars);

    str1.free(&str1);
    str1 = str_from("abcdefghij");
    str1.reap(&str1, 0, 8);

    chars = str1.to_chars(&str1);
    printf("'%s'\n", str1.to_chars(&str1));
    printf("%ld\n", str1.len);
    free(chars);

    str1.free(&str1);
    str1 = str_from("  asd   \r\n");
    str1.trim(&str1);

    chars = str1.to_chars(&str1);
    printf("'%s'\n", str1.to_chars(&str1));
    printf("%ld\n", str1.len);
    free(chars);

    str2.free(&str2);
    str2 = str1.substring(&str1, 1, 3);

    chars = str2.to_chars(&str2);
    printf("'%s'\n", str2.to_chars(&str2));
    printf("%ld\n", str2.len);
    free(chars);

    str1.free(&str1);
    str2.free(&str2);
    str3.free(&str3);

    return 0;
}