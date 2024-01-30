"""Generating different art effects of an image 
Image processing techniques used:
 - Filtering
 - Edge Detection
 - Thresholding
 - Mask
 - Bitwise Operations
"""
#Import Libraries
import cv2

#load image
def loadImage(path):
    image = cv2.imread(path)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB) 
    return image

#Create cartoon effect

def cartoonEffect(image):
    """ Apply bilateral filter to reduce the colour palette 
        Convert to grayscale image
        Apply median filter to reduce noise and smoothen edges using a Gaussian blur filters
        Create edge mask using adaptive thresholding (for detecting and enhancing the edges)
        Combine the processed colour image and edge mask using bitwise operation
    """
    filtered = cv2.bilateralFilter(image, 9, 9, 2)
    grey = cv2.cvtColor(filtered,cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(grey,(5,5),0)
    edge = cv2.adaptiveThreshold(blur,255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY, 9, 2)
    result = cv2.bitwise_and(filtered, filtered, mask=edge)

    return result

#Oil painting effect

def oilPaintingEffect(image):
    result = cv2.xphoto.oilPainting(image, 7, 1)

    return result

#Water colours effect

def waterColoursEffect(image):
    result = cv2.stylization(image, sigma_s=60, sigma_r=0.6)

    return result

#Pencil sketches - B/W and colour

def pencilSketches(image):
    gray, colour = cv2.pencilSketch(image, sigma_s=60, sigma_r=0.07, shade_factor=0.05)

    return gray, colour

def saveImage(image,path):
    result = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    cv2.imwrite(path,result)

#Main file

def main():
    
    image_file = "images\waterfall.jpg"
    original = loadImage(image_file)
    cartoon = cartoonEffect(original)
    oil_p = oilPaintingEffect(original)
    water_c = waterColoursEffect(original)
    dst_bw,dst_color = pencilSketches(original)

    #Save images
    saveImage(cartoon,"waterfall_mod.jpg")
    saveImage(oil_p,"waterfall_oilp.jpg")
    saveImage(water_c,"waterfall_wc.jpg")
    saveImage(dst_bw,"waterfall_bw.jpg")
    saveImage(dst_color,"waterfall_ck.jpg")
    
           
if __name__ == '__main__': 
    main()













