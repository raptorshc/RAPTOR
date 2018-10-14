import pointgen
import mapplot

def main():
    gen = pointgen.PointGenerator()
    gen.generate(10)

    mp = mapplot.MapPlotter(gen.points)
    # mp.plot_path()
    mp.plot_locations(int(gen.find_best()))
    mp.show()

if __name__ == "__main__":
    main()