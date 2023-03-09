#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
  int data;
  Node   *left;
  Node   *right;
  Node(int value = 0){
    data = value;
    left = right = NULL;
  }
  ~Node(){}
};

class BST {
  public:
    Node *root;
    int Count;
    BST(){
      root = NULL;
      Count = 0;
    }
  ~BST() {}

  void add(int value){
    Node *temp = new Node(value);
    if(Count == 0){
      root = temp;
      Count++;
    }else{
      add2(root, temp);
    }

  }

  void print(){
    print2(root, 0);
  }

  void add2(Node *temp, Node *child){
    if(child -> data < temp -> data && (temp -> left == NULL || temp -> left == 0)){
      temp -> left = child;
    } else if(child -> data < temp -> data){
      add2(temp -> left, child);
    }

    if(child -> data > temp -> data && (temp -> right == NULL || temp -> right == 0)){
      temp -> right = child;
    }else if(child -> data > temp -> data){
      add2(temp -> right, child);
    }

  }

  void print2(Node *temp, int level){
    if(temp == NULL || temp == 0){
      cout << "Tree is empty" << endl;
    }else{
      level++;
      if(temp -> left != NULL  || temp -> left != 0)
        print2(temp -> left,  level);
      cout << "Level: " << level << "  Value: " << temp -> data << endl;
      if(temp -> right != NULL || temp-> right != 0)
        print2(temp -> right, level);
    }
  }

};


int main(){
  BST tree;
  int arr[8] = {50,25,75,1,35,45,65,85};
  for(int i = 0; i < 8; i++){
    tree.add(arr[i]);
  }
  tree.print();
  return 0;
}
