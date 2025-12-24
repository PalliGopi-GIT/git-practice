#include<stdio.h>
void heapify(int a[],int n,int i){
     int largest=i;
     int left=2*i+1;
     int right=2*i+2;
     if(left<n && a[left]>a[largest]){
        largest=left;
     }
     if(right<n && a[right]>a[largest]){
        largest=right;
     }
     if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
     }
}
void heap_sort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main(){
    int i,n,a[100];
    printf("enter the size of your list\n");
    scanf("%d",&n);
    printf("enter your elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heap_sort(a,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
