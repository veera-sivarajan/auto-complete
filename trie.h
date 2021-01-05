# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define NUM_CHILD 26

typedef struct Node {
    struct Node *childrens[NUM_CHILD];
    int EOW;
} node;

node *create_node (char letter, int num);
    
int get_index (char letter);
    
node *get_next (node *parent, char letter);
    
void join_nodes (node *parent, node *child);

void insert_word (node *root, char *word);

void traverse (int start_index, node *root);

void traverse_helper (int start_index, node *root);

void free_tree (node *root);
