'''
Generates possible location inputs for Skynet to analyze,
currently prints in the format <area>(distance), then gives
an expected output.

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
            area = random.random()  # each location has an 'area'
            lat_vec = InputGenerator.find_vector(
                self.init_lat, InputGenerator.rand_lat())  # a latitude vector
            long_vec = InputGenerator.find_vector(
                self.init_long, InputGenerator.rand_long())  # and a longitude vector

            # calculate the distance as magnitude from our randomized lat and long
            distance = InputGenerator.vector_mag(lat_vec, long_vec)

            self.vectors[f"{i}"] = [
                area,
                distance,
                # calculate the total weight of this location based on the area and distance
                InputGenerator.calc_weight(area, distance)
            ]

    def __repr__(self):
        res = ""
        for x in self.vectors:
            # print location #, area, and distance
            res += f"{x}: <{self.vectors[x][0]:.3f}>({self.vectors[x][1]:.3f})\n"

        res += f"\nExpected output: {self.find_best()}\n"
        return res

    def find_best(self):
        best = list(self.vectors.keys())[0]
        for x in self.vectors:
            if self.vectors[x][2] > self.vectors[best][2]:
                best = x

        return best

    @staticmethod
    # currently the first arg has a weight of .25, the second a weight of .5
    def calc_weight(*args):
        return args[0]*.25 + args[1]*.5

    @staticmethod
    def find_vector(initial, final):
        return initial - final

    @staticmethod
    def vector_mag(lat, long):
        return math.sqrt(lat**2 + long**2)

    @staticmethod
    def rand_lat():
        return random.random() * 90  # assume we're in the northern hemisphere

    @staticmethod
    def rand_long():
        return random.random() * -180  # assume we're in the western hemisphere


with open("generated-ouputs.txt", "w") as f:
    for i in range(5):
        gen = InputGenerator()
        gen.generate()
        print(gen)
        f.write(gen.__str__())
