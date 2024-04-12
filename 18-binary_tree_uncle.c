#include "binary_trees.h"

/**
 * binary_tree_uncle - Find uncle of  node
 * @node: a PTR > node to find uncle
 *
 * Return: pointer > uncle node
 *         NULL = node is NULL
 *         NULL =  parent is NULL
 *         NULL = the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (!node || !node->parent)
return (NULL);
return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Find sibling of a node
 * @node: pointer > node to find the sibling
 *
 * Return: pointer > sibling node
 *         NULL = node is NULL
 *         NULL = parent is NULL
 *         NULL =has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (!node || !node->parent)
return (NULL);
if (node == node->parent->left)
return (node->parent->right);
return (node->parent->left);
}
