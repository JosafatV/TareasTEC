# Dictionary tests

import random

# Roll a dice and automaticall reroll it if it is below reroll
# returns minimum r if r is specified
def roll(droll, r, reroll):
    rolled = droll()

    if (rolled <= reroll ):
        rolled = droll()

    if (rolled < r):
        rolled = r
        return r

    return rolled

# Decorators? allow to roll dice by specifing the dice (dN) in the function
def d20():
    return random.randint(1, 20)

def d12():
    return random.randint(1, 12)

def d8():
    return random.randint(1, 8)

def d6():
    return random.randint(1, 6)



def test (n_rolls):
    avg_d20_1 = 0
    avg_d20_2 = 0

    for i in range (1, n_rolls):
        avg_d20_1 += d20()
        avg_d20_2 += roll(d20, 2, 1)

    print (avg_d20_1/n_rolls)
    print (avg_d20_2/n_rolls)







# General implementation of the Wounding Table
# returns the minimal required value to wound
def wound (S, T):
    if (S == T):
        print ("4+")
        return 4
    elif (S<=T):
        if (S*2 <= T):
            print ("6+")
            return 6
        else:
            print ("5+")
            return 5
    else:
        if (S >= T*2):
            print ("2+")
            return 2
        else:
            print ("3+")
            return 3
    
