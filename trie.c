# include "trie.h"

node *create_node () {
    node *temp = (node *) malloc(sizeof(node));
    if (temp) {
        for (int i = 0; i < NUM_CHILD; ++i) {
            temp->childrens[i] = NULL;
        }
        temp->EOW = num;
    }
    return temp;
}
    
int get_index (char letter) {
    return letter - 'a';
}

node *get_next (node *parent) {
}

void join_nodes (node *parent, node *child) {
}

// FIXME: new letters overwrites existing letter's EOW data 
void insert_word (node *root, char *word) {
}

void traverse (int start_index, node *root) {
}

void traverse_helper (int start_index, node *root) {
}

void free_tree (node *root) {
    for (int i = 0; i < NUM_CHILD; ++i) {
        node *child = root->childrens[i];
        if (child) 
            free_tree(child);
        free(child);
    }
}
