from tkinter import image_names
from types import NoneType
from xml.dom.domreg import well_known_implementations
from PIL import Image, ImageFilter
import os
import pathlib
import sys
import re

def uid_generator(max):
    for i in range(max):
        yield str(i)


def willOverwrite(out_name):
    return os.path.isfile(out_name)


def output_name_generator(output_dir, imgs_name, extension, uid):
    
    imgs_regex = re.match(r"(\w+)( \(\d{1,4}\))?(.\w{3,4})", imgs_name) # Remove extension and Windows file uid 
    if imgs_regex is None:
        print("Could not match ", imgs_name)
        imgs_name_clean = "aaa_temp"
    else:
        imgs_name_clean = imgs_regex.group(1) 
    
    out_name = f"{output_dir}/{imgs_name_clean}{extension}"

    # Check if file exists, if it does generate a new name until it is unique
    while willOverwrite(out_name):
        print(f"{out_name} would overwrite trying the next name: ", end="")
        out_name = f"{output_dir}/{imgs_name_clean} ({next(uid)}){extension}"
        print(out_name)
        
    return out_name


def open_image(source_dir, imgs_name):
    try:  # Opening the image
        img_path = source_dir + "/" + imgs_name
        img = Image.open(img_path)
        return img
    except:
        return False


def convert_image_jpg(source_dir, output_dir, imgs_name, uid):
    """ Open and convert a file to jpg """
    img = open_image(source_dir, imgs_name)
    if img:
        out_name = output_name_generator(output_dir, imgs_name, ".jpg", uid)
        try:  # Convert images to jpg and save. Add a number if the image already exists
            img.save(out_name)
            return 0
        except:
            try:
                print(f" - Removed transparencies for {imgs_name}")
                img = img.convert("RGB")
                img.save(out_name)
                return 0
            except:
                print(" - Issues writting file " + out_name)
                return 1
    else:
        print("Issues opening file " + imgs_name)
        return 1



def mass_convert_to_jpg(source_dir, output_dir):
    """ Look through source dir and covert/move all the images to png into output dir
    Creates a list with all the small images (small is res<1000x1000) """
     
    # Check if Output folder exist and create it if it doesn't
    if not os.path.isdir(output_dir):
        print("Creating output folder")
        os.mkdir(output_dir)

    # Check Source folder exists
    if not os.path.isdir(source_dir):
        print("Source folder doesn't exist")
        exit()

    # Create a list with all the items in source dir
    imgs_list = os.listdir(source_dir)

    # Create a generator to ensure unique names
    uid = uid_generator((len(imgs_list)+1)*2)

    # Loop through the original files
    for imgs_name in imgs_list:
         convert_image_jpg(source_dir, output_dir, imgs_name, uid)

    # print (f"+++ Completed with {issues} issues +++")


if __name__ == "__main__":
    
    source_dir = "./Original"
    output_dir = "./New_jpgs"
    #name_base = input("Base name for images: ")

    mass_convert_to_jpg(source_dir, output_dir)
