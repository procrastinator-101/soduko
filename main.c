#include <stdio.h>


void disp(int tab[9][9]);
void solve(int tab[9][9]);

int main(int argc, char **argv)
{
	int tab[9][9];

	if (argc < 10)
		return (0);
	else
	{
		for (int i = 0; i < 9; i++)
                {
                        for (int j = 0; j < 9; j++)
				tab[i][j] = argv[i + 1][j] - 48;
                }
		disp(tab);
		solve(tab);
		disp(tab);
	}
	return (0);
}



void disp(int tab[9][9])
{
	int l;

	l = 75;
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			if (i > 0)
				printf("||");
			else
				printf("//");
			for (int j = 0; j < l - 2; j++)
                    		printf("/");
			printf("\n");
		}
		else
		{
	 		printf("|| ");
			for (int j = 0; j < l - 3; j++)
                        	printf(".");
			printf("\n");
		}
		printf("|| ");
		for (int j = 0; j < 9; j++)
      		{
     			printf("%d   ", tab[i][j]);
                	if ((j + 1) % 3 == 0)
                    		printf("||   ");
     			else
				printf(":   ");
		}
       		printf("\n");
		if (i == 8)
		{
			for (int j = 0; j < l; j++)
                                printf("/");
			printf("\n");
		}
	}
}
