#pragma once
#include "Layer.h"
#include "Matrix.h"

class NeuralNetwork {
private:
	vector<Layer> Layers;
	vector<Matrix> weightMatrix;
	int NumLayer;
	vector<int> topology;
	vector<double> target;
	vector<double> MSERROR;
	vector<double> Errors;
	double Error;
	double learning;
	vector<double> *bias;
	vector<Matrix> *DerError;
	
public:
	//initialize NeuralNetwork
	NeuralNetwork();
	~NeuralNetwork();
	NeuralNetwork(int inputlayer, int hiddenlayer, int outputlayer);
	NeuralNetwork(vector<int> &topology);
	void initialize(const Layer & layer);
	
	// property function
	void SetNeuron(int numLayer, int numNeuron, double val);
	void SetLayer(int numLayer, Layer &layer);
	Layer GetLayer(int numLayer);
	void PrintNeuralNetwork();
	void PrintMatrix();
	void MarixIniailize();
	void BiasInitialize();
	void PrintBias();
	void PrintError();
	void PrintDerError();
	void TargetInitialize(vector<double> &target);
	void ErrorInit();
	const vector<int> GetTopology()const { return this->topology; }
	
	
	//Functional Function
	void FeedForward();

	//void Backprop(vector<double> &target>;
	void Backprop();
	void weightupdate(vector<Matrix> *Dererror);
	


};