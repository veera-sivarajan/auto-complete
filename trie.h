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

int contains (node *root, char *word);

int last_node (node *root);

char itoc (int num);

void suggest (node *root, char prefix[50]);

int auto_complete (node *root, char *word);

void free_tree (node *root);
