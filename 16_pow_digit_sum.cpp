#include<iostream>
#include<vector>


class pow2_Factory{
    int power;
    std::vector<int> digits_hex;
    int total;
public:
    pow2_Factory(int input):power(input){};
    void digitsFactory(){
        for(int i=0;i<=power;i++){
            if(i==0){
                digits_hex.push_back(1);
                continue;
            }
            int remainder = 0;
            for(int j=0;j<digits_hex.size();j++){
                int mult = digits_hex[j]*2+remainder;
                digits_hex[j]=mult%10;
                remainder = (int)(mult/10);
            }
            while(remainder!=0){
                digits_hex.push_back(remainder%10);
                remainder = (int)(remainder/10);
            }
        }
    }
    // Adding vector number
    int addPow(){
        int result = 0;
        for(int i=0;i<digits_hex.size();i++){
            result+=digits_hex[i];
        }
        return result;
    }
    // showing the vector
    void showPow(){
        for(int i=digits_hex.size();i>=0;i--){
            std::cout << digits_hex[i];
        }
        std::cout <<"\n";
    }
    //~pow2_Factory();
};

int main(){
    int power;
    while(std::cin >> power){
        pow2_Factory test(power);
        test.digitsFactory();
        test.showPow();
        std::cout << "Value for power: "<< power 
            << " ,Total: " << test.addPow() << "\n\n";
    }
    return 0;
}
