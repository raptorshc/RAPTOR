import matplotlib.pyplot as plt

import cartopy.crs as ccrs
import cartopy.io.img_tiles as cimgt
from cartopy.mpl.gridliner import LATITUDE_FORMATTER, LONGITUDE_FORMATTER


class MapPlotter():
    def __init__(self, coordinates):
        self.coordinates = coordinates

        self.request = cimgt.GoogleTiles()

        # plt.switch_backend('Agg')
        ax = plt.axes(projection=self.request.crs)

        # find extent and plot using that
        extent = MapPlotter.find_extent(self.coordinates)
        ax.set_extent(extent)
        ax.add_image(self.request, 10, interpolation='spline36', zorder=0)

        gl = ax.gridlines(draw_labels=True, alpha=0.2)
        gl.xlabels_top = gl.ylabels_right = False
        gl.xformatter = LONGITUDE_FORMATTER
        gl.yformatter = LATITUDE_FORMATTER

    def plot_locations(self, best):
        print(f'init long: {self.coordinates["longs"][0]}, init lat: {self.coordinates["lats"][0]}')
        plt.scatter(self.coordinates["longs"][0], self.coordinates["lats"][0],  # put our initial location in red
                    color='red', zorder=2, transform=ccrs.Geodetic())

        for i in range(1, len(self.coordinates["longs"])):
            if i == best:
                plt.plot([self.coordinates["longs"][0], self.coordinates["longs"][i]],
                         [self.coordinates["lats"][0], self.coordinates["lats"][i]],
                         color='green', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())

                plt.scatter(self.coordinates["longs"][i], self.coordinates["lats"][i],
                            color='green', zorder=2, transform=ccrs.Geodetic())
            else:
                plt.plot([self.coordinates["longs"][0], self.coordinates["longs"][i]],
                         [self.coordinates["lats"][0], self.coordinates["lats"][i]],
                         color='blue', linewidth=0.5, zorder=1,
                         transform=ccrs.Geodetic())  # plot the initial point to a location
                # scatter the location separately
                plt.scatter(self.coordinates["longs"][i], self.coordinates["lats"][i],
                            color='blue', zorder=2, transform=ccrs.Geodetic())

    def plot_path(self):
        print(f'init long: {self.coordinates["longs"][0]}, init lat: {self.coordinates["lats"][0]}')
        plt.scatter(self.coordinates["longs"][0], self.coordinates["lats"][0],  # put our initial location in red
                    color='red', zorder=3, transform=ccrs.Geodetic())

        for i in range(1, len(self.coordinates["longs"])):
            plt.plot([self.coordinates["longs"][i - 1], self.coordinates["longs"][i]],
                     [self.coordinates["lats"][i - 1], self.coordinates["lats"][i]],
                     color='blue', linewidth=0.5, zorder=1,
                     transform=ccrs.Geodetic())  # plot path from the previous point to the current

            # print(f'Plotting: {self.coordinates["longs"][i]}, {self.coordinates["lats"][i]}')
            plt.scatter(self.coordinates["longs"][i], self.coordinates["lats"][i],
                        # scatter the current location seperately
                        color='blue', zorder=2, transform=ccrs.Geodetic())

    def show(self, filename):
        plt.savefig(filename, dpi=225)
        plt.show()

    @staticmethod
    def find_extent(coordinates):
        extent = [coordinates["longs"][0], coordinates["longs"][0], coordinates["lats"][0],
                  coordinates["lats"][0]]  # x0, x1, y0, y1

        for i in range(len(coordinates["longs"])):
            if coordinates["longs"][i] < extent[0]:  # bottom left
                extent[0] = coordinates["longs"][i] - 0.01
            if coordinates["longs"][i] > extent[1]:  # top right
                extent[1] = coordinates["longs"][i] + 0.01
            if coordinates["lats"][i] < extent[2]:  # bottom left
                extent[2] = coordinates["lats"][i] - 0.01
            if coordinates["lats"][i] > extent[3]:  # top right
                extent[3] = coordinates["lats"][i] + 0.01

        return extent
