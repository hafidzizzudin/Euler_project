#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

int letter_to_number(char& input){
    switch(input){
        case 'A':   return 1;
            break;
        case 'B':   return 2;
            break;
        case 'C':   return 3;
            break;
        case 'D':   return 4;
            break;
        case 'E':   return 5;
            break;
        case 'F':   return 6;
            break;
        case 'G':   return 7;
            break;  
        case 'H':   return 8;
            break;  
        case 'I':   return 9;
            break;  
        case 'J':   return 10;
            break;  
        case 'K':   return 11;
            break;  
        case 'L':   return 12;
            break;
        case 'M':   return 13;
            break;  
        case 'N':   return 14;
            break;  
        case 'O':   return 15;
            break;  
        case 'P':   return 16;
            break;  
        case 'Q':   return 17;
            break;  
        case 'R':   return 18;
            break;  
        case 'S':   return 19;
            break;  
        case 'T':   return 20;
            break;  
        case 'U':   return 21;
            break;  
        case 'V':   return 22;
            break;  
        case 'W':   return 23;
            break;  
        case 'X':   return 24;
            break;
        case 'Y':   return 25;
            break;  
        case 'Z':   return 26;
            break;
        default: return 0;
    }
}


void reading_input_n_count_score(int& result){
    // reading save all input into big string line
    std::ifstream infile;
    infile.open("22_input.in");
    std::string line;
    infile >> line;
    
    // save it into vector string
    std::stringstream ss(line);
    std::string name;
    std::vector<std::string> names; 
    while(std::getline(ss, name,',')){
        names.push_back(name);
    }
    
    // sort the vector
    std::sort(names.begin(),names.end());
    
    // count total scores
    for(int k=0;k<names.size();k++){
        int sum=0;
        for(int i=0;i<names[k].size();i++){
            sum+=letter_to_number(names[k][i]);
        }
        std::cout <<"Name: " << names[k] << ", T_let_num: " << sum 
            <<", Count: " << k+1 <<", Score: " << sum*(k+1) << "\n";
        result=result+(sum*(k+1));
    }
}

int main(){
    int result=0;
    reading_input_n_count_score(result);
    std::cout << "The total score for all names: " << result << "\n";
    
    return 0;
}
