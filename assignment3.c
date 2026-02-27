#include "assignment3.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* --- Problem 1: Tokenization --- */
int count_tokens(const char* str, char delim) {
    if (str == NULL) return 0;
    
    int count = 0;
    bool in_token = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delim) {
            if (!in_token) {
                count++;
                in_token = true;
            }
        } else {
            in_token = false;
        }
    }
    return count;
}

char** get_tokens(const char* str, char delim) {
    int num_tokens = count_tokens(str, delim);
    char** tokens = (char**)malloc((num_tokens + 1) * sizeof(char*));
    if (tokens == NULL) return NULL;

    int token_idx = 0;
    const char* p = str;
    while (*p != '\0') {
        while (*p == delim && *p != '\0') p++;
        
        if (*p != '\0') {
            const char* start = p;
            while (*p != delim && *p != '\0') p++;
            int length = p - start;
            tokens[token_idx] = (char*)malloc((length + 1) * sizeof(char));
            if (tokens[token_idx] == NULL) {
                for (int i = 0; i < token_idx; i++) free(tokens[i]);
                free(tokens);
                return NULL;
            }
            strncpy(tokens[token_idx], start, length);
            tokens[token_idx][length] = '\0';
            token_idx++;
        }
    }
    tokens[token_idx] = NULL;
    return tokens;
}

/* --- Problem 2: Array Utilities --- */

int find(int* A, int n, bool (*pred)(int)) {
    for (int i = 0; i < n; i++) {
        if (pred(A[i])) return i;
    }
    return -1;
}

int count(int* A, int n, bool (*pred)(int)) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (pred(A[i])) total++;
    }
    return total;
}

void map(int* A, int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        A[i] = f(A[i]);
    }
}

int reduce(int* A, int n, int (*f)(int, int)) {
    if (n <= 0) return 0;
    int accumulator = A[0];
    for (int i = 1; i < n; i++) {
        accumulator = f(accumulator, A[i]);
    }
    return accumulator;
}

/* --- Problem 3: Generic Insertion Sort --- */

int gen_insertion_sort(void* array, int n, size_t size, int (*compare)(const void*, const void*)) {
    int total_swaps = 0;
    char* base = (char*)array;
    void* key = malloc(size);
    if (!key) return 0;

    for (int i = 1; i < n; i++) {
        memcpy(key, base + (i * size), size);
        int j = i - 1;
        
        while (j >= 0 && compare(base + (j * size), key) > 0) {
            memcpy(base + ((j + 1) * size), base + (j * size), size);
            total_swaps++;
            j--;
        }
        memcpy(base + ((j + 1) * size), key, size);
    }
    
    free(key);
    return total_swaps;
}

/* --- Problem 4: String Sorting --- */

void sort_strings(const char* A[], int n) {
    for (int i = 1; i < n; i++) {
        const char* key = A[i];
        int j = i - 1;
        
        while (j >= 0) {
            size_t len_j = strlen(A[j]);
            size_t len_key = strlen(key);
            bool move = false;

            if (len_j > len_key) {
                move = true; 
            } else if (len_j == len_key && strcmp(A[j], key) > 0) {
                move = true; 
            }

            if (move) {
                A[j + 1] = A[j];
                j--;
            } else {
                break;
            }
        }
        A[j + 1] = key;
    }
}