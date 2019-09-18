#include<iostream>
#include<vector>
#include<fstream>


void reading_input(std::vector<std::vector<int>>& pyramid){
    std::ifstream infile;
    infile.open("18_input.in");
    for(unsigned int i=1;i<=15;i++){
        std::vector<int> input;
        for(unsigned int j=1;j<=i;j++){
            int tmp;
            infile >> tmp;
            input.push_back(tmp);
        }
        pyramid.push_back(input);
    }
}

int max_sum_path(std::vector<std::vector<int>>& pyramid){
    for(int i=pyramid.size()-2;i>=0;i--){
        int next = i+1;
        std::cout << next <<"\n";
        for(int j=0;j<pyramid[i].size();j++){
            if(pyramid[next][j] > pyramid[next][j+1])
                pyramid[i][j] += pyramid[next][j];
            else
                pyramid[i][j] += pyramid[next][j+1];
        }
    }
    return pyramid[0][0];
}


int main(){
    std::vector<std::vector<int>> pyramid;
    reading_input(pyramid);
    int result = max_sum_path(pyramid);
    std::cout << "The maximum sum of the path is: " << result << "\n";
    return 0;
}
