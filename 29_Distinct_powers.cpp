#include<iostream>
#include<vector>
#include<algorithm>

class BigInteger{
    private:
        std::vector<int> digit;
    public:
        // CONSTRUCTOR
        // blank, std::vector<int>, int, std::string
        BigInteger(){};
        BigInteger(std::vector<int> input):digit(input){};
        BigInteger(int input){
            if(input==0){
                this->digit.push_back(0);
                return;
            }
            while(input!=0){
                this->digit.push_back(input%10);
                input/=10;
            }
        }
        BigInteger(const std::string& input){
            for(int i=input.size()-1;i>=0;i--){
                int tmp = input[i]-'0';
                this->digit.push_back(tmp);
            }
            //Clearing leading 0
            while(*(this->digit.end()-1)==0 && this->digit.size()!=1){
                this->digit.pop_back();
            }
        }
        
        // Function to get the size of the digit
        int call_size() const
        {
            return this->digit.size();
        }
        
        // Function to get the digit at index
        int getDigit(const int& index) const
        {
            return this->digit[index];
        }
        
        // Function to push new digit at last element
        void push_back(int val){
            this->digit.push_back(val);
        }
        
        // Function to insert val in it with n times
        void insert(std::vector<int>::iterator it,int n, int val){
            this->digit.insert(it,n,val);
        }
         
        // Function to return pointer at beginning
        std::vector<int>::iterator begin(){
            return this->digit.begin();
        }
        
        // Function to return pointer at beginning
        std::vector<int>::iterator end(){
            return this->digit.end();
        } 
        
        // Summation operator + overloading
        BigInteger operator+(const BigInteger& right) const
        {
            BigInteger res;
            int dif = this->digit.size()-right.call_size();
            int remainder=0, limit_out, limit_in;
            if(dif>0){
                limit_out = this->digit.size();
                limit_in = right.call_size();
            }
            else{
                limit_out = right.call_size();
                limit_in = this->digit.size();
            }
            for(int i=0;i<limit_out;i++)
            {   
                int added, addition;
                if(dif>0)
                    added = this->digit[i];
                else
                    added = right.getDigit(i);
                if(i<limit_in){
                    if(dif>0)
                        addition = right.getDigit(i);
                    else
                        addition = this->digit[i];
                }
                else{
                    addition=0;
                }
                int tmp_sum = added+addition+remainder;
                remainder = tmp_sum/10;
                res.push_back(tmp_sum%10);
            }
            while(remainder!=0){
                res.push_back(remainder%10);
                remainder/=10;
            }
            return res; 
        }
        
        // Multiplication operator * overloading
        BigInteger operator*(const BigInteger& right) const
        {
            BigInteger res(0);
            // multiplication of each element at right
            for(int i=0;i<right.call_size();i++){ //loop through right elements
                if(right.getDigit(i)!=0){
                    int remainder = 0;
                    BigInteger tmp;
                    for(int j=0;j<this->digit.size();j++){ //loop through left element
                        int mult = this->digit[j]*right.getDigit(i)+remainder;
                        tmp.push_back(mult%10);
                        remainder = (int)(mult/10);
                    }
                    while(remainder!=0){
                        tmp.push_back(remainder%10);
                        remainder/=10;
                    }
                    if(i==0){
                        res=tmp;
                    }
                    else{
                        // inserting 0
                        if(*(tmp.end()-1)!=0)
                            tmp.insert(tmp.begin(),i,0);
                        res=res+tmp;
                    }
                }
            }
            return res;
        }
        
        // Increment operator ++ overloading
        void operator++(){
            BigInteger unity(1);
            (*this) = (*this)+ unity;
        }
        
        // Power operator ^ overloading
        BigInteger operator^(const BigInteger& right) const
        {
            BigInteger res(1);
            BigInteger counter(1);
            while(counter<=right){
                res = res*(*this);
                ++counter;
            }
            return res;
        }
        
        // Equal operator == overloading
        bool operator==(const BigInteger& right) const
        {
            // size check
            if(this->digit.size()==right.call_size()){
                for(int i=0;i<this->digit.size();i++){
                    // element check
                    if(this->digit[i]!=right.getDigit(i))
                        return false;
                }
            }
            else{
                return false;
            }
            return true;
        }
        
        // Greater than operator > overloading
        bool operator>(const BigInteger& right) const
        {
            // size check
            if(this->digit.size()>right.call_size())
                return true;
            else if(this->digit.size()==right.call_size()){
                for(int i=digit.size()-1;i>=0;i--){
                    // element check
                    if(this->digit[i]>right.getDigit(i)){
                        return true;
                    }
                    else if(this->digit[i]==right.getDigit(i)){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            return false;
        }
        
        // Less than equal operator <= overloading
        bool operator<=(const BigInteger& right) const
        {
            return !(*this>right);
        }
        
        // Unequal operator != overloading
        bool operator!=(const BigInteger& right) const
        {
            return !(*this==right);
        }
        
        // Print the digit reversed
        void print(){
            if(this->digit.size()!=0){
                for(int i=this->digit.size()-1;i>=0;i--){
                    std::cout << this->digit[i];
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
    std::vector<BigInteger> combination;
    for(int a=2;a<=100;a++){
        for(int b=2;b<=100;b++){
            BigInteger tmp1(a);
            BigInteger tmp2(b);
            auto res = tmp1^tmp2;
            std::vector<BigInteger>::iterator it= find(combination.begin(),combination.end(),res);
            if(it==combination.end()){
                combination.push_back(res);
            }
        }
    }
    std::cout << "The number of distinct term is: " << combination.size() << "\n"; 
    //combination.back().print();
    return 0;
}
