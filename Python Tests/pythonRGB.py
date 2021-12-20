
import sys
import os.path
import numpy as np
from PIL import Image


#image_path = sys.argv[1]
image_path = "logo10.png"
side = 10
#modulo = int(sys.argv[2])
modulo = int("1")

#Se carga la imagen en formato RGB forzado por si acaso 
img = Image.open(image_path).convert('RGB')
##se convierte en np array
np_image = np.array(img)

#funcion de rgb
def rgb2hex(r, g, b):
    return '#{:02x}{:02x}{:02x}'.format(r, g, b)

def np_array_to_hex(array):
    array = np.asarray(array, dtype='uint32')
    array =  (1<< 42) + ((array[:, :, 0]<<16) + (array[:, :, 1]<<8) + array[:, :, 2])
    return [hex(x)[-8:] for x in array.ravel()]

def hex_to_binary(array, side):
    out = []
    for i in range (0, len(array)):
        if (array[i]=="00000000"):
            out.append("0")
        else:
            out.append("1")
            
    return out

def make_matrix (matrix, side):
    out = []
    for i in range (0, len (matrix), side):
        row = []
        for s in range (0, side):
            row.append(matrix[i+s])
        out.append(row)
    return out

def quartus_sprite (matrix):
    

                
hex_array = np_array_to_hex(np_image)

#print (len(hex_array))
print(make_matrix(hex_array, side))
#mx = make_matrix(hex_to_binary(hex_array, side), side)
#print_matrix(mx)
