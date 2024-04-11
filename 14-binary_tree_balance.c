#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_h = 0, r_h = 0;

		if (tree->right)
			r_h = 1 + binary_tree_height(tree->right);
		if (tree->left)
			l_h = 1 + binary_tree_height(tree->left);

		return ((r_h > l_h) ? r_h : l_h);
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: balance factor
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t r_h = 0, l_h = 0;
	if (!tree)
		return (0);
	if (tree->right)
		r_h = 1 + binary_tree_height(tree->right);
	if (tree->left)
		l_h = 1 + binary_tree_height(tree->left);
	return ((int) l_h - r_h);
}
