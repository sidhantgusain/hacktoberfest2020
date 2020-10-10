#include<stdio.h>
#include<stdlib.h>

void max_heapify(int a[],int n,int i)
{
    int l,r,largest,temp;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<n && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,n,largest);
    }
}

void build_max_heap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
       max_heapify(a,n,i);
    }
}

void heap_sort(int a[],int n)
{
    int i,temp;
    build_max_heap(a,n);
    for(i=n-1;i>=0;i--)
    {
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        n=n-1;
        max_heapify(a,n,0);
    }
}

int main()
{
    int i,n;
    printf("\n enter size of array");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("enter element %d : ",i);
        scanf("%d",&a[i]);
    }
    heap_sort(a,n);
    printf("\n sorted array \n" );
    for(i=0;i<n;i++)
    {
        printf("\n %d",a[i]);
    }
    return 0;

}
