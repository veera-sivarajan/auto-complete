# include "readfile.h"
# include "trie.h"

int main (void) {
    char **words = read_file("input.txt");
    for (int i = 0; i < 39; ++i) {
        printf("Word: %s\n", words[i]);
    }
    return 0;
}
