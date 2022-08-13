#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int a[256][256],b[256][256],i,j,m,k,t,x;
	double g=0.4,c=2;					
	FILE *fp,*fq;
	fp=fopen("input.txt","r");
	fq=fopen("output.txt","w+");
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			fscanf(fp,"%d",&k);
			a[i][j]=k;
		}
	}
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			m=c*pow(a[i][j],g);
			if(m>255)
				m=255;
			b[i][j]=m;
		}
	}
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			fprintf(fq,"%d ",b[i][j]);
		}
	}
	fclose(fp);
	fclose(fq);
}
