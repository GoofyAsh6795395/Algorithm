#include <iostream>
#define max 100

typedef struct heap{
    int arr[max];
    int qty;
};
heap h;

void maxHeapify(int idx){
    int maxVal,maxIdx;
    int childL = idx*2;
    int childR = idx*2+1;
    maxVal = h.arr[idx];
    maxIdx = idx;
    if(childL <= h.qty && h.arr[childL] > maxVal){
        maxIdx = childL;
        maxVal = h.arr[childL];
    }
    if(childR <= h.qty && h.arr[childR] > maxVal){
        maxIdx = childR;
        maxVal = h.arr[childR];
    }
    if(h.arr[maxIdx] != h.arr[idx]){
        h.arr[maxIdx] = h.arr[idx];
        h.arr[idx] = maxVal;
        maxHeapify(maxIdx);
    }
}

void build(){
    for(int idx= (h.qty)/2;idx >= 1;idx--){
        maxHeapify(idx);
    }
}

void heapSort(){
    for(;h.qty >=2;h.qty--){
        maxHeapify(1);
        int tep;
        tep = h.arr[1];
        h.arr[1] = h.arr[h.qty];
        h.arr[h.qty] = tep;
    }

}

int main(int argc, const char* argv[]) {
    std::cin>>h.qty;
    int rod = h.qty;
    for(int cnt=1;cnt <= h.qty;cnt++){
        std::cin>>h.arr[cnt];
    }
    build();
    heapSort();
    for(int cnt=1;cnt <= rod;cnt++){
        std::cout<<h.arr[cnt]<<" ";
    }
    return 0;
}
