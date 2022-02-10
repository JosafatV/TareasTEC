import random


class DiceRoller:
    """
    Roll a dice and automaticall reroll it if it is below reroll
    WIP: returns minimum r if r is specified
    """

    @property
    def d20(self):
        return random.randint(1, 20)

    @property
    def d12(self):
        return random.randint(1, 12)

    @property
    def d10(self):
        return random.randint(1, 10)

    @property
    def d8(self):
        return random.randint(1, 8)

    @property
    def d6(self):
        return random.randint(1, 6)

    @property
    def d4(self):
        return random.randint(1, 4)


if __name__ == "__main__":
    # By defining the the functions as property we can call them
    # as attributes of the class instead of methods (roll.d20())
    roll = DiceRoller()
    print(f' Rolling a d20: {roll.d20}')
    print(f' Rolling a d12: {roll.d12}')
    print(f' Rolling a d10: {roll.d10}')
    print(f' Rolling a d8: {roll.d8}')
    print(f' Rolling a d6: {roll.d6}')
    print(f' Rolling a d4: {roll.d4}')


def my_hof(func):
    def wrapper():
        print("+++ ", end="")
        func()
        print("+++ ")
    return wrapper()


# This decorator allows us to run an "amplified" version of hello() by running my_hof(hello)
# Note: not sure why is making the call automatically
@my_hof
def my_hello():
    print("Hello world!", end=" ")


def my_hof2(func):
    def wrapper(param="cruel world"):
        print("+++ End transmission: ", end="")
        func(param)
        print("+++ ")
    return wrapper()

# This decorator has parameters


@my_hof2
def my_bye(name):
    print(f"Good bye, {name}", end=" ")

# Note: not sure why is also not accepting the parameter
# my_bye("Aritosteles")
# my_hof2(my_bye("Aristoteles"))


def my_hof3(func):
    def wrapper(*args, **kwargs):
        print(" >> ", end="")
        func(*args, **kwargs)
        print("")
    return wrapper()

# This decorator fixes issues with multiple parameter. No longer needing to change parameters in wrapper, func call and func definition
# Again no idea why is it instant-calling and this one I can't patch to run


"""
@my_hof3
def transmit(words, date, time, to):
    print(f"{date}, {time} to {to}: {words} :: ")


transmit("Requisiton denied", "M41.132", "05:30", "ME-4ErOs24")
"""
