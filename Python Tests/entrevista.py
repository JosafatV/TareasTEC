# Create a routine where it receive a list of numbers
# and it must first group the even numbers and after the odd numbers.
# Input: [30, 40, 5, 7, 48, 35, 13, 6 , 9] Output: [6, 30, 40, 48, 5, 7, 9, 13, 35]

Input = [30, 40, 5, 7, 48, 35, 13, 6 , 9]

# check if a number is even or odd
def check_even (Num):
    if ((Num % 2) == 0 ):
        return True
    else:
        return False

# order a list from small to large, odds then evens
def order_list (In):
    In.sort()
    out_even = []
    out_odd = []

    for i in range (0, len(In)):
        if (check_even(In[i])):
            out_even.append(In[i])
        else:
            out_odd.append(In[i])
            
    print (out_even+out_odd)
    return (out_even+out_odd)
    
order_list (Input)


