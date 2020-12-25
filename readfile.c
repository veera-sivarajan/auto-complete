# include "readfile.h"

void read_file (char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return;
    char *word = (char *) malloc(1024);
    while (fscanf(file, "%s\n", word) != EOF) {
        printf("Output: %s\n", word);
    }
    fclose(file);
}
        
