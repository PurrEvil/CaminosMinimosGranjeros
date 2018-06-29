/*
 * Arribo.h
 *
 *  Created on: 22 jun. 2018
 *      Author: purrevil
 */

#ifndef ARRIBO_H_
#define ARRIBO_H_
#include <string>
#include "Lista.h"

class Arribo{
private:
	std::string arribo;
	unsigned int* costo;
	std::string cultivo;
	Lista<std::string>* escalas;
public:
	Arribo(std::string salida,std::string arribo,unsigned int costo, std::string cultivo){
		this->arribo = arribo;
		this->costo = new unsigned int(costo);
		this->cultivo = cultivo;
		this->escalas = new Lista<std::string>;
		this->agregarEscala(arribo);

	}


	std::string	obtenerArribo(){
		return this->arribo;
	}
	std::string obtenerCultivo(){
		return this->cultivo;
	}
	unsigned int* obtenerCosto(){
		return this->costo;
	}
	void cambiarCosto(unsigned int nuevoCosto){
		*this->costo = nuevoCosto;
	}

	Lista<std::string>* obtenerEscalas(){
		return this->escalas;
	}
	void agregarEscala(std::string escala){
		this->escalas->agregar(escala);
	}
	void cambiarEscalas(Lista<std::string>* escalasNuevas){
		for(unsigned int i= 1; i<= this->escalas->contarElementos(); i++){
			this->escalas->remover(i);
		}
		escalasNuevas->iniciarCursor();
		while(escalasNuevas->avanzarCursor()){
			this->escalas->agregar(escalasNuevas->obtenerCursor());

		}
	}
	~Arribo(){
		delete this->costo;
		delete this->escalas;
	}
};



#endif /* ARRIBO_H_ */
