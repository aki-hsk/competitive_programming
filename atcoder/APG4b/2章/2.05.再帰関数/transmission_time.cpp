#include<bits/stdc++.h>
using namespace std;

//x番の組織について、子組織からの報告書が揃った時刻を返す
//childrenは組織の関係を表す2次元配列(参照渡し)
int complete_time(vector<vector<int>> &children, int x) {
    if(children.at(x).size() == 0) return 0; //子組織が無いような組織について、報告書が揃う時刻は0

    //再帰ステップ
    int max_receive_time = 0; //受け取った時刻の最大値
    //x番の組織の子組織についてループ
    for(int c:children.at(x)) {
        //(小組織cの元に揃った時刻 + 1)の時刻にcからの報告書を受け取る
        int receive_time = complete_time(children, c) + 1;

        //受け取った時刻の最大値 = 揃った時刻
        max_receive_time = max(max_receive_time, receive_time);
    }
    return max_receive_time;
}

int main() {
    //組織の数
    int N;
    cin >> N;

    vector<int> p(N); //各組織の親組織
    p.at(0) = -1;
    //i番目の親は何かを示した配列
    for(int i=1; i<N; i++) cin >> p.at(i);

    //組織の関係から2次元配列を作る
    vector<vector<int>> children(N); //ある組織の小組織の番号一覧
    for(int i=1; i<N; i++) {
        int parent = p.at(i);       //i番の親組織の記号
        children.at(parent).push_back(i); //parentの小組織にi番を追加
    }

    //0番の組織の元に報告書が揃う時間を求める
    cout << complete_time(children, 0) << endl;
}