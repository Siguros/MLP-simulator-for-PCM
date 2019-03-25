#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Neuron {
public:
	// initialize
	Neuron();
	~Neuron();
	Neuron(double val);
	void initialize();

	// property function
	void printNeuron();
	const double GetValue()const;
	const double GetActVal()const;
	const double GetDerVal()const;
	void SetNeuron(double val);

	// Functional function
	void ActivateVal();
	void DerivedVal();

private:
	double realVal;
	double activateVal;
	double derivedVal;


};