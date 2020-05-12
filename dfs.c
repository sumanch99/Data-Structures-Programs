#include<stdio.h>
void main()
{
	int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q,res;
	printf("\nHow many rows for the matrix 1?:");
	scanf("%d",&m);
	printf("\nHow many columns for the matrix 1?:");
	scanf("%d",&n);
	printf("\nHow many rows for the matrix 2?:");
	scanf("%d",&p);
	printf("\nHow many columns for the matrix 2?:");
	scanf("%d",&q);
	if(n==p)
	{
		printf("\nEnter the matrix 1:");
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		printf("\nEnter the matrix 2:");
		for(i=0;i<p;i++)
			for(j=0;j<q;j++)
				scanf("%d",&b[i][j]);		
		for(i=0;i<m;i++)
			for(j=0;j<q;j++)
			{
				c[i][j]=0;
				for(k=0;k<n;k++)
						c[i][j]+=a[i][k]*b[k][j];
			}
		printf("\nThe multiplied matrix:");
		for(i=0;i<m;i++)
		{
			printf("\n");
			for(j=0;j<q;j++)
				printf("%d\t",c[i][j]);
		}
	}
}
