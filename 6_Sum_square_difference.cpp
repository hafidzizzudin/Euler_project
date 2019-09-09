#include<iostream>

long long pow(int a, int b){
    long long result=1;
    while(b--){
        result*=(long long)a;
    }
    return result;
}


long long diff_sum_square(int target){
    long long sumSquare=0;
    long long squareSum=0;
    
    // Sum of the squares
    for(long long i=1;i<=(long long)target;i++){
        sumSquare+=pow(i,2);
    }
    
    // Square of the sum
    for(long long i=1;i<=(long long)target;i++){
        squareSum+=i;
    }
    if(sumSquare<pow(squareSum,2))
        return pow(squareSum,2)-sumSquare;
    else
        return sumSquare-pow(squareSum,2);
}



int main(){
    std::cout <<"Enter the maximum number to be calculated: ";
    int target;
    std::cin>>target;
    std::cout << diff_sum_square(target) <<"\n";
    return 0;
}
