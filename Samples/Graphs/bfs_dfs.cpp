#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using modifier = void (*) (int&);

bool graph[5][5]={    {true,false,true,false,false},
                      {false,false,true,true,false},
                      {true,true,false,true,false},
                      {false,true,true,false,true},
                      {false,false,false,true,false}    };

bool existsIn(int vertex, std::vector<int> list){
    for(auto v: list){
        if(v == vertex) return true;
    }
    return false;
}

void traverseBFS(int start, std::vector<int> visited, modifier m){
    std::queue<int> traverseQueue;
    traverseQueue.push(start);
    while(!traverseQueue.empty()){
        int currentVertex = traverseQueue.front();
        traverseQueue.pop();
        if(!existsIn(currentVertex,visited)){
            visited.push_back(currentVertex);
            m(currentVertex);
            for(int i=0; i<5; i++){
                if( graph[currentVertex][i] && !existsIn(i, visited)) {
                    traverseQueue.push(i);
                }
            }
        }

    }

}
//modified version
void traverseBFS2(int start, std::vector<int> visited, modifier m){
    std::queue<int> traverseQueue;
    traverseQueue.push(start);
    int l=0;
    while(!traverseQueue.empty()){
        std::vector<int> levelContainer;
        std::cout<<"Level:" << l << std::endl;
        while(!traverseQueue.empty()){
            int currentVertex = traverseQueue.front();
            levelContainer.push_back(currentVertex);
            if(!existsIn(currentVertex, visited)){
                visited.push_back(currentVertex);
                m(currentVertex);
            }
            traverseQueue.pop();
        }
        for(auto vertex : levelContainer) {
            for(int i=0;i<5;i++){
                if(graph[vertex][i] && !existsIn(i, visited)){
                    traverseQueue.push(i);
                }
            }
        }
        std::cout<<std::endl;
        l++;
    }

}


void traverseDFS(int start, std::vector<int> visited, modifier m){
    std::stack<int> traverseStack;
    traverseStack.push(start);
    while(!traverseStack.empty()){
        int currentVertex = traverseStack.top();
        traverseStack.pop();
        if(!existsIn(currentVertex,visited)){
            visited.push_back(currentVertex);
            m(currentVertex);
            for(int i=0; i<5; i++){
                if( graph[currentVertex][i] && !existsIn(i, visited)) {
                    traverseStack.push(i);
                }
            }
        }

    }
}
void print(int& elem){
    std::cout<<elem<<" ";
}


int main() {
    std::vector<int> v;
    traverseDFS(0,v, print);
}