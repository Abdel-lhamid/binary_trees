#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *curr, *parent, *new_node;
if (tree == NULL)
return (NULL);
curr = *tree;
parent = NULL;
while (curr != NULL)
{
parent = curr;
if (value < curr->n)
curr = curr->left;
else if (value > curr->n)
curr = curr->right;
else
return (NULL);
}
new_node = binary_tree_node(parent, value);
if (new_node == NULL)
return (NULL);
if (parent == NULL)
*tree = new_node;
else if (value < parent->n)
parent->left = new_node;
else
parent->right = new_node;
return (new_node);
}

