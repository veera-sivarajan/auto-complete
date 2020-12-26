# include "readfile.h"
# include "trie.h"

int main (void) {
    node *root = create_node('R');
    // char **words = read_file("input.txt");
    // int i = 0;
    // while (i < 39) {
    //     printf("WORD: %s\n", words[i]);
    //     free(words[i]);
    //     ++i;
    // }
    // free(words);
    insert_word(root, "apple");
    insert_word(root, "hello");
    insert_word(root, "boomer");
    insert_word(root, "bat");
    traverse(get_index('b'), root->childrens[get_index('b')]);
    free(root);
    return 0;
}
