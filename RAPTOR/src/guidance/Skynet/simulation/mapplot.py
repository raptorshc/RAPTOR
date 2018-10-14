import cartopy.crs as ccrs
import cartopy.io.img_tiles as cimgt
from cartopy.mpl.gridliner import LONGITUDE_FORMATTER, LATITUDE_FORMATTER

import matplotlib.pyplot as plt

import pointgen


class MapPlotter():
    def __init__(self):
        self.coords = {"lats": [], "longs": []}

        self.request = cimgt.OSM()

        plt.switch_backend('Agg')
        ax = plt.axes(projection=self.request.crs)

        ax.set_extent([-90, -80, 31, 38])  # assume we're near to huntsville
        ax.add_image(self.request, 6, interpolation='bilinear', zorder=0)

        gl = ax.gridlines(draw_labels=True, alpha=0.2)
        gl.xlabels_top = gl.ylabels_right = False
        gl.xformatter = LONGITUDE_FORMATTER
        gl.yformatter = LATITUDE_FORMATTER

    def plot_locations(self, numpoints):
        gen = pointgen.PointGenerator()
        gen.generate(numpoints)

        plt.scatter(gen.points["longs"][0], gen.points["lats"][0],  # put our initial location in red
                    color='red', zorder=2, transform=ccrs.Geodetic())

        best = int(gen.find_best())

        for i in range(1, numpoints+1):
            if i == best:
                plt.plot([gen.points["longs"][0], gen.points["longs"][i]],
                         [gen.points["lats"][0], gen.points["lats"][i]],
                         color='green', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())

                plt.scatter(gen.points["longs"][i], gen.points["lats"][i],
                            color='green', zorder=2, transform=ccrs.Geodetic())
            else:
                plt.plot([gen.points["longs"][0], gen.points["longs"][i]],
                         [gen.points["lats"][0], gen.points["lats"][i]],
                         color='blue', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())  # plot the initial point to a location

                plt.scatter(gen.points["longs"][i], gen.points["lats"][i],  # scatter the location seperately
                            color='blue', zorder=2, transform=ccrs.Geodetic())

    def plot_path(self, numpoints):
        gen = pointgen.PointGenerator()
        gen.generate(numpoints)

        plt.scatter(gen.points["longs"][0], gen.points["lats"][0],  # put our initial location in red
                    color='red', zorder=2, transform=ccrs.Geodetic())

        for i in range(1, numpoints+1):
            plt.plot([gen.points["longs"][i-1], gen.points["longs"][i]],
                     [gen.points["lats"][i-1], gen.points["lats"][i]],
                     color='blue', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())  # plot path from the previous point to the current

            plt.scatter(gen.points["longs"][i], gen.points["lats"][i],  # scatter the current location seperately
                        color='blue', zorder=2, transform=ccrs.Geodetic())

    def show(self):
        plt.tight_layout()
        plt.savefig('test.png')
        plt.show()


mp = MapPlotter()
mp.plot_path(10)
mp.show()
