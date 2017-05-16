#include <iostream>

#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
using namespace std;

void max_heapify(vector<pair<long long int,long long int> > &a, unordered_map<long long int,long long int> &b,long long int i, long long int n)
{
    long long int j;
    pair<int,long long int> tempa;
    tempa = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1].second > a[j].second)
            j = j + 1;
        if (tempa.second > a[j].second)
            break;
        else if (tempa.second <= a[j].second)
        {
            a[j/2] = a[j];

            j = 2 * j;
        }
    }
    a[j/2] = tempa;
 	for (long long int x=1;x<a.size();x++)
 	{
 		b[a[x].first]=x;	
	}
 
    return;
}

void build_maxheap(vector<pair<long long int,long long int> > &a,unordered_map<long long int,long long int> &b,long long int n)
{
    long long int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,b,i,n);
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//FILE *fPtr;
	long long int data;
	long long int number,deducted;
	vector<long long int> vData;
	//freopen("open04.txt","r",stdin);
	cin>>number>>deducted;
	while(cin>>data)
	{
		vData.push_back(data);
	}
	long long int id,score;//insert���`�I��id��score 
	long long int add,count;//update�n�[��score,count�O���X�Ӹ`�I�n�[(�᭱id list���Ӽ�) 	
	long long int nodenum=1,n=0,line=0;
	vector<pair<long long int,long long int> > node;
	node.push_back(make_pair(-1,-1));
	unordered_map<long long int,long long int> pos; //�sid�����m 
	while(true)
	{
		if(line==number)
			break;
		switch(vData[n])
		{
			case 1:
				id=vData[n+1];
				score=vData[n+2];
				score+=nodenum*deducted;
				//cout<<id<<" "<<score<<" "<<nodenum<<"\n";
				node.push_back(make_pair(id,score));
				pos.insert(make_pair(id,nodenum));
				//cout<<node[nodenum].first<<" "<<node[nodenum].second<<"\n";
				//cout<<pos[id]<<"\n";
				nodenum+=1; //����id�bvector-based heap�̭������m 
				n+=3;
				line+=1;
				break;
			case 2:
				add=vData[n+1];
				count=vData[n+2];
				//cout<<add<<" "<<count<<" "<<vData[i+3+2]<<"\n";
				for(long long int h=0;h<count;h++)
				{
					node[pos[vData[n+3+h]]].second+=add;
				}
				n+=(3+count);
				line+=1;				
				break;
			case 3:
				//cout<<nodenum<<"\n";			
				build_maxheap(node,pos,node.size()-1); //�ئ�max_heap tree
				cout<<"id: "<<node[1].first<<", value: "<<node[1].second-((nodenum-1)*deducted)<<"\n"; //���X���G (score�̰����A�]�N�Oroot)
				//for(long long int r=1;r<node.size();r++)
			//	{
			//		cout<<node[r].first<<" "<<node[r].second<<" ";
			//	}
			//	cout<<"\n";
				//-pos.find(node[1].first)->second
				n+=1;
				line+=1;
				break;
			default:
				break;
		}
	}
	
	//fclose(stdin);
	return 0;
}
