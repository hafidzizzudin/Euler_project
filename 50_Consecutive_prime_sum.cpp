#include<iostream>
#include<vector>

bool check_prime(int test){
    if(test==2){
        return true;
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
    int max_sum, temp_prime_sum = 2, target = 3, largest_prime_of_sum=0, index = 1;
    int start, end, longest_cons_index=0;
    std::cout << "Enter the maximum sum: ";
    std::cin >> max_sum;
    std::vector<int> vec_prime_sum{0,2};
    bool dont_reach_max = true;
    while(dont_reach_max){
        if(check_prime(target)){ // Checking if input value is prime or not
            index++;
            temp_prime_sum+=target; // checking if the sum is prime or not
            vec_prime_sum.push_back(temp_prime_sum);
            for(int i=index-2;i>=0;i--){
                int tmp_sum = vec_prime_sum[index]-vec_prime_sum[i];
                int tmp_cons_index = index-i+1;
                if(check_prime(tmp_sum) && (tmp_cons_index>longest_cons_index)){
                    largest_prime_of_sum = tmp_sum;
                    longest_cons_index = tmp_cons_index;
                    start = i;
                    end = index;
                }
                if(tmp_sum >= max_sum){
                    dont_reach_max = false;
                    break;
                }
            }
        }
        target+=2;
    }
    for(int i=start+1;i<=end;i++){
        std::cout << vec_prime_sum[i]-vec_prime_sum[i-1] << " ";
    }
    std::cout << "\n";
    std::cout << "Start: " << start+1 <<", End: " << end << ", Length: " 
        << end-start << "\n";
    
    std::cout << "The longest number of consecutive prime below max_sum "
        << max_sum <<" is: " << largest_prime_of_sum << "\n";
    return 0;
}
