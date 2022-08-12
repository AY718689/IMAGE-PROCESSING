#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define row 256
#define col 256
int i,j,k;
int a[row][col],b[row+2][col+2],d[row][col];
int robert_cross(int b[row+2][col+2],int i,int j)
{
	int c[4],u,v;
	c[0]=b[i-1][j-1];
	c[1]=b[i-1][j];
	c[2]=b[i][j-1];
	c[3]=b[i][j];
	int gx = abs(c[0]-c[3]);
	int gy = abs(c[1]-c[2]);
	int x = gx*gx;
	int y= gy*gy;
	int t = (int)sqrt(x+y);
	if(t>255)
		return 255;
	else if(t<0)
		return 0;
	else
		return t;
	
}
main()
{
	FILE *fp;
	FILE *fq;
	int i,j;
	fp = fopen("input.txt","r");
	fq = fopen("output.txt","w+");
	for(i = 0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fscanf(fp,"%d ",&k);
			a[i][j]=k;
		
		}
	}
	//corner padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
			{
				if(j==0)
					b[i][j]=a[i][j];
				else if(j==col-1)
					b[i][j+2]=a[i][j];
			}
			if(i==row-1)
			{
				if(j==0)
					b[i+2][j]=a[i][j];
				else if(j==col-1)
					b[i+2][j+2]=a[i][j];
			}
		}
	}
	//top and bottom padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
				b[i][j+1]=a[i][j];
			if(i==row-1)
				b[i+2][j+1]=a[i][j];
		}
	}
	//left and right padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j==0)
				b[i+1][j]=a[i][j];
			if(j==col-1)
				b[i+1][j+2]=a[i][j];
		}
	}
	//remaining
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			b[i+1][j+1]=a[i][j];
		}
	}
	
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			d[i][j] = robert_cross(b,i,j);
		}
	}
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			fprintf(fq,"%d ",d[i][j]);
		}
		
	}
	fclose(fp);
	fclose(fq);
	
}
