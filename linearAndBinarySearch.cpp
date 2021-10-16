//linear and binary search
#include<bits/stdc++.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<chrono>
using namespace std;
using namespace std::chrono;

class linear
{
	public:
		int ln(int*,int,int);
};
class binary
{
	public:
		int bn(int*,int,int);
};
int linear::ln(int a[],int size,int key)
{
	int i,flag=-1;
	for(i=0;i<size;i++)
	{
		if(a[i]==key)
		{
			cout<<"The element is found"<<endl<<"Position: "<<i+1<<endl;
			flag=1;
			break;
		}
	}
	if(flag==-1)
	{
		cout<<"Element not found"<<endl;	
	}
	return 0;
}

int binary::bn(int a[],int size,int key)
{
	int i,low,high,mid,flag;
	low=0;
	high=size-1;
	flag=-1;
	while(low<=high)
	{
		mid=(high+low+1)/2;
		if(key==a[mid])
		{
			cout<<"The element is found"<<endl<<"Position: "<<mid+1<<endl;
			flag=1;
			break;
		}
		else if(key>a[mid])
		{
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(flag==-1)
	{
		cout<<"Element not found"<<endl;	
	}
	return 0;
}
int main()
{
	int choice,size,*a,key,i;
	cout<<"1.Linear search"<<endl<<"2.Binary Search"<<endl<<"Enter your choice"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			cout<<"Enter size of the array"<<endl;
			cin>>size;
			a=new int[size];
			srand(time(0));
			for(i=0;i<size;i++)
			{
				a[i]=rand();
				cout<<a[i]<<" "<<endl;
			}
			cout<<"Enter the element to be seached"<<endl;
			cin>>key;
			linear obj;
			auto start=high_resolution_clock::now();
			obj.ln(a,size,key);
			auto end=high_resolution_clock::now();
			cout<<"Time taken: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
			cout<<"Space consumed: "<<sizeof(i)+size*sizeof(a)+sizeof(key)+sizeof(choice)+sizeof(size)<<"Bytes"<<endl;
			break;
		}
		case 2:
		{
			cout<<"Enter size of the array"<<endl;
			cin>>size;
			a=new int[size];
			long sum=0;			
			cout<<"Enter the sorted array"<<endl;
			for(i=0;i<size;i++)
			{
				sum+=rand()%100;
				a[i]=sum;
				cout<<a[i]<<endl;
			}
			cout<<"Enter the element to be seached"<<endl;
			cin>>key;
			binary obj1;
			auto start=high_resolution_clock::now();
			obj1.bn(a,size,key);
			auto end=high_resolution_clock::now();
			cout<<"Time taken: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
			cout<<"Space consumed: "<<sizeof(i)+size*sizeof(a)+sizeof(key)+sizeof(choice)+sizeof(sum)<<"Bytes"<<endl;
			break;
		}
		default:
			cout<<"Invalid choice"<<endl;
	}
}
