#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment2.h"

//Problem 1 
int add_user_password(const char* file_name, const char* username, const char* password) {
    FILE* file = fopen(file_name, "rb");
    if (file != NULL) {
        int u_len, p_len;
        while (fread(&u_len, sizeof(int), 1, file) == 1) {
            char* f_user = malloc(u_len + 1);
            fread(f_user, 1, u_len, file);
            f_user[u_len] = '\0';

            fread(&p_len, sizeof(int), 1, file);
            if (strcmp(f_user, username) == 0) {
                free(f_user);
                fclose(file);
                return 0;
            }
            fseek(file, p_len, SEEK_CUR);
            free(f_user);
        }
        fclose(file);
    }
    file = fopen(file_name, "ab");
    if (!file) return 0;

    int u_len = strlen(username);
    int p_len = strlen(password);
    fwrite(&u_len, sizeof(int), 1, file);
    fwrite(username, 1, u_len, file);
    fwrite(&p_len, sizeof(int), 1, file);
    fwrite(password, 1, p_len, file);

    fclose(file);
    return 1;
}

int check_user_password(const char* file_name, const char* username, const char* password) {
    FILE* file = fopen(file_name, "rb");
    if (!file) return -1;

    int u_len, p_len;
    while (fread(&u_len, sizeof(int), 1, file) == 1) {
        char* f_user = malloc(u_len + 1);
        fread(f_user, 1, u_len, file);
        f_user[u_len] = '\0';

        fread(&p_len, sizeof(int), 1, file);
        char* f_pass = malloc(p_len + 1);
        fread(f_pass, 1, p_len, file);
        f_pass[p_len] = '\0';

        if (strcmp(f_user, username) == 0) {
            int match = (strcmp(f_pass, password) == 0);
            free(f_user);
            free(f_pass);
            fclose(file);
            return match ? 1 : -3;
        }
        free(f_user);
        free(f_pass);
    }
    fclose(file);
    return -2;
}

//Problem 2 
int fib3_p(unsigned int n, unsigned int p) {
    if (n == 0) return 0;
    if (n == 1) return 1 % p;
    if (n == 2) return 2 % p;

    unsigned int a = 0, b = 1, c = 2;
    for (unsigned int i = 3; i <= n; i++) {
        unsigned int next = (a + b + c) % p;
        a = b;
        b = c;
        c = next;
    }
    return c;
}
// Problem 3 
char* evolve(const char* state) {
    int len = strlen(state);
    char* next_state = malloc(len + 1);
    int* pos = malloc(sizeof(int) * len); 
    int* target = malloc(sizeof(int) * len); 
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (state[i] == '*') pos[count++] = i;
    }

    if (count <= 1) {
        strcpy(next_state, state);
        free(pos); free(target);
        return next_state; 
    }

    for (int i = 0; i < count; i++) {
        if (i == 0) target[i] = pos[i] + 1; 
        else if (i == count - 1) target[i] = pos[i] - 1; 
        else {
            int dist_l = pos[i] - pos[i-1];
            int dist_r = pos[i+1] - pos[i];
            if (dist_l < dist_r) target[i] = pos[i] - 1; 
            else if (dist_r < dist_l) target[i] = pos[i] + 1;
            else target[i] = -1;
        }
    }

    memset(next_state, '-', len);
    next_state[len] = '\0';
    for (int i = 0; i < count; i++) {
        if (target[i] == -1) continue;
        int collisions = 0;
        for (int j = 0; j < count; j++) {
            if (target[i] == target[j]) collisions++;
        }
        if (collisions == 1) next_state[target[i]] = '*';
    }
    free(pos); free(target);
    return next_state;
}

char* last_state(const char* state) {
    char* current = malloc(strlen(state) + 1);
    strcpy(current, state);
    while (1) {
        char* next = evolve(current);
        if (strcmp(current, next) == 0) {
            free(current);
            return next;
        }
        free(current);
        current = next;
    }
}