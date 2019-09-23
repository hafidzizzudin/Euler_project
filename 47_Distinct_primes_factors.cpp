#include<iostream>

int check_prime(int test){
    int prime_num = 0;
    bool found = false;
    while(test%2==0){
        test/=2;
        if(!found){
            found = true;
            prime_num++;
        }
    }
    for(int i=3;i*i<=test;i+=2){
        found = false;
        while (test % i == 0)  
        {  
            test /= i;
            if(!found){
                found = true;
                prime_num++;
            }
        }
    }
    if(test>2){
        prime_num++;
    }
    return prime_num;
}

int main(){
    int current, prev1=3, prev2=3, prev3=3;
    int cur_num=647;
    while(true){
        current = check_prime(cur_num);
        if(prev1==4 && prev2==4 && prev3==4 && current==4){
            break;
        }
        prev3 = prev2;
        prev2 = prev1;
        prev1 = current;
        cur_num++;
    }
    std::cout << "The first 4 consecutive number that has 4 distinct prime factor: " 
        << cur_num-3 << "\n";
    return 0;
}
