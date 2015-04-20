#! /usr/bin/perl
# SpriteAdder.pl
# Charles Shinaver
# This script adds a new sprite to the project
# Usage: perl SpriteAdder.pl NewSpriteName

use strict;
use warnings;

# Check if user passed new sprite name
if (scalar(@ARGV) == 0)
{
    print "Usage: perl SpriteAdder.pl NewSpriteName\n";
    exit(1);
}


# Display info to user
print "Welcome to SpriteAdder!\n";

sub add_class_files
{
    print "Adding class files...\n";
    my $sprite_name = $_[0];
    my $uc_sprite_name = uc $sprite_name;
    # Iterate through bruh class files
    open my $bruh_header, "<", "../Bruh.h";
    open my $new_sprite_header, ">", "../$sprite_name.h";
    open my $bruh_imp, "<", "../Bruh.cpp";
    open my $new_sprite_imp, ">", "../$sprite_name.cpp";

    while (my $line = <$bruh_header>)
    {
        $line =~ s/Bruh/$sprite_name/g;
        $line =~ s/BRUH/$uc_sprite_name/g;
        next if $line =~ /DEMO/;
        print $new_sprite_header $line;
    }

    while (my $line = <$bruh_imp>)
    {
        $line =~ s/Bruh/$sprite_name/g;
        print $new_sprite_imp $line;
    }

    close $bruh_header;
    close $new_sprite_header;
    close $bruh_imp;
    close $new_sprite_imp;
}

sub add_to_cmake_file
{
    my $sprite_name = $_[0];

    open my $cmake_fh, "<", "../CMakeLists.txt";
    open my $new_cmake_fh, ">", "../newCMakeLists.txt";

    my $cmake_newsprite_definition = "";
    while (my $line = <$cmake_fh>)
    {
        # For definition, grab next two lines
        if ($line =~ /Bruh Class/)
        {
            print $new_cmake_fh $line;

            $line =~ s/Bruh/$sprite_name/g;
            $cmake_newsprite_definition .= $line;
            for my $i (0..1)
            {
                $line = <$cmake_fh>;
                print $new_cmake_fh $line;
                $line =~ s/Bruh/$sprite_name/g;
                $cmake_newsprite_definition .= $line;
            }
            print $new_cmake_fh "\n$cmake_newsprite_definition";
        }
        elsif ($line =~ /Bruh_lib/)
        {
            $line =~ s/Bruh_lib/Bruh_lib ${sprite_name}_lib/;
            print $new_cmake_fh $line;
        }
        else
        {
            print $new_cmake_fh $line;
        }
    }

    # Rename old cmake file
    `rm ../CMakeLists.txt`;
    `mv ../newCMakeLists.txt ../CMakeLists.txt`;

}

sub create_new_sprite
{
    my $sprite_name = $_[0];

    # Add Class files
    add_class_files $sprite_name;
    
    # Add to Cmake file
    add_to_cmake_file $sprite_name;

    # Add to Sprite Factory

}

create_new_sprite @ARGV;
