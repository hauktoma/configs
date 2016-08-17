#!/bin/sh
#
# ~/.xinitrc
#
# Executed by startx (run your window manager from here)

if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi

# Load X resources
[[ -f ~/.Xresources ]] && xrdb -merge ~/.Xresources &

# Fonts for X fix
# xset +fp /usr/share/fonts/local
# xset fp rehash 

# fix Java graphical library
wmname LG3D

# exec gnome-session
# exec startkde
# exec startxfce4
# ...or the Window Manager of your choice

# exec openbox-session

feh --bg-fill /home/hauktoma/pictures/linux_wallpapers/concrete-arch-light.jpg &
setxkbmap -option grp:switch,grp:alt_shift_toggle us,cz &
# guake &
# nm-applet &

conky | while read -r; do xsetroot -name "$REPLY"; done &

# /home/hauktoma/.screenlayout/single_monitor.sh
/usr/bin/xset b off

export MC_SKIN='/home/hauktoma/.config/mc/solarized.ini'

exec dwm
# exec openbox-session
