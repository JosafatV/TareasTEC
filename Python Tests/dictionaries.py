# Dictionary tests

music_dict = {
    "aritst": "Linkin Park",
    "album": "Hybrid Theory",
    "songs": ["Paper Cut", "In The End", "Forgotten"],
    "year": 1999,
    "bought": False
    }


print("Dictionary's length is: " + str (len(music_dict)))

print ("\n  +++ Keys +++")
print (music_dict.keys())

print ("\n  +++ Values +++")
print (music_dict.values())

print ("\n  +++ Items +++")
print (music_dict.items())

print ("\n  +++ Accessing data +++")

if "year" in music_dict:
    print ("You can search by year!")

a = music_dict["songs"]
print (a[2])

print (music_dict.get("album"))

music_dict.update({"bought": True})

print("Bought? ", music_dict["bought"])



def parent(num):
    def first_child():
        return "Hi, I am Emma"

    def second_child():
        return "Call me Liam"

    if num == 1:
        return first_child()
    else:
        return second_child()




def main():
    pass # ToDo: make main function

