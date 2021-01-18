#include<stdio.h>

int check_line(int tab[9][9], int line, int min)//returns the right value for the case from line angle
{
	int k;
	int i;

	k = 0;
	while (++k < 10)
	{
		i = -1;
		while (++i < 9)
			if (k == tab[line][i])//changed from line + i
				break ;
		if (i == 9 && k > min)
			return (k);
	}
	return (-1);
}

int check_col(int tab[9][9], int col, int k)
{
	int i;

	i = -1;
	while (++i < 9)
		if (k == tab[i][col])
			return (0);
	return (1);
}

int check_sq(int tab[9][9], int line, int col, int k)
{
	int i;
	int j;
	int l;
	int c;

	l = line / 3 * 3;
	c = col / 3 * 3;
	i = l - 1;
	while (++i < l + 3)
	{
		j = c - 1;
		while (++j < c + 3)
			if (k == tab[i][j])
				return (0);
	}
	return (1);
}

int check(int tab[9][9], int line, int col , int min)
{
	int k;

	k = check_line(tab, line, min);
	while (k != -1)
	{
		if (check_col(tab, col, k) && check_sq(tab, line, col, k))
			return (k);
		k = check_line(tab, line, k);
	}
	return (-1);
}

int solve_case(int tab[9][9], int line, int col)
{
	int k;

	if (tab[line][col] != 0)
	{
		if (col < 8)		
			return (solve_case(tab, line, col + 1));
		else if (line < 8)
			return (solve_case(tab, line + 1, 0));
		else
			return (1);
	}
	else
	{
		k = check(tab, line, col, 0);
		while (k != -1)
		{	
			tab[line][col] = k;
			if (col < 8)
			{
				if (solve_case(tab, line, col +  1))
					return (1);
			}
			else if (line < 8)
			{
				if (solve_case(tab, line + 1, 0))
					return (1);
			}
			else
				return (1);
			k = check(tab, line, col, k);
		}
	}
	tab[line][col] = 0;
	return (0);
}

void solve(int tab[9][9])
{
	//int l;
	
	solve_case(tab, 0, 0);
}
