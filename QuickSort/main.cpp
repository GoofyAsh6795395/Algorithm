#include <iostream>
#include <stdlib.h>
#define max 100

int arr[max];
int qty;

int partition(int l, int r){
    int idxL, idxR;
  //  int random = rand()%(r+1) + l;
  //  std::swap(arr[random],arr[r]);
    idxR =l;
    idxL = idxR-1;
    int pivot = arr[r];
    for(;idxR <= (r-1);idxR++){
        if(arr[idxR] <= pivot){
            idxL++;
            std::swap(arr[idxR],arr[idxL]);
        }
    }
    std::swap(arr[r],arr[idxL+1]);
    return idxL+1;
}

void quickSort(int l, int r){
    if(l < r){
        int pivot = partition(l,r);
        quickSort(l,pivot-1);
        quickSort(pivot,r);
    }
}

int main(int argc, const char* argv[]) {
    std::cin>>qty;
    for(int cnt=1;cnt<= qty;cnt++){
        std::cin>>arr[cnt];
    }
    quickSort(1,qty);
    for(int cnt=1;cnt<= qty;cnt++){
        std::cout<<arr[cnt]<<" ";
    }
    return 0;
}
