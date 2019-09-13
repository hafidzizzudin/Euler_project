#include<iostream>
#include<algorithm>
#include<vector>

class Collatz{
    public:
        static std::vector<long long> Chain;
        static std::vector<long long> Length;
};

long long collatz(long long input){
    auto it = find(Collatz::Chain.begin(),Collatz::Chain.end(),input);
    if(it != Collatz::Chain.end())
    {
        return Collatz::Length[it-Collatz::Chain.begin()];
    }
    else
    {   
        long long count;
        if(input%2==0){
            count = 1 + collatz(input/2);
        }
        else
        {
            count = 1 + collatz(input*3 + 1);
        }
        Collatz::Chain.push_back(input);
        Collatz::Length.push_back(count);
        return count;
    }
}

std::vector<long long> makeVector(){
    std::vector<long long> v;
    v.push_back(1);
    return v;
}

std::vector<long long> Collatz::Chain = makeVector();
std::vector<long long> Collatz::Length = makeVector();

int main(){
    /*
    long long input;
    std::cout << "Enter the maximum number number: ";
    std::cin >> input;
    long long target_val = 1, largest = 0;
    while(target_val<input){
        long long digit = collatz(target_val);
        if(digit > largest){
            std::cout << "Vector cap: "<< Collatz::Chain.size()
            <<", The number of digit in collatz sequence of " << target_val
            <<": " << digit << "\n";
            largest = digit;
        }
        target_val++;
    }*/
    
    unsigned long input;
    std::cout << "Enter the maximum number number: ";
    std::cin >> input;
    unsigned long longest=0, longest_val;
    unsigned long curval;
    
    for(unsigned long i=1;i<input;i++){
        curval = i;
        int counter=1;
        while(curval!=1){
            counter++;
            if(counter > longest){
                longest = counter;
                longest_val = i;
            }
            if(curval%2 == 0)
                curval/=2;
            else
                curval=curval*3+1;
        }
    }
    
    std::cout <<"The longest sequence belongs to: " << longest_val
        << ", with number of sequence: " << longest <<"\n";
    
    return 0;
}
