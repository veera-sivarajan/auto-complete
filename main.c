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
    char *word1 = (char *) malloc(20 * sizeof(char *));
    word1 = "appppple";
    char *word2 = (char *) malloc(20 * sizeof(char *));
    word2 = "akbar";
    insert_word(root, word1);
    insert_word(root, word2);
    auto_complete(root, "a"); 
    free_tree(root);
    free(root);
    return 0;
}
