# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NUM_CHILD 26

typedef struct Node {
    char letter;
    struct Node *childrens[NUM_CHILD];
} node;

node *create_node (char letter);
    
int get_index (char letter);
    
node *get_next (node *parent, char letter);
    
void join_nodes (node *parent, node *child);

void insert_word (node *root, char *word);
