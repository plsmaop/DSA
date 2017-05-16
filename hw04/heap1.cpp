#include <iostream>
#include <vector>

#include <time.h>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
using namespace std;



vector< pair<int, long long> > heap;
unordered_map<int, int> iv_heap;

void heap_sort(int j)
{
 int tmp;
 if (heap.at(j).second > heap.at((j-1)/2).second)
 {
  pair<int,long long> tmp;
  tmp = heap.at(j);
  heap.at(j) = heap.at((j-1)/2);
  iv_heap[heap.at(j).first] = j;
  heap.at((j-1)/2) = tmp;
  iv_heap[heap.at((j-1)/2).first] = (j-1)/2;
  j = (j-1)/2;
  heap_sort(j);
 }
 else
 {
  return;
 }
}



int main()
{
 ios::sync_with_stdio(false);
 clock_t t1,t2;
 t1 = clock();
 long long num_deduc;
 int num_op;
 int mode_op;
 int id;
 long long score;
 int tmp;
 int score_add;
 int num_items_add;
 cin>>num_op;
 cin>>num_deduc;
 long long iter = 0;
 pair<int, long long> node;

 for (int i = 0; i < num_op; i++)
 {  
  cin>>mode_op;
  if (mode_op == 1)
  {
   iter++;
   cin>>id>>score;
   score = score+iter*num_deduc;
   node = make_pair(id,score);
   heap.push_back(node);
   iv_heap[id] = heap.size() - 1;
   heap_sort(heap.size()-1); 
  }
  else if (mode_op == 2)
  {
   cin>>score_add>>num_items_add;
   for (int j = 0; j < num_items_add; j++)
   {
    cin>>id;
    int k = iv_heap[id];
    heap.at(k).second = heap.at(k).second + score_add;
    heap_sort(k);
   }

  }
  else
  {
   cout<<"id: "<<heap.at(0).first<<", value: "<<heap.at(0).second-iter*num_deduc<<" "<<endl;

  }
 } 
  t2 = clock();
  float diff((float)t2-(float)t1);
  float sec = diff/CLOCKS_PER_SEC;
  cout<<sec<<endl;
return 0;
}










