#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

template <typename T>
class Pilha{
    struct Node{
        T item;
        Node* prox;
        
        Node(const T& dado, Node* pointer){
            item = dado;
            prox = pointer;
        }
    };
    Node* topo = nullptr;
    int tamanho = 0;

    public:

    Pilha(){} //Nao preciso passar nada no construtor
    ~Pilha(){
        while (!empty()){
            pop();
        }
    }

    void push(const T& x){
        topo = new Node(x, topo);
        tamanho++;
    }

    void pop() {
        Node* auxiliar = topo;
        topo = topo->prox;
        delete auxiliar;
        tamanho--;
    }

    T& top(){
        return topo->item;
    }

    bool empty() const {
        return topo == nullptr;
    }

    int size() const {
        return tamanho;
    }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Pilha<int> a;
    Pilha<int> b;
    Pilha<int> c;
    vector<string> d;

    for (int i = 0; i < n; i++){
        int z;
        cin >> z;
        a.push(z);
    }

    int j = 1;

    while (true){
        if (j <= n){
            if ((!a.empty()) && (a.top() == j)){
                c.push(a.top());
                a.pop();
                j++;
                d.push_back("A C");
            } else if (!b.empty() && (b.top() == j)){
                c.push(b.top());
                b.pop();
                j++;
                d.push_back("B C");
            } else if (b.empty()){
                b.push(a.top());
                a.pop();
                d.push_back("A B");
            } else if ((!b.empty()) && (a.top() < b.top())){
                b.push(a.top());
                a.pop();
                d.push_back("A B");
            } else {
                cout << "-1";
                return 0;
            }
        } else {
            break;
        }
    }

    cout << d.size() << endl;
    for (string elemento : d){
        cout << elemento << endl;
        }

    return 0;
}