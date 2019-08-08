#include<stdio.h>                     //Intersection merging
struct Interval{
    int s;
    int e;
};

int cmp(void* a, void* b){
    int s1 = ((struct Interval*)a)->s;
    int s2 = ((struct Interval*)b)->s;
    return (s1-s2 > 0);
}

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
     struct Interval *arr = (struct Interval*)malloc(sizeof(struct Interval)*n);
    printf("Enter elements of array : ");
    for(int i=0;i<n;i++)
        scanf("%d %d",&arr[i].s,&arr[i].e);
    qsort(arr,n,sizeof(arr[0]),cmp);
    for(int i=0;i<n-1;i++){
        if(arr[i+1].s <= arr[i].e){
            arr[i].e = arr[i].e>arr[i+1].e?arr[i].e:arr[i+1].e;
            for(int j=i+1;j<n;j++){
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }
    printf("The output array is : ");
    for(int i=0;i<n;i++)
        printf("\(%d,%d\) \n",arr[i].s,arr[i].e);
    }
