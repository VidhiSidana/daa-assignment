#include<iostream>
using namespace std;
void merge(int arr[],int first,int last,int mid){
    int n1=mid-first+1;
    int n2=last-mid;
    int brr[n1],crr[n2];
    for(int i=0;i<n1;i++){
        brr[i]=arr[first+i];
    }
    for(int j=0;j<n2;j++){
        crr[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=first;
    while(i<n1&& j<n2){
        if(brr[i]<crr[j]){
            arr[k++]=brr[i++];
        }
        else{
            arr[k++]=crr[j++];
        }
    }
    while (i < n1){
         arr[k++] = brr[i++];
    }
    while (j < n2){
        arr[k++] = crr[j++];
}
}


void mergesort(int arr[],int first,int last){
    if(first<last){
    int mid=(first+last)/2;
    mergesort(arr,first,mid);
    mergesort(arr,mid+1,last);
    merge(arr,first,last,mid);
    }
}
int main(){
    int  n;
   
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int first=0;
    int last=n-1;
    mergesort(arr,first,last);
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}