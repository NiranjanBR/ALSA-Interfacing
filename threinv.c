#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
float A[3][3],B[3][3];
int i,j,k,l,m,n,e,f,g,h;
float det=0;
void* thread_det()
{
printf("\n thread for determinant is created\n");
for(i=0,k=1,m=2,e=-1,g=2;i<3;i++,e++,g--,k-=g,m-=e)
{
for(j=0,l=1,n=2,f=-1,h=2;j<3;j++,f++,h--,l-=h,n-=f)
{
B[i][j]=pow(-1,(i+j))*((A[k][l]*A[m][n])-(A[m][l]*A[k][n]));
if(i==0)
{
det+=A[i][j]*B[i][j];
}
}
}
printf("The determinant of the matrix is %f ",det);
//printf("\nCofactor of the matrix is :\n");
}
void* thread_cofac()
{
printf("\n thread for cofactor is created and cofactor is \n");
for(i=0;i<3;i++)
{
printf("\n");
for(j=0;j<3;j++)
printf("%7.3f \t",B[i][j]);
}
}
void* thread_adjoint()
{
printf("\n thread for adjoint is created \n");
for(i=0;i<3;i++)
for(j=0;j<3;j++)
A[i][j]=B[j][i];
printf("\nAdjoint of the matrix is :\n");
for(i=0;i<3;i++)
{
printf("\n");
for(j=0;j<3;j++)
printf("%7.3f \t",A[i][j]);
}
}
void* thread_inverse()
{
printf("\nthread for inverse is created\n");
for(i=0;i<=2;i++)
{
for(j=0;j<3;j++)
A[i][j]*=(1/det);
}
printf("\nInverse of the matrix is :\n");
for(i=0;i<3;i++)
{
printf("\n");
for(j=0;j<3;j++)
{
printf("%7.3f \t",A[i][j]);
}
}
}

int main()
{
pthread_t nothreads[4];
 
printf("Enter the 3x3 matrix :\n");//Enters the matrix
for(i=0;i<3;i++)
for(j=0;j<3;j++)
scanf("%f",&A[i][j]);
pthread_create(&nothreads[0],NULL,&thread_det,NULL);
pthread_join(nothreads[0],NULL);
pthread_create(&nothreads[1],NULL,&thread_cofac,NULL);
pthread_join(nothreads[1],NULL);
pthread_create(&nothreads[2],NULL,&thread_adjoint,NULL);
pthread_join(nothreads[2],NULL);
pthread_create(&nothreads[3],NULL,&thread_inverse,NULL);
pthread_join(nothreads[3],NULL);
//pthread_join(nothreads,NULL);
return 0;
}
