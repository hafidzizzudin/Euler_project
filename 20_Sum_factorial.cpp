#include<iostream>
#include<vector>
#include<memory>

class factorial_Factory{
    int number;
    std::vector<int> digits_hex;
    int total;
public:
    factorial_Factory(int input):number(input){
        std::cout<< "factorial_Factory is created\n";
    }
    
    std::vector<int> mult_fact(int input, int pow){
        int remainder = 0;
        std::vector<int> tmp_vec = digits_hex;
        for(int j=0;j<tmp_vec.size();j++){
            int mult = tmp_vec[j]*input+remainder;
            tmp_vec[j]=mult%10;
            remainder = (int)(mult/10);
        }
        while(remainder!=0){
            tmp_vec.push_back(remainder%10);
            remainder = (int)(remainder/10);
        }
        if(pow==0){
            return tmp_vec;
        }
        else{
            // inserting 0 
            for(int i=0;i<pow;i++){
                tmp_vec.insert(tmp_vec.begin(),0);
            }
            return tmp_vec;
        }
    }
    
    std::vector<int> addition(std::vector<std::vector<int>>& tmp_vec){
        // summation digit_hex+tmp_vec
        for(int k=1;k<tmp_vec.size();k++){
            int remainder = 0; 
            int dif_size = tmp_vec[0].size()-tmp_vec[k].size();
            if(dif_size != 0){
                if(dif_size < 0){
                    dif_size*=-1;
                    tmp_vec[0].insert(tmp_vec[0].end(),dif_size,0);
                }else{
                    tmp_vec[k].insert(tmp_vec[k].end(),dif_size,0);
                }
            }
            
            for(int i=0;i<tmp_vec[0].size();i++){
                int add = tmp_vec[0][i] + tmp_vec[k][i]+remainder;
                tmp_vec[0][i] = add%10;
                remainder = (int)(add/10);
            }
            while(remainder!=0){
                tmp_vec[0].push_back(remainder%10);
                remainder = (int)(remainder/10);
            }
        }
        return tmp_vec[0];
    }
    
    void digitsFactory(){
        digits_hex.push_back(1);
        for(int i=1;i<=number;i++){
            // Digitize the i
            int tmp = i;
            std::vector<int> input;
            // Saving multiplier into vector input
            while(tmp!=0){
                input.push_back(tmp%10);
                tmp/=10;
            }
            if(input.size()==1){
                digits_hex = mult_fact(input[0],0);
            }
            else{
                std::vector<std::vector<int>> tmp_vec;
                for(int j=0;j<input.size();j++){
                    if(input[j] == 0){
                        continue;
                    }
                    tmp_vec.push_back(mult_fact(input[j],j));
                }
                digits_hex = addition(tmp_vec);
            }
        }
    }
    void calc_total(){
        total = 0;
        for(int i=0;i<digits_hex.size();i++){
            total+=digits_hex[i];
        }
    }
    
    ~factorial_Factory(){
        std::cout << "factorial_Factory is deleted\n";
    }
    void show_total(){
        std::cout << "The total number of " << number <<" factorial is: " 
            << total <<"\n";
    }
    
    void show_digit(){
        for(int i=digits_hex.size()-1;i>=0;i--){
            std::cout << digits_hex[i];
        }
        std::cout << "\n";
    }
};

int main(){
    int input;
    std::cout<<"Enter the number: \n";
    std::cin >> input;
    auto p = std::make_shared<factorial_Factory>(input);
    p->digitsFactory();
    p->show_digit();
    p->calc_total();
    p->show_total();
    
    return 0;
}
