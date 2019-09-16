#include<iostream>
#include<vector>

void simplified(std::vector<int>& top_vec, std::vector<int>& bot_vec){
    //bool simable = false;
    for(int i=0;i<top_vec.size();i++){
        for(int j=0;j<bot_vec.size();j++){
            if(top_vec[i]%bot_vec[j]==0 && top_vec[i]!= 1){
                top_vec[i]/=bot_vec[j];
                bot_vec[j]=1;
            }
        }
    }
    for(int i=0;i<bot_vec.size();i++){
        for(int j=0;j<top_vec.size();j++){
            if(bot_vec[i]%top_vec[j]==0 && bot_vec[i]!= 1){
                bot_vec[i]/=top_vec[j];
                top_vec[j]=1;
            }
        }
    }
    for(int i=0;i<top_vec.size();i++){
        for(int j=0;j<bot_vec.size();j++){
            if(top_vec[i]%bot_vec[j]==0 && top_vec[i]!= 1){
                top_vec[i]/=bot_vec[j];
                bot_vec[j]=1;
            }
        }
    }
    for(int i=0;i<bot_vec.size();i++){
        for(int j=0;j<top_vec.size();j++){
            if(bot_vec[i]%top_vec[j]==0 && bot_vec[i]!= 1){
                bot_vec[i]/=top_vec[j];
                top_vec[j]=1;
            }
        }
    }
}

int main(){
    int top, bot;
    //top = 40;
    //bot = 20;
    std::cout << "Enter the grid size (n) for grid nxn: ";
    std::cin >> bot;
    top = bot*2;
    std::vector<int> top_vec;
    std::vector<int> bot_vec;
    for(int i=top;i>bot;i--){
        top_vec.push_back(i);
    }
    for(int i=bot;i>0;i--){
        bot_vec.push_back(i);
    }
    simplified(top_vec,bot_vec);
    std::cout << "Top vector: ";
    for(int i=0;i<top_vec.size();i++){
        std::cout<<top_vec[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Bot vector: ";
    for(int i=0;i<bot_vec.size();i++){
        std::cout<<bot_vec[i] << " ";
    }
    
    long long result=1;
    for(int i=0;i<top_vec.size();i++){
        result=(long long)(result*top_vec[i]);
    }
    for(int i=0;i<bot_vec.size();i++){
        result=(long long)(result/bot_vec[i]);
    }
    std::cout << "\n";
    std::cout << result << "\n";
    return 0;
}
