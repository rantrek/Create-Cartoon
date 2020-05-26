
# coding: utf-8

# In[27]:


#Creating a cartoon effect of an image using OpenCV image processing library

#Import Libraries
import cv2
import numpy as np
import matplotlib.pyplot as plt
#from matplotlib import cm
#%matplotlib inline 
from pylab import *


# In[73]:


#Load image file
original = cv2.imread("waterfall.jpg")


# In[80]:


#Apply bilateral filter to reduce the colour palette and smoothen edges

filtered = cv2.bilateralFilter(original, 9, 9, 2)


# In[81]:


#Convert to grayscale image
grey = cv2.cvtColor(original,cv2.COLOR_BGR2GRAY)



# In[82]:


#Apply median filter to reduce noise
#blur = cv2.medianBlur(grey,5)
blur = cv2.GaussianBlur(grey,(5,5),0)


# In[83]:


#Using adaptive thresholding for detecting and enhancing the edges
edge = cv2.adaptiveThreshold(blur,255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY, 9, 2)


# In[84]:


#Combine the processed colour image and edge mask
cartoon = cv2.bitwise_and(filtered, filtered, mask=edge)


# In[85]:


#Display images
figure(figsize = (15,15))

subplot(2,2,1)
plt.imshow(original)
plt.title('Original')

subplot(2,2,2)
plt.imshow(cartoon)
plt.title('cartoon')

#subplot(2,2,3)
#plt.imshow(edge)
#plt.title('edges')
#
#subplot(2,2,4)
#plt.imshow(blur)
#plt.title('blurred')

