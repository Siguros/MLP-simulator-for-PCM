#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include "Neuron.h"
#include "Layer.h"
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <ctime>
#include <random>
#include "main.h"
using namespace std;

int main() {
	Layer Inputlayer;
	Matrix InputMatrix;
	double val;
	// 만약 정규분포 randomseed 형성시
	

	//srand(unsigned int(time(0)));
	// vector checking
	/*vec = new vector<double> (3);
	for (int i = 0; i < 3; i++) {
		vec->at(i) = i;
		cout << vec->at(i);
	}
	delete vec;
	if (vec != nullptr) {
		cout << "Y";
	}*/
	Inputlayer.initialize(5);
	for(int idx=0; idx<5; idx++){
		val = ((double)(rand()))/RAND_MAX;
		Inputlayer.SetNeuron(idx, val);
		cout << val << " ";
	}
	cout<<endl;
	
	NeuralNetwork ann(5, 3, 2);
	ann.initialize(Inputlayer);
	ann.PrintNeuralNetwork();
	ann.PrintMatrix();
	ann.FeedForward();
	ann.PrintNeuralNetwork();
	vector<double> target(2);
	target.at(0) = 0.3;
	target.at(1) = 0.7;
	ann.TargetInitialize(target);
	ann.ErrorInit();
	ann.PrintError();
	cout << endl;
	ann.Backprop();
	for (int epoch = 0; epoch < 100; epoch++) {
		ann.FeedForward();
		ann.Backprop();
		ann.PrintNeuralNetwork();
	}
	

	/*for (int epoch = 0; epoch < 100; epoch++) {
		ann.FeedForward();
		ann.Backprop();
		ann.PrintNeuralNetwork();
	}
	/*&Matrix mat1;
	mat1.Initialize(3, 3, true);
	mat1.printMatrx();
	Matrix mat2;
	mat2.Initialize(3, 3, true);
	mat2.printMatrx();
	Matrix mat3;
	mat3 = mat1 - mat2;
	mat3.printMatrx();
	mat3 -= mat1;
	mat3.printMatrx();
	//ann.Backprop(target);
	//ann.PrintError();
	/*vLayer.push_back(hiddenLayer);
	vLayer.push_back(OutputLayer);
	/*																																																NeuralNetwork ann(5, 3, 2);
	/*ann.initialize(Inputlayer);
	ann.FeedForward();
	*/
}


