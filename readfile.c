# include "readfile.h"
# include "string.h"

char **read_file (char *filename) {
    char *all_words[39];
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;
    char *word = calloc(sizeof(char *), 1000);
    while (fscanf(file, "%s\n", word) != EOF) {
        all_words[count] = (char *) malloc(sizeof(char *) * 1000);
        strcpy(all_words[count], word);
        count += 1;
    }
    fclose(file);
    return &all_words;
}
        
