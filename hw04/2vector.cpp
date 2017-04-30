#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
using namespace std;

class MaxHeap{
    public:
        MaxHeap(){
            tree.push_back(-1);
            score.push_back(0);
            iterator.push_back(-1);
        }
        ~MaxHeap();
        bool empty(){return tree.size()==1;}
        int size(){ return tree.size();}
        void insert(int id, long long value);
        void swapNode(int parent,int kid){
            int tmp = iterator[kid];
            iterator[kid] = iterator[parent];
            iterator[parent] = tmp;
        }
        void update(long long add, int id){
            score[iterator[pos[id]]]+=add;
            int iter = pos[id];
            long long value = score[iterator[pos[id]]];
            upHeap(iter,id,value);
        }
        void upHeap(int iter, int id, long long value){
            while(true){
                if (iter==1) {
                    pos[id] = iter;
                    break;
                }
                int parent_pos = iter/2;
                int parent_id = tree[iterator[parent_pos]];
                long long parent_value = score[iterator[parent_pos]];
                if(parent_value <= value){
                    swapNode(parent_pos,iter);
                    pos[parent_id] = iter;
                    iter = parent_pos;
                }
                else{
                    pos[id] = iter; 
                    break;
                }
            }
        }
        void printRoot(long long n){
            int root = iterator[1];
            int id = tree[root];
            long long value = score[root] - n;
            cout << "id: " << id << ", value: " <<  value << "\n";
        }
    private:
        vector<int> tree;
        vector<long long> score;
        unordered_map<int,int> pos;
        vector<int> iterator;
};

void MaxHeap::insert(int id, long long value){
    tree.push_back(id);
    score.push_back(value);
    int current_pos = tree.size()-1;
    iterator.push_back(current_pos);
    int iter = iterator.size()-1;
    upHeap(iter,id,value);
}

int main(){
    ios::sync_with_stdio(false);
    long long action_number, deducted,tmp, deducted_count=0;
    scanf("%lld%lld", &action_number,&deducted);
    vector<long long> data;
    while(scanf("%lld", &tmp) != EOF) data.push_back(tmp);
    MaxHeap* tree = new MaxHeap;
    for(int i = 0; i < data.size(); i++){
        switch(data[i]){
            case 1:{
                deducted_count++;
                int id = data[i+1];
                long long value = data[i+2]+deducted_count*deducted;
                tree->insert(id,value);

                i=i+2;
                break;
            }
            case 2:{
                long long add = data[i+1]; 
                int n = data[i+2];
                for(int j = 0; j < n; j++) {
                    int current_id = data[i+3+j];
                    tree->update(add,current_id);
                }
                i = i + 2 + n; 
                break;
            }
            case 3:
                tree->printRoot(deducted_count*deducted);
                break;
            default:
                break;
        }
    }
    return 0;
}