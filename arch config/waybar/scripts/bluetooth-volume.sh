#!/bin/bash

STATE="$HOME/.cache/waybar-bluetooth-volume"

if [ -f "$STATE" ]; then
    rm "$STATE"
else
    touch "$STATE"
fi

pkill -RTMIN+8 waybar