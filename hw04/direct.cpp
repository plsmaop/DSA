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
        }
        ~MaxHeap();
        bool empty(){return tree.size()==1;}
        int size(){ return tree.size();}
        void insert(int id, long long value, long long deducted);
        void swapNode(int parent,int kid){
            int tmp = tree[kid];
            long long tmp2 = score[kid];
            tree[kid] = tree[parent];
            score[kid]=score[parent];
            tree[parent] = tmp;
            score[parent] = tmp2;
        }
        void update(long long add, int id){
            score[pos[id]]+=add;
            int current_pos = pos[id];
            long long value = score[pos[id]];
            upHeap(current_pos,id,value);
        }
        void upHeap(int current_pos,int id, long long value){
            while(true){
                if (current_pos==1) {
                    pos[id] = current_pos;
                    break;
                }
                int parent_pos = current_pos/2;
                int parent_id = tree[parent_pos];
                long long parent_value = score[parent_pos];
                if(parent_value < value){
                    swapNode(parent_pos,current_pos);
                    pos[parent_id] = current_pos;
                    current_pos = parent_pos;
                }
                else{
                    pos[id] = current_pos; 
                    break;
                }
            }
        }
        void printRoot(){
            cout << "id: " << tree[1] << ", value: " << score[1]<< "\n";
        }
    private:
        vector<int> tree;
        vector<long long> score;
        unordered_map<int,int> pos;
};

void MaxHeap::insert(int id, long long value, long long deducted){
    for(int i = 1; i < tree.size(); i++) score[i]-=deducted;
    tree.push_back(id);
    score.push_back(value);
    int current_pos = tree.size()-1;
    upHeap(current_pos,id,value);
}

int main(){
    int action_number, deducted,tmp;
    scanf("%d%d", &action_number,&deducted);
    vector<int> data;
    while(scanf("%d", &tmp) != EOF) data.push_back(tmp);
    MaxHeap* tree = new MaxHeap;
    for(int i = 0; i < data.size(); i++){
        switch(data[i]){
            case 1:{
                int id = data[i+1];
                int value = data[i+2];
                tree->insert(id,value,deducted);
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
                tree->printRoot();
                break;
            default:
                break;
        }
    }
    return 0;
}