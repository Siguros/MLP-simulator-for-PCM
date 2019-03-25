#pragma once
#include "Neuron.h"
#include "Matrix.h"
#include <assert.h>

class Layer {

private:
	vector<Neuron> *layers;
	int Sizelayer;

public:
	//initialize
	Layer();
	~Layer();
	Layer(int Layersize);
	void initialize(int Layersize);

	//property function
	void SetNeuron(int idx, Neuron &n);
	void SetNeuron(int idx, const double val);
	Neuron& GetNeuron(int idx)const;
	const int GetSize()const { return this->Sizelayer; }
	void AddNeuron(const double& val);

	//Neuron Activate
	//void ActivateNeuron();
	//void DerivedNeuron();
	Matrix LayerToMatrix();
	Matrix LayerToActMatrix();
	const Matrix LayerToDerMatrix();
	void MatrixToLayer(const Matrix&m);
	//Matrix LayerToMatrix();




};