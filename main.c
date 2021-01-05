# include "readfile.h"
# include "trie.h"

int main (void) {
    node *root = create_node();
    char **words = read_file("input.txt");
    int i = 0;
    while (i < 39) {
        insert_word(root, words[i]);
        ++i;
    }
    free(words);
    auto_complete(root, "bl"); 
    free_tree(root);
    free(root);
    return 0;
}
