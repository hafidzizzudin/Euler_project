#include<iostream>
#include<exception>
#include<cmath>


// CLUE 
// max = (p1^e1)*(p2*e2)*...*(pk^ek)
// p: prime number
// e: power of the prime
// number of factor = (e1+1)*(e2+1)*...*(ek+1)
int digitCount(int max){
    int ndigit=0,current_digit = 1;
    while(max%2==0){
        max/=2;
        ndigit++;
    }
    current_digit *= (ndigit+1);
    for(int i=3;i*i<=max;i+=2){
        ndigit = 0;
        while (max % i == 0)  
        {  
            max = max/i;  
            ndigit++;
        }
        current_digit*=(ndigit+1);
    }
    
    if(max>2)
        current_digit*=2;
    
    if(max == 1)
        return max;
    else
        return current_digit;
}

int findTheFirstTriangleNumber(int minDigit){
    
    int val=0, adder = 1;
    int digit = 0, largest = 0;
    while(digit <= minDigit){
        val+=adder;
        digit = digitCount(val);
        adder++;
        //std::cout << val <<"\n";
    }
    if(minDigit == 1){
        std::cout<<digit <<"\n"; 
        return 3;
    }
    else{
        std::cout<<digit <<"\n"; 
        return val;
    }
}

int main(){
    int minDigit;
    std::cout << "Enter the maximum number of divisible value: ";
    std::cin >> minDigit;
    int result;
    try{
        result = findTheFirstTriangleNumber(minDigit);
    }
    catch(std::exception& e){
        std::cout << "Exception message: " << e.what();
    }
    catch(int a){
        std::cout << "catching "<< a << "\n";
    }
    catch(...){
        std::cout << "catching arbitrary message \n";
    }
    std::cout << "The first triangle number that has over " << minDigit
    << " digits is: " << result <<"\n";
    return 0;
}
