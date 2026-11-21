#!/bin/bash

SPECIAL="special:desktop"

if hyprctl workspaces -j | jq -e ".[] | select(.name == \"$SPECIAL\")" >/dev/null; then
    # If desktop workspace is already active, return to previous workspace
    hyprctl dispatch togglespecialworkspace desktop
else
    # Move current workspace windows to special workspace
    WORKSPACE=$(hyprctl activeworkspace -j | jq -r '.id')

    hyprctl clients -j | jq -r ".[] | select(.workspace.id == $WORKSPACE) | .address" | while read -r address; do
        hyprctl dispatch movetoworkspacesilent special:desktop,address:$address
    done

    hyprctl dispatch togglespecialworkspace desktop
fi