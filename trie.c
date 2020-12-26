# include "trie.h"
int i = 0;
node *create_node (char letter) {
    node *temp = (node *) malloc(sizeof(node));
    i += 1;
    printf("Malloc count: %i\n", i);
    temp->letter = letter;
    for (int i = 0; i < NUM_CHILD; ++i) {
        temp->childrens[i] = NULL;
    }
    return temp;
}
    
int get_index (char letter) {
    return letter - 97;
}

node *get_next (node *parent, char letter) {
    if (parent->childrens[get_index(letter)] != NULL) {
        return parent->childrens[get_index(letter)];
    }
    return NULL;
}

void join_nodes (node *parent, node *child) {
    if (parent->childrens[get_index(child->letter)] == NULL) {
        parent->childrens[get_index(child->letter)] = child;
    }
}

void insert_word (node *root, char *word) {
    int len = strlen(word);
    node *temp = root;
    for (int i = 0; i < len; ++i) {
        join_nodes(temp, create_node(word[i]));
        temp = get_next(temp, word[i]);
    }
}

void traverse (int start_index, node *root) {
    printf("%c", root->letter);
    traverse_helper(0, root);
}

void traverse_helper (int start_index, node *root) {
    for (int i = start_index; i < NUM_CHILD; ++i) {
        node *child = root->childrens[i];
        if (child) {
            printf("%c", child->letter);
            traverse_helper(0, child);
        }
    }
}

void free_tree (node *root) {
    for (int i = 0; i < NUM_CHILD; ++i) {
        node *child = root->childrens[i];
        if (child) 
            free_tree(child);
        free(child);
    }
}
