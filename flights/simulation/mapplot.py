import matplotlib.pyplot as plt

import cartopy.crs as ccrs
import cartopy.io.img_tiles as cimgt
from cartopy.mpl.gridliner import LATITUDE_FORMATTER, LONGITUDE_FORMATTER


class MapPlotter():
    def __init__(self, coordinates):
        self.coordinates = coordinates

        self.request = cimgt.OSM()

        plt.switch_backend('Agg')
        ax = plt.axes(projection=self.request.crs)

        # assume we're near to huntsville
        ax.set_extent([-87.6073, -85.573, 34.1928, 35.2612])
        ax.add_image(self.request, 10, interpolation='bilinear', zorder=0)

        gl = ax.gridlines(draw_labels=True, alpha=0.2)
        gl.xlabels_top = gl.ylabels_right = False
        gl.xformatter = LONGITUDE_FORMATTER
        gl.yformatter = LATITUDE_FORMATTER

    def plot_locations(self, best):
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
                         color='blue', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())  # plot the initial point to a location

                plt.scatter(self.coordinates["longs"][i], self.coordinates["lats"][i],  # scatter the location seperately
                            color='blue', zorder=2, transform=ccrs.Geodetic())

    def plot_path(self):
        plt.scatter(self.coordinates["longs"][0], self.coordinates["lats"][0],  # put our initial location in red
                    color='red', zorder=2, transform=ccrs.Geodetic())

        for i in range(1, len(self.coordinates["longs"])):
            plt.plot([self.coordinates["longs"][i-1], self.coordinates["longs"][i]],
                     [self.coordinates["lats"][i-1], self.coordinates["lats"][i]],
                     color='blue', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())  # plot path from the previous point to the current

            plt.scatter(self.coordinates["longs"][i], self.coordinates["lats"][i],  # scatter the current location seperately
                        color='blue', zorder=2, transform=ccrs.Geodetic())

    def show(self, filename):
        plt.savefig(filename)
        plt.show()
