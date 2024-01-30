#include "CartoonEffects.h"

CartoonEffects::CartoonEffects(){}

CartoonEffects::~CartoonEffects() {}

void CartoonEffects::setInputName(string name)
{
	this->name = name;
}

string CartoonEffects::getInputName()
{
	return name;
}

void CartoonEffects::setOutputName(string r)
{
	this->r = r;
}

string CartoonEffects::getOutputName()
{
	return r;
}

Mat CartoonEffects::loadImage(string name)
{
	img = imread(name, IMREAD_COLOR);

	if (img.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return Mat();
	}
	return img;
}

Mat CartoonEffects::createEffects(Mat img) {
	
	Mat filtered, grayImage,blur,edge,mask;

	//Apply bilateral filter to reduce the colour palette 
	bilateralFilter(img, filtered, 9, 9, 2);

	//Convert to grayscale image
	cvtColor(img, grayImage, COLOR_BGR2GRAY);

	//Apply median or Gaussian blur filter to reduce noise and smoothen edges
	//GaussianBlur(grayImage,blur,Size(7, 7), 0);
	medianBlur(grayImage, blur, 5);

	//Create edge mask using adaptive thresholding (for detecting and enhancing the edges)
	adaptiveThreshold(blur, edge, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 9, 5);

	//Combine the processed colour image and edge mask using bitwise operation
	bitwise_and(filtered, filtered, c, mask = edge);

	return c;
}

void CartoonEffects::DisplayImages(Mat img, Mat c)
{
	//Initialize window title names
	string original{ "image" };
	string cartoonIm{ "cartoon image" };
	
	// Create windows for display.
	namedWindow(original, WINDOW_NORMAL);
	namedWindow(cartoonIm, WINDOW_NORMAL);
	
	// Show images inside it.
	imshow(original, img);
	imshow(cartoonIm, c);
}

void CartoonEffects::saveImage(string r, Mat c)
{
	imwrite(r, c); 
}


