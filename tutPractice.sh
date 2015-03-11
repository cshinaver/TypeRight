#! /bin/bash

curDir=`pwd`
if [[ $1 == '' ]]
then
    echo "Please pass a tut number for first argument"
    exit 1
fi

# Get number for tut
tutNum=$1
tutsDirBase=/Users/charlesshinaver/Desktop/tuts/lazyfoo.net/tutorials/SDL
tutsDir=$tutsDirBase/$1

if ! [[ -e $tutsDirBase ]]
then
    echo "Tutorials directory doesn't exist."
    exit 1
fi


# Change to directory of tut
cd $tutsDir*

# Extract directory and fix permissions
unzip $tutNum* -d foo
chmod -R u+rwx foo
cd foo/*

# copy to old
cp *.bmp $curDir/imgs
cp *.png $curDir/imgs

# Remove unzipped folder
cd ../..
rm -r foo
