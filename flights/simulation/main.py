import mapplot
import pointgen


# Reading an excel file using Python
import xlrd


def main():
    # To open Workbook
    wb = xlrd.open_workbook("../data/falcon/10.27/DATA.xlsx")
    sheet = wb.sheet_by_index(0)

    data = {"longs": [], "lats": []}
    for i in range(sheet.nrows):
        data["lats"].append(sheet.cell_value(i, 4))
        data["longs"].append(sheet.cell_value(i, 5))

    # with open("generated-ouputs.txt", "r") as f:
    #     for i in range(5):
    #         gen = pointgen.PointGenerator()
    #         gen.generate(10)
    #         print(gen)
    #         f.write(gen.__str__())

    # mpl = mapplot.MapPlotter(gen.points)
    # mpl.plot_locations(int(gen.find_best()))
    # mpl.show("locations.png")

    mpp = mapplot.MapPlotter(data)
    mpp.plot_path()
    mpp.show("path.png")

if __name__ == "__main__":
    main()