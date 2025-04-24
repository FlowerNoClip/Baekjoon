#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <deque> 
#include <iterator> 
#include <list> 
#include <stack> 
#include <map> 
#include <unordered_map>
#include <set> 
#include <unordered_set>
#include <math.h> 
#define ll long long 
#define INF 1e9+10 
using namespace std;

void preorder(char node, map<char, pair<char, char>>& tree) {
    if (node == '.') return;

    cout << node;                         // 1. 루트 출력
    preorder(tree[node].first, tree);          // 2. 왼쪽 자식
    preorder(tree[node].second, tree);         // 3. 오른쪽 자식
}
void inorder(char node, map<char, pair<char, char>>& tree) {
    if (node == '.') return;

    inorder(tree[node].first, tree);
    cout << node;
    inorder(tree[node].second, tree);
}

void postorder(char node, map<char, pair<char, char>>& tree) {
    if (node == '.') return;

    postorder(tree[node].first, tree);
    postorder(tree[node].second, tree);
    cout << node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    map<char, pair<char, char>> tree;
    //A노드의 왼쪽 과 오른쪽 노드를 저장하는 합수.
    int T; cin >> T;

    while (T--)
    {
        char q;
        char w;
        char e;
        cin >> q >> w >> e;
        tree[q].first = w;
        tree[q].second = e;
    }
    preorder('A', tree);
    cout << endl;
    inorder('A', tree);
    cout << endl;
    postorder('A', tree);
}

