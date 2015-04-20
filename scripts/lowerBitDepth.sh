#! /bin/sh
# This gets rid of the png error for pngs that have too great of bit depth

echo "Converting images..."
for img
do
    if [[ $img =~ \.png ]]; then
        echo "Processing $img"
        convert $img -strip $img
    else
        echo "$img is not a .png file"
    fi
done
