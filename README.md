# Inugami-dev64's comfy AESTHETIC dwm build

This dwm build includes some additional patches and fonts. The color scheme 
is made to be similar to classical Windows theme. For full AESTHETIC 
experience I recommend using Chicago95 theme for GTK applications.  

![](demo.png)

## Keybindings

### General

* Super + Left / Right - change window focus  
* Super + Enter - switch window zoom  
* Super + b - toggle statusbar
* Super + g - toggle window float mode  
* Super + Shift + c - kill client
* Super + [ - focus on previous monitor  
* Super + ] - focus on next monitor  
* Super + Shift + [ - move active window to previous monitor
* Super + Shift + ] - move active window to next monitor
* Super + j / k - increment / decrement master stacking
* Super + h / l - resize master stack


### Global layout settings

* Super + t - set stacking layout  
* Super + y - set floating layout  
* Super + u - set monocle layout  


### Floating window resizing

Window resizing can be done using mouse by clicking Super and then dragging the window
while holding right click, or via following shortcuts:  

* Super + Control + h - make window 40px horizontally smaller  
* Super + Control + j - make window 40px vertically bigger  
* Super + Control + k - make window 40px vertically smaller  
* Super + Control + l - make window 40px horizontally bigger  


### Window moving

Windows can be moved using Super + mouse dragging or via following shortcuts:  

* Super + Shift + h - move window 40px left
* Super + Shift + j - move window 40px down
* Super + Shift + k - move window 40px up
* Super + Shift + l - move window 40px right


### Program specific

* Super + Period - volume up (requires pamixer)  
* Super + Comma - volume down (requires pamixer)  
* Super + q - run kpcli (requires kpcli)
* Super + r - run program (requires dmenu)
* Super + Shift + Enter - spawn new terminal window (requires st)  
* Super + i - open webbrowser (requires Chromium)
* Super + f - open file manager (requires vifm)  
* Super + p - open process manager (requires htop)
* Super + s - new screenshot (requires xfce4-screenshooter)


## Building
Building dwm is done with following command:  
`# make PASSWORD_DB=<path-to-keepass-db>`  

Installing dwm can be done with:  
`# make install`
