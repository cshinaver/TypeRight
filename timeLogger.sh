#! /bin/sh

rawTimeData=".rawTimeData"
timeNow=`date +"%m-%d-%Y %r"`

# Check if in correct project directory
if ! [[ "$(expr "$(pwd)" : '.*/\(.*\)')" = "TypeRight" ]]
then
    echo "Please run this script from the TypeRight directory"
    exit 1
fi

echo "Welcome to TimeLogger!"

# Get name
if ! [ -e .name ]; then
    echo "Please enter your name"
    read name
    echo $name > .name
else
    name=`cat .name`
    echo "Name found: $name"
fi

# Get checkin status
echo "Are you checking in (0) or out (1)?"
read ans

if [ $ans -eq 0 ]; then
    echo "$name checking in at $timeNow"
    echo "$name;in;$timeNow" >> $rawTimeData
elif [ $ans -eq 1 ]; then
    echo "$name checking out at $timeNow"
    echo "$name;out;$timeNow" >> $rawTimeData
else
    echo "Please enter 0 or 1 for checking in or out"
    exit 1
fi
