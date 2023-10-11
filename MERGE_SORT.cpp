#include <iostream>
using namespace std;

#define max 100
int arr[max],num;

// conquer: function to
// parameters: initial index of left array(1), final index of right array(3), middle value of them(2)
// idx: index; qty: quantity
void conquer(int l,int mid,int r){
    // calculate arrays' length
    int qtyL = mid-l+1;
    int qtyR = r-mid;
    int idx = l,idxL=1,idxR=1;
    int lt[qtyL+1];
    int rt[qtyR+1];
    // copy left, right arrays to temporary ones
    for(int cnt=1;cnt <= qtyL;cnt++){
        lt[cnt] = arr[l+cnt-1];
    }
    for(int cnt=1;cnt <= qtyR;cnt++){
        rt[cnt] = arr[mid+cnt];
    }
    // compare indexed elements of temporary arrays, then assign bigger one to indexed element of main array
    while(idxL <= qtyL || idxR <= qtyR){
        if(lt[idxL] <= rt[idxR]){
            arr[idx] = lt[idxL];
            idxL++;
            idx++;
        }else{
            arr[idx] = rt[idxR];
            idxR++;
            idx++;
        }
    }
    // check which temporary array gets all assigned, then assign value of remaining elements in another array separately to main
    if(idxL != qtyL){
        while(idxL <= qtyL){
            arr[idx] = lt[idxL];
            idxL++;
            idx++;
        }
    }else{
        while(idxR <= qtyR){
            arr[idx] = rt[idxR];
            idxR++;
            idx++;
        }
    }
}
//mergeSort: function to divide arrays recursively and conquer
void mergeSort(int l,int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        conquer(l,mid,r);
    }
}

int main(int argc, const char* argv[]) {
    cin>>num;
    for (int cnt=1;cnt <= num;cnt++){
        cin>>arr[cnt];
    }
    mergeSort(1,num);
    for (int cnt=1;cnt <= num;cnt++){
        cout<<arr[cnt]<<endl;
    }
    return 0;
}
