# include "trie.h"
int i = 0;
node *create_node (char letter, int num) {
    node *temp = (node *) malloc(sizeof(node));
    i += 1;
    // printf("Malloc count: %i\n", i);
    temp->letter = letter;
    for (int i = 0; i < NUM_CHILD; ++i) {
        temp->childrens[i] = NULL;
    }
    temp->EOW = num;
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
    int index = get_index(child->letter);
    if (parent->childrens[index] == NULL) 
        parent->childrens[index] = child;
}

// FIXME: strings with same starting letter are inserted incorrectly
void insert_word (node *root, char *word) {
    int len = strlen(word);
    node *temp = root;
    for (int i = 0; i < len; ++i) {
        if (i == len - 1) {
            join_nodes(temp, create_node(word[i], 1));
            // temp = get_next(temp, word[i]);
        }
        else {
            join_nodes(temp, create_node(word[i], 0));
            temp = get_next(temp, word[i]);
        }
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
            if (child->EOW == 1) {
                printf("%c", child->letter);
                printf("\n");
                // traverse_helper(get_index(child->letter) + 1, root);
            }
            else if (child->EOW == 0) {
                printf("%c", child->letter);
                traverse_helper(0, child);
            }
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
