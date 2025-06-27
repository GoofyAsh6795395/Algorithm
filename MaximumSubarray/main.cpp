#include <iostream>

using namespace std;
#define maxx 100

int arr[maxx];

typedef struct inf{
    int l;
    int r;
    int sum;
};

struct inf crossingMaximum(int l,int mid,int r){
    int idxL,idxR,idxML = mid,idxMR = mid+1;
    int maxL = arr[mid],maxR = arr[mid+1],max = arr[mid] + arr[mid+1];
    int sumL = arr[mid],sumR = arr[mid+1];
    inf res;
    for(idxL = mid-1;idxL >= l;idxL--){
        sumL = sumL + arr[idxL];
        if(sumL > maxL){
            maxL = sumL;
            idxML = idxL;
        }
    }
    for(idxR = mid+2;idxR <= r;idxR++){
        sumR = sumR + arr[idxR];
        if(sumR > maxR){
            maxR = sumR;
            idxMR = idxR;
        }
    }
    max = maxL + maxR;
    res.l = idxML;
    res.r = idxMR;
    res.sum = max;
    return res;
}

inf maximumSubarray(int l,int r){
    if(l != r){
        int mid = (l+r)/2;
        int maxC,maxL,maxR;
        inf res;
        maxL = maximumSubarray(l,mid).sum;
        maxR = maximumSubarray(mid+1,r).sum;
        maxC = crossingMaximum(l,mid,r).sum;
        if(maxL >= maxR && maxL >= maxC){
            res.l = maximumSubarray(l,mid).l;
            res.r = maximumSubarray(l,mid).r;
            res.sum = maxL;
            return res;
        }else if(maxR >= maxL && maxR >= maxC){
            res.l = maximumSubarray(mid+1,r).l;
            res.r = maximumSubarray(mid+1,r).r;
            res.sum = maxR;
            return res;
        }else{
            res.l = crossingMaximum(l,mid,r).l;
            res.r = crossingMaximum(l,mid,r).r;
            res.sum = maxC;
        }
    }else{
        inf basic;
        basic.l = l;
        basic.r = r;
        basic.sum = arr[l];
        return basic;
    }
}

int main(int argc, const char* argv[]) {
    int num;
    cin>>num;
    for(int cnt=1;cnt <= num;cnt++){
        cin>>arr[cnt];
    }
    inf res;
    res = maximumSubarray(1,num);
    cout<<res.l<<" "<<res.r<<endl<<res.sum;
    return 0;
}
