#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_CAPACITY 4096

// A dynamically growing buffer to hold generated output
typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} Buffer;

int row = 0;

void buffer_init(Buffer *buf) {
    buf->capacity = INITIAL_CAPACITY;
    buf->size = 0;
    buf->data = malloc(buf->capacity);
    buf->data[0] = '\0';
}

void buffer_append(Buffer *buf, const char *str) {
    size_t len = strlen(str);
    if (buf->size + len + 1 >= buf->capacity) {
        buf->capacity *= 2;
        buf->data = realloc(buf->data, buf->capacity);
    }
    strcpy(buf->data + buf->size, str);
    buf->size += len;
}

void generate(char *symbols[], int n, int k, char *result[], int depth, Buffer *buf) {
    if (depth == k) {
        char temp[64];
        snprintf(temp, sizeof(temp), "Permutation %d:\t", row + 1);
        buffer_append(buf, temp);
        for (int i = 0; i < k; i++) {
            buffer_append(buf, result[i]);
            buffer_append(buf, " ");
        }
        buffer_append(buf, "\n");
        row++;
        return;
    }

    for (int i = 0; i < n; i++) {
        result[depth] = symbols[i];
        generate(symbols, n, k, result, depth + 1, buf);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <length> <symbols...>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int k = atoi(argv[1]);
    int n = argc - 2;
    char **symbols = &argv[2];
    unsigned long long count = pow(n, k);

    char **result = malloc(sizeof(char *) * k);
    Buffer buf;
    buffer_init(&buf);

    generate(symbols, n, k, result, 0, &buf);

    FILE *f = fopen("README.md", "w");
    if (!f) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    fprintf(f, "# Permutation Generator\n\n");
    fprintf(f, "This program generates all possible permutations of a given set of symbols with the given command\n");
    fprintf(f, "for a specified length `k`, allowing repetition.\n\n");
    fprintf(f, "**./permutations.exe 4 a b**");

    fprintf(f, "## Parameters\n");
    fprintf(f, "- Length (`k`): `%d`\n", k);
    fprintf(f, "- Symbols: ");
    for (int i = 0; i < n; i++) {
        fprintf(f, "`%s` ", symbols[i]);
    }
    fprintf(f, "\n\n");

    fprintf(f, "## Output\n\n");
    fprintf(f, "```\n");
    fprintf(f, "%s", buf.data);
    fprintf(f, "```\n\n");

    fprintf(f, "**Total permutations**: `%llu`\n", count);
    fclose(f);

    free(buf.data);
    free(result);
    return EXIT_SUCCESS;
}
