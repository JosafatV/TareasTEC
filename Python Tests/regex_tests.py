from distutils.filelist import findall
import re
import string
from traceback import print_tb

#\\ BACKSLASH
#\" DOUBLE QUOTE
#\' SINGLE QUOTE
#\n NEWLINE
#\t TAB
#\U UNICODE
#\v VERTICAL TAB

# r in front of the string turns it into a raw string,
# which ignores the behaviour of the escape character
path = r"C:\Users\tasks\new"

# To print these we also have to print them as raw strings
print(path)

# \s SPACE_CHARACTER
# \d DIGIT
# \w ALPHANUM CHARACTER (including others like æ)

# \W NON-ALPHANUM CHARACTER

string_p1 = "It happened once, back in 1924. I haven't had a night free of nightmares since then. The eyes... they haunt me."
regex_p1 = re.compile(r"\d{4}")
res_p1 = re.findall(regex_p1, string_p1)
print(f'Res 1: {res_p1}')



string_p2 = "The church had mysteriously burned after, in 1925, 1926 and 1927 with no witnesses of the arsonist"
res_p2 = re.search(r"\d{3}", string_p2)
print(f'Res 2: {res_p2}') # Returns first instance found
print(f'Res 2 (methods): {string_p2[res_p2.start():res_p2.end()]}')



string_p3 = "The following year, the police had invested on preventing the deviant from doing it again"
res_p3 = re.match(r"\w{4,}", string_p3)
print (f'Res 3: {res_p3}') # Match always searches from the beginning. Since "The" isn't a 4+ letter word the match fails and returns None
res_p3b = re.fullmatch(r".{4,}", string_p3)
print (f'Res 3b: {res_p3b}')



string_p4 = "Arthur, Belle and Chardumor"
str_split = string_p4.split(" ")
print (f'Res 4 (standard split): {str_split}')
res_p4 = re.split(r"(,\s|\sand\s)", string_p4)
print (f'Res 4 (regex split): {res_p4}')



string_p5 = "where initially part of the COUNTRY investigation team, looking for the troublemaker with the COUNTY Police Department."
res_p5 = re.sub(r"[A-Z]{2,}", "Chondix", string_p5, 1)
print(f'Res 5: {res_p5}') # we have specified count == 1 so we will change only the 1st instance, instead of all the capitalized words
res_p5b = re.subn(r"[A-Z]{2,}", "Samalin", res_p5)
print(f'Res 5b (subn): {res_p5b}') # returns a tuple with the new string and number of replacements.



string_p6 = "The detectives had few clues when they arrived back on the 19th of February, 1924."
res_p6 = re.search(r".+\s(.+ed).+(\d\d.+\s.+),", string_p6)
print(f'Res 6: {res_p6.group()}') #Can also call res_p6.group(index) default: 0 is the whole text
print(f'Res 6b (groups): {res_p6.groups()}') # Uses the groups (...)
print (f'Res 6c (starting indexes): Group 1 - {res_p6.start(1)}, Group 2 - {res_p6.start(2)}')
# Similar result can be obtained with .findall which returns a list without the full text
#   the result from .search also has the index for start and end



string_p7 = "Guided only by the superstition of the locals and the word on the streets.\nThe 21st, just after dawn"
res_p7 = re.findall(r"the", string_p7, re.I) # re.I ignores capitalization, meaning we find "The" when looking for "the"
print(f'Res 7: {res_p7}') 
res_p7b = re.findall(r".the", string_p7, re.I | re.S) # re.S adds "\n" to the characters "." represents
print(f'Res 7b: {res_p7b}')
res_p7c = re.search(r"""(.+ed) # Searcing for word ending in _ed
						.+ # Middle of the string
						(\d\d.+) # Date with ordinary number
						, # End of the string""", string_p7, re.S | re.X) # re.X (verbose) allows us to break up the regex search
print(f'Res 7c: {res_p7c.groups()}')
res_p7d = re.findall(r"^\w{3,}", string_p7, re.M) # re.M (multi-line) allows us to recognize the beginning of multiple lines (\n) with anchors (^|$)
print(f'Res 7d: {res_p7d}')


string_p8 ="The hatch creaked as the detectives openned it. A dark, unsettly corridor of ancient and decrepit construction greeted them."
res_p8 = re.findall("a.*d", string_p8) # Maximizes the string found (first "a" to last possible "d"). Max steps
print(f'Res 8 (greedy): {res_p8}')
res_p8b = re.findall("a.*?d", string_p8)
print(f'Res 8 (lazy): {res_p8b}') # Finish after finding the first string (first "a" to first "d"). Min steps


string_p9 = "Extrange sigils in the altar made their mids reel. A dizziness came over them and their stomachs churned."


string_p10 = "They attributed this to some gas leak or a lack of oxygen in the dark catacombs"


string_f = " (...) ".join([string_p1, string_p2, string_p3, string_p4, string_p5, string_p6, string_p7, string_p8])
#print (string_f)

#^(adv\s)?([0-9]{1,2}\s)?[0-9]?D[0-9]{1,3}(r[0-9]{1,3})?$
#normal dice D[0-9]
#dice with min val D[0-9]r[0-9]
#dice with advantage adv D[0-9]