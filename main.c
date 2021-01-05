# include "readfile.h"
# include "trie.h"

int main (void) {
    node *root = create_node();
    // char **words = read_file("input.txt");
    // int i = 0;
    // while (i < 39) {
    //     printf("WORD: %s\n", words[i]);
    //     free(words[i]);
    //     ++i;
    // }
    // free(words);
    insert_word(root, "apple");
    insert_word(root, "akbar");
    insert_word(root, "birbal");
    auto_complete(root, "a"); 
    free_tree(root);
    free(root);
    return 0;
}
