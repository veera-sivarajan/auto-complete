# include "readfile.h"
# include "trie.h"
# include <readline/readline.h>
# include <readline/history.h>

# define NUM_WORDS 39

int main (void) {
    node *root = create_node();
    char **words = read_file("input.txt");
    char *input;
    for (int i = 0; i < NUM_WORDS; ++i) {
        insert_word(root, words[i]);
    }
    while (1) {
        input = readline(">> ");
        if (strcmp(input, "exit") == 0) {
            break;
        }
        auto_complete(root, input); 
        free(input);
    }
    for (int i = 0; i < NUM_WORDS; ++i) {
        free(words[i]);
    }
    free(words);
    free_tree(root);
    free(root);
    return 0;
}
