from PyPDF2 import PdfFileWriter, PdfFileReader

def extractor(file_name, out_name, page_num):
    inputpdf = PdfFileReader(open(file_name, "rb"))

    for i in range(inputpdf.numPages):
        if i == page_num:
            output = PdfFileWriter()
            output.addPage(inputpdf.getPage(i))
            with open("splited/"+out_name+"-page%s.pdf" % i, "wb") as outputStream:
                output.write(outputStream)


def extractor_many (file_name, out_name, extract_list):
    inputpdf = PdfFileReader(open(file_name, "rb"))

    if inputpdf.isEncrypted:
        #inputpdf.decrypt("")
        print("File is encrypted")
        inputpdf.decrypt("")
        print (inputpdf.getNumPages())

    for i in range(inputpdf.numPages):
        if i in extract_list:
            output = PdfFileWriter()
            output.addPage(inputpdf.getPage(i-1))
            with open("splited/"+out_name+"-page%s.pdf" % i, "wb") as outputStream:
                output.write(outputStream)


fn = "Nids.pdf"
on = "document"
el = [35,36,37,41,51,52,53,54,57,63,64]






extractor_many(fn, on, el)
#extractor("sih.pdf", "back", 25)


def many_files(file_name, out_name, range_start, range_end):
    for i in range (range_start,range_end):
        fn = "doc (" + str(i) + ").pdf"
        on = "cover_"+str(i)
        print ("Extracting from " + fn)
        extractor(fn, on)



