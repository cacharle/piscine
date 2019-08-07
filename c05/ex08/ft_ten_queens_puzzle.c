#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BOARD_SIZE 10
#define ABS(x) (x < 0 ? -(x) : x)

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

static void print_cols(int cols[BOARD_SIZE])
{
    int i;

    i = 0;
    while (i < BOARD_SIZE)
        ft_putchar(cols[i++] + '0');
    ft_putchar('\n');
}

static int  valid_position(int cols[BOARD_SIZE], int x, int y)
{
    int i;

    i = 0;
    while (i < x)
    {
        if (y == cols[i])
            return (FALSE);
        if (ABS(x - i) == ABS(y - cols[i]))
            return (FALSE);
        i++;
    }
    return (TRUE);
}

static  void    solve(int cols[BOARD_SIZE], int x, int *solution_counter)
{
    int i;

    if (x == BOARD_SIZE)
    {
        print_cols(cols);
        (*solution_counter)++;
        return ;
    }
    i = -1;
    while (++i < BOARD_SIZE)
    {
        if (!valid_position(cols, x, i))
            continue ;
        cols[x] = i;
        solve(cols, x + 1, solution_counter);
    }
}

int             ft_ten_queens_puzzle(void)
{
    int solution_counter;
    int cols[BOARD_SIZE];

    solution_counter = 0;
    solve(cols, 0, &solution_counter);
    return (solution_counter);
}
