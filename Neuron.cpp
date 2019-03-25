#include "Neuron.h"
#include <cmath>
Neuron::Neuron()
{
	this->realVal = 0;
	initialize();
}

Neuron::~Neuron()
{
}

Neuron::Neuron(double val)
{
	this->realVal = val;
	initialize();
}

void Neuron::initialize()
{
	ActivateVal();
	DerivedVal();
}

void Neuron::printNeuron()
{
	cout <<"Neuron:"<< this->realVal << endl;
}

const double Neuron::GetValue()const
{
	return this->realVal;
}

const double Neuron::GetActVal()const
{
	return this->activateVal;
}

const double Neuron::GetDerVal()const
{
	return this->derivedVal;
}

void Neuron::SetNeuron(double val)
{
	this->realVal = val;
	initialize();
}

void Neuron::ActivateVal()
{
	activateVal = 1 / (1 + exp(-this->realVal));
}

void Neuron::DerivedVal()
{
	derivedVal = (1 - activateVal)*activateVal;
}
