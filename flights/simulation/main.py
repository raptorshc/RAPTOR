import mapplot
import pointgen

# Reading an excel file using Python
import xlrd


def main():
    # To open Workbook
    wb = xlrd.open_workbook("../data/falcon/10.27/DATA.xlsx")
    sheet = wb.sheet_by_index(0)

    data = {"longs": [], "lats": []}
    for i in range(1, sheet.nrows):
        if (float(sheet.cell_value(i, 4)), float(sheet.cell_value(i, 5))) != (
        0.0, 0.0):  # don't include any (0.0, 0.0) points in the list
            data["lats"].append(float(sheet.cell_value(i, 4)))
            data["longs"].append(
                float(sheet.cell_value(i, 5)) * -1)  # longitude is stored in positive, needs to be negative for USA

    with open("generated-ouputs.txt", "w") as f:
        for i in range(5):
            gen = pointgen.PointGenerator()
            gen.generate(10)
            print(gen)
            f.write(gen.__str__())

    print("Generating locations map..")
    mpl = mapplot.MapPlotter(gen.points)
    mpl.plot_locations(int(gen.find_best()))
    mpl.show("locations.png")

    print("Generating path map..")
    mpp = mapplot.MapPlotter(gen.points)
    mpp.plot_path()
    mpp.show("path.png")

    print("Done!")


if __name__ == "__main__":
    main()