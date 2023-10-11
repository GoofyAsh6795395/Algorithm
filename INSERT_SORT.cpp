#include <stdio.h>
#include <iostream>

#define max 1000
using namespace std;

int main(int argc, const char* argv[]) {
    int arr[max],num;
    cin>>num;
    for(int cnt=1;cnt <= num;cnt++){
        cin>>arr[cnt];
    }
    for(int pos=2;pos <= num;pos++){
        int subpos = pos-1;
        int val = arr[pos];
        while(val <= arr[subpos] && subpos >= 1){
            arr[subpos+1] = arr[subpos];
            subpos--;
        }
        arr[subpos+1] = val;
    }
    for(int cnt=1;cnt <= num;cnt++){
        cout<<arr[cnt]<<" ";
    }
    return 0;
}