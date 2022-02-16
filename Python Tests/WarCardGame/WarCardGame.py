from CardGameClasses import Deck, Player
from GameStats import StatManager


class WarCardGame:
    PLAYER = 0
    COMPUTER = 1
    TIE = 2

    round = 0

    def __init__(self, player, computer) -> None:
        self._player = player
        self._computer = computer
        self._deck = Deck([])

        self.make_initial_deck()

    def make_initial_deck(self):
        self._deck.build()
        self._deck.shuffle()
        self.make_decks(self._player)
        self.make_decks(self._computer)

    def make_decks(self, participant):
        for _ in range(26):
            card = self._deck.draw()
            participant.add_card(card)

    def get_round_winner(self, p1_card, pc_card):
        if p1_card.value > pc_card.value:
            return WarCardGame.PLAYER
        elif p1_card.value < pc_card.value:
            return WarCardGame.COMPUTER
        else:
            return WarCardGame.TIE

    def get_cards_won(self, p1_card, pc_card, prev_cards):
        if prev_cards:
            return [p1_card, pc_card] + prev_cards
        else:
            return [p1_card, pc_card]

    def add_cards_to_participant(self, participant, cards):
        for card in cards:
            participant.add_card(card)

    def count_cards(self):
        print(f"{self._player.name} has {self._player.count_cards()} cards left")
        print(f"{self._computer.name} has {self._computer.count_cards()} cards left\n")
        self.round += 1
        return (self.round, self._player.count_cards(), self._computer.count_cards())

    def start_war(self, cards_from_battle):
        player_cards = []
        computer_cards = []

        print("Drawing hidden cards\n")

        # Leave 1 card for the battle!
        for _ in range(3):
            if self._player.count_cards() > 1:
                player_cards.append(self._player.draw_card())
            if self._computer.count_cards() > 1:
                computer_cards.append(self._computer.draw_card())

        self.start_battle(player_cards + computer_cards + cards_from_battle)

    def start_battle(self, cards_from_war=None):
        print(f" +++ Commencing simulation - Round {self.round} +++ ")

        p1_card = self._player.draw_card()
        pc_card = self._computer.draw_card()

        print(f"{self._player.name}: {p1_card.show()}")
        print(f"{self._computer.name}: {pc_card.show()}")

        winner = self.get_round_winner(p1_card, pc_card)
        cards_won = self.get_cards_won(p1_card, pc_card, cards_from_war)

        if winner == WarCardGame.PLAYER:
            print("  You won this round!\n")
            self.add_cards_to_participant(self._player, cards_won)
        elif winner == WarCardGame.COMPUTER:
            print("  The Omnissiah wins this round!\n")
            self.add_cards_to_participant(self._computer, cards_won)
        else:
            print("  A tie! This is war\n")
            if not self.check_game_over():  # Prevent a war if a user doesn't have more cards
                self.start_war(cards_won)

        return winner

    def check_game_over(self):
        if self._player.has_empty_deck():
            print("\n================================================")
            print("      The machine surpases the flesh... again     ")
            print("================================================\n")
            return True
        elif self._computer.has_empty_deck():
            print("\n================================================")
            print(f"You have won this time but the machine is eternal")
            print("================================================\n")
            return True
        else:
            return False

    def start_game_message(self):
        print("==============================================")
        print("                WAR CARD GAME                 ")
        print("==============================================")


if __name__ == "__main__":
    p1name = input("Enter player 1 name: ")
    p2name = input("Enter player 2 name: ")

    player1 = Player("p1name")
    player2 = Player("p2name", True)

    game = WarCardGame(player1, player2)
    game.start_game_message()

    game_data = []
    game_data.append(game.count_cards())

    while not game.check_game_over():
        game.start_battle()
        game_data.append(game.count_cards())

        # answer = input('press "Enter" to continue or "X" to exit the game\n') # Can take upwards of 1000 rounds
        answer = ""
        if "x" == answer.lower():
            break

    mngr = StatManager(game_data)
    mngr.graph_game()
