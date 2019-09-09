#include<iostream>

int sum_even_fibonacci(int max){
    int sum = 0;
    int prev1=0,prev2=1,current;
    
    while(current<max){
        current = prev1+prev2;
        if(current%2 == 0){
            sum+=current;
        }
        prev1 = prev2;
        prev2 = current;
    }
    return sum;
}

int main(){
    int max;
    max = 4000000;
    int result = sum_even_fibonacci(max);
    std::cout << result << std::endl;
    return 0; 
}
