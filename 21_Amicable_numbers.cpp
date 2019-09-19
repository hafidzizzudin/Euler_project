#include<iostream>
#include<vector>

int sum_proper_div(int enter){
    if(enter==1){
        return 1;
    }
    int sum=0;
    int input = enter;
    // Collecting all factors
    // Source: https://math.stackexchange.com/questions/2782625/how-to-get-all-the-factors-of-a-number-using-its-prime-factorization
    std::vector<int> factor(1,1);
    int mult=1;
    while(input%2==0){
        input/=2;
        mult*=2;
        factor.push_back(mult*factor[0]);
    }
    for(int i=3;i*i<=input;i+=2){
        int index_max = factor.size();
        mult = 1;
        while (input % i == 0)  
        {  
            input /= i;
            mult*=i;
            for(int j = 0;j<index_max;j++){
                factor.push_back(mult*factor[j]);
            }
        }
    }
    if(input>2){
        int index_max = factor.size();
        for(int j=0;j<index_max;j++){
            factor.push_back(input*factor[j]);
        }
    }
    // Sum all factor
    for(int i=0;i<factor.size();i++){
        sum+=factor[i];
    }
    return sum-enter;
}

int main(){
    int sum_amic = 0;
    int prev = 0;
    for(int i=1;i<=10000;i++){
        int amic = sum_proper_div(i);
        int amic2 = sum_proper_div(amic);
        if(amic2 == i){
            if(i!=amic){
                if(i!=prev){
                    prev = amic;
                    sum_amic = sum_amic + i + amic;
                    std::cout << "a: " << i <<", f(a): " << amic <<"\n";
                    std::cout << "b: " << amic << ", f(b): " << amic2 <<"\n\n";
                }
            }
        }
    }
    std::cout << "The sum of amiccable number below 10000 is: " 
        << sum_amic << "\n"; 
    return 0;
}
