#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{
	NumLayer = 0;
}

NeuralNetwork::~NeuralNetwork()
{

}

NeuralNetwork::NeuralNetwork(int inputlayer, int hiddenlayer, int outputlayer)
{
	NumLayer = 3;
	for (int i = 0; i < NumLayer; i++) {
		Layer layer;
		this->Layers.push_back(layer);
		
	}
	this->Layers.at(0).initialize(inputlayer);
	this->topology.push_back(inputlayer);
	this->Layers.at(1).initialize(hiddenlayer);
	this->topology.push_back(hiddenlayer);
	this->Layers.at(2).initialize(outputlayer);
	this->topology.push_back(outputlayer);
	
}

NeuralNetwork::NeuralNetwork(vector<int>& topology)
{
	NumLayer = (int)(topology.size());

	for (int i=0; i< NumLayer; i++) {
		Layer layer;
		layer.initialize(topology.at(i));
		Layers.push_back(layer);
	}
	
}

void NeuralNetwork::initialize(const Layer & layer)
{
	for (int i = 0; i < layer.GetSize(); i++) {
		this->Layers.at(0).SetNeuron(i, layer.GetNeuron(i).GetValue());
	}
	this->MarixIniailize();
	this->BiasInitialize();
	learning = 0.3;
	
}

void NeuralNetwork::SetNeuron(int numLayer, int numNeuron, double val)
{
	Layers.at(numLayer).SetNeuron(numNeuron, val);
}

void NeuralNetwork::SetLayer(int numLayer, Layer & layer)
{
	this->Layers.at(numLayer) = layer;
}

Layer NeuralNetwork::GetLayer(int numLayer)
{
	return this->Layers.at(numLayer);
}

void NeuralNetwork::PrintNeuralNetwork()
{
	cout << "=========" << "NeuralNetwork" << "==========" << endl;
	for (int idx = 0; idx < NumLayer; idx++) {
		cout << (idx + 1) << "번째 Layer의 Neuron 값:" << endl;
		for (int i = 0; i < Layers.at(idx).GetSize(); i++) {
			cout <<"Real:"<< Layers.at(idx).GetNeuron(i).GetValue()<<" ";

		}
		cout << endl;
		for (int i = 0; i < Layers.at(idx).GetSize(); i++) {
			cout << "Act:" << Layers.at(idx).GetNeuron(i).GetActVal() << " ";
		}
		cout << endl;
	}
}

void NeuralNetwork::PrintMatrix()
{
	for (int i = 0; i < this->NumLayer - 1; i++) {
		this->weightMatrix.at(i).printMatrx();
	}
}

void NeuralNetwork::MarixIniailize()
{
	
	for (int i = 0; i < NumLayer - 1; i++) {
		Matrix matrix;
		weightMatrix.push_back(matrix);
		weightMatrix.at(i).Initialize(topology.at(i + 1), topology.at(i), true);
	}
}

void NeuralNetwork::BiasInitialize()
{
	bias = new vector<double>(NumLayer);
	for (int i = 0; i < NumLayer; i++) {
		bias->at(i) = 0.3;
	}

}

void NeuralNetwork::PrintBias()
{
	for (int i = 0; i < this->NumLayer; i++) {
		cout << this->bias->at(i) << endl;
	}
}

void NeuralNetwork::PrintError()
{
	cout << "============ERROR============" << endl;
	for (int i = 0; i < this->MSERROR.size(); i++) {
		cout << MSERROR.at(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < this->MSERROR.size(); i++) {
		cout << Errors.at(i) << " ";
	}
}

void NeuralNetwork::PrintDerError()
{
	for (int idx = 0; idx < this->DerError->size(); idx++) {
		this->DerError->at(idx).printMatrx();
	}
}

void NeuralNetwork::TargetInitialize(vector<double> &target)
{
	this->target = target;
}

void NeuralNetwork::ErrorInit()
{
	this->MSERROR = target;
	this->Errors = target;
	for (int i = 0; i < MSERROR.size(); i++) {
		this->Errors.at(i) = (this->Layers.at(NumLayer - 1).GetNeuron(i).GetActVal() - this->Errors.at(i));
		this->MSERROR.at(i) = (this->Layers.at(NumLayer - 1).GetNeuron(i).GetActVal() - this->MSERROR.at(i))*(this->Layers.at(NumLayer - 1).GetNeuron(i).GetActVal())*(1 - this->Layers.at(NumLayer - 1).GetNeuron(i).GetActVal());
	}
	this->DerError = new vector<Matrix>(NumLayer - 1);
	for(int widx=0;widx<NumLayer-1; widx++){
		this->DerError->at(widx).Initialize(this->weightMatrix.at(widx).GetRow(), this->weightMatrix.at(widx).GetCol(), false);
	}
}

void NeuralNetwork::FeedForward()
{
		//First FeedForward
		this->Layers.at(1).MatrixToLayer(this->weightMatrix.at(0).MatrixMultply(this->Layers.at(0).LayerToMatrix()));
		this->Layers.at(1).AddNeuron(this->bias->at(0));
		for (int i = 2; i < this->NumLayer; i++) {
			this->Layers.at(i).MatrixToLayer(this->weightMatrix.at(i - 1).MatrixMultply(this->Layers.at(i - 1).LayerToActMatrix()));
			this->Layers.at(i).AddNeuron(this->bias->at(i - 1));
		}
	
}



void NeuralNetwork::Backprop()
{
	ErrorInit();
	//first Backpropagation
	int OutputLayerIndex = this->NumLayer-1;
	Matrix derivedValues = this->Layers.at(OutputLayerIndex).LayerToDerMatrix();
	Matrix *gradientYtoZ = new Matrix(this->Layers.at(OutputLayerIndex).GetSize(), 1, false); 
	for (int i = 0; i < this->Errors.size(); i++) {
		double d = derivedValues.GetVal(i, 0);
		double e = this->Errors.at(i);
		double g = d * e;
		gradientYtoZ->SetMatrix(i, 0, g);
	}
	int lastHiddenLayerIndex = OutputLayerIndex - 1;
	Layer lastHiddenLayer = this->Layers.at(lastHiddenLayerIndex);
	Matrix weightOutputToHidden = this->weightMatrix.at(lastHiddenLayerIndex);
	Matrix *deltaOutputToHidden = new Matix(gradientYtoZ.TransPose)
	//Moving from last hidden layer to inputLayer
	for (int idx = OutputLayerIndex - 1; idx >= 0; idx--) {

	}
}

void NeuralNetwork::weightupdate(vector<Matrix> *Dererror)
{
	for (int idx = 0; idx < NumLayer - 1; idx++) {
		this->weightMatrix.at(idx) -= Dererror->at(idx)*learning;
	}
}