#include<iostream>
#include<vector>
#include<algorithm>

int pow(int a, int b){
    int result=1;
    while(b--){
        result*=a;
    }
    return result;
}

int KPK(int max){
    int total = 1;
    std::vector<int> prime = {2};//,3,5,7,11,13,17,19};
    std::vector<int> power(1,0);
   //assignPrimeFactor(power,prime,max);
    for(int target=2;target<=max;target++){
        int count = 0, val = target;
        while(val%2==0){
            val/=2;
            count++;
        }
        if(count != 0 && count > power[0]){
            power[0] = count;
        }
        
        for(int i=3;i*i<=val;i+=2){
            std::cout << "PASS\n";
            count = 0;
            while (val % i == 0)  
            {  
                val = val/i;
                count++;  
            }
            if(count != 0){
                auto it = find(prime.begin(),prime.end(),i);
                if(it != prime.end()){
                    int index = it-prime.begin();
                    if(power[index] < count)
                        power[index] = count;
                }
                else{
                    prime.push_back(i);
                    power.push_back(1);
                }
            }
        }
        
        if(val>2){
            auto it = find(prime.begin(),prime.end(),val);
            if(it != prime.end()){
                int index = it-prime.begin();
                if(power[index] == 0)
                    power[index] = 1;
            }
            else{
                prime.push_back(val);
                power.push_back(1);
            }
        }
        std::cout << "target: " << target << " ,Last value: "<< val << "\n";
    }
    //==================================================================
    for(int i=0;i<power.size();i++){
        std::cout << prime[i] << " " << power[i] << "\n";
        if(power[i] != 0)
            total*=pow(prime[i],power[i]);
    }
    return total;
}

int main(){
    int max ;
    //std::cout << "Enter the value: " <<std::endl;
    std::cin >> max;
    int result = KPK(max);
    std::cout << result << std::endl;
    return 0; 
}
