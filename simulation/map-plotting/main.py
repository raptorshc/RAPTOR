import pointgen
import mapplot

def main():
    gen = pointgen.PointGenerator()
    gen.generate(10)

    mpl = mapplot.MapPlotter(gen.points)
    mpl.plot_locations(int(gen.find_best()))
    mpl.show("outputs/locations.png")

    mpp = mapplot.MapPlotter(gen.points)
    mpp.plot_path()
    mpp.show("outputs/path.png")

if __name__ == "__main__":
    main()