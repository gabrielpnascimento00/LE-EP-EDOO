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

    No* inserir(No* no, int valor) {
        if (no == nullptr) return new No(valor);
        if (valor < no->valor){
            no->esq = inserir(no->esq, valor);
        } else {
            no->dir = inserir(no->dir, valor);
        }
        return no;
    }

    No* menor(No* no) {
        while (no->esq != nullptr) no = no->esq;
        return no;
    }

    No* remover(No* no, int valor) {
        if (no == nullptr) return nullptr;

        if (valor < no->valor) {
            no->esq = remover(no->esq, valor);
        } else if (valor > no->valor) {
            no->dir = remover(no->dir, valor);
        } else {
            if (no->esq == nullptr) {
                No* filho = no->dir;
                delete no;
                return filho;
            }
            if (no->dir == nullptr) {
                No* filho = no->esq;
                delete no;
                return filho;
            }
            No* suc = menor(no->dir);
            no->valor = suc->valor;
            no->dir = remover(no->dir, suc->valor);
        }
        return no;
    }

    void preOrdem(No* no) {
        if (no == nullptr) return;
        cout << " " << no->valor;
        preOrdem(no->esq);
        preOrdem(no->dir);
    }

    void emOrdem(No* no) {
        if (no == nullptr) return;
        emOrdem(no->esq);
        cout  << " " << no->valor;
        emOrdem(no->dir);
    }

    void posOrdem(No* no) {
        if (no == nullptr) return;
        posOrdem(no->esq);
        posOrdem(no->dir);
        cout << " " << no->valor;
    }

    int altura(No* no) {
        if (no == nullptr) return -1;
        return 1 + max(altura(no->esq), altura(no->dir));
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

    void inserir(int valor) { raiz = inserir(raiz, valor); }
    void remover(int valor) { raiz = remover(raiz, valor); }

    bool buscar(int valor) {
        No* no = raiz;
        while (no != nullptr && no->valor != valor)
            no = (valor < no->valor) ? no->esq : no->dir;
        return no != nullptr;
    }

    void preOrdem()  { preOrdem(raiz);}
    void emOrdem()   { emOrdem(raiz);}
    void posOrdem()  { posOrdem(raiz);}
    int altura()     { return altura(raiz); }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    ArvoreBinaria arvore;

    while (q--){
        int num; cin >> num;

        arvore.inserir(num);
    }

    cout << "Pre order :";
    arvore.preOrdem();
    cout << endl;

    cout << "In order  :";
    arvore.emOrdem();
    cout << endl;

    cout << "Post order:";
    arvore.posOrdem();
    cout << endl;

    return 0;
}