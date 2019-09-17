#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> number{1,2,3,4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,18,19,20,
    30,40,50,60,70,80,90};
std::vector<int> n_letter{3,3,5,4,4,3,5,5,4,3,
    6 ,6 ,8 ,8 ,7 ,7 ,9 ,8 ,8 , 6, 
     6, 5, 5, 5, 7, 6, 6};
  //30,40,50,60,70,80,90
int count_letter(int input){
    int count = 0;
    bool hundred = false,ten=false;
    // direct return if input = 1000
    if(input==1000)
        return 11;
    //check 100's number
    if((int)input/100 != 0){
        auto it = find(number.begin(),number.end(),(int)(input/100));
        count+=n_letter[it-number.begin()]+7;
        input = input%100;
        hundred = true;
    }
    if(input==0)
    {
        return count;
    }
    if((int)input/10!=0){
        auto it = find(number.begin(),number.end(),input);
        if(it!=number.end()){
            input = 0;
        }
        else{
            int remainder = input%10;
            int target = input - remainder;
            it = find(number.begin(),number.end(),target);
            input = remainder;
        }
        
        if(hundred)
            count+=n_letter[it-number.begin()]+3; // for and if hundred's found
        else
            count+=n_letter[it-number.begin()];
        ten = true;
    }
    if(input==0)
    {
        return count;
    }
    else{
        auto it = find(number.begin(),number.end(),input);
        count+=n_letter[it-number.begin()];
        if(hundred && !ten)
            return count+3; // for and if no ten's
        else
            return count;
    }
    
}

int counting_total(int max){
    int count = 0;
    for(int i=1;i<=max;i++){
        count += count_letter(i);
    }
    return count;
}

int main(){

    int count = counting_total(1000);
    std::cout<<"The total of letter from 1 to 1000 is: " << count <<"\n";
    /*
    int input;
    while(std::cin>>input){
        std::cout <<"Input: " << input << ", Result: " << count_letter(input) <<"\n";
    }
    */
}
