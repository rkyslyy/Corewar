//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"


void	do_null(t_process *processor)
{
	int n = 0;

	processor->t_dir = 0;
	while (n < 9)
	{
		processor->arg1[n] = '\0';
		processor->arg2[n] = '\0';
		processor->arg3[n] = '\0';
		n++;
	}
}

char *ft_show_me_the_arg(t_process *pro, int arg)
{
	if (arg == 1)
		return (pro->arg1);
	else if (arg == 2)
		return (pro->arg2);
	else
		return (pro->arg3);
}

void readLittleShit(unsigned char map[],int tmp, t_process *pro, int arg)
{
	int n;
	char *arg1;

	n = 0;
	arg1 = ft_show_me_the_arg(pro, arg);
	if (tmp == 1)
	{
		while (n < 2)
			arg1[n++] = map[(pro->cur_pos + pro->iterator++) % (MEM_SIZE * 2)];
		if ((unsigned char) ft_ab(arg1, 16) > 16
			|| (unsigned char) ft_ab(arg1, 16) <= 0)
			pro->iC = 1;
	}
	else if (tmp == 3)
		while (n < 4)
			arg1[n++] = map[(pro->cur_pos + pro->iterator++) % (MEM_SIZE * 2)];
	else if (tmp == 2 && (pro->com2 == 14 || pro->com2 == 10 ||
						  (pro->com2 == 11 || pro->com2 == 9) ||
						  (pro->com2 == 12) || (pro->com2 == 15)))
	{
		pro->t_dir += arg;
		while (n < 4)
			arg1[n++] = map[(pro->cur_pos + pro->iterator++) % (MEM_SIZE * 2)];
	}
	else if (tmp == 2 && pro->com2 != 14 && pro->com2 != 10)
		while (n < 8)
			arg1[n++] = map[(pro->cur_pos + pro->iterator++) % (MEM_SIZE * 2)];
}

void	read_shit(unsigned char *map, t_process *processor)
{
	int		n;
	char 	tmp[3];
	char 	*bin;

	tmp[2] = '\0';
	do_null(processor);
	if (processor->codage == 0)
	{
		processor->iterator += 2;
		readLittleShit(map, 2, processor, 1);
	}
	else
	{
		tmp[0] = map[(processor->cur_pos + 2) % (MEM_SIZE * 2)];
		tmp[1] = map[(processor->cur_pos + 3) % (MEM_SIZE * 2)];
		processor->iterator += 4;
		n = ft_ab(tmp, 16);
		readLittleShit(map, saver(n, 8, 0), processor, 1);
		readLittleShit(map, saver(n, 8, 2), processor, 2);
		readLittleShit(map, saver(n, 8, 4), processor, 3);
	}
}
