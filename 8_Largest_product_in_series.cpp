#include<iostream>
#include<string>
#include<fstream>
#include<vector>

long long maxMultAdjacent(std::vector<int> dataset, int nset){
    long long largest = 0;
    long long mult = 1;
    int index = 0;
    for(int i=0;i<nset;i++){
        mult*=(long long)dataset[index];
        index++;
    }
    largest = mult;
    //std::cout << index << " " << start << "\n";
    while(index<dataset.size()){
        if(dataset[index-nset] == 0){
            mult = 1;
            for(int i=index-nset+1;i<=index;i++){
                mult *= (long long)dataset[i];
            }
        }
        else{
            mult/= (long long)dataset[index-nset];
            mult*= (long long)dataset[index];
        }
        if(mult>largest){
            std::cout <<"INDEX: " << index <<", VALUE: " << mult << "\n";
            largest = mult;
        }
        index++;
    }
    std::cout << "LAST INDEX: " << index << "\n";
    return largest;
}

int main(){
    std::vector<int> dataset(1000);
    std::ifstream infile; 
    infile.open("8_input.in");
    
    for(int i=0;i<20;i++){
        char line[50];
        infile >> line;
        for(int j=0;j<50;j++){
            dataset[i*50+j] = line[j] - '0';
            //std::cout << dataset[i*50+j];
        }
    }
    
    int nset;
    std::cout <<"Enter the number of adjacent values: ";
    std::cin >> nset;
    long long result = maxMultAdjacent(dataset,nset);
    std::cout <<"The largest multiplication of " 
    << nset <<" adjacent numbers: "<< result << "\n";
    
    return 0;
}
