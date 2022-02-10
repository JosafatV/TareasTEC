# This example shows different ways to make lists, called list comprehensions

my_list = []

for char in "hello":
    my_list.append(char)

my_list2 = [char for char in "hello"]

my_list3 = [num*2 for num in range(0, 10)]

my_list4 = [num**2 for num in range(0, 10) if num % 3 == 0]

my_list5 = [num % 3 == 0 for num in range(0, 10)]

print(f'normal for-loop\t{my_list}')
print(f'comprenehnsion\t{my_list2}')
print(f'type conversion\t{list("hello")}')
print(f'operating\t{my_list3}')
print(f'with if-cond\t{my_list4}')
print(f'with function\t{my_list5}')


# Also works with sets. Change [] to {}

my_set = {num % 3 == 0 for num in range(0, 10)}

print(f'set example:\t{my_set}')


# And to modify dictionaries

my_dict = {
    "a": 1,
    "b": 2,
    "c": 3,
    "d": 4,
    "e": 5
}

new_dict = {k: v**2 for k, v in my_dict.items() if v % 2 == 0}
print(f'dictionary ex:\t{new_dict}')


# Excercise
some_list = ["a", "b", "c", "b", "d", "m", "n", "n"]

duplicates = []
for value in some_list:
    if some_list.count(value) > 1:
        if value not in duplicates:
            duplicates.append(value)

print(f"Desired:\t{duplicates}")

my_set = set(some_list)
duplicates = my_set.intersection(some_list)

dups = list({elem for elem in some_list if some_list.count(elem) > 1})

print(f"My result:\t{dups}")
