#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[],int first,int last){
    int pivot=arr[last];
    int i=first-1;
    
    for(int j=first;j<last;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;
}
void quicksort(int arr[],int first,int last){
    if(first<last){
        int p=partition(arr,first,last);
        quicksort(arr,first,p-1);
        quicksort(arr,p+1,last);
    }
}
int main(){
     int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout<<arr[i]<<endl;
    return 0;
}