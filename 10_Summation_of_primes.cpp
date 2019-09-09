#include<iostream>
#include<vector>

long long sumOfPrimes(long long max){
    long long sum=2;
    std::vector<int> primevec(1,2);
    int test = 3;
    while((*(primevec.end()-1) < max) && (test<max)){
        bool prime = true;
        for(int i=0;primevec[i]*primevec[i]<=test;i++){
            if(test%primevec[i] == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            primevec.push_back(test);
            sum = (long long)(sum+test);
        }
        test+=2;
    }
    std::cout << "\n";
    return sum;
}

int main(){
    
    long long max;
    std::cout << "Enter the upper bound for prime search: ";
    std::cin >> max;
    
    std::cout << "The summation of the primes below " << max <<" is: " 
    << sumOfPrimes(max) <<"\n";
    
    return 0;
}
