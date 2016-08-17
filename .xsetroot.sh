DATETIME=`date '+%e %b %Y %a, %k:%M'`
UPTIME=`uptime | sed 's/.*up\s*//' | sed 's/,\s*[0-9]* user.*//' | sed 's/  / /g'`
BATTERYSTATE=$( acpi -b | awk '{ split($5,a,":"); print substr($3,0,2), $4, "["a[1]":"a[2]"]" }' | tr -d ',' )
VOLUME=`amixer get Master | egrep -o "[0-9]+%"`
LAYOUT=`xkblayout-state print "%s"`
xsetroot -name "${LAYOUT} | Vol ${VOLUME} | Up ${UPTIME}h | ${BATTERYSTATE} | ${DATETIME}"
