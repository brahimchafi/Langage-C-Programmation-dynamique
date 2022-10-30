#include <stdio.h>
#include<limits.h>
#define INF 999999999
long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void sequence(int i,int j)
{
if (i == j)
printf(" A%d ",i);
else
   {
      printf("( ");
      sequence(i, s[i][j]);
      sequence(s[i][j] + 1, j);
      printf(" )");
   }
}

void multiplication_chainee(void)
{
long int q;
int k;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}

int minmat(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    for (k = i; k <j; k++)
    {
        count = minmat(p, i, k) +
                minmat(p, k+1, j) +
                p[i-1]*p[k]*p[j];
 
        if (count < min)
            min = count;
    }
 
    
    return min;
}

void main()
{
		int k;
		printf("Enterez le nombre d'elements-> ");
		scanf("%d",&n);
		  for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
						{
 							m[i][i]=0;
 							m[i][j]=INF;
 							s[i][j]=0;
							}			
		
		printf("\n		-----------------------------------------------------------\n");
		printf("       		|Pour 4 matrices A1 A2 A3 A4 de dimensions 5x4 4x6 6x2 2x7|\n");	
		printf("		|	 l'entree des dimensions serait 5-4-6-2-7         |\n ");	
		printf(" 		|---------------------------------------------------------|");
		printf("\n		-----------------------------------------------------------\n");
		printf("\nEntrez les dimensions: \n");
			for(k=0;k<=n;k++)
				{
 					printf("P%d: ",k);
 					scanf("%d",&p[k]);
				}
				
				multiplication_chainee();
			printf("\nMatrice des couts M:\n");
				for(i=1;i<=n;i++)
 					for(j=i;j<=n;j++)
  						printf("m[%d][%d]: %ld\n",i,j,m[i][j]);


		i=1,j=n;
		printf("\nParenth%csage de la multiplication : ",130);
		sequence(i,j);
			
		printf("\nLe cout minimal est : %d ",minmat(p, 1, n));

}
