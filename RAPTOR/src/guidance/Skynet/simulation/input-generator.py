'''
    Generates possible inputs for Skynet to analyze,
    currently prints in the format <weight>(lat distance, long distance)

    Author: Sean Widmier
'''
import random
import math


class InputGenerator:
    def __init__(self):
        self.vectors = {}

    def generate(self):
        self.init_lat = InputGenerator.rand_lat()
        self.init_long = InputGenerator.rand_long()

        for i in range(10):
            self.vectors[random.random()] = [  # each location has a weight
                InputGenerator.vector_mag(self.init_lat, InputGenerator.rand_lat()), # and a latitude vector magnitude
                InputGenerator.vector_mag(self.init_long, InputGenerator.rand_long())]  # and a longitude vector magnitude

    def __repr__(self):
        res = ""
        for x in self.vectors:
            res += f"<{x:.3f}>({self.vectors[x][0]:.3f},{self.vectors[x][1]:.3f})\n"
        return res

    @staticmethod
    def vector_mag(initial, final):
        return math.sqrt(final**2 + initial**2)

    @staticmethod
    def rand_lat():
        return random.random() * 90 # assume we're in the northern hemisphere
    
    @staticmethod
    def rand_long():
        return random.random() * -180 # assume we're in the western hemisphere

with open("generated-ouputs.txt", "w") as f:
    for i in range(5):
        gen = InputGenerator()
        gen.generate()
        print(gen)
        f.write(gen.__str__())