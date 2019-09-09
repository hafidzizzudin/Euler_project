#include<iostream>
#include<vector>
#include<ctime>

bool checkPalindrom(long long input){
    bool check = true;
    std::vector<int> digitCheck;
    while(input != 0){
        digitCheck.push_back(input%10);
        input/=10;
    }
    for(int i=0;i<digitCheck.size()/2;i++){
        if(digitCheck[i] != digitCheck[digitCheck.size()-1-i]){
            check = false;
            break;
        }
    }
    return check;
}

int pow(int a, int b){
    int result=1;
    while(b--){
        result*=a;
    }
    return result;
}

int main(){
    long long max_mult = 0; 
    int first=0, second=0;
    int digit;
    std::cout << "Enter the number of digit (max. 6 digits): "; 
    std::cin >> digit;
    int max = pow(10,digit)-1;
    //std::cout << max << " "<<pow(10,digit-1) <<" " << second << "\n";
    clock_t begin = clock();
    while(max>=pow(10,digit-1)){
        if(max<second)
            break;
        for(int i=max;i>=pow(10,digit-1);i--){
            long long mult = (long long)max*i;
            if(mult<max_mult)
                break;
            if(checkPalindrom(mult) && mult>max_mult){
                first = max;
                second = i;
                max_mult = mult;
            }
        }
        max--;
    }

    std::cout << "first value: " << first << "\n";
    std::cout << "second value: " << second << "\n";
    std::cout << "Multiplication value: " << max_mult << "\n";
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time: " << elapsed_secs <<"\n";
    return 0;
}
