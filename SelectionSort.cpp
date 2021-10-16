

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

class SelectionSort
{
public:
    void swap(int *x,int *y)
    {
         int temp=*x;
         *x=*y;
         *y=temp;
    }
    void sort(int A[],int n)
    {
        int i,j,k;

         for(i=0;i<n-1;i++)
         {
             for(j=k=i;j<n;j++)
             {
                 if(A[j]<A[k])
                 k=j;
             }
             swap(&A[i],&A[k]);
         }
    }

};

int main()
{
    int n,i;
    clock_t start, stop;
    cout<<"\nEnter the number of elements : ";
    cin>>n;
    int a[n];
    SelectionSort selectionSort;
    cout<<"\nThe unsorted list is:\n\n";
    for(i=0; i<n; i++)
    {
        a[i] = rand()%1000;
        cout<<a[i]<<"\t";
    }
    start=clock();
    selectionSort.sort(a,n);
    stop=clock();
    cout<<"\n\nSorted elements are \n"<<endl;
    for(i=1;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<"\n\nANALYSIS:";
    cout<<"\nTime taken: "<<((float)(stop-start)/CLK_TCK)<<" milliseconds";
    cout<<"\nSpace consumed: "<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(selectionSort)<<" bytes";
    cout<<"\n";
    return 0;
}
