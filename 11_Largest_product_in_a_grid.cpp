#include<iostream>
#include<vector>
#include<fstream>

void reading(std::vector<std::vector<int>>& dataset, int m, int n){
    std::ifstream infile; 
    infile.open("11_input.in");
    for(int i=0;i<m;i++){
        std::vector<int> rowinput;
        for(int j=0;j<n;j++){
            int tmp;
            infile >> tmp;
            rowinput.push_back(tmp);
        }
        dataset.push_back(rowinput);
    }
}

long long findHighestMult(std::vector<std::vector<int>>& dataset, int n_adj){
    long long largest=0;
    for(int i=0;i<dataset.size();i++){
        for(int j=0;j<dataset[0].size();j++){
            long long mult = 1;
            bool left = false, right = false, top = false, bot = false;
            //left
            if(j-n_adj+1>=0){
                left = true;
                int k = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[i][k];
                    k--;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //right
            if(j+n_adj-1<dataset[0].size()){
                right = true;
                int k = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[i][k];
                    k++;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //top
            if(i-n_adj+1>=0){
                top = true;
                int k = i;
                int count = n_adj;
                while(count--){
                    mult*=dataset[k][j];
                    k--;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //bot
            if(i+n_adj-1<dataset.size()){
                bot = true;
                int k = i;
                int count = n_adj;
                while(count--){
                    mult*=dataset[k][j];
                    k++;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //left-top
            if(left && top){
                int v = i;
                int h = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[v][h];
                    v--;
                    h--;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //left-bot
            if(left && bot){
                int v = i;
                int h = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[v][h];
                    v++;
                    h--;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //right-top
            if(right && top){
                int v = i;
                int h = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[v][h];
                    v--;
                    h++;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
            //right-bot
            if(right && bot){
                int v = i;
                int h = j;
                int count = n_adj;
                while(count--){
                    mult*=dataset[v][h];
                    v++;
                    h++;
                }
                if(largest<mult)
                    largest = mult;
                mult = 1;
            }
        }
    }
    
    return largest;
}

int main(){
    std::vector<std::vector<int>> dataset;
    int m, n, n_adj;
    
    std::cout << "Enter the height (m) of grid (m x n): "; 
    std::cin >> m;
    std::cout << "Enter the length (n) of grid (m x n): "; 
    std::cin >> n;
    std::cout << "Enter the number of adjacent number: ";
    std::cin >> n_adj;
    
    reading(dataset, m, n);
    
    long long result = findHighestMult(dataset,n_adj);
    std::cout << "The highest adjacent of four number in the grid is: " 
    << result << "\n";
}
