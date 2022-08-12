#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j,m=256,n=256,r,p;
int a[256][256]; 
int main()
{
	FILE *fptr;
	fptr=fopen("input.txt","r");
	fscanf(fptr,"%d %d %d",&m,&n,&r);
	printf("%d %d %d",m,n,r);
	for(i=0;i<m;i++)
	{
  		for(j=0;j<n;j++)
  		{
    		fscanf(fptr,"%d ",&p);
    		a[i][j]=p;
  		}
	}
	fclose(fptr);
	fptr=fopen("output.txt","w+");
	fprintf(fptr,"P2\n%d %d %d\n",m,n,r);
	float c =105.89;
	for(i=0;i<m;i++)
	{
  		for(j=0;j<n;j++)
  		{
  			float s=c*(log10(a[i][j]+1));
  			int q=(int)s;
    		fprintf(fptr,"%d ",q);
  		}
	}
	fclose(fptr);
}
