/*
 ============================================================================
 Name        : sudoku.c
 Author      : Shouvik Banik
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>
void check(int in[4][4]);
void main()
{
	int in[4][4],i,count=0,j,num,choice;
	int sudo[4][4]={
			{2,3,1,4},
			{4,1,3,2},
			{3,2,4,1},
			{1,4,2,3}};
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			in[i][j]=0;

	in[0][0]=2;
	in[0][2]=1;
	in[1][3]=2;
	in[2][0]=3;
	in[3][1]=4;
	in[3][3]=3;

	printf("Solve this SUDOKU::\n");
	while(1)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				printf("%d ",in[i][j]);
			}
			printf("\n");
		}
		printf("\nEnter position::(x-coord) & (y-coord): ");
		scanf("%d%d",&i,&j);
		printf("\nEnter digit: ");
		scanf("%d",&num);
		in[i][j]=num;
		if(count==9)
		{
			printf("\nDo you want to check?(1/0) -> ");
			scanf("%d",&choice);
			if(choice==1)
			{
				check(in);
			}
			if(choice==0)
			{
				printf("\nThe solution is::\n");
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
					{
						printf("%d ",sudo[i][j]);
					}
					printf("\n");
				}
			}
		}
		count++;
	}
}
void check(int in[4][4])
{
	int vert[4][4],i,j,x,flag=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(x=j+1;x<4;x++)
			{
				if(in[i][j]==in[i][x])
				{
					flag=1;
					printf("\nRepeated %d entry in %dth row\n",in[i][j],i);
					exit(0);
				}
			}
		}
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			vert[i][j]=in[j][i];

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(x=j+1;x<4;x++)
			{
				if(in[i][j]==in[i][x])
				{
					flag=1;
					printf("\nRepeated %d entry in %dth col\n",in[i][j],i);
					exit(0);
				}
			}
		}
	}
	if(flag==0)
	{
		printf("\nWell done!!!\n");
		exit(0);
	}
}













