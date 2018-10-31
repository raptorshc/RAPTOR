import pointgen
import mapplot


def main ( ):
	gen = pointgen.PointGenerator ( )

	with open ( "generatedOutputs.txt", 'w+' ) as f:
		for i in range ( 10 ):
			gen.generate ( 10 )
			f.write ( str ( gen ) )

	mp = mapplot.MapPlotter ( gen.points )
	# mp.plot_path()
	mp.plot_locations ( int ( gen.find_best ( ) ) )
	mp.show ( )


if __name__ == "__main__":
	main ( )
