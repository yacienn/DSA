#!/bin/bash

WALLPAPER_DIR="$HOME/pic"

while true; do
    WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -name "*.jpg" -o -name "*.jpeg" -o -name "*.png" \) | shuf -n 1)

    swww img "$WALLPAPER" \
        --transition-type random \
        --transition-duration 2

    sleep 300
done
