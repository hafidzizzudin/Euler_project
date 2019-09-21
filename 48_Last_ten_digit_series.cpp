#include<iostream>
#include<vector>

void add_vector(std::vector<int>& series_unit, const
std::vector<std::vector<int>>& tmp_vec){
    int remainder = 0;
    for(int i=0;i<10;i++){
        int tmp=0;
        for(int j=0;j<tmp_vec.size();j++){
            if(i<tmp_vec[j].size()){
                tmp+=tmp_vec[j][i];
            } 
        }
        series_unit[i] = (tmp+remainder)%10;
        remainder=(tmp+remainder)/10;
    }
}

std::vector<int> mult_fact(std::vector<int> tmp_vec,int input,int pow){
    int remainder = 0;
    for(int j=0;j<tmp_vec.size();j++){
        int mult = tmp_vec[j]*input+remainder;
        tmp_vec[j]=mult%10;
        remainder = (int)(mult/10);
    }
    if(pow==0){
        return tmp_vec;
    }
    else{
        // inserting 0 
        tmp_vec.insert(tmp_vec.begin(),pow,0);
        return tmp_vec;
    }
}

void mult_vector(std::vector<int>& series_unit, const std::vector<int>& digit_num){
    if(digit_num.size()==1){
        series_unit = mult_fact(series_unit,digit_num[0],0);
        return;
    }
    else{
        std::vector<std::vector<int>> tmp_vec;
        for(int j=0;j<digit_num.size();j++){
            if(digit_num[j] == 0){
                continue;
            }
            tmp_vec.push_back(mult_fact(series_unit,digit_num[j],j));
        }
        add_vector(series_unit,tmp_vec); // update and adding series unit by all digit mult
    }
}

void update_first_ten(std::vector<int>& first_ten_digit, int num){
    // digitize num
    std::vector<int> digit_num;
    int pow = num;
    int remainder = 0;
    while(num!=0){
        digit_num.push_back(num%10);
        num/=10;
    }
    // multiplication of number, pow times
    std::vector<int> series_unit(10,0);
    for(int i=1;i<=pow;i++){
        if(i==1){
            for(int j=0;j<digit_num.size();j++){
                series_unit[j] = digit_num[j];
            }
        }
        else{
            mult_vector(series_unit,digit_num); //multiply and update series unit by digit_num
        }
    }
    // update first_ten_digit by adding the new series unit from above block
    remainder = 0;
    for(int i=0;i<10;i++){
        int tmp_add = first_ten_digit[i] + series_unit[i] + remainder;
        first_ten_digit[i] = tmp_add%10;
        remainder = tmp_add/10;
    }
}

void show_digit(const std::vector<int>& first_ten_digit){
    std::cout << "The first ten digit of the series is: ";
    for(int i=first_ten_digit.size()-1;i>=0;i--){
        std::cout << first_ten_digit[i];
    }
    std::cout <<"\n";
}


int main(){
    std::vector<int> first_ten_digit(10,0);
    show_digit(first_ten_digit);
    int max;
    std::cout << "Enter the max series: ";
    std::cin >> max; 
    for(int i=1;i<=max;i++){
        if(i%10!=0){
            update_first_ten(first_ten_digit,i);
        }
    }
    show_digit(first_ten_digit);
    return 0;
}
