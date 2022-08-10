#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,m,r,i,j;
	FILE *fptr;
	fptr=fopen("Cat Portrait.txt","r");
	fscanf(fptr,"%d %d %d",&n,&m,&r);
	printf("%d %d %d",n,m,r);
	
	int a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(fptr,"%d",&a[i][j]);
		}
	}
	printf("%d %d %d",n,m,r);
	fclose(fptr);
	fptr=fopen("Cat Portrait negative.txt","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fprintf(fptr,"%d ",r-a[i][j]);
		}
		fprintf(fptr,"\n");
	}
	printf("%d",n);
	fclose(fptr);
}
