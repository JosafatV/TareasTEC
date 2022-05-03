from PIL import Image, ImageFilter
import os
import pathlib
import sys
import re


# TODO: Implement like this (probably on different files)
def file_selector ():
    """ Open a window to select a file. Return an input file name."""
    pass

def sharpen(img):
    """ Run a sharpen filter on the image."""
    pass

def resize (img, width, height):
    """ Stretch an image to the desired pixel size."""
    sharpen(img)
    pass

def resize_keep_ratio (img, multiplier):
    """ Resize an image while keeping it's aspect ration."""
    sharpen(img)
    pass

def make_square(img):
    """ If a picture is almost square it will strentch it into a square. """
    pass

def convert_to_png(img, out_name):
    """ Convert an image to a different format with minimal modification. """
    out_name += ".png"
    pass

def convert_to_jpg(img, out_name):
    """ Convert an image to a different format with minimal modification. """
    out_name += ".jpg"
    pass

def mass_convert_to_png(src_folder, out_folder):
    """ Convert all images in the Original folder to PNG. """
    for img in src_folder:
        img_out_name = img
        convert_to_png (img, img_out_name)
    pass

def mass_convert_to_jpg(src_folder, out_folder):
    """ Convert all images in the Original folder to JPG. """
    for img in src_folder:
        img_out_name = img
        convert_to_jpg (img, img_out_name)
    pass

def albumcovers(src_folder, out_folder):
    """ Custom convert functions to resize, square and convert images in the Original folder"""
    pass