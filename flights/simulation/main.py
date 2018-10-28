import mapplot
import pointgen

def main():
    with open("generated-ouputs.txt", "w") as f:
        for i in range(5):
            gen = pointgen.PointGenerator()
            gen.generate(10)
            print(gen)
            f.write(gen.__str__())

    mpl = mapplot.MapPlotter(gen.points)
    mpl.plot_locations(int(gen.find_best()))
    mpl.show("locations.png")

    mpp = mapplot.MapPlotter(gen.points)
    mpp.plot_path()
    mpp.show("path.png")

if __name__ == "__main__":
    main()
