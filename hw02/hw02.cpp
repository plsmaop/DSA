#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <utility>
#define MAX_LINE 42000000
using namespace std;

class Node {
    public:
        Node() { mContent = ' '; mMarker = false; }                 //constructor 預設為空字串，marker沒有上色代表不是任何字的終結點
        ~Node() {}                                                  //destructor
        char content() { return mContent; }                         //節點內容
        void setContent(char c) { mContent = c; }                   //存入某個字
        bool wordMarker() { return mMarker; }                       //節點是否為字的終結點
        void setWordMarker() { mMarker = true; }                    //設節點為字的終結點
        Node* findChild(char c){                                    //查詢看看c這個字有沒有存在在vector裏
            for(int i = 0; i < mChildren.size(); i++){
                Node* tmp = mChildren[i];
                if ( tmp->content() == c) return tmp;
            }
            return NULL;
        }
        void appendChild(Node* child) {mChildren.push_back(child);} //往下存字 
        vector<Node*> children() {return mChildren; }               //查詢往下存的vector
        void addRow(int _row){mRow.push_back(_row);}                //存入行數
        vector<int> row(){return mRow;}                             //查詢儲存的行數
    private:
        char mContent;                                              //節點內容
        bool mMarker;                                               //是否為終結點
        vector<Node*> mChildren;                                    //往下指
        vector<int> mRow;                                           //出現在哪些行
};
class Trie {
    public:
        Trie(){root = new Node();}                                  //constructor，root是空的
        ~Trie(){delete root;}                                       //destructor 
        void addWord(std::string s, int _row){                      //存入一個詞，同時存入出現在第igram第幾行
            Node* current = root;                                   //從root開始往下
            if ( s.length() == 0){
                current->setWordMarker();                           //存入an empty word
                return;
            }
            for(int i = 0; i < s.length(); i++){        
                Node* child = current->findChild(s[i]);             //看下面有沒有這個字，有的話回傳
                if ( child != NULL ) current = child;               //如果下面有，節點往下
                 else{                                              //如果沒有
                    Node* tmp = new Node();                         //建立新節點
                    tmp->setContent(s[i]);                          //放入新字
                    current->appendChild(tmp);                      //指標存入上面的節點的vector
                    current = tmp;                                  //節點往下
                }
                if(i == s.length()-1){
                    current->setWordMarker();                       //如果字串剛好結束，這個節點視為終結點，上色
                    current->addRow(_row);                          //同時存入行數
                }
            }
        }
        vector<int> getRow(std::string s){
            Node* current = root;                                   //從root開始
            for(int i = 0; i < s.length(); i++){
                Node* tmp = current->findChild(s[i]);               //看看下面有沒有這個字
                current = tmp;                                      //繼續往下
             }
             return current->row();                                 //找到終結點就回傳存行數的vector
        }
    private:
        Node* root;
};
Trie *trie = new Trie();
inline bool isSep(char c){ return c == ' ' || c == '\t' || c == 0;}         //是否是空格或結尾
bool eq(const char* query, const char* gram){                               //比較兩個字串是否相等
    if(*query == '_') return true;
    while(true){
        if( isSep(*query) && isSep(*gram) ) return true; 
        if( *query != *gram) return false;
        query++; gram++;
    }
}
set<string> expansion_quest_mark(const string& s){                          //展開有問號的字
    set<string> rtn_set;
    size_t loc = s.find('?');                                               //先搜問號的位置
    if( loc == string::npos ){ 
        rtn_set.insert(s);                                                  //沒有的話就回傳原本的字串
        return rtn_set;
    }
    string s1 = s.substr(0, loc) + s.substr(loc+1, string::npos);           //刪掉問號的字串
    string s2;                                                              //刪掉整組字的字串
    size_t nextSep = s.find(' ', loc);                                      //看看這個字是否為最後一個字
    if(nextSep == string::npos)                                             //如果後面沒有空格了
        s2 = s.substr(0,loc);                                               //就直接拿掉最後一個字
    else      
        s2 = s.substr(0,loc) + s.substr( s.find(' ',loc)+1 ,string::npos);  //不然就單純拿掉這個字，接上後面的字串
    rtn_set = expansion_quest_mark (s1);                                    //遞迴之後第一個結果存入set裡
    set<string> rtn_set2 ;
    rtn_set2=expansion_quest_mark(s2);                                      //遞迴之後第二個結果存入第二個set
    for(auto i : rtn_set2)                 
        rtn_set.insert(i);                                                  //合併兩個set
    return rtn_set;                                                         //遞迴
}
set<string> expansion_slash_mark(const string& s){                          //將分隔號展開
    set<string> rtn_set;                        
    size_t loc = s.find('/');                                               //先找到分隔號的位置
    if(loc == string::npos){                                                //如果不存在
        rtn_set.insert(s);                                                  //就直接回傳原本的字串
        return rtn_set;
    }
    int word_start = loc;                                                   //從分隔號的位置求該字來往前推
    while(word_start && s[word_start-1] != ' ' ) word_start--;              //只要不是第0個且在多往前一個不是空格，就繼續往前，最後會等於該字的第一個
    int word_end = loc;                                                     //從分隔好的位置開始往後推
    while( !isSep( s[word_end] )) word_end++;                               //只要不是空格或終結點都往後，最後停在空格或終結點
    string s1 = s.substr(0, word_start);                                    //前面的字串
    string s3;                                                              //後面的字串
    if(word_end == s.length())                                              //如果剛好停在終結點，代表該字為最後一個字
        s3 = "";                                                            //後面的字串為空字串
    else 
        s3 = s.substr(word_end, string::npos);                              //不然就接上後面的字串，且word_end是空格
    string s2;                                                              //中間的字串，要求的字
    int last = word_start ;                                                 //從第一個字開始求
    for(int i = word_start ;  ; i++){                                       
        if(s[i] == '/' || i == word_end) {                                  //遇到分隔號或走到最後
            s2 = string(s.c_str()+last, i-last);                            //就把該字的開始到分隔號或終結點之前加起來
            for(auto e: expansion_slash_mark(s1+s2+s3))                     //把前後串起來，開始遞回
                rtn_set.insert(e);                                          //結果回傳set
            last = i+1;                                                     //如果同個字後面還有分隔號的話繼續做
        }
        if(i == word_end)                                                   //如果走到最後了
            break;                                                          //離開迴圈
    }               
    return rtn_set;                                                         //回傳set
}
set<string> expansion_star_mark(const string& s){
    set<string>  rtn_set;
    size_t loc = s.find('*');
    if(loc == string::npos){
        rtn_set.insert(s);
        return rtn_set;
    }
    string s1;                                                              //將*拿掉
    size_t nextSep = s.find(' ', loc);                                      //檢查該字是否為最後一個
    if(loc == 0 && nextSep != string::npos) s1 = s.substr(2,string::npos);  //如果是第一個請不是唯一
    else if(loc == 0 && nextSep == string::npos) s1 = "";                   //只剩一個
    else if(nextSep == string::npos) s1 = s.substr(0,loc-1);                //如果是後一個
    else s1 = s.substr(0, loc) + s.substr(loc+2, string::npos);             //如果不是
    if(s1 != "") rtn_set = expansion_star_mark(s1);
    int p_current = 0;                                                      //由空白來算目前字數
    for(const char* c = s.c_str();*c;c++){                                  //切割要查詢的句子
        if( *c == '*') continue;                                            //遇到星號可以不算
        if(c == s.c_str()){                                                 //第一個字的指標
            p_current++;
            continue;
        }
        if( isSep( *(c-1) )) p_current++;                      
    }
    string s2 = s1;                                                         //擴展潛在字串
    vector< set<string> >setn;                                              //潛在擴展字串的set
    while(p_current < 5){
        if(s2=="") s2 = "_";                                                 //如果是空字串
        else if(nextSep == string::npos) s2 = s2.substr(0, string::npos) + " _";
        else s2 = s2.substr(0,loc) + "_ " + s2.substr(loc, string::npos);
        setn.push_back( expansion_star_mark(s2));
        p_current++;
    }
    for(int i = 0; i < setn.size(); i++){
        for(auto j : setn[i]){
            rtn_set.insert(j);
        }
    }
    return rtn_set;
}
set<string> Expansion(const string& s){
    set<string> s1 = expansion_quest_mark(s);
    set<string> s2;
    for(auto i : s1)
        for(auto j : expansion_slash_mark(i)) s2.insert(j);
    set<string> s3; 
    for(auto i : s2)
        for(auto j : expansion_star_mark(i)) s3.insert(j);
    return s3;
}
vector<string> extract(const char* c[], int p_query){
    vector<string> ans;
    for(int i = 0; i < p_query; i++){
        string tmps = c[i];
        size_t loc = tmps.find(' ');
        if(loc != string::npos) tmps = tmps.substr(0, loc);
        if (tmps != "_" && tmps != "") ans.push_back(tmps);
    }
    return ans;
}
vector<int> int_merge(vector<int> s1, vector<int>s2){
    vector<int> ans;
    vector<int>::iterator itor1 = s1.begin();                               //第一個與第二個字的iterator
    vector<int>::iterator itor2 = s2.begin();
    vector<int>::iterator itor1_end = s1.end();
    vector<int>::iterator itor2_end = s2.end();
    while(itor1 != itor1_end && itor2 != itor2_end){
        if (*itor1 == *itor2) {                                             //所對應的值相等則兩者都指向下一個
            ans.push_back(*itor1);
            itor1++; itor2++;
          }
        else if (*itor1 < *itor2) itor1++;                                  //第二個大於第一個，則第一個往下指
        else itor2++;                                                       //第一個大於第二個，則第二個往下指
    }
    return ans;
}
vector<int> merge(const vector<string>& str, Trie* trie){
    vector<int> ans;
    vector<int> tmp;
    vector<int> tmp2;
    vector<int> tmp3;                                                        //儲存行數的array
    int size = str.size();
    if(size == 1) return trie->getRow(str[0]);
    else if(size == 2) ans = int_merge(trie->getRow(str[0]),trie->getRow(str[1]));
    if(size == 3){
        tmp = int_merge(trie->getRow(str[0]),trie->getRow(str[1]));
        ans = int_merge(tmp,trie->getRow(str[2]));
    }
    else if(size == 4){
        tmp = int_merge(trie->getRow(str[0]),trie->getRow(str[1]));
        tmp2 = int_merge(trie->getRow(str[2]),trie->getRow(str[3]));
        ans = int_merge(tmp,tmp2);
    }
    else if(size == 5){
        tmp = int_merge(trie->getRow(str[0]),trie->getRow(str[1]));
        tmp2 = int_merge(trie->getRow(str[2]),trie->getRow(str[3]));
        tmp3 = int_merge(trie->getRow(str[4]), tmp2);
        ans = int_merge(tmp3,tmp);
    }
    return ans;                                                             //儲存行數的array
}
struct ansCmp {                                                             //自定義pair的排序，key由小到大，value由大到小
    bool operator()(const pair<long long, string>& p1, const pair<long long, string>& p2) {
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second; 
    }
};
string all[MAX_LINE];
vector< vector<int> > dash;
void Query(const string& s){
    set<string>query_set = Expansion(s);
    set< pair<long long, string>, ansCmp > ans;                             //key為頻率，value為字串
    for(string query: query_set){                                           //query為set裡的字串的iterator，會不斷往後
        const char* query_words[6];                                         //準備將字串切成最多五個字
        int p_query = 0;                                                    //第幾個字
        for(const char* c = query.c_str();*c;c++){                          //切割要查詢的句子
            if(c == query.c_str()){                                         //第一個字的指標
                query_words[p_query++] = c;
                continue;
            }
            if(isSep( *(c-1) )) query_words[p_query++] = c;                 //每個字第一個字母的指標
        }   
        vector<string> str = extract(query_words,p_query);                  //將字分開
        vector<int> index;
        if(p_query >= 2){
            if(str.size()==0) index = dash[p_query-2];
            else index = merge(str, trie);                                  //merge posting之後產生index
        }
        for(int row: index){                                                //row為index的指標，會不斷往後
            string gram = all[row];                                         //取出第row存的字串
            const char* gram_words[6];                                      //準備將字串切成最多五個字
            int p_gram = 0;                                                 //第幾個字
            for(const char* c = gram.c_str();*c;c++){                       //切割句子
                if(c == gram.c_str()){                                      //第一個字的指標
                    gram_words[p_gram++] = c;
                    continue;
                }
                if( isSep( *(c-1) ))                                        //每個字第一個字母的指標
                    gram_words[p_gram++] = c;
            }
            if(p_gram - 1 != p_query)                                       //確認字數相符
                continue;
            bool isEQ = true;                                               
            for(int i = 0; i < p_query; i++){                               //確認每個字是否相同
                if(!eq( query_words[i],gram_words[i] )){
                    isEQ = false;                                           //不相同的話就跳出迴圈
                    break;   
                }
            }
            // this piece of code may run many times
            if(isEQ){                                                       //如果符合條件的話
                long long freq;                                             //存放頻率
                freq = atoll(gram_words[p_gram-1]);                         //取出頻率
                ans.insert( make_pair (freq, all[row]) );                   //存成pair
                if(ans.size() > 5)                                          //大於五個的刪掉
                    ans.erase(ans.begin());
            }
        }
    }
    cout <<"query: " << s << "\n" << "output: " << ans.size() << "\n";
    for(auto i = ans.rbegin(); i != ans.rend();i++) {
        cout << i->second ;                                                 //fget會多加換行
    }
}
int main(int argc,char *argv[]){                                                    
    int count = 0;  
                                                           //第幾行
    /*for(int i = 2; i <= 5; i++){                                            //第i個gram
        char path[100];                                                     //檔案路徑
        sprintf(path, "%s%dgm.small.txt", argv[1], i);                      //寫入路徑
        FILE* filein = fopen(path, "r");                                    //打開檔案
        char tmps[100];
        
        while( fgets(tmps, 100, filein) != NULL){
            all[count]=tmps;                                                //全部存入
            char* p = tmps ;                                                //紀錄要從字串中取出的字的位置
            for(int j = 0; j < i; j++){
                char *start = p, *end = p;                                  //extract a word from a line
                while(!isSep(*end)) end++;                                  //只要不是終結點或空格就繼續記錄
                trie->addWord(string(start, end-start), count);             //紀錄出現在第i個gram的第count行
                p = end+1;                                                  //從下一個字繼續存
            }*/
    for(int i = 2; i <= 5; i++){
        FILE* filein;
        char* buffer;
        long file_size;
        size_t result;
        char path[100];
        sprintf(path, "%s%dgm.small.txt", argv[1], i);
        filein = fopen(path, "r");
        fseek(filein, 0 , SEEK_END);
        file_size = ftell(filein);
        rewind(filein);
        buffer = (char*) malloc (sizeof(char)*file_size);
        result = fread(buffer,1,file_size,filein);
        char* p = buffer;
        string tmps;
        while(*p){
            char *start = p, *end = p;
            while( *end != '\n' ) end++;
            tmps = string(start,end-start);
            all[count] = tmps;
            char* w_p = start;
            for(int j = 0; j < i; j++){
                char *w_start = w_p, *w_end = w_p; 
                while( *w_end != ' ') w_end++;
                trie->addWord(string(w_start, w_end-w_start), count);
                w_p = w_end+1;
            }
            p = end+1;
            string s = tmps;
            vector<int> tmp_arr; 
            size_t loc = s.find('\t'); 
            string tmp2 = s.substr(loc+1,string::npos);
            const char* c = tmp2.c_str();
            long long freq = atoll(c);
            switch(i){
                case 2:
                    if(freq>690000000) tmp_arr.push_back(count);
                    break;
                case 3:
                    if(freq>45400000) tmp_arr.push_back(count);
                    break;
                case 4:
                    if(freq>24060400) tmp_arr.push_back(count);
                    break;
                case 5:
                    if(freq>21500000) tmp_arr.push_back(count);
                    break;
                default:
                    break;
            }
            count++;                                                        //換下一行
        dash.push_back(tmp_arr);
        }
    }
    string tmps;
    vector<string> input;
    int i = 0;
    while( getline(cin,tmps) ) input.push_back(tmps);
    vector<int> output = trie->getRow("fuck");
    for(auto i : output) cout << i << "\n";
    //for(auto i : input) Query(i);
    //delete trie;*/
    return 0;
}
