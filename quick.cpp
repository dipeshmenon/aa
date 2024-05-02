
#include<iostream>
using namespace std;
//considering pivot as last element 

void swap(int& a , int& b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(int arr[] , int low , int high)
{
	int i = low-1;
	int pivot = arr[high];
	
	for(int j=low;j<high;j++)
	{
		if(arr[j] <= pivot){
			i++;
			
			swap(arr[i] , arr[j]);
		}
		
	}
	swap(arr[i+1],arr[high]);
	return i+1;
	
}
void quicksort(int arr[] , int low , int high)
{
	if(low<high)
	{
		int pi = partition(arr,low,high);
		
		quicksort(arr , low , pi-1);//pivot is not considered for other sub parts
		quicksort(arr,pi+1,high);//pivot is not considered for other sub parts
	}
}

int main()
{
	int n;

	cout<<"Enter the value of n: ";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	
 cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quicksort(arr, 0, n - 1);

    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
	return 0;
}
