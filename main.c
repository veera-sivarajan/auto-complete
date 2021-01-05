# include "readfile.h"
# include "trie.h"
# include <readline/readline.h>
# include <readline/history.h>

int main (void) {
    node *root = create_node();
    char **words = read_file("input.txt");
    int i = 0;
    while (i < 39) {
        insert_word(root, words[i]);
        ++i;
    }
    free(words);
    while (1) {
        char *input = readline(">> ");
        if (strcmp(input, "exit") == 0) {
            break;
        }
        auto_complete(root, input); 
    }
    free_tree(root);
    free(root);
    return 0;
}
