#include "libft/libft.h"
#include "push_swap.h"

static int add_cmd_to_queue(t_list **cmds, enum e_pscmd cmd)
{
    t_list *new_elem;
    enum e_pscmd *ptr_cmd;

    ptr_cmd = malloc(sizeof(enum e_pscmd));
    if (!ptr_cmd)
        return 1;

    new_elem = ft_lstnew(ptr_cmd);
    if (!new_elem)
    {
        free(ptr_cmd);
        return 1;
    }
    ft_lstadd_back(cmds, new_elem);
    return 0;
}

void run_command(t_list **stack_a, t_list **stack_b, t_list **cmds, enum e_pscmd cmd)
{
    if (cmd == SA)
        ;
    else if (cmd == SB)
        ;
    else if (cmd == SS)
        ;
    else if (cmd == PA)
        ;
    else if (cmd == PB)
        ;
    else if (cmd == RA)
        ;
    else if (cmd == RB)
        ;
    else if (cmd == RR)
        ;
    else if (cmd == RRA)
        ;
    else if (cmd == RRB)
        ;
    else if (cmd == RRR)
        ;
    add_cmd_to_queue(cmds, cmd);
}
