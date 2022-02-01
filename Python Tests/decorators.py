# Decorators are usually used with classes!

import random

# Roll a dice and automaticall reroll it if it is below reroll
# returns minimum r if r is specified

class DiceRoller:

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


# By defining the the functions as property we can call them
# as attributes of the class instead of methods (roll.d20())
roll = DiceRoller()
print(f' Rolling a d20: {roll.d20}')
print(f' Rolling a d12: {roll.d12}')
print(f' Rolling a d10: {roll.d10}')
print(f' Rolling a d8: {roll.d8}')
print(f' Rolling a d6: {roll.d6}')
print(f' Rolling a d4: {roll.d4}')







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
	
