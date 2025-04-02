#include "binary_trees.h"

/**
 * create_avl_node - Creates a new AVL tree node
 * @value: The value to put in the node
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *create_avl_node(int value)
{
    avl_t *new_node;

    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *build_avl(int *array, size_t start, size_t end, avl_t *parent)
{
    avl_t *root;
    size_t mid;

    /* Base case */
    if (start > end)
        return (NULL);

    /* Get the middle element as the root */
    mid = (start + end) / 2;
    root = create_avl_node(array[mid]);
    if (root == NULL)
        return (NULL);

    /* Set parent */
    root->parent = parent;

    /* Recursively build left subtree */
    if (start < mid)
        root->left = build_avl(array, start, mid - 1, root);

    /* Recursively build right subtree */
    if (mid < end)
        root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    /* Check for invalid inputs */
    if (array == NULL || size == 0)
        return (NULL);

    /* Build the AVL tree */
    return (build_avl(array, 0, size - 1, NULL));
