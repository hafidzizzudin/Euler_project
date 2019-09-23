#include<iostream>

int main(){
    int max_size = 1001;
    int current_size = 1;
    int sum = 1;
    int point1, point2, point3, point4=1;
    while(current_size<max_size){
        current_size+=2;
        int constant = (current_size-1);
        int jump = constant*4;
        point4 = point4+jump;
        point3 = point4-constant;
        point2 = point3-constant;
        point1 = point2-constant;
        sum += point1+point2+point3+point4;
    }
    std::cout << "The sum of diagonal in a 1001x1001 spiral formed is: " << sum <<"\n";
    
    return 0;
}
