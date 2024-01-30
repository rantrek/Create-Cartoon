#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class CartoonEffects
{
private:
	string name;
	string r;
	

public:
	Mat img;
	Mat c;

	CartoonEffects(); //default constructor
	//CartoonEffects(string name, string r Mat img, Mat c); //overload constructor

	~CartoonEffects(); //Destructor

	//Methods

	void setInputName(string name);
	
	string getInputName();

	void setOutputName(string r);
	
	string getOutputName();

	Mat loadImage(string name);

	Mat createEffects(Mat img);

	void DisplayImages(Mat img, Mat c);

	void saveImage(string r, Mat c);
};

