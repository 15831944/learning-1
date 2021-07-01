'''
Created on Jun 30, 2021

@author:  Gabriel Dimitriu
'''
#pip3 install matplotlib
import matplotlib.pyplot as plot
import matplotlib.image as image

img = image.imread("ship.bmp")
plot.imshow(img)
plot.show()