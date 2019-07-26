#include <stdio.h>
#include <stdlib.h>

void Spiral_Order(int n,int arr[n][n])
{
    int dir,L,R,T,B;
    dir=L=T=0;
    R=B=(n-1);
    while(L<=R && T<=B)
    {
        if(dir==0)
        {
            for(int i=L;i<=R;i++)
            {
                printf("%d ",arr[T][i]);
            }
            T++;
        }
        else if(dir==1)
        {
            for(int i=T;i<=B;i++)
            {
                printf("%d ",arr[i][R]);
            }
            R--;
        }
        else if(dir==2)
        {
            for(int i=R;i>=L;i--)
            {
                printf("%d ",arr[B][i]);
            }
            B--;
        }
        else if(dir==3)
        {
            for(int i=B;i>=T;i--)
            {
                printf("%d ",arr[i][L]);
            }
            L++;
        }
        dir=(dir+1)%4;
    }
}
int main()
{
    int size;
    printf("Enter Size of array : ");
    scanf("%d",&size);
    int arr[size][size];
    printf("Enter elements of array :-\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
             scanf("%d",&arr[i][j]);
        }
    }
    Spiral_Order(size,arr);
    return 0;
}
