#include "Layer.h"

Layer::Layer()
{
}

Layer::~Layer()
{

	if (layers != nullptr) {
		delete this->layers;
	}
}

Layer::Layer(int Layersize)
{
	this->Sizelayer = Layersize;
	this->layers = new vector<Neuron>(Sizelayer);
}

void Layer::initialize(int Layersize)
{	
	if (layers != nullptr) {
		this->layers->clear();
	}
	this->Sizelayer = Layersize;
	this->layers = new vector<Neuron>(Sizelayer);

}

void Layer::SetNeuron(int idx, Neuron & n)
{
	layers->at(idx) = n;
}

void Layer::SetNeuron(int idx, const double val)
{
	layers->at(idx).SetNeuron(val);
}


Neuron& Layer::GetNeuron(int idx)const
{
	return layers->at(idx);
}


void Layer::AddNeuron(const double& val)
{
	for (int i = 0; i < Sizelayer; i++) {
		double temp = this->GetNeuron(i).GetValue();
		temp += val;
		this->GetNeuron(i).SetNeuron(temp);
	}
}

Matrix Layer::LayerToMatrix()
{
	Matrix result(this->Sizelayer, 1,true);
	for (int row = 0; row < this->Sizelayer; row++) {
		result.SetMatrix(row,0, this->GetNeuron(row).GetValue());
	}	
	return result;
}


Matrix Layer::LayerToActMatrix()
{
	Matrix result(this->Sizelayer,1 , true);
	for (int row = 0; row < this->Sizelayer; row++) {
		result.SetMatrix(row, 0, this->GetNeuron(row).GetActVal());
	}
	return result;
}

const Matrix Layer::LayerToDerMatrix()
{
	Matrix result(this->Sizelayer, 1, true);
	for (int row = 0; row < this->Sizelayer; row++) {
		result.SetMatrix(row, 0, this->GetNeuron(row).GetDerVal());
	}
	return result;
}

void Layer::MatrixToLayer(const Matrix &m)
{
	assert(m.GetCol()== 1);
	if (this->Sizelayer == m.GetRow()) {
		for (int i = 0; i < this->Sizelayer; i++) {
			this->layers->at(i).SetNeuron(m.GetVector().at(i).at(0));
		}
	}
	else {
		this->initialize(m.GetRow());
		for (int i = 0; i < this->Sizelayer; i++) {
			this->layers->at(i).SetNeuron(m.GetVector().at(i).at(0));
		}
	}
}

