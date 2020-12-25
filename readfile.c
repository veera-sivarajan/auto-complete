# include "readfile.h"

char **read_file (char *filename) {
    char *all_words[39];
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;
    char *word = (char *) malloc(1024);
    while (fscanf(file, "%s\n", word) != EOF) {
        // printf("Output: %s\n", word);
        all_words[count] = word;
        count += 1;
    }
    fclose(file);
    return &all_words[0];
}
        
