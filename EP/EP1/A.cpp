#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

template <typename T>
class Vetor {
private:
    T* dados;
    int tamanho;
    int capacidade;
    void redimensionar() {
        capacidade *= 2;
        T* novo = new T[capacidade];
        for (int i = 0; i < tamanho; i++) {
            novo[i] = dados[i];
        }
        delete[] dados;
        dados = novo;
    }
public:
    Vetor() {
        tamanho = 0; capacidade = 2;
        dados = new T[capacidade];
    }

    ~Vetor() {delete[] dados;}

    int getTamanho() const {
        return tamanho;
    }

    T get(int i) const {
        return dados[i];
    }

    void set(int i, T valor) {
        dados[i] = valor;
    }

    void inserir(T valor) {
        if (tamanho == capacidade) {
            redimensionar();
        }
        dados[tamanho] = valor;
        tamanho++;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string palavra;

    while (cin >> palavra){

        Vetor<char> letras;
        Vetor<int> prox;

        letras.inserir(' ');
        prox.inserir(0);

        int pont = 0;
        int ultimo = 0;

        for (int i = 0; i < palavra.length(); i++){
            char a = palavra[i];

            if (a == '['){
                pont = 0;
            } else if (a == ']'){
                pont = ultimo;
            } else {
                int novo = letras.getTamanho();
                letras.inserir(a);

                prox.inserir(prox.get(pont));
                prox.set(pont, novo);

                if (pont == ultimo) ultimo = novo;
                pont = novo;
            }
        }

        for (int i = prox.get(0); i != 0; i = prox.get(i)){
            cout << letras.get(i);
        }
        cout << endl;
    }

    return 0;
}