#include<iostream>
#include<fstream>
#include<vector>

std::vector<int> reading_n_sum(int m, int n){
    std::ifstream infile; 
    infile.open("13_Input.in");
    
    if(infile.is_open()){
        std::cout << "The file is successfully opened\n";
    }
    else{
        std::cout << "Opening file failed\n";
    }
    
    std::vector<int> sum (50,0);
    
    char line[n];
    
    for(int i=0;i<m;i++){
        infile >> line;
        int index_vec = 0;
        int remain = 0;
        for(int j=n-1;j>=0;j--){
            int val = line[j] - '0';
            int addition = remain + val + sum[index_vec];
            sum[index_vec] = addition%10;
            remain = addition/10;
            index_vec++;
        }
        while(remain != 0){
            if(index_vec < sum.size()){
                int addition = remain + sum[index_vec];
                sum[index_vec] = addition%10;
                remain = addition/10;
                index_vec++;
            }
            else{
                sum.push_back(remain%10);
                remain = remain/10;
                index_vec++;
            }
        }
    }
    return sum;
}

void print_first_ten_digit(std::vector<int>& digits){
    for(int i=digits.size()-1;i>=digits.size()-10;i--){
        std::cout << digits[i];
    }
    std::cout<<"\n";
}

int main(){
    int m,n;
    
    std::cout << "Enter the height (m) of matrix mxn: ";
    std::cin >> m;
    std::cout << "Enter the height (n) of matrix mxn: ";
    std::cin >> n;
    
    std::vector<int> digits = reading_n_sum(m,n);
    print_first_ten_digit(digits);
    
    return 0;
}
