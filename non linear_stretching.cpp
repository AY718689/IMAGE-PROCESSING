#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	int n,m,r,i,j;
	int rmax,rmin;
	FILE *fptr;
	fptr=fopen("input.txt","r");
	fscanf(fptr,"%d %d %d",&n,&m,&r);
	printf("%d %d %d",n,m,r);
	
	double a[n][m],k;
	int b[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(fptr,"%lf ",&k);
			a[i][j] =k;
		}
	}
	rmax = a[0][0];
	rmin = a[0][0];
	for(i=0;i<m;i++)
	{ 
    	for(j=0;j<n;j++) 
		{ 
			if(a[i][j]<rmin) 
				rmin=a[i][j]; 
			if(a[i][j]>rmax) 
				rmax=a[i][j]; 
		} 
	} 
	printf("Rmax : %d\n",rmax);
	printf("Rmin : %d\n",rmin);
	fclose(fptr);
	fptr=fopen("output.txt","w+");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			b[i][j] =(int)((log(a[i][j]-rmin+1)/log(rmax-rmin+1))*255);
			if(b[i][j]>255)
				b[i][j]=255;
			if(b[i][j]<0)
				b[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fprintf(fptr,"%d ",b[i][j]);
		}
	}
	fclose(fptr);
}
