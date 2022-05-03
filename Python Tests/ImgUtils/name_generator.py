""" 
Return a new file name with path  based on the source file name.
The output name must not be the same as a name in the output directory (no overwritting)
 """

from tkinter import image_names
from PIL import Image, ImageFilter
import os
import pathlib
import sys
import re



def uid_generator(max):
    for i in range(max):
        yield str(i)


def name_generator (source_name, output_dir, ext):

    if (not os.path.isdir(output_dir)):
        print("Error: output directory does not exist")

     imgs_name_clean = re.match(r"(.*)\.\w{3,4}", source_name).group(1)  # Remove extension


     return "new_name" + ext




if __name__ == "__main__":
    # Intended user
    source_path = "./Original"
    output_path = "./New_jpgs"
    extension = ".jpg"

    file_list = os.listdir(source_path)



    for file in file_list:
        print(name_generator(file, output_path, extension))


"""
So if we are reading a dir with three files A.png, A.jpg and B.png we expect
three name in the output: A.jpg 1_A.jpg and B.jpg
"""