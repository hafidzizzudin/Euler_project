#include<iostream>

long long largestPrimeFactor(long long max){
    long long largestVal = 2;
    while(max%2==0){
        max/=2;
    }
    //std::cout << "max 2: " << max << "\n";
    for(long long i=3;i*i<=max;i+=2){
        while (max % i == 0)  
        {  
            largestVal = i;  
            max = max/i;  
        }
        //std::cout << "max "<< i <<": " << max << "\n";
    }
    
    if(max>2)
        largestVal = max;
    
    return largestVal;
}


int main(){
    long long max;
    std::cout << "Enter the value: " <<std::endl;
    std::cin >> max;
    long long result = largestPrimeFactor(max);
    std::cout << result << std::endl;
    return 0; 
}
