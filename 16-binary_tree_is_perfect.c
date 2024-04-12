#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t height = 0, nodes = 0, perfect_nodes = 0;
if (!tree)
return (0);
if (!tree->left && !tree->right)
return (1);
height = tree_height(tree);
nodes = tree_size(tree);
perfect_nodes = pow_recur(2, height + 1) - 1;
return (perfect_nodes == nodes);
}

/**
 * pow_recur - Returns the value of x raised to the power of y
 * @x: The base value
 * @y: The exponent value
 *
 * Return: x raised to the power of y
 */
int pow_recur(int x, int y)
{
if (y < 0)
return (-1);
if (y == 0)
return (1);
else
return (x * pow_recur(x, y - 1));
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: The binary tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: The binary tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
size_t height_l = 0, height_r = 0;
if (!tree)
return (0);
height_l = tree->left ? 1 + tree_height(tree->left) : 0;
height_r = tree->right ? 1 + tree_height(tree->right) : 0;
return (height_l > height_r ? height_l : height_r);
}

