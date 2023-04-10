#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define f first
#define s second
#define endl '\n'

class No
{
    private:
		int v;
		No* prox;
		No* ant;

	public:
		No(int v) // construtor
		{
			this->v = v;
			this->prox = NULL;
			this->ant = NULL;
		}

		int obterValor() // obtém o valor
		{
			return v;
		}

		No* obterProx() // obtém o próximo No
		{
			return prox;
		}

		No* obterAnt(){
			return ant;
		}

		void setProx(No* p) // seta o próximo No
		{
			prox = p;
		}

		void setAnt(No* a){
			ant = a;
		}

};

class ListaCircular
{
    private:
		int qtd = 0;
		No* cauda;
		No* cabeca;
	public:
		ListaCircular(){
			cabeca = NULL;
			cauda = NULL;
		}

		ListaCircular(int v){
			cabeca = new No(v);
			cauda = cabeca;
		}

		virtual ~ListaCircular(){
			No* atual = cabeca;
			No* proximo;
			for(int i = 0; i < qtd; i++){
				proximo = atual->obterProx();
				delete atual;
				atual = proximo;
			}
		}

		void mostrar(){
			No* c = cabeca;
			if(vazia())
				cout << "Lista Vazia!!\n";
			else{
				cout << "\nImprimindo a lista circular: \n";
				int cont = 1;
				while(cont <= qtd){
					cout << c->obterValor() << " ";
					c = c->obterProx();
					cont++;
				}
				cout << endl;
			}
		}

		bool vazia(){
			return cabeca == NULL;
		}
		
		void inserir(int v) {
			No* newNo = new No(v);
			if (qtd == 0) {
                
				newNo->setProx(newNo);
				cabeca = newNo;
				cauda = newNo;
				qtd++;
			}
			else {
				newNo->setProx(newNo);
				cauda->setProx(newNo);
				newNo->setAnt(cauda);
				cauda = newNo;
				qtd++;
			}
			cauda->setProx(cabeca);
			cabeca->setAnt(cauda);
			
		}

		bool existe(int v){
			No* c = cabeca;
			for(int i = 0; i < qtd; i++){
				if(c->obterValor() == v){
					return true;
				}
				c = c->obterProx();
			}
			return false;
		}
		void remover(int v){
			No* c = cabeca;
			if(vazia()) cout << "Lista vazia!\n" << endl;
			else if(!existe(v)){
				cout<<"Valor nao existe na lista! ";
			}
			else {
				int contv = 0;
				for (int i = 0; i < qtd; i++) {
					if(c->obterValor() == v) contv++;
					c = c->obterProx();
				}
				while(contv--) {
					c = cabeca;
					while(c->obterValor() != v) {
						c = c->obterProx();
					}
					if(c == cabeca && qtd == 1) {
						cabeca = NULL;
						cauda = NULL;
					}
					else if(c == cabeca) {
						cabeca = cabeca->obterProx();
						cabeca->setAnt(cauda);
						cauda->setProx(cabeca);
					}
					else if(c == cauda) {
						cauda = cauda->obterAnt();
						cauda->setProx(cabeca);
						cabeca->setAnt(cauda);
					}
					else {
						c->obterAnt()->setProx(c->obterProx());
						c->obterProx()->setAnt(c->obterAnt());
					}
					delete c;
					qtd--;
				}
			}
		}


		void percorrer	(int v) {
			No* c = cabeca;
			if(vazia()) {
				cout << "Fila vazia!" << endl;
			}
			else if (existe(v)) {
				cout << "Quantas vezes você quer percorrer a lista? ";
				int a;
				while(!(cin>>a)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Por favor, digite um número." << endl;
					sleep(1);
					cout << "Quantas vezes você quer percorrer a lista? ";
				}
				cout << endl;
				cout << "Percorrendo lista " << a << " vezes a partir do valor: " << v << endl << endl;
				int p = 0;
				sleep(1);
				while (c->obterValor() != v) {
					c = c->obterProx();
				}
				while (p < a) {
					cout << c->obterValor() << " ";
					c = c->obterProx();
					if(c->obterValor()==v) {
                        p++;
                        cout << endl;
                    }
				}
				sleep(1);
                cout << "\nLista percorrida!" << endl;
			}
            else {
                cout << "Elemento não está na lista!\n";
            }
		}
};
ListaCircular* l = new ListaCircular();
int main(){
	system("clear");
    
    int cases;
    cout << "Digite 1 para inserir algum elemento na lista." << endl;
    cout << "Digite 2 para remover algum elemento da lista." << endl;
    cout << "Digite 3 para ver se existe algum elemento na lista." << endl;
    cout << "Digite 4 para percorrer a lista a partir de um elemento especifico." << endl;
    cout << "Digite 5 para mostrar a lista." << endl;
    cout << "Digite 0 para encerrar o programa.\n" << endl;

	if(!(cin>>cases)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Por favor digite um número.\n";
		sleep(1);
		return main();
	}
	int a;

	switch(cases) {
		case 1:

			cout<< "Qual numero deseja inserir na lista? ";
			while(!(cin>>a)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor, digite um número." << endl;
				sleep(1);
				cout<< "Qual numero deseja inserir na lista? ";
			}
			l->inserir(a);
			cout << "Numero " << a << " inserido na lista com sucesso!" << endl;
			sleep(1);
			return main();

		case 2:

			cout << "Qual numero deseja remover da lista? ";
			while(!(cin>>a)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor, digite um número." << endl;
				sleep(1);
				cout<< "Qual numero deseja remover da lista? ";
			}
			l->remover(a);
			cout <<"\nElemento " << a << " removido com sucesso!" << endl;
			sleep(1);
			return main();

		case 3:

			cout << "Digite um elemento a ser procurado na lista: ";
			while(!(cin>>a)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Por favor, digite um número." << endl;
				sleep(1);
				cout<< "Digite um elemento a ser procurado na lista: ";
			}
			if(l->existe(a)) cout << "\nO elemento " << a << " está na lista!" << endl;
			else cout << "\nO elemento não está na lista!" << endl;
			sleep(1);
			return main ();

		case 4:

			if(l->vazia()) cout << "Lista Vazia!\n";
			else {
				l->mostrar();
				cout << "\nDigite o elemento elemento da lista para começar a percorrer: ";
				while(!(cin>>a)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Por favor, digite um número." << endl;
					sleep(1);
					cout << "Digite o elemento elemento da lista para começar a percorrer: ";
				}
				l->percorrer(a);
				
				
			} 
            sleep(3);
			return main ();

		case 5:

			l->mostrar();
			sleep(1);
			return main();

		case 0:
			break;
        default:
            cout << "Opção inválida. Por favor digite alguma opção válida.\n";
            sleep(1);
            return main();
			
	}
    return 0;
}
