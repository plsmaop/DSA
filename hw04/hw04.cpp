#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
using namespace std;

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}
inline long long ReadLong(long long *x) {
    static char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

class MaxHeap{
    public:
        MaxHeap(){
            pair<int,long long> node (-1,0);
            tree.push_back(node);
            iterator.push_back(-1);
        }
        ~MaxHeap();
        void insert(int id, long long value);
        void upHeap(int iter, int id, long long value, int new_id = 1 );
        void swapNode(int parent,int kid){
            int tmp = iterator[kid];
            iterator[kid] = iterator[parent];
            iterator[parent] = tmp;
        }
        void update(long long add, int id){
            tree[iterator[pos[id]]].second+=add;
            int iter = pos[id];
            long long value = tree[iterator[pos[id]]].second;
            upHeap(iter,id,value,0);
        }

        void printRoot(long long deduct){
            int root = iterator[1];
            int id = tree[root].first;
            long long value = tree[root].second - deduct;
            cout << "id: " << id << ", value: " << value << "\n";
        }
    private:
        vector< pair<int, long long> > tree;
        unordered_map<int,int> pos;
        vector<int> iterator;
};
void MaxHeap::insert(int id, long long value){
    pair<int, long long> node(id,value);
    tree.push_back(node);
    int current_pos = tree.size()-1;
    iterator.push_back(current_pos);
    int iter = iterator.size()-1;
    upHeap(iter,id,value);
}
void MaxHeap::upHeap(int iter, int id, long long value, int new_id  ){
    while(true){
        if (iter==1) {
            pos[id] = iter;
                break;
        }
        int parent_pos = iter/2;
        int parent_id = tree[iterator[parent_pos]].first;
        long long parent_value = tree[iterator[parent_pos]].second;
        if(parent_value < value || (parent_value == value && new_id == 1)){
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
int main(){
    ios::sync_with_stdio(false);
    int action_number;
    long long insert_count=0, deducted, tmp;
    scanf("%d%lld", &action_number,&deducted);
    vector<long long> data;
    while(ReadLong(&tmp) ) data.push_back(tmp);
    MaxHeap* tree = new MaxHeap;
    for(int i = 0; i < data.size(); i++){
        switch(data[i]){
            case 1:{
                insert_count++;
                int id = data[i+1];
                long long value = data[i+2]+insert_count*deducted;
                tree->insert(id, value);
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
                tree->printRoot(insert_count*deducted);
                break;
            default:
                break;
        }
    }
    //delete tree;
    return 0;
}
