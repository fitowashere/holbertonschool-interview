#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, pos;

    /* Check for valid direction */
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /* First pass: slide all non-zero elements to the left */
        pos = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                /* Move the non-zero element to the leftmost available position */
                if (i != pos)
                {
                    line[pos] = line[i];
                    line[i] = 0;
                }
                pos++;
            }
        }

        /* Second pass: merge identical adjacent numbers */
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        /* Third pass: slide again after merging */
        pos = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != pos)
                {
                    line[pos] = line[i];
                    line[i] = 0;
                }
                pos++;
            }
        }
    }
    else /* SLIDE_RIGHT */
    {
        /* First pass: slide all non-zero elements to the right */
        pos = size - 1;
        for (i = size; i > 0; i--)
        {
            j = i - 1; /* Actual index for the array */
            if (line[j] != 0)
            {
                /* Move the non-zero element to the rightmost available position */
                if (j != pos)
                {
                    line[pos] = line[j];
                    line[j] = 0;
                }
                /* Move position to the left for next element */
                if (pos > 0)
                    pos--;
            }
        }

        /* Second pass: merge identical adjacent numbers */
        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }

        /* Third pass: slide again after merging */
        pos = size - 1;
        for (i = size; i > 0; i--)
        {
            j = i - 1; /* Actual index for the array */
            if (line[j] != 0)
            {
                if (j != pos)
                {
                    line[pos] = line[j];
                    line[j] = 0;
                }
                /* Move position to the left for next element */
                if (pos > 0)
                    pos--;
            }
        }
    }

    return (1);
}
