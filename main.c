# include "readfile.h"
# include "trie.h"

int main (void) {
    char **words = read_file("input.txt");
    int i = 0;
    while (i < 39) {
        printf("WORD: %s\n", words[i]);
        ++i;
    }
    return 0;
}
