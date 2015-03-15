#! /usr/bin/awk -f

function twelveToTwentyFour(_time)
{
    numHours=substr(_time, 0, 2);
    suffix=substr(_time, 10, 2);
    if (suffix == "PM" && numHours != "12")
    {
        numHours += 12;
    }
    else if (suffix == "AM" && numHours == "12")
    {
        numHours = 0;
    }

    return numHours;
}

function minutes(_time)
{
    return substr(_time, 4, 2);
}

BEGIN {
    FS=";";
    inFound=0;
    totalHours=0;
    totalMinutes=0;
    printf("%s %10s %13s %14s\n", "Member", "Date", "Time in", "Time out");
    
}

/in/ {
    if (inFound == 1)
    {
        printf("Unmatched ""in"" time on row %i. Make sure all ""ins"" have a matching ""out""\n", NR);
        exit;
    }
    timeIn=$4;
    date=$3;
    nameIn=$1;
    nrIn=NR;
    inFound=1;
    hoursIn=twelveToTwentyFour(timeIn);
    minutesIn=minutes(timeIn);

}

/out/ {
    nameOut=$1;
    if (nameIn != nameOut)
    {
        printf("Name for ""in"" (%s) does not match name for ""out"" (%s) on row %i. Make sure all names are adjacent matching.\n", nameIn, nameOut, NR);
        exit;
    }
    timeOut=$4;

    hoursOut=twelveToTwentyFour(timeOut);
    minutesOut=minutes(timeOut);

    # Calculate total number of minutes
    # Algorithm found:
    # http://stackoverflow.com/questions/3518819/algorithm-needed-to-calculate-difference-between-two-times
    startx = hoursIn * 60 + minutesIn;
    endx = hoursOut * 60 + minutesOut;
    duration = endx - startx;
    if (duration < 0)
        duration += 1440;
    totalMinutes += duration;


    # Print hours
    printf("%s %15s %8s %13s\n", nameIn, date, timeIn, timeOut);
    inFound=0;
}

END {
    # Calculate number of hours
    totalHours = int(totalMinutes / 60);
    totalMinutes = totalMinutes - totalHours * 60;
    printf("Total hours: %i\n", totalHours);
    printf("Total minutes: %i\n", totalMinutes);
}

