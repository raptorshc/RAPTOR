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

        self.gen = pointgen.PointGenerator()

    def plot(self, numpoints):
        self.gen.generate(numpoints)

        plt.scatter(self.gen.points["longs"][0], self.gen.points["lats"][0],  # put our initial location in red
                    color='red', zorder=2, transform=ccrs.Geodetic())

        best = int(self.gen.find_best())
        
        for i in range(1, numpoints+1):
            if i == best:
                plt.plot([self.gen.points["longs"][0], self.gen.points["longs"][i]],
                         [self.gen.points["lats"][0], self.gen.points["lats"][i]],
                         color='green', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())

                plt.scatter(self.gen.points["longs"][i], self.gen.points["lats"][i], 
                    color='green', zorder=2, transform=ccrs.Geodetic())
            else:
                plt.plot([self.gen.points["longs"][0], self.gen.points["longs"][i]],
                         [self.gen.points["lats"][0], self.gen.points["lats"][i]],
                         color='blue', linewidth=0.5, zorder=1, transform=ccrs.Geodetic())  # plot the initial point to a location
                
                plt.scatter(self.gen.points["longs"][i], self.gen.points["lats"][i],  # scatter the location seperately
                    color='blue', zorder=2, transform=ccrs.Geodetic())
    def show(self):
        plt.tight_layout()
        plt.savefig('test.png')
        plt.show()


mp = MapPlotter()
mp.plot(10)
mp.show()
