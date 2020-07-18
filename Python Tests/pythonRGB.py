
import sys
import os.path
import numpy as np
from PIL import Image

#funcion de rgb
def rgb2hex(r, g, b):
    return '#{:02x}{:02x}{:02x}'.format(r, g, b)

#Se carga la imagen en formato RGP forzador por si acaso 
img = Image.open(sys.argv[1]).convert('RGB')
##se convierte en np array
np_image = np.array(img)

def np_array_to_hex2(array):
    array = np.asarray(array, dtype='uint32')
    array =  (1<< 42) + ((array[:, :, 0]<<16) + (array[:, :, 1]<<8) + array[:, :, 2])
    return [hex(x)[-8:] for x in array.ravel()]

modulo = int(sys.argv[2])
#variable de control
linea = 0

for x in range(0, modulo  , 1):
    #se convierte imagen a hex
    all_data = np_array_to_hex2(np_image)
    #se escriben los archivos
    hex_file = open('file' + str(x) + '.hex', "w") 
    largo  = len(all_data) 
    for y in range(0, largo, 1):
       if linea == modulo:
            linea = 0  
       if linea == x:
            linea += 1
            hex_file.write("".join(all_data[y]) + "\n")
       else: 
            linea += 1
linea = 0

hex_file2 = open("file.hex", "w") 
for data in all_data:
    hex_file2.write("".join(data) + "\n")
   

print(np_image.shape)  # (rows, columns, channels)
total =np_image.shape[0] *np_image.shape[1]
print("total" ,total )
print("Pedazo",total / modulo)
#print (np_image)
#print(np_array_to_hex2(np_image))
