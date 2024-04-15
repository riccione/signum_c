/*
 * Signum is written on C with:
 * - vrg for cli args https://github.com/rdentato/vrg
 *
 *
 *
 */ 
#define VRGCLI
#include "vrg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sodium.h>

/* 
 * https://c-faq.com/lib/randrange.html
 */ 
int get_rand_num(int lo, int hi) {
    int r = rand();
    // int num = lo + r / (RAND_MAX / (hi - lo + 1) + 1); 
    int num = lo + r % (hi - lo + 1); 
    return num;
}

int get_rand_sodium(int lo, int hi) {
    if (sodium_init() < 0) {
        printf("PANIC: libsodium is not installed!");
        return 1;
    } else {
        // printf("sodium is available\n");
        // char my_str[32];
        // uint32_t my_int;
        // randombytes_buf(my_str, 32);
        // my_int = randombytes_uniform(10);
        // printf("%d\n", my_int);
        // printf("%d", randombytes_random());
        uint32_t rand = randombytes_random();
        int n = lo + rand % (hi - lo + 1); 
        return n;
    }
}

int main(int argc, char *argv[]) {
    int digit = 0;
    int len = 10;
    srand(time(0));
    vrgcli("vrg test app") {
        vrgarg("-h, --help\tDisplay help") {
            vrgusage();
        }
        vrgarg("-d, --digit\tGenerate digit PIN") {
            digit = 1;
        }
        vrgarg("-l, --len\tSet password length") {
            len = vrgarg;
        }
    }

    if (digit == 1) {
        int lo = 48;
        int hi = 57;

        char s[25];
        for(int i = 0; i < 25; i++) {
            int num = lo + rand() % (hi - lo + 1); 
            // s[i] = get_rand_num(lo, hi);
            s[i] = num;
        }
        printf("%s", s);
    }


    return 0;
}
