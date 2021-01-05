# include "readfile.h"
# include "trie.h"

int main (void) {
    node *root = create_node('R', 0);
    // char **words = read_file("input.txt");
    // int i = 0;
    // while (i < 39) {
    //     printf("WORD: %s\n", words[i]);
    //     free(words[i]);
    //     ++i;
    // }
    // free(words);
    insert_word(root, "boner");
    insert_word(root, "bo");
    traverse(get_index('b'), root->childrens[get_index('b')]);
    free_tree(root);
    free(root);
    return 0;
}
