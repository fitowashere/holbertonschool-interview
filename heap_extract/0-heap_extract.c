#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t heap_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_last_node - finds the last level-order node in a heap
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 * @level: current level in the tree
 * @current_index: current index in the level
 *
 * Return: Pointer to the last node
 */
binary_tree_t *get_last_node(binary_tree_t *root, size_t size, size_t level, size_t current_index)
{
    binary_tree_t *left, *right;

    if (current_index == size)
        return (root);

    if (current_index + (1 << level) > size)
    {
        left = get_last_node(root->left, size, level - 1, current_index + 1);
        if (left)
            return (left);
        return (NULL);
    }
    else
    {
        right = get_last_node(root->right, size, level - 1, 
                          current_index + (1 << level));
        if (right)
            return (right);
        left = get_last_node(root->left, size, level - 1, current_index + 1);
        if (left)
            return (left);
        return (NULL);
    }
}

/**
 * find_last_node - wrapper to find the last level-order node
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 *
 * Return: Pointer to the last node
 */
binary_tree_t *find_last_node(binary_tree_t *root, size_t size)
{
    size_t height = 0;
    size_t tree_size = size;

    /* Calculate the height of the tree */
    while (tree_size > 1)
    {
        tree_size >>= 1;
        height++;
    }

    return (get_last_node(root, size, height, 1));
}

/**
 * sift_down - fixes a max heap by sifting down the root
 * @root: pointer to the root node of the heap
 *
 * Return: Pointer to the new root node
 */
binary_tree_t *sift_down(binary_tree_t *root)
{
    binary_tree_t *current = root;
    binary_tree_t *largest = NULL;
    int temp;

    while (1)
    {
        largest = current;

        if (current->left && current->left->n > largest->n)
            largest = current->left;
        if (current->right && current->right->n > largest->n)
            largest = current->right;

        if (largest == current)
            break;

        /* Swap values */
        temp = current->n;
        current->n = largest->n;
        largest->n = temp;

        current = largest;
    }

    return (root);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(binary_tree_t **root)
{
    int extracted_value;
    binary_tree_t *last_node;
    size_t size;

    if (!root || !*root)
        return (0);

    /* Get the value to return */
    extracted_value = (*root)->n;

    /* Get the size of the heap */
    size = heap_size(*root);

    /* If there's only one node, free it and return the value */
    if (size == 1)
    {
        free(*root);
        *root = NULL;
        return (extracted_value);
    }

    /* Find the last node in level-order traversal */
    last_node = find_last_node(*root, size);
    if (!last_node)
        return (0);

    /* Replace root's value with last node's value */
    (*root)->n = last_node->n;

    /* Remove the last node */
    if (last_node->parent)
    {
        if (last_node->parent->right == last_node)
            last_node->parent->right = NULL;
        else
            last_node->parent->left = NULL;
    }

    /* Free the last node */
    free(last_node);

    /* Rebuild the heap */
    *root = sift_down(*root);

    return (extracted_value);
}
