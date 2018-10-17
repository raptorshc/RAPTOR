
'''
Generates possible location inputs for Skynet to analyze,
currently prints in the format <area>(distance), then gives
an expected output.

Author: Sean Widmier
'''
import math
import random


class PointGenerator:
    def __init__(self):
        self.points = {"longs": [], "lats": []}
        self.vectors = {}

    def generate(self, numpoints):
        self.numpoints = numpoints

        # the first entry in each list are the initial points
        self.points["longs"].append(-86.640948)
        self.points["lats"].append(34.722427)  # set to huntsville's location

        for i in range(1, numpoints+1):
            self.points["longs"].append(PointGenerator.rand_long())
            # generate a random coordinate
            self.points["lats"].append(PointGenerator.rand_lat())

            area = random.random()  # each location has an 'area'

            lat_vec = PointGenerator.find_vector(
                self.points["lats"][0], self.points["lats"][i])  # a latitude vector
            long_vec = PointGenerator.find_vector(
                self.points["longs"][0], self.points["longs"][i])  # and a longitude vector

            # calculate the distance as magnitude from our randomized lat and long
            distance = PointGenerator.vector_mag(lat_vec, long_vec)

            self.vectors[f"{i}"] = [
                area,
                distance,
                # calculate the total weight of this location based on the area and distance
                PointGenerator.calc_weight(area, distance)
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
    # currently the first arg (area) has a weight of .25, the second arg (distance) an inverse weight
    def calc_weight(*args):
        return (args[0]*.25) * args[1]**-1

    @staticmethod
    def find_vector(initial, final):
        return initial - final

    @staticmethod
    def vector_mag(lat, long):
        return math.sqrt(lat**2 + long**2)

    @staticmethod
    def rand_lat():
        return random.uniform(34.1928, 35.2612)  # assume we're near huntsville

    @staticmethod
    def rand_long():
        # assume we're near huntsville
        return random.uniform(-87.6073, -85.573)
