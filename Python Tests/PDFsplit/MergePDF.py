from PyPDF2 import PdfFileWriter, PdfFileReader
import time



def merger(out_name):

    output = PdfFileWriter()

    for i in range(0, 301):
        try:
            pdf_file = PdfFileReader(open("splited/document-page"+str(i)+".pdf", "rb"))
            print("Adding page" + str(i))
            output.addPage(pdf_file.getPage(0))
        except:
            pass

    with open("merged/"+out_name+".pdf", "wb") as outputStream:
        output.write(outputStream)

merger("merged")


