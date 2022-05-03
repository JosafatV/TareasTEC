from PIL import Image, ImageFilter
import os
import pathlib
import sys
import re


def id_generator(max):
    for i in range(max):
        yield str(i)


def resizer(img):
    """ Scale-up images. Almost-square images turn square, others keep their aspect ratio"""
    ratio = max(img.width, img.height) / min(img.width, img.height)

    if ratio < 1.1:
        img = img.resize((1000, 1000))
    else:
        img = img.resize((img.width+1000, img.height+1000))

    try:
        img = img.filter(ImageFilter.SHARPEN)
    except:
        print(f"+++ Couldn't sharpen +++")

    return img


def squarer(img):
    """ Resize images to match their width """
    img = img.resize((img.width, img.width))
    return img


def mass_convert_to_png(source, output):
    """ Look through source dir and covert/move all the images to png into output dir
    Creates a list with all the small images (small is res<1000x1000) """
    # Check if Output folder exist and create it if it doesn't
    if (not os.path.isdir(output)):
        os.mkdir(output)

    if os.path.isdir(source) and os.path.isdir(output):
        imgs_list = os.listdir(source)

        # Loop through the original files
        for imgs_name in imgs_list:

            id_gen = id_generator(len(imgs_list))  # Generator
            imgs_path = source + "/" + imgs_name
            out_name = output + "/" + imgs_name[:-3] + "png"

            try:  # Openning the image
                img = Image.open(imgs_path)
                print(
                    f"Processing: {imgs_path} size: {img.size}")
            except:
                print("Issues with file " + imgs_path)
                return

            # Resize images smaller than 1000x1000 if they are ~sqaure
            if img.size < (1000, 1000):
                img = resizer(img)

            try:  # Convert images to png and save. Add a number if the image already exists
                if(os.path.isfile(out_name)):
                    out_name = out_name[:-4] + next(id_gen) + ".png"
                img.save(out_name, 'png')
            except:
                print("Issues writting file " + out_name)


def mass_convert_to_jpg(source, output):
    """ Look through source dir and covert/move all the images to png into output dir
    Creates a list with all the small images (small is res<1000x1000) """
    # Check if Output folder exist and create it if it doesn't
    if (not os.path.isdir(output)):
        os.mkdir(output)

    if os.path.isdir(source) and os.path.isdir(output):
        imgs_list = os.listdir(source)

        # Loop through the original files
        for imgs_name in imgs_list:
            imgs_name_clean = re.match(
                r"(.*)\.\w{3,4}", imgs_name).group(1)  # Remove extension
            id_gen = id_generator(len(imgs_list))  # Generator for names
            imgs_path = source + "/" + imgs_name
            out_name = output + "/" + imgs_name_clean + ".jpg"

            try:  # Openning the image
                img = Image.open(imgs_path)
                print(
                    f"Processing: {imgs_name_clean} size: {img.size}")
            except:
                print("Issues with file " + imgs_name_clean)
                return

            # Resize images smaller than 1000x1000 if they are ~sqaure
            if img.size < (1000, 1000):
                img = resizer(img)
            if abs(img.width-img.height) < 20:
                img = squarer(img)

            try:  # Convert images to jpg and save. Add a number if the image already exists
                if(os.path.isfile(out_name)):
                    out_name = output + "/00" + \
                        next(id_gen) + imgs_name_clean + ".jpg"
                img.save(out_name)
            except:
                try:
                    print(f" - Removed transparencies for {imgs_name_clean}")
                    img = img.convert("RGB")
                    img.save(out_name)
                except:
                    print(" - Issues writting file " + out_name)


if __name__ == "__main__":
    source = "./Original"
    output_jpg = "./New_jpgs"
    output_png = "./New_pngs"

    mass_convert_to_jpg(source, output_jpg)
    #mass_convert_to_png(source, output_png)
