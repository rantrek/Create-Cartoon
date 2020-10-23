// CreateCartoon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#Generating a cartoon effect of an image using OpenCV image processing library
//Image processing techniques used :
//- Filtering
//- Edge Detection
//- Thresholding
//- Mask
//- Bitwise Operations

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
	// Read the file "image.jpg".
	// This file "image.jpg" should be in the project folder.
	// Else provide full path: "D:/images/image.jpg"
	
	String imageName("car.jpg"); // by default

	// LOAD image
	image = imread(imageName, IMREAD_COLOR);

	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	//Apply bilateral filter to reduce the colour palette 

	Mat filtered;

	bilateralFilter(image, filtered, 9, 9, 2);

	//Convert to grayscale image

	Mat grayImage;

	cvtColor(filtered, grayImage, COLOR_BGR2GRAY);

	//Apply median filter to reduce noise and smoothen edges using median blur or Gaussian blur filters

	Mat blur;

	GaussianBlur(grayImage,blur,Size(7, 7), 0);
	//medianBlur(grayImage,blur,5)

	//Create edge mask using adaptive thresholding (for detecting and enhancing the edges)

	Mat edge;

	adaptiveThreshold(blur, edge, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 9, 2);

	//Combine the processed colour image and edge mask using bitwise operation

	Mat cartoon, mask;

	bitwise_and(filtered, filtered, cartoon, mask = edge);

	//Display the images

	// Create a window for display.
	namedWindow("image", WINDOW_NORMAL);
	namedWindow("filtered image", WINDOW_NORMAL);
	namedWindow("gray image", WINDOW_NORMAL);
	namedWindow("blurred image", WINDOW_NORMAL);
	namedWindow("edge mask", WINDOW_NORMAL);
	namedWindow("cartoon image", WINDOW_NORMAL);

	// Show our image inside it.
	imshow("image", image);
	imshow("filtered image", filtered);
	imshow("gray image", grayImage);
	imshow("blurred image", blur);
	imshow("edge mask", edge);
	imshow("cartoon image", cartoon);

	// Both images are displayed but cartoon image on top of original image
	// Move cartoon image window to see original image

	// SAVE image
	imwrite("result.jpg", image);  // it will store the image with name "result.jpg"
	imwrite("result_cartoon.jpg", cartoon); // it will store the cartoon image with name "result_gray.jpg"

	waitKey(0);  // Wait for a keystroke in the window
	return 0;

}


