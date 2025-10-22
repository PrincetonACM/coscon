//Compiled with `c99 chal0.c -o chal0 -no-pie -fno-stack-protector`

#include <stdio.h>
#include <string.h>

void useful_gadgets() {
    __asm__("pop %rsi\n\t"
        "pop %rdi\n\t"
        "ret\n\t");
}

void secret_function(int key1, int key2) {
    if (key1 == 1337 && key2 == 64) {

        char key_str[10];
        int key_int = key1 * key2;
        sprintf(key_str, "%d", key_int);

        FILE *fptr;
        char flag_file[30] = "flag";
        strcat(flag_file, key_str);

        fptr = fopen(flag_file, "r");
        char flag[50];
        fgets(flag, 50, fptr);

        puts("well done!");
        puts(flag);
    } else {
        puts("impressive! but not quite...");
    }
}

int main() {

    char last_words[30];

    puts("You'll never reach my secret function!");
    puts("Any last words?");

    gets(last_words);

    puts("Goodbye!");

    return 0;
}