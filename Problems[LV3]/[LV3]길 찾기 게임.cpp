#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2);

typedef struct Node{
    int num, x, y;
    Node* left;
    Node* right;
}Node;

void insert(Node* cur, Node* node){
    if(node->x < cur->x){
        if(cur->left == NULL)
            cur->left = node;
        else
            insert(cur->left, node);
    }
    else{
        if(cur->right == NULL)
            cur->right = node;
        else
            insert(cur->right, node);
    }
}

void preorder(Node* cur){
    if(cur == NULL) return;
    answer[0].push_back(cur->num);
    preorder(cur->left);
    preorder(cur->right);
}

void postorder(Node* cur){
    if(cur == NULL) return;
    postorder(cur->left);
    postorder(cur->right);
    answer[1].push_back(cur->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> v;
    
    for(int i = 0; i < nodeinfo.size(); i++){
        v.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1],NULL,NULL});
    }
    
    sort(v.begin(), v.end(), [](const Node &a, const Node &b){
        if(a.y == b.y)
            return a.x < b.x;
        else 
            return a.y > b.y;
    });
    
    for(int i = 1; i < v.size(); i++){
        insert(&v[0], &v[i]);
    }
    
    preorder(&v[0]);
    postorder(&v[0]);
        
    return answer;
}