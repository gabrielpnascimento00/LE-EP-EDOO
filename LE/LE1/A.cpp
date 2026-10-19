#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

template <typename T>
class Fila{
    struct Node{
        T item;
        Node* prox;
        
        Node(const T& dado, Node* pointer){
            item = dado;
            prox = pointer;
        }
    };
    Node* frente = nullptr;
    Node* fim = nullptr;
    int tamanho = 0;

    public:

    Fila(){} //Nao preciso passar nada no construtor
    ~Fila(){
        while (!empty()){
            pop();
        }
    }

    void push(const T& x){
        Node* novo = new Node(x, nullptr);
        if (empty()){
            frente = novo;
        } else {
            fim->prox = novo;
        }
        fim = novo;
        tamanho++;
    }

    void pop() {
        Node* auxiliar = frente;
        frente = frente->prox;
        delete auxiliar;
        tamanho--;
    }

    T& top(){
        return frente->item;
    }

    bool empty() const {
        return frente == nullptr;
    }

    int size() const {
        return tamanho;
    }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    while (n--){
        Fila<int> esq;
        Fila<int> dir;

        int tam_max, v; cin >> tam_max >> v;
        int tam_atual = 0;

        tam_max *= 100;

        int ans = 0;

        while (v--){
            int tam; cin >> tam;
            string lado; cin >> lado;

            if (lado == "left"){
                esq.push(tam);
            } else {
                dir.push(tam);
            }
        }
        bool esquerda = true;

        while ((!esq.empty()) or (!dir.empty())){
            if (esquerda){
                while (true){
                    if ((!esq.empty()) && (tam_atual + esq.top() <= tam_max)){
                        tam_atual += esq.top();
                        esq.pop();
                    } else {
                        esquerda = false;
                        ans++;
                        tam_atual = 0;
                        break;
                    }
                }
            } else {
                while (true){
                    if ((!dir.empty()) && (tam_atual + dir.top() <= tam_max)){
                        tam_atual += dir.top();
                        dir.pop();
                    } else {
                        esquerda = true;
                        ans++;
                        tam_atual = 0;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}