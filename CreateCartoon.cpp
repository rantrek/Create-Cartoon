
//#Generating a cartoon effect of an image using OpenCV image processing library
//Image processing techniques used :
//- Filtering
//- Edge Detection
//- Thresholding
//- Mask
//- Bitwise Operations

#include "CartoonEffects.h"

int main()
{
   //Initialize variables
	string input{"./images/waterfall.jpg"}; //read image
	string output{ "./images/result_cartoon.jpg" }; //save image
	string imageName, result;
	Mat image, cartoon;

	//Create class object myCartoon
	CartoonEffects myCartoon;

	//Set and get file paths for input and output images
	myCartoon.setInputName(input);
	imageName = myCartoon.getInputName();
	myCartoon.setOutputName(output);
	result = myCartoon.getOutputName();

	//Load image
	image = myCartoon.loadImage(imageName);

	//Generate the cartoon effect
	cartoon = myCartoon.createEffects(image);

	//Display the images
	myCartoon.DisplayImages(image, cartoon);

	// SAVE cartoon image
	myCartoon.saveImage(result, cartoon);

	waitKey(0);  // Wait for a keystroke in the window

	return 0;

}


