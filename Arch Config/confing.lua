-- ============================================================
-- HYPRLAND LUA CONFIG
-- ============================================================


------------------
---- MONITOR ----
------------------

hl.monitor({
    output   = "",
    mode     = "preferred",
    position = "auto",
    scale    = "auto",
})


---------------------
---- MY PROGRAMS ----
---------------------

local terminal    = "kitty"
local fileManager = "kitty -e yazi"
local menu        = "rofi -show drun -theme ~/.config/rofi/theme.rasi"
local editor      = "code"


-------------------
---- AUTOSTART ----
-------------------

hl.on("hyprland.start", function ()
    -- Start Waybar
    hl.exec_cmd("waybar")

    -- Start wallpaper daemon
    hl.exec_cmd("awww-daemon")

    -- Set wallpaper
    hl.exec_cmd("sleep 1 && awww img ~/pic/1387268.jpg")

    -- Start dropdown terminal
    hl.exec_cmd("kitty --class dropdown-terminal")
end)


-------------------------------
---- ENVIRONMENT VARIABLES ----
-------------------------------

hl.env("XCURSOR_SIZE", "24")
hl.env("HYPRCURSOR_SIZE", "24")


-----------------------
----- LOOK & FEEL -----
-----------------------

hl.config({
    general = {
        gaps_in  = 6,
        gaps_out = 12,

        border_size = 2,

        col = {
            active_border = {
                colors = {
                    "rgba(33ccffee)",
                    "rgba(00ff99ee)"
                },
                angle = 45
            },

            inactive_border = "rgba(595959aa)",
        },

        resize_on_border = false,
        allow_tearing = false,

        layout = "dwindle",
    },

    decoration = {
        rounding       = 10,
        rounding_power = 2,

        active_opacity   = 1.0,
        inactive_opacity = 1.0,

        shadow = {
            enabled      = true,
            range        = 4,
            render_power = 3,
            color        = 0xee1a1a1a,
        },

        blur = {
            enabled  = true,
            size     = 3,
            passes   = 1,
            vibrancy = 0.1696,
        },
    },

    animations = {
        enabled = true,
    },
})


--------------------
---- ANIMATIONS ----
--------------------

hl.curve(
    "easeOutQuint",
    {
        type = "bezier",
        points = {
            {0.23, 1},
            {0.32, 1}
        }
    }
)

hl.curve(
    "easeInOutCubic",
    {
        type = "bezier",
        points = {
            {0.65, 0.05},
            {0.36, 1}
        }
    }
)

hl.curve(
    "linear",
    {
        type = "bezier",
        points = {
            {0, 0},
            {1, 1}
        }
    }
)

hl.curve(
    "almostLinear",
    {
        type = "bezier",
        points = {
            {0.5, 0.5},
            {0.75, 1}
        }
    }
)

hl.curve(
    "quick",
    {
        type = "bezier",
        points = {
            {0.15, 0},
            {0.1, 1}
        }
    }
)

hl.curve(
    "easy",
    {
        type = "spring",
        mass = 1,
        stiffness = 238.1191,
        dampening = 24.21279333
    }
)


hl.animation({
    leaf = "global",
    enabled = true,
    speed = 10,
    bezier = "default"
})

hl.animation({
    leaf = "border",
    enabled = true,
    speed = 5.39,
    bezier = "easeOutQuint"
})

hl.animation({
    leaf = "windows",
    enabled = true,
    speed = 4.79,
    spring = "easy"
})

hl.animation({
    leaf = "windowsIn",
    enabled = true,
    speed = 4.1,
    spring = "easy",
    style = "popin 87%"
})

hl.animation({
    leaf = "windowsOut",
    enabled = true,
    speed = 1.49,
    bezier = "linear",
    style = "popin 87%"
})

hl.animation({
    leaf = "fadeIn",
    enabled = true,
    speed = 1.73,
    bezier = "almostLinear"
})

hl.animation({
    leaf = "fadeOut",
    enabled = true,
    speed = 1.46,
    bezier = "almostLinear"
})

hl.animation({
    leaf = "fade",
    enabled = true,
    speed = 3.03,
    bezier = "quick"
})

hl.animation({
    leaf = "layers",
    enabled = true,
    speed = 3.81,
    bezier = "easeOutQuint"
})

hl.animation({
    leaf = "layersIn",
    enabled = true,
    speed = 4,
    bezier = "easeOutQuint",
    style = "fade"
})

hl.animation({
    leaf = "layersOut",
    enabled = true,
    speed = 1.5,
    bezier = "linear",
    style = "fade"
})

hl.animation({
    leaf = "fadeLayersIn",
    enabled = true,
    speed = 1.79,
    bezier = "almostLinear"
})

hl.animation({
    leaf = "fadeLayersOut",
    enabled = true,
    speed = 1.39,
    bezier = "almostLinear"
})

hl.animation({
    leaf = "workspaces",
    enabled = true,
    speed = 1.94,
    bezier = "almostLinear",
    style = "fade"
})

hl.animation({
    leaf = "workspacesIn",
    enabled = true,
    speed = 1.21,
    bezier = "almostLinear",
    style = "fade"
})

hl.animation({
    leaf = "workspacesOut",
    enabled = true,
    speed = 1.94,
    bezier = "almostLinear",
    style = "fade"
})

hl.animation({
    leaf = "zoomFactor",
    enabled = true,
    speed = 7,
    bezier = "quick"
})


-------------------
---- DWINDLE ----
-------------------

hl.config({
    dwindle = {
        preserve_split = true,
    },
})


-------------------
---- MASTER ----
-------------------

hl.config({
    master = {
        new_status = "master",
    },
})


-------------------
---- SCROLLING ----
-------------------

hl.config({
    scrolling = {
        fullscreen_on_one_column = true,
    },
})


----------------
---- MISC ----
----------------

hl.config({
    misc = {
        force_default_wallpaper = -1,
        disable_hyprland_logo = false,
    },
})


---------------
---- INPUT ----
---------------

hl.config({
    input = {
        kb_layout  = "fr",
        kb_variant = "",
        kb_model   = "",
        kb_options = "",
        kb_rules   = "",

        follow_mouse = 1,

        sensitivity = 0,

        touchpad = {
            natural_scroll = false,
        },
    },
})


------------------
---- GESTURES ----
------------------

hl.gesture({
    fingers = 3,
    direction = "horizontal",
    action = "workspace"
})


---------------------
---- KEYBINDINGS ----
---------------------

-- ============================================================
-- MAIN MODIFIER
-- ============================================================

local mainMod = "ALT"


-- ============================================================
-- TERMINAL
-- Alt + Q
-- ============================================================

hl.bind(
    mainMod .. " + A",
    hl.dsp.exec_cmd(terminal)
)


-- ============================================================
-- CLOSE WINDOW
-- Alt + C
-- ============================================================

hl.bind(
    mainMod .. " + R",
    hl.dsp.window.close()
)


-- ============================================================
-- FULLSCREEN
-- Alt + F
-- ============================================================

hl.bind(
    mainMod .. " + F",
    hl.dsp.window.fullscreen()
)


-- ============================================================
-- YAZI
-- Alt + E
-- ============================================================

hl.bind(
    mainMod .. " + E",
    hl.dsp.exec_cmd(fileManager)
)


-- ============================================================
-- VS CODE
-- Alt + Shift + C
-- ============================================================

hl.bind(
    mainMod .. " + C",
    hl.dsp.exec_cmd(editor)
)


-- ============================================================
-- HYPRLAUNCHER
-- Alt + R
-- ============================================================

hl.bind(
    mainMod .. " + I",
    hl.dsp.exec_cmd(menu)
)


-- ============================================================
-- FLOATING WINDOW
-- Alt + V
-- ============================================================

hl.bind(
    mainMod .. " + V",
    hl.dsp.window.float({
        action = "toggle"
    })
)


-- ============================================================
-- PSEUDO
-- Alt + P
-- ============================================================

hl.bind(
    mainMod .. " + P",
    hl.dsp.window.pseudo()
)


-- ============================================================
-- TOGGLE SPLIT
-- Alt + J
-- ============================================================

hl.bind(
    mainMod .. " + J",
    hl.dsp.layout("togglesplit")
)


-- ============================================================
-- ALT + TAB
-- ============================================================

hl.bind(
    "ALT + TAB",
    hl.dsp.window.cycle_next()
)

hl.bind(
    "ALT + SHIFT + TAB",
    hl.dsp.window.cycle_next({
        next = false
    })
)


-- ============================================================
-- MOVE FOCUS
-- Alt + Arrow Keys
-- ============================================================

hl.bind(
    mainMod .. " + left",
    hl.dsp.focus({
        direction = "left"
    })
)

hl.bind(
    mainMod .. " + right",
    hl.dsp.focus({
        direction = "right"
    })
)

hl.bind(
    mainMod .. " + up",
    hl.dsp.focus({
        direction = "up"
    })
)

hl.bind(
    mainMod .. " + down",
    hl.dsp.focus({
        direction = "down"
    })
)


-- ============================================================
-- WORKSPACES
-- Alt + 1-0
-- ============================================================

for i = 1, 10 do

    local key = i % 10

    hl.bind(
        mainMod .. " + " .. key,
        hl.dsp.focus({
            workspace = i
        })
    )

    hl.bind(
        mainMod .. " + SHIFT + " .. key,
        hl.dsp.window.move({
            workspace = i
        })
    )

end


-- ============================================================
-- SPECIAL WORKSPACE
-- Alt + S
-- ============================================================

hl.bind(
    mainMod .. " + S",
    hl.dsp.workspace.toggle_special("magic")
)

hl.bind(
    mainMod .. " + SHIFT + S",
    hl.dsp.window.move({
        workspace = "special:magic"
    })
)


-- ============================================================
-- SCROLL WORKSPACES
-- ============================================================

hl.bind(
    mainMod .. " + mouse_down",
    hl.dsp.focus({
        workspace = "e+1"
    })
)

hl.bind(
    mainMod .. " + mouse_up",
    hl.dsp.focus({
        workspace = "e-1"
    })
)


-- ============================================================
-- MOVE WINDOW WITH MOUSE
-- ============================================================

hl.bind(
    mainMod .. " + mouse:272",
    hl.dsp.window.drag(),
    {
        mouse = true
    }
)


-- ============================================================
-- RESIZE WINDOW WITH MOUSE
-- ============================================================

hl.bind(
    mainMod .. " + mouse:273",
    hl.dsp.window.resize(),
    {
        mouse = true
    }
)


-- ============================================================
-- DROPDOWN TERMINAL
-- Alt + T
-- ============================================================

hl.bind(
    mainMod .. " + G",
    hl.dsp.workspace.toggle_special("dropdown")
)


-- ============================================================
-- VOLUME UP
-- Alt + Shift + =
-- ============================================================

hl.bind(
    mainMod .. " + SHIFT + equal",
    hl.dsp.exec_cmd(
        "wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 5%+"
    )
)


-- ============================================================
-- VOLUME DOWN
-- Alt + Shift + -
-- ============================================================

hl.bind(
    mainMod .. " + SHIFT + minus",
    hl.dsp.exec_cmd(
        "wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-"
    )
)


-- ============================================================
-- MUTE
-- Alt + M
-- ============================================================

hl.bind(
    mainMod .. " + M",
    hl.dsp.exec_cmd(
        "wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle"
    )
)


-- ============================================================
-- BRIGHTNESS DOWN
-- Alt + F5
-- ============================================================

hl.bind(
    mainMod .. " + F5",
    hl.dsp.exec_cmd(
        "brightnessctl -e4 -n2 set 5%-"
    )
)


-- ============================================================
-- BRIGHTNESS UP
-- Alt + F6
-- ============================================================

hl.bind(
    mainMod .. " + F6",
    hl.dsp.exec_cmd(
        "brightnessctl -e4 -n2 set 5%+"
    )
)


-- ============================================================
-- SCREENSHOT
-- Alt + Print
-- ============================================================

hl.bind(
    mainMod .. " + PRINT",
    hl.dsp.exec_cmd(
        "mkdir -p ~/Pictures && grim ~/Pictures/screenshot-$(date +%Y-%m-%d_%H-%M-%S).png"
    )
)


-- ============================================================
-- SCREENSHOT AREA
-- Alt + Shift + Print
-- ============================================================

hl.bind(
    mainMod .. " + SHIFT + PRINT",
    hl.dsp.exec_cmd(
        "mkdir -p ~/Pictures && grim -g \"$(slurp)\" ~/Pictures/screenshot-$(date +%Y-%m-%d_%H-%M-%S).png"
    )
)


-- ============================================================
-- LOCK SCREEN
-- Alt + L
-- ============================================================

hl.bind(
    mainMod .. " + L",
    hl.dsp.exec_cmd("hyprlock")
)


-- ============================================================
-- SHUTDOWN
-- Alt + Shift + L
-- ============================================================

hl.bind(
    mainMod .. " + SHIFT + L",
    hl.dsp.exec_cmd("systemctl poweroff")
)

-- ============================================================
-- TELEGRAM
-- Alt + G
-- ============================================================

hl.bind(
    mainMod .. " + T",
    hl.dsp.exec_cmd("Telegram")
)
-- ============================================================
-- MEDIA CONTROLS
-- ============================================================

hl.bind(
    "XF86AudioNext",
    hl.dsp.exec_cmd("playerctl next"),
    {
        locked = true
    }
)

hl.bind(
    "XF86AudioPrev",
    hl.dsp.exec_cmd("playerctl previous"),
    {
        locked = true
    }
)

hl.bind(
    "XF86AudioPlay",
    hl.dsp.exec_cmd("playerctl play-pause"),
    {
        locked = true
    }
)

hl.bind(
    "XF86AudioPause",
    hl.dsp.exec_cmd("playerctl play-pause"),
    {
        locked = true
    }
)


-------------------------------
---- WINDOWS AND WORKSPACES ---
-------------------------------


-- ============================================================
-- SUPPRESS MAXIMIZE
-- ============================================================

hl.window_rule({
    name = "suppress-maximize-events",

    match = {
        class = ".*"
    },

    suppress_event = "maximize",
})


-- ============================================================
-- XWAYLAND DRAG FIX
-- ============================================================

hl.window_rule({
    name = "fix-xwayland-drags",

    match = {
        class      = "^$",
        title      = "^$",
        xwayland   = true,
        float      = true,
        fullscreen = false,
        pin        = false,
    },

    no_focus = true,
})


-- ============================================================
-- DROPDOWN TERMINAL
-- ============================================================

hl.window_rule({
    name = "dropdown-terminal",

    match = {
        class = "^dropdown-terminal$"
    },

    float = true,

    move = "0 0",

    size = "90% 45%",

    rounding = 10,
})


-- ============================================================
-- HYPRLAND RUN
-- ============================================================

hl.window_rule({
    name = "move-hyprland-run",

    match = {
        class = "hyprland-run"
    },

    move = "20 monitor_h-120",

    float = true,
})


-- ============================================================
-- FIREFOX
-- Alt + W
-- ============================================================

hl.bind(
    mainMod .. " + W",
    hl.dsp.exec_cmd("firefox")
)
hl.window_rule({
    name = "vscode-transparent",

    match = {
        class = "^code$",
    },

    opacity = "0.83 override 0.995 override",
})


-- HyprMod managed settings
require("hyprland-gui")
