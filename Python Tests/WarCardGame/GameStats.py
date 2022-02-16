import matplotlib.pyplot as plt


class StatManager:
    def __init__(self, dataset) -> None:
        self.dataset = dataset
        self.num_rounds = len(dataset)
        self._rounds = []
        self._list_p1 = []
        self._list_p2 = []

    def agregate_item(self, index):
        aggregate = 0
        for set in self.dataset:
            aggregate += set[index]
        return aggregate

    def create_lists(self):
        for set in self.dataset:
            self._rounds.append(set[0])
            self._list_p1.append(set[1])
            self._list_p2.append(set[2])

    def graph_game(self):
        self.create_lists()
        plt.plot(self._rounds, self._list_p1, label="player")
        plt.plot(self._rounds, self._list_p2, label="computer")

        plt.title('War Card Game Stats')
        plt.xlabel('Rounds')
        plt.ylabel('Cards')

        plt.show()


if __name__ == "__main__":
    data_points = [(0, 26, 26), (1, 25, 27), (2, 21, 31),
                   (3, 20, 32), (4, 21, 31)]

    sm = StatManager(data_points)
    sm.graph_game()
