#!/usr/bin/perl
# Creates new levels
# Usage ./LevelAdder.pl levelNumber

use strict;
use warnings;

use Scalar::Util qw(looks_like_number);

die "Please pass desired level number" if scalar(@ARGV) == 0;
die "Please pass a valid level number" if not looks_like_number($ARGV[0]);
die "Please pass a positive number" if $ARGV[0] <= 0;
my $level_num = $ARGV[0];

sub read_line
{
    $_[0] =~ s/(level[\(\) ]*)[0-9]/$1$level_num/gi;
}

sub create_new_file_from_file
{
    my $level_name = $_[0];
    my $new_level_name = $level_name;
    $new_level_name =~ s/[0-9]/$level_num/g;

    open my $old_file, "<", $level_name;
    open my $new_file, ">", $new_level_name;

    my $line;
    while ($line = <$old_file>)
    {
        read_line $line;
        print $new_file $line;
    }

    close $old_file;
    close $new_file;
}

create_new_file_from_file "../Level1.h";
create_new_file_from_file "../Level1.cpp";
