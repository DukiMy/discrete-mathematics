#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SYMBOLS 100
#define MAX_LENGTH 100

int input_symbols(char *input_line, char *symbols[]) {
    int symbol_count = 0;
    char *token;

    printf("Input space-separated symbols: ");
    fgets(input_line, MAX_LENGTH, stdin);
    input_line[strcspn(input_line, "\n")] = '\0';
    token = strtok(input_line, " ");

    while (token != NULL && symbol_count < MAX_SYMBOLS) {
        symbols[symbol_count++] = strdup(token);
        token = strtok(NULL, " ");
    }

    return symbol_count;
}

int input_length(char *input_line) {
    printf("Input length of permutations (k): ");
    fgets(input_line, MAX_LENGTH, stdin);
    return atoi(input_line);
}

static void recurse(char *symbols[], int n, int k, char *result[], char **permutations, int depth, int *row) {
    if (depth == k) {
        char *line = malloc((k > 0 ? k : 1) * MAX_LENGTH);
        if (!line) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        line[0] = '\0';

        for (int i = 0; i < k; i++) {
            strcat(line, result[i]);
            if (i < k - 1) strcat(line, " ");
        }

        permutations[(*row)++] = line;
        return;
    }

    for (int i = 0; i < n; i++) {
        result[depth] = symbols[i];
        recurse(symbols, n, k, result, permutations, depth + 1, row);
    }
}

char **generate(char *symbols[], int n, int k, int *total) {
    if (k <= 0 || n <= 0) {
        *total = 0;
        return NULL;
    }

    unsigned long long count = (unsigned long long)pow(n, k);
    *total = (int)count;

    char **permutations = malloc(sizeof(char *) * count);
    char **result = malloc(sizeof(char *) * k);
    int row = 0;

    recurse(symbols, n, k, result, permutations, 0, &row);

    free(result);
    return permutations;
}

char **create_task(int *out_count) {
    char input_line[MAX_LENGTH];
    char *symbols[MAX_SYMBOLS];

    int symbol_count = input_symbols(input_line, symbols);
    int k = input_length(input_line);

    if (symbol_count <= 0 || k <= 0) {
        fprintf(stderr, "Invalid input. Aborting.\n");
        *out_count = 0;
        return NULL;
    }

    printf("\nGenerating permutations of length %d from %d symbols:\n", k, symbol_count);
    char **perms = generate(symbols, symbol_count, k, out_count);

    for (int i = 0; i < symbol_count; i++) {
        free(symbols[i]);
    }

    return perms;
}

void tasks_do(char **perms, int count) {
    if (!perms || count <= 0) {
        printf("No permutations to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d:\t%s\n", i + 1, perms[i]);
        free(perms[i]);
    }
    free(perms);
}

int main() {
    int count;
    char **results = create_task(&count);
    tasks_do(results, count);
    free(results);
    return EXIT_SUCCESS;
}
