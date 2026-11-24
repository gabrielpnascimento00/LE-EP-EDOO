#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

struct No {
    int valor;
    No* esq;
    No* dir;
    No(int v) : valor(v), esq(nullptr), dir(nullptr) {}
};

class ArvoreBinaria {
private:
    No* raiz;

    No* construir(string pre, string in) {
        if (pre.empty()) return nullptr;
        char r = pre[0];
        No* no = new No(r);
        int k = in.find(r);
        no->esq = construir(pre.substr(1, k), in.substr(0, k));
        no->dir = construir(pre.substr(1 + k), in.substr(k + 1));
        return no;
    }

    void posOrdemLetras(No* no) {
        if (no == nullptr) return;
        posOrdemLetras(no->esq);
        posOrdemLetras(no->dir);
        cout << (char)no->valor;
    }

    void liberar(No* no) {
        if (no == nullptr) return;
        liberar(no->esq);
        liberar(no->dir);
        delete no;
    }

public:
    ArvoreBinaria() : raiz(nullptr) {}
    ~ArvoreBinaria() { liberar(raiz); }

    void construir_arvore(string pre, string in) { raiz = construir(pre, in); }
    void posOrdemLetras() { posOrdemLetras(raiz); cout << "\n"; }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int qte; cin >> qte;

        string pre, in; cin >> pre >> in;

        ArvoreBinaria arvore;

        arvore.construir_arvore(pre, in);
        arvore.posOrdemLetras();
    }

    return 0;
}