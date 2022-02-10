# Testing the map, filter, zip AND reduce functions
# includes a little taste of lambda
from functools import reduce
from re import I

lista = list(range(0, 5))

# map(func, iter)


def multi3(list):
    """ Returns a list with all its elements multiplied by 3"""
    res = []
    for i in list:
        res.append(list[i]*3)
    return res


def m3(item):
    """ Multiplies a number by 3 """
    return item*3


def m_multi(lista):
    """ Returns a list with all its elements multiplied by 3 without using a for-looop"""
    def mul3(item):
        return item*3

    return list(map(mul3, lista))


def mm3_lambda(lista):
    """ Returns a list with all its elements multiplied by 3 using lambda instead of a for-looop"""
    return list(map(lambda param: param*3, lista))


print(f'lista is:\t{lista}')
print(f'multi is:\t{multi3(lista)}')
print(f'  map is:\t{list(map(m3, lista))}')
print(f'm-multi is:\t{m_multi(lista)}')
print(f'mm3_lambda is:\t{mm3_lambda(lista)}')


def check_odd(item):
    """Returns True if odd, False if even"""
    return item % 2 != 0


def get_odds(lista):
    """Returns a list with all the odd items"""
    def is_odd(item):
        return item % 2 != 0

    return list(filter(is_odd, lista))


def odds_lambda(lista):
    """Returns a list with all the odd items using lambda"""
    # Here we replace is_odd with a lambda function
    return list(filter(lambda p: (p % 2) != 0, lista))


print(f'lista is:\t{lista}')
print(f'filter is:\t{list(filter(check_odd, lista))}')
print(f'filinfunc is:\t{get_odds(lista)}')
print(f'odds_lambda is:\t{odds_lambda(lista)}')


listb = list(range(1, 11, 3))
listc = ["a", "b", "c", "d", "e"]


def zipper(lista, listb):
    """ Joins two lists into tuples based on their index.
    Excess elements are not included in the resulting list"""
    return list(zip(lista, listb))


print(f'lista is:\t{lista}')
print(f'listb is:\t{listb}')
print(f'listc is:\t{listc}')
print(f'zipping is:\t{list(zip(lista, listb))}')
print(f'zipper is:\t{zipper(lista, listb)}')
print(f'trizi is:\t{list(zip(lista, listb, listc))}')


def accumulator(accm, item):
    """Adds an item in a list to an accumulator defined in the reduce fincion"""
    print(f'accm: {accm} | item: {item}')
    return accm + item


def my_reduce(lista):
    accm = 0
    for i in lista:
        accm += i
    return accm


print(f'lista is:\t{lista}')
print(f'reduce is:\t{reduce(accumulator, lista, 0)}')
print(f'my_reduce is:\t{my_reduce(lista)}')
print(f're-lambda is:\t{reduce((lambda accm, item: accm+item), lista, 0)}')


# Lambda extra
a = [(0, 1), (4, 3), (10, -1), (9, 9)]
a.sort(key=lambda x: x[1])

print(a)
