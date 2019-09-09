#include<iostream>
#include<cmath>

void findSpecialPhyta(){
    bool found = false;
    int a,b,c;
    for(int i=1;i<999;i++){
        a=i;
        for(int j=i+1;j<999;j++){
            b=j;
            int csquare = a*a + b*b;
            c = (int)sqrt(csquare);
            if(csquare%c == 0){
                if(a+b+c == 1000){
                    found = true;
                    break;
                }
                else if(a+b+c > 1000){
                    break;
                }
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        std::cout << a << " + " << b << " + " << c << " = "<<a+b+c <<"\n";
        std::cout << a << " * " << b << " * " << c << " = "<<a*b*c <<"\n";
    }
    else
        std::cout << "Failed to find special triplet pythagorean\n";
}

int main(){
    
    findSpecialPhyta();
    return 0;
}
