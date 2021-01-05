# include "trie.h"

node *create_node () {
    node *temp = (node *) malloc(sizeof(node));
    if (temp) {
        for (int i = 0; i < NUM_CHILD; ++i) {
            temp->childrens[i] = NULL;
        }
        temp->EOW = 0;
    }
    return temp;
}
    
int get_index (char letter) {
    return letter - 'a';
}

void insert_word (node *root, char *word) {
    int str_len = strlen(word);
    node *temp = root;
    int index;
    for (int i = 0; i < str_len; ++i) {
        index = get_index(word[i]);  
        if (!temp->childrens[index]) { // if child node does not exist
            temp->childrens[index] = create_node();
        }
        temp = temp->childrens[index];
    }
    temp->EOW = 1;
}

int traverse (node *root, char *word) {
    node *temp = root;
    int str_len = strlen(word);
    int index;
    for (int i = 0; i < str_len; ++i) {
        index = get_index(word[i]);
        if (!temp->childrens[index]) {
            return 0; 
        }
        temp = temp->childrens[index];
    }
    if (temp != NULL && temp->EOW)
        return 1;
    return 0;
}

void free_tree (node *root) {
    for (int i = 0; i < NUM_CHILD; ++i) {
        node *child = root->childrens[i];
        if (child) 
            free_tree(child);
        free(child);
    }
}
