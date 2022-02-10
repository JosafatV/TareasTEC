# Kyndryl
#
# Python file manager
#
# from fileManager import *
#
# Josafat Vargas
# 4th of Feb, 2022

def readFile(fileName):
    """ Opens, reads and then closes a file. Returns the information in the file as a string
    fileName (str): file to be accessed ie: "myfile.txt", "myFolder/myFile.txt".
    return: string with the information in the file
    return: int if error
    """
    try:
        file_object = open(fileName, "r")
        read_data = file_object.read()
        file_object.close()
        return read_data
    except:
        print("+++ Read operation failed +++")
        return 1


def writeFile(fileName, toWrite):
    """ Opens, writes and then closes a file. Creates a file if it doesn't exist and it will overwrite existing files
    fileName (str): file to be accessed ie: "myfile.txt", "myFolder/myFile.txt".
    toWrite (str): data that the file willl have after creation
    return: 1 if error
    return: 0 if success
    """
    try:
        file_object = open(fileName, "w")
        file_object.write(toWrite)
        file_object.close()
        return 0
    except:
        print("+++ Write operation failed +++")
        return 1


def appendFile(fileName, toWrite):
    """ Opens, appends and then closes a file. File must exist before appending
    fileName (str): file to be accessed ie: "myfile.txt", "myFolder/myFile.txt".
    toWrite (str): data to be appended to the file
    return: 1 if error
    return: 0 if success
    """
    try:
        file_object = open(fileName, "a")
        file_object.write(toWrite)
        file_object.close()
    except:
        print("+++ Append operation failed +++")
        return 1


def fileManager(fileName, mode, data):
    """ Manages the access and operaions in external files
    Parameters:
        fileName (str): file to be accessed
        mode (str): "r" to read, "w" to write (erases previous data), "a" appends data to file
        data (str): anything if read, data to append/wrie
    Returns:
        return: 1 if the operation failed
        return: 0 if overwrites/appends to fileName file succeded
        return: data read if mode == "r" 
    """
    # read and print file
    if mode == "r" or mode == "R":
        return readFile(fileName)
    # appends to file
    elif mode == "a" or mode == "A":
        return appendFile(fileName, data)
    # Create a new file
    elif mode == "w" or mode == "W":
        return writeFile(fileName, data)
    else:
        print("Mode not recognized")
        return 1
