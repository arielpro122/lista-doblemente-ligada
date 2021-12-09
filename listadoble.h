#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>

using namespace std;

template <class T>
class listadoble{
	
	struct Nodo{
		T dato;
		Nodo *sig;
		Nodo *ant;
		
		Nodo(const T &dato, Nodo *sig = nullptr, Nodo *ant = nullptr)
		:dato(dato), sig(sig), ant(ant){
		}
	};
	
	Nodo *head;
	Nodo *tail;
	size_t cont;
	
public: 
	listadoble();
	~listadoble();
	
	bool empty();
	
	void pushfront(const T &dato);
	void pushback(const T &dato);
	void insertar(const T &dato, size_t p);
	
	void popfront();
	void popback();
	void erase(size_t p);
	void remove_if(const T& dato);
	
	size_t size();
	
	void print();
	void printreverse();
	
	T* front();
	T* back();
	
	T* find(const T &dato);
	
	listadoble &operator<<(const T &dato){
		pushback(dato);
		
		return *this;
	}
	
	T* operator[](size_t p){
		size_t pos = 0;
		Nodo *temp = head;
		
		while (temp != nullptr){
			if(p == pos){
				return &temp->dato;
			}
			temp = temp ->sig;
			pos++;
		}
		return nullptr;
	}
	
	
};


template <class T>
listadoble<T>::listadoble(){
	cont = 0;
	head = nullptr;
	tail = nullptr;
}


template <class T>
listadoble<T>::~listadoble(){
	while(!empty()){
		popfront();
	}
}


template <class T>
bool listadoble<T>::empty(){
	return cont == 0;
}


template <class T>
void listadoble<T>::pushfront(const T &dato){
	Nodo *nodo = new Nodo(dato, head);
	if(cont == 0){
		head = nodo;
		tail = nodo;
	} else {
		head-> ant =nodo;
		head = nodo;
	}
	cont++;
}


template <class T>
void listadoble<T>::pushback(const T &dato){
	Nodo *nodo = new Nodo(dato, nullptr, tail);
	if(cont == 0){
		head = nodo;
		tail = nodo;
	}else{
		tail->sig = nodo;
		tail = nodo;
	}
	cont++;
}


template <class T>
size_t listadoble<T>::size(){
	return cont;
}


template <class T>
void listadoble<T>::print(){
	Nodo *temp = head;
	while (temp != nullptr){
		cout << temp -> dato << endl;
		temp = temp->sig;
	}
}


template <class T>
void listadoble<T>::printreverse(){
	Nodo *temp = tail;
	while (temp != nullptr){
		cout << temp -> dato << endl;
		temp = temp->ant;
	}
}


template <class T>
T* listadoble<T>::front(){
	if(empty()){
		return nullptr;
	}else{
		return &head->dato;
	}
}


template <class T>
T* listadoble<T>::back(){
	if(empty()){
		return nullptr;
	}else{
		return &tail->dato;
	}
}


template <class T>
T* listadoble<T>::find(const T &dato){
	Nodo *temp = head;
	while (temp != nullptr){
		if(temp->dato == dato){
			return &temp->dato;
		}
		temp = temp->sig;
	}
	return nullptr;
}


template <class T>
void listadoble<T>::popfront(){
	if(empty()){
		cout << "Lista vacía" << endl;
	}else if (cont == 1){
		delete head;
		head = nullptr;
		tail = nullptr;
		cont--;
	}else{
		Nodo *temp = head->sig;
		
		head ->sig ->ant = nullptr;
		delete head;
		head = temp;
		cont--;
	}
}


template <class T>
void listadoble<T>::popback(){
	if(empty()){
		cout << "Lista vacía" << endl;
	}else if (cont == 1){
		delete tail;
		head = nullptr;
		tail = nullptr;
		cont--;
	}else{
		Nodo *temp = tail->ant;
		
		temp ->sig = nullptr;
		delete tail;
		tail = temp;
		cont--;
	}
}

template <class T>
void listadoble<T>::insertar(const T &dato, size_t p){
	if(p >= cont){
		cout << "Posición no válida" << endl;
	}else if(p == 0){
		pushfront(dato);
	} else{
		Nodo *temp = head -> sig;
		size_t pos = 1;
		
		while (temp != nullptr){
			if (p == pos){
				Nodo *nodo = new Nodo(dato);
				nodo -> sig = temp;
				nodo -> ant = temp -> ant;
				
				temp -> ant -> sig = nodo;
				nodo -> sig -> ant = nodo;
				cont ++;
				break;
			}
			temp = temp -> sig;
			pos++;
		}
	}
}


template <class T>
void listadoble<T>::erase(size_t p){
	if(p >= cont){
		cout << "Posición no válida" << endl;
		
	}else if (p == 0){
		popfront();
	}else if(p == cont-1){
		popback();
	}else{
		Nodo *temp = head -> sig;
		size_t pos = 1;
		
		while (temp != nullptr){
			if(p == pos){
				temp ->ant ->sig = temp -> sig;
				temp -> sig -> ant = temp -> ant;
				
				
				delete temp;
				cont--;
				
				break;
			}
			temp = temp -> sig;
			pos++;
		}
	}
}

template <class T>
void listadoble<T>::remove_if(const T& dato){
	if(empty()){
		cout << "Lista vacía" << endl;
	}else{
		Nodo *temp = head;
		size_t pos = 0;
		while(temp ->sig != nullptr){
			if(temp->dato == dato){
				if(pos == 0){
					popfront();
					temp = head;
				}else{
					erase(pos);
					temp = head;
					pos = 0;
				}
			} else{
				pos++;
				temp = temp -> sig;
			}
		}
		if(temp->dato == dato){
			popback();
		}
	}
	
	

}





















#endif
