#include<iostream>
#include<vector>

int findPrime(int n_prime){
    std::vector<int> primevec(1,2);
    int test = 3;
    while(primevec.size() != n_prime){
        bool prime = true;
        for(int i=0;primevec[i]*primevec[i]<=test;i++){
            if(test%primevec[i] == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            primevec.push_back(test);
        }
        test+=2;
    }
    return *(primevec.end()-1);
}

int main(){
    int n_prime;
    std::cout <<"Enter intended n-th prime: ";
    std::cin >> n_prime;
    
    std::cout <<"Prime number " << n_prime << " is: " << findPrime(n_prime) << "\n";
    return 0;
}
