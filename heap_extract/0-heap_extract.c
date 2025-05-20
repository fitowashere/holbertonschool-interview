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
 * find_last_node - finds the last level-order node in a heap
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root, size_t size)
{
    heap_t *last = NULL;
    size_t pos = 0;
    size_t bit = 0;

    if (!root || size == 0)
        return (NULL);

    /* Find the position of the last node using binary representation */
    bit = 1 << (sizeof(size_t) * 8 - 1);
    while (!(bit & size))
        bit >>= 1;
    bit >>= 1;  /* Skip the leftmost bit which is for the root */

    last = root;
    while (bit)
    {
        if (size & bit)
            last = last->right;
        else
            last = last->left;
        bit >>= 1;
    }

    return (last);
}

/**
 * sift_down - fixes a max heap by sifting down the root
 * @root: pointer to the root node of the heap
 *
 * Return: Pointer to the new root node
 */
heap_t *sift_down(heap_t *root)
{
    heap_t *current = root;
    heap_t *largest = NULL;
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
int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *last_node;
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
