#include <iostream>
#define maxValue 1000
#define maxQuantity 100

int arrayIn[maxQuantity];
int arrayOut[maxQuantity];
int auxiliary[maxValue];
int quantity;

int main(int argc, const char* argv[]) {
    std::cin>>quantity;
    for(int counter=1;counter <= quantity;counter++){
        std::cin>>arrayIn[counter];
        auxiliary[arrayIn[counter]]++;
    }
    for(int counter=2;counter <= quantity;counter++){
        auxiliary[counter] += auxiliary[counter-1];
    }
    for(int counter = quantity;counter >= 1;counter--){
        arrayOut[auxiliary[arrayIn[counter]]] = arrayIn[counter];
        auxiliary[arrayIn[counter]]--;
    }
    for(int counter=1;counter <= quantity;counter++){
        std::cout<<arrayOut[counter]<<" ";
    }
    return 0;
}
