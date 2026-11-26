#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct No{
    No* esq;
    No* dir;
    int valor;

    No(int v){
        this -> esq = nullptr;
        this -> dir = nullptr;
        this -> valor = v;
    }
};

class BST{
    private:

    No* raiz = nullptr;

    No* inserir(No* no, int valor){
        if (no == nullptr) return new No(valor);

        if (valor < no->valor){
            no->esq = inserir(no->esq, valor);
        } else {
            no->dir = inserir(no->dir, valor);
        }
        return no;
    }

    No* menor(No* no){
        while (no->esq != nullptr){
            no = no->esq;
        }
        return no;
    }

    No* remover(No* no, int valor){
        if (no == nullptr) return nullptr;

        if (valor < no->valor){
            no->esq = remover(no->esq, valor);
        } else if (valor > no->valor){
            no->dir = remover(no->dir, valor);
        } else {
            if (no->esq == nullptr){
                No* filho = no->dir;
                delete no;
                return filho;
            }
            if (no->dir == nullptr){
                No* filho = no->esq;
                delete no;
                return filho;
            }
            No* prx = menor(no->dir);
            no->valor = prx->valor;
            no->dir = remover(no->dir, no->valor);
        }
        return no;
    }

    int contar(No* no){
        if (no == nullptr) return 0;
        return 1 + contar(no->esq) + contar(no->dir);
    }

    void posOrdem(No* no){
        if (no == nullptr) return;

        posOrdem(no->esq);
        posOrdem(no->dir);
        cout << no->valor << endl;
    }

    public:
        BST() : raiz(nullptr) {}

        void Pinserir(int valor){raiz = inserir(raiz, valor);}
        void Premover(int valor){raiz = remover(raiz, valor);}
        int Pcontar(){return contar(raiz);}
        void PposOrdem(){posOrdem(raiz);}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c; cin >> c;
    BST arvore;

    while(c--){
        string com; cin >> com;
        int valor; cin >> valor;

        if (com == "ins"){
            arvore.Pinserir(valor);
        } else {
            arvore.Premover(valor);
        }
    }

    cout << arvore.Pcontar() << endl;
    arvore.PposOrdem();

    return 0;
}