import random


class Suit:

    DESCRIPTIONS = {
        "clubs": "♣",
        "diamonds": "♦",
        "hearts": "♥",
        "spades": "♠"
    }

    def __init__(self, description) -> None:
        self._description = description.lower()
        self._symbol = Suit.DESCRIPTIONS[description.lower()]

    @property
    def description(self):
        return self._description

    @property
    def symbol(self):
        return self._symbol


class Card:

    VALUES = {
        11: "Jack",
        12: "Queen",
        13: "King",
        14: "Ace"
    }

    def __init__(self, suit, value) -> None:
        self._suit = suit
        self._value = value

    def show(self):
        if self._value in self.VALUES:
            return f"{self.VALUES[self._value]} of {self._suit.description} ({self._suit.symbol})"
        return f"{str(self._value)} of {self._suit.description} ({self._suit.symbol})"

    def is_special(self):
        return self._value > 10

    def __str__(self) -> str:
        return self.show()

    @property
    def suit(self):
        return self._suit.symbol

    @property
    def value(self):
        return self._value


class Deck:
    def __init__(self, cards=[]) -> None:
        self._cards = cards

    @property
    def size(self):
        if self._cards is []:
            return 0
        return len(self._cards)

    def build(self):
        for suit in Suit.DESCRIPTIONS:
            for i in range(2, 15):
                self._cards.append(Card(Suit(suit), i))

    def show(self):
        for card in self._cards:
            print(card.show())

    def shuffle(self):
        print("Shuffling the deck")
        random.shuffle(self._cards)

    def draw(self):
        if self.size > 0:
            return self._cards.pop()
        return None

    def add(self, card):
        self._cards.insert(0, card)


class Player:
    def __init__(self, name, is_computer=False):
        self.name = name
        self._deck = Deck([])
        self._is_computer = is_computer

    def has_empty_deck(self):
        return self._deck.size == 0

    def count_cards(self):
        return self._deck.size

    def draw_card(self):
        if self.has_empty_deck == True:
            print(f"player {self.name} has no cards")
            return None
        return self._deck.draw()

    def add_card(self, card):
        self._deck.add(card)

    @property
    def is_computer(self):
        return self._is_computer
