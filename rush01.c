#include <unistd.h>
#include <stdlib.h>

// This function counts how many "towers" are visible
// when we are looking from the left side of a row. Same if we reverse row.
// We can use it to check if our rows matches the hints.
// Example: [2, 1, 4, 3] -> count = 2
int visible_count(int *line, int len)
{
    int max = 0;
    int count = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        if (line[i] > max)
        {
            max = line[i];
            count++;
        }
    }
    return (count);
}

int main(int argc, char *argv[])
{
    // Check if we get only 2 arguments
    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return 0;
    }

    // Allocate memory for 16 hints (top, bottom, left, right)
    int *hints = malloc(16 * sizeof(int));

    // Parsing the input string and saving digits 1-4 into hints array
    int idx = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        char c = argv[1][i];
        if (c >= '1' && c <= '4')
        {
            if (idx >= 16)
            {
                write(1, "Error\n", 6);
                free(hints);
                return 0;
            }
            hints[idx++] = c - '0';
        }
        else if (c != ' ')
        {
            write(1, "Error\n", 6);
            free(hints);
            return 0;
        }
    }

    // Check if we have exactly 16 numbers
    if (idx != 16)
    {
        write(1, "Error\n", 6);
        free(hints);
        return 0;
    }

    // Create an empty 4x4 board with zeros, so we could change cell value by index.
    int board[4][4] = {0};

    // ++++Using solver, but we have to write func for it++++
    

    // Clean memory
    free(hints);
    return 0;
}
