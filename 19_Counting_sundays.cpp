#include<iostream>
#include<vector>

int main(){
    std::vector<int> month{31,0,31,30,31,30,31,31,30,31,30,31};
                          //1,2,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12 
    int years=1901;
    int count = 0;
    int day = 2;
    if(day==0){
        count++;
    }
    while(years<=2000){
        bool leap = false;
        if(years%100 == 0){
            if(years%400 == 0){
                leap = true;
            }
        }
        else if(years%4 == 0){
            leap = true;
        }
        int dates;
        for(int i=1;i<=12;i++){
            if(i==2){
                if(leap){
                    dates = 29;
                }
                else{
                    dates = 28;
                }
            }
            else{
                dates = month[i-1];
            }
            day = day + dates%7;
            day = day%7;
            
            if(day==0){
                count++;
            }
        }
        years++;
    }
    std::cout << "Number of Sunday: " << count << "\n";
    return 0;
}
