#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
No se verifica que dos nodos ocupen el mismo lugar. No es necesario por ahora <<

*/

//int radio_fis_con;
//int radio_com_con;

float dist (int x1, int y1, int x2, int y2){ //calcular distancias
	float a, b, a2, b2, c; //para control de flujo
	a = x2 - x1;
	b = y2 - y1;
	a2 = a*a;
	b2 = b*b;
	c = sqrt(a2+b2);
	return c; 
	
}

class Nodo{
	public:
		int id;
		float consumo;
		float x, y;
		vector<Nodo*> fis_con; //conexion fisica
		vector<Nodo*> com_con; //conexion comunicación

		Nodo(int id, float x, float y){
			this->id = id;
			this->x = x;
			this->y = y;
		}
		
		//añadir con_fis
		void add_fis_con (Nodo *n){
			fis_con.push_back(n);
		}
		
		//conectar comunic
		void add_com_con (Nodo *n){
			com_con.push_back(n);
		}
		
		void imprimir_fis_con (){
			cout<<" fis_con: ";
			for(int i=0; i<fis_con.size();i++){
				cout<<fis_con[i]->id<<" ";
			}
		}
		
		void imprimir_com_con (){
			cout<<" com_con: ";
			for(int i=0; i<com_con.size();i++){
				cout<<com_con[i]->id<<" ";
			}
		}
};



class Grid{
	public:
	vector<Nodo*> lista_nodos;
	
	int fis_con_radio;
	int com_con_radio; 
	
	//Constructor vacio
	Grid(){};
	
	Grid (float fcradio, float ccradio){
		if(fcradio <= 0)
			fcradio = 1;
			
		if(ccradio <= 0)
			ccradio = 1;
			
		this->fis_con_radio = fcradio;
		this->com_con_radio = ccradio;
	}
	
	void add_nodo (Nodo *n){
		lista_nodos.push_back(n);
	}
	
	void pair_up (Nodo *n){ //para conectar un nodo con todos los nodos posibles
		float d;
		for(int i=0; i < lista_nodos.size(); i++){ //recorrer toda la lista
			if(n->id != lista_nodos[i]->id){ //evitar conectar un nodo consigo mismo
				d = dist(n->x, n->y, lista_nodos[i]->x, lista_nodos[i]->y);
				
				if(d<=fis_con_radio)
					n->add_fis_con(lista_nodos[i]);
					
				if(d<=com_con_radio)
					n->add_com_con(lista_nodos[i]);
			}
		}
	}
	
	void imprimir_nodos () {
		for(int i=0; i< lista_nodos.size();i++){
			cout<<"id: "<<lista_nodos[i]->id; //id
			cout<<"| mem: "<<&lista_nodos[i]; //mem aloc
			cout<<"| cord: ("<<lista_nodos[i]->x<<","<<lista_nodos[i]->y<<")"; //coord	
			lista_nodos[i]->imprimir_fis_con();
			lista_nodos[i]->imprimir_com_con();		
			cout<<endl;
		}
	}
	
};

int main (){
	
	Nodo a(1,1,1);
	Nodo b(2,1,3);
	Nodo c(3,1,5);
	Nodo d(4,3,1);
	Nodo e(5,3,3);
	Nodo f(6,3,5);
	Nodo g(7,5,1);
	Nodo h(8,5,4);
	Nodo i(9,5,5);
	
	Grid test(2,3);
	
	test.add_nodo(&a);
	test.add_nodo(&b);
	test.add_nodo(&c);
	test.add_nodo(&d);
	test.add_nodo(&e);
	test.add_nodo(&f);
	test.add_nodo(&g);
	test.add_nodo(&h);
	test.add_nodo(&i);				
	
	test.imprimir_nodos();
	system("pause");
	
	test.pair_up(&a);
	
	test.imprimir_nodos();

	/*
	a.add_fis_con(&b);
	cout<<&a.fis_con[0]->id<<endl<<&b; //test memory space
	b.id = 18;
	//cout<<a.fis_con[0]->id;
	*/
	
	return 0;
}
