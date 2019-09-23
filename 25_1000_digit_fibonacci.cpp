#include<iostream>
#include<vector>


class BigInteger{
    private:
        std::vector<int> fibonaci_digit;
    public:
        BigInteger(){};
        BigInteger(std::vector<int> input):fibonaci_digit(input){};
        
        int call_size() const
        {
            return this->fibonaci_digit.size();
        }
        
        int getDigit(const int& index) const
        {
            return fibonaci_digit[index];
        }
        
        void push_back(int val){
            this->fibonaci_digit.push_back(val);
        }
        
        BigInteger operator+(const BigInteger& right) const
        {
            BigInteger res;
            int dif = this->fibonaci_digit.size()-right.call_size();
            int remainder=0, limit_out, limit_in;
            if(dif>0){
                limit_out = this->fibonaci_digit.size();
                limit_in = right.call_size();
            }
            else{
                limit_out = right.call_size();
                limit_in = this->fibonaci_digit.size();
            }
            for(int i=0;i<limit_out;i++)
            {   
                int addition;
                if(i<limit_in){
                    addition = right.getDigit(i);
                }
                else{
                    addition=0;
                }
                int tmp_sum = this->fibonaci_digit[i]+addition+remainder;
                remainder = tmp_sum/10;
                res.push_back(tmp_sum%10);
            }
            while(remainder!=0){
                res.push_back(remainder%10);
                remainder/=10;
            }
            return res; 
        }
        
        void print(){
            if(this->fibonaci_digit.size()!=0){
                for(int i=this->fibonaci_digit.size()-1;i>=0;i--){
                    std::cout << this->fibonaci_digit[i];
                }
                std::cout << "\n";
            }
            else{
                std::cout << "No digit contained\n";
            }
        }
        ~BigInteger(){}
};


int main(){
    std::vector<int> init(1,1);
    BigInteger prev1(init);
    BigInteger prev2(init);
    BigInteger current;
    int index=3;
    int size =0;
    int target_length = 1000, cur_length=0;
    while(cur_length<target_length){
        current = prev1+prev2;
        prev2 = prev1;
        prev1 = current;
        cur_length = current.call_size();
        index++;
    }
    std::cout << "The index of the first term of Fibonacci sequence which contain " << target_length 
        <<" digits is: " << index-1 << "\n";
    return 0;
}
