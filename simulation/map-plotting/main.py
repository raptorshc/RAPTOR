import pointgen
import mapplot
import xlrd

def main():
    wb = xlrd.open_workbook("DATA.xlsx")
    sheet = wb.sheet_by_index(0)

    data = {"longs": [], "lats": []}
    for i in range(67,sheet.nrows):
        data["lats"].append(float(sheet.cell_value(i, 4)))
        data["longs"].append(-1.0*float(sheet.cell_value(i, 5)))

#     gen = pointgen.PointGenerator()
#     gen.generate(10)

#     mpl = mapplot.MapPlotter(gen.points)
#     mpl.plot_locations(int(gen.find_best()))
#     mpl.show("outputs/locations.png")

    mpp = mapplot.MapPlotter(data)
    print(mpp.coordinates)
    mpp.plot_path()
    mpp.show("outputs/path.png")

#     with open("outputs/generated-ouputs.txt", "w") as f:
#         f.write(gen.__str__())


if __name__ == "__main__":
    main()