# include "trie.h"

node *create_node (char letter) {
    node *temp = (node *) malloc(sizeof(node));
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
    parent->childrens[get_index(child->letter)] = child;
}

void insert_word (node *root, char *word) {
    int len = strlen(word);
    node *temp = root;
    for (int i = 0; i < len; ++i) {
        join_nodes(temp, create_node(word[i]));
        temp = get_next(temp, word[i]);
    }
}

void traverse (node *root, char next_letter) {
    node *child = get_next(root, next_letter);
    if (child) {
        printf("%c", child->letter);
    }
    printf("%c", child->childrens[get_index('e')]->letter);
}
        

