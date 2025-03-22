
/*
Name:Jalil Fountain
Hello grader, I am in Aneesha's lab but I followed along with Adam's recording, so thats why my functoins 
prototypes parameters are different names then whats used when making the functions;

*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXARRAYS 6
#define MAXVALUE 1000000
void quickSort(int *numbers,int low, int high);
void randArray(int A[], int size, int maxval);
void bubbleSort(int A[], int n);
void insertionSort(int arr[], int n);
void swap(int *a, int *b);
void arrayCopy(int from[], int to[], int size);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void mergeInsertionSort(int arr[], int l, int r);
long timediff(clock_t t1, clock_t t2);
int main() {
// Different sizes to test the sort.
int sizes[MAXARRAYS] = {10000, 20000, 30000, 40000, 50000, 60000};
int* originalArray; //to keep the original array unchanged so that we can use
//it for various algorithms.
int* sortedArray; //We will mainly pass this one to all the function.
int i;
clock_t start,end;
long elapsed;


for(i=0;i<MAXARRAYS;i++){
    printf("\nSize: %d\n",sizes[i]);
    
    originalArray=malloc(sizeof(int)*sizes[i]);
    
    sortedArray=malloc(sizeof(int)*sizes[i]);

    randArray(originalArray,sizes[i],MAXVALUE);

    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    bubbleSort(sortedArray,sizes[i]);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for BubbleSort\n",sizes[i],elapsed);


    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    selectionSort(sortedArray,sizes[i]);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for SelectionSort\n",sizes[i],elapsed);

    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    insertionSort(sortedArray,sizes[i]);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for InsertionSort\n",sizes[i],elapsed);

    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    mergeSort(sortedArray,0,sizes[i]-1);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for MergeSort\n",sizes[i],elapsed);

    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    mergeInsertionSort(sortedArray,0,sizes[i]-1);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for MergeInsertionSort\n",sizes[i],elapsed);

    arrayCopy(originalArray,sortedArray,sizes[i]);

    start=clock();
   
    quickSort(sortedArray,0,sizes[i]-1);
    
    end=clock();
    
    elapsed=timediff(start,end);
    
    printf("\nSorting %d takes %ld milliseconds for QuickSort\n",sizes[i],elapsed);

    free(originalArray);
    free(sortedArray);
}

return 0;
}

void arrayCopy(int original[], int copy[], int size)
{
    for(int i=0; i<size;i++){

        copy[i]=original[i];

    }

}

void randArray(int arr[], int size, int maxval) {
    for(int i=0;i<size;i++){
        
        arr[i]= rand() % MAXVALUE + 1;
    }

}

void swap(int *xp,int *yp){
 //swap the passed integers using pass by reference
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void bubbleSort(int arr[], int n) {
int i,j;

for(i=0;i<n-1;i++){
    
    for(j=0;j<n-i-1;j++){

        if(arr[j]>arr[j+1]){
            
            swap(&arr[j],&arr[j+1]);
            
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i,item,j;

    for(i=1;i<n;i++){
        
        item=arr[i];
            
        for(j=i-1;j>=0;j--){
                
            if(arr[j]>item)
                
            arr[j+1]=arr[j];
            
            else
            
            break;
            
        }
        
        arr[j+1]=item;
    }

}

void merge(int arr[],int l, int m,int r)
{
    int i,j,k;
    int leftSize=m-l+1;
    int rightSize=r-m;

    int *L=malloc(leftSize * sizeof(int));
    int *R=malloc(rightSize * sizeof(int));

    for(i=0;i<leftSize;i++){
        L[i]=arr[l+i];
    }

    for(j=0;j<rightSize;j++){
        R[j]=arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<leftSize&&j<rightSize){

        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{

            arr[k]=R[j];
            j++;
        }
            k++;

    }
    while(i<leftSize){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<rightSize){
        arr[k]=R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {

    int m=(l+r)/2;

    mergeSort(arr,l,m);

    mergeSort(arr,m+1,r);

    merge(arr,l,m,r);

    }

}

void mergeInsertionSort(int arr[],int l,int r)
{
    if(r<=25)
    {
        insertionSort(arr,r);

        return;
    }

    if(l<r)
    {

        int m=(l+r)/2;

        mergeSort(arr,l,m);

        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);

    }


}

int partition(int *vals,int low,int high)
{

    int i = low+rand()%(high-low+1);

    swap(&vals[low],&vals[i]);

    int lowposition=low;
    low++;

    while(low<=high)
    {
        while(low<=high &&vals[low]<=vals[lowposition]){
            low++;
        }
        while(high>=low&& vals[high]>vals[lowposition]){
            high--;
        }
        if(low<high){
            swap(&vals[low],&vals[high]);
        }
    }

        swap(&vals[lowposition],&vals[high]);

    return high;
}

void quickSort(int *numbers,int low,int high)
{

    if (low<high){

        int split=partition(numbers,low,high);

        quickSort(numbers,low,split-1);
    
        quickSort(numbers,split+1,high);
    }


}

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

void selectionSort(int arr[],int n)
{

    int i,j,min_idx,temp;

    for(i=0;i<n-1;i++){
        min_idx=i;

        for(j=i+1;j<n;j++)
        if(arr[j]<arr[min_idx])
        min_idx=j;

        temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }

}