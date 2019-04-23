my @tet_hline = ( "####" );
my @tet_vline = ( "#", "#", "#", "#" );
my @tet_cube = ( "##", "##" );
my @tet_t1 = ( ".#.", "###" );
my @tet_t2 = ( "#.", "##", "#." );
my @tet_t3 = ( "###", ".#." );
my @tet_t4 = ( ".#", "##", ".#" );
my @tet_z1 = ( "##.", ".##" );
my @tet_z2 = ( ".##", "##." );
my @tet_z3 = ( ".#", "##", "#." );
my @tet_z4 = ( "#.", "##", ".#" );
my @tet_gupleft = ( "##", ".#", ".#" );
my @tet_gupright = ( "##", "#.", "#." );
my @tet_grighttop = ( "..#", "###" );
my @tet_grightdown = ( "###", "..#" );
my @tet_gdownright = ( "#.", "#.", "##" );
my @tet_gdownleft = ( ".#", ".#", "##" );
my @tet_gleftdown = ( "###", "#.." );
my @tet_gleftup = ( "#..", "###" );

my $count = int($ARGV[0]);

#how to create array of arrays correct?
#my @figures = ( @tet_hline, @tet_vline, @tet_cube );

while ($count > 0)
{
	my $rnd = int(rand(19));
	my @sel;
	#Fix this using array of arrays
	@sel = @tet_hline if ($rnd == 0);
	@sel = @tet_vline if ($rnd == 1);
	@sel = @tet_cube if ($rnd == 2);
	@sel = @tet_t1 if ($rnd == 3);
	@sel = @tet_t2 if ($rnd == 4);
	@sel = @tet_t3 if ($rnd == 5);
	@sel = @tet_t4 if ($rnd == 6);
	@sel = @tet_z1 if ($rnd == 7);
	@sel = @tet_z2 if ($rnd == 8);
	@sel = @tet_z3 if ($rnd == 9);
	@sel = @tet_z4 if ($rnd == 10);
	@sel = @tet_gupleft if ($rnd == 11);
	@sel = @tet_gupright if ($rnd == 12);
	@sel = @tet_grighttop if ($rnd == 13);
	@sel = @tet_grightdown if ($rnd == 14);
	@sel = @tet_gdownright if ($rnd == 15);
	@sel = @tet_gdownleft if ($rnd == 16);
	@sel = @tet_gleftdown if ($rnd == 17);
	@sel = @tet_gleftup if ($rnd == 18);

	my $Height = scalar(@sel);
	my $Width = length(@sel[0]);

	my $oy = int(rand(5 - $Height));
	my $ox = int(rand(5 - $Width));

	for (my $y = 0; $y < 4; ++$y)
	{
		for (my $x = 0; $x < 4; ++$x)
		{
			if ($y >= $oy && $x >= $ox && $y < $oy + $Height && $x < $ox + $Width)
			{
				print (substr($sel[$y - $oy], $x - $ox, 1));
			}
			else
			{
				print ".";
			}
		}
		print "\n";
	}
	print "\n" if ($count > 1);
	--$count;
}
