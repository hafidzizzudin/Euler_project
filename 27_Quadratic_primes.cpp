#include<iostream>

bool check_prime(int test){
    if(test==2){
        return true;
    }
    else if(test<=0){
        return false;
    }
    int count_factor = 0;
    while(test%2==0){
        test/=2;
        count_factor++;
    }
    for(int i=3;i*i<=test;i+=2){
        while (test % i == 0)  
        {  
            test /= i;
            count_factor++;
        }
    }
    if(test>2){
        count_factor++;
    }
    if(count_factor==1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int a_max, b_max, longest_n=-1;
    for(int a=-999;a<1000;a++){
        if(a==0)
            continue;
        for(int b=-1000;b<=1000;b++){
            if(b==0){
                continue;
            }
            int n=0;
            while(true){
                //std::cout << a << " " << b << " " << n << "\n";
                int quad_func = n*n + a*n + b;
                if(check_prime(quad_func))
                    n++;
                else
                    break;
            }
            if(n>longest_n){
                longest_n = n;
                a_max = a;
                b_max = b;
            }
        }
    }
    std::cout << "The result of highest n: " << longest_n << "\n";
    std::cout << "The coefficient of a: " << a_max << ", and b: " << b_max << "\n";
    std::cout << "The product of coeffecient a and b: " << a_max*b_max <<"\n";
    
    return 0;
}
