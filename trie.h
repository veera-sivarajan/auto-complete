# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NUM_CHILD 26

typedef struct Node {
    struct Node *childrens[NUM_CHILD];
    int EOW;
} node;

node *create_node ();
    
int get_index (char letter);
    
void insert_word (node *root, char *word);

int traverse (node *root, char *word);

void free_tree (node *root);
