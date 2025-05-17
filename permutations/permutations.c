#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_CAPACITY 4096

// A dynamically growing buffer to hold generated output
int row = 0;
typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} Buffer;

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
        buffer_append(buf, "\n\n");
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

    FILE *f = fopen("README.md", "w");
    if (!f) {
        perror("Failed to open file");
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

    fprintf(f, "# Output\n");
    fprintf(f, "-----------------------\n");
    fprintf(f, "%s", buf.data);
    fprintf(f, "-----------------------\n");
    fprintf(f, "Total permutations: %llu\n", count);
    fclose(f);

    free(buf.data);
    free(result);
    return EXIT_SUCCESS;
}
