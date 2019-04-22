#!/usr/bin/perl
use warnings;

my %tet_hline = ( "Width" => 4, "Height" => 1, "arr" => ( 	[['#', '#', '#', '#']]) );
my %tet_vline = ( "Width" => 1, "Height" => 4, "arr" => ( 	['#'],
								['#'],
								['#'],
								['#']) );

my %sel = %tet_hline;
my $oy = int(rand(5 - $sel{"Height"}));
my $ox = int(rand(5 - $sel{"Width"}));

#print ("$sel{'arr'}[0][0]\n");

#print ("Generated oy = $oy ox = $ox\n");

for (my $y = 0; $y < 4; ++$y)
{
	for (my $x = 0; $x < 4; ++$x)
	{
		if ($y >= $oy && $x >= $ox && $y < $oy + $sel{"Height"} && $x < $ox + $sel{"Width"})
		{
			
			#print ("yi = ", $y - $oy, ", xi = ", $x - $ox);
			print ($sel{"arr"}[$y - $oy][$x - $ox]);
		}
		else
		{
			print (".");
		}
	}
	print ("\n");
}
