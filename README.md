# 🏠 dotfiles

[🇨🇳 中文](README.zh-CN.md) · [🇬🇧 English](README.md)

My Arch Linux Wayland desktop configuration, built around **Hyprland** with a Catppuccin Mocha theme, Waybar, Fish, Kitty, Neovim, and Yazi. ✨

> ⚠️ This is a personal configuration collection and is not guaranteed to work out of the box. Adjust the hardware, monitor, and path-specific settings before using it.

## 🖼️ Preview

<p align="center">
  <img src="./output.gif" alt="Pacman animation" />
</p>

<table>
  <tr>
    <td><img src="./20250220_17h00m00s_grim.png" alt="Desktop preview 1" /></td>
    <td><img src="./20250220_17h01m54s_grim.png" alt="Desktop preview 2" /></td>
  </tr>
  <tr>
    <td><img src="./20250220_17h09m10s_grim.png" alt="Desktop preview 3" /></td>
    <td><img src="./20241122_21h59m50s_grim.png" alt="Desktop preview 4" /></td>
  </tr>
  <tr>
    <td colspan="2"><img src="./20250220_15h21m29s_grim.png" alt="Desktop preview 5" /></td>
  </tr>
</table>

## 🍬 Waybar Pac-Man Animation

The `output.gif` shown above demonstrates a custom Waybar animation 🎞️. The related script and font resources are available in [`waybar/scripts/pacman.sh-resource`](https://github.com/ther0ok1eboy/dotfiles/tree/master/waybar/scripts/pacman.sh-resource).

## 🧩 Components

| Component | Directory | Description |
| --- | --- | --- |
| [Hyprland](https://hypr.land/) | `hypr/` | Window manager, window rules, input, keybindings, and startup tasks |
| [Waybar](https://github.com/Alexays/Waybar) | `waybar/` | Status bar, weather, media controls, Cava, and Pac-Man animation |
| [Fish](https://fishshell.com/) | `fish/` | Shell configuration, functions, completions, and plugins |
| [Kitty](https://sw.kovidgoyal.net/kitty/) | `kitty/` | Terminal configuration |
| [Neovim](https://neovim.io/) / [LazyVim](https://www.lazyvim.org/) | `nvim/` | Editor configuration and plugin lockfile |
| [Yazi](https://yazi-rs.github.io/) | `yazi/` | File manager, themes, and preview scripts |
| [Fuzzel](https://codeberg.org/dnkl/fuzzel) | `fuzzel/` | Wayland launcher and clipboard menu |
| [Rofi](https://github.com/davatorium/rofi) | `rofi/` | Application launcher |
| [Mako](https://github.com/emersion/mako) | `mako/` | Wayland notification daemon |
| [CopyQ](https://hluk.github.io/CopyQ/) / `cliphist` | `copyq/` | Clipboard management |

## 📁 Repository Layout

```text
.
├── copyq/       # CopyQ configuration and data
├── fish/        # Fish shell configuration, functions, themes, and plugins
├── fuzzel/      # Fuzzel configuration and Catppuccin theme
├── hypr/        # Hyprland configuration, wallpapers, and startup scripts
├── kitty/       # Kitty configuration
├── mako/        # Mako notification configuration
├── nvim/        # Neovim / LazyVim configuration
├── rofi/        # Rofi configuration and theme
├── waybar/      # Waybar configuration, styles, scripts, and animation font resources
└── yazi/        # Yazi configuration, themes, and file preview scripts
```

## 🚀 Installation

### 1. 📥 Clone

```bash
git clone https://github.com/ther0ok1eboy/dotfiles.git ~/dotfiles
cd ~/dotfiles
```

### 2. 📦 Install Dependencies

Install the corresponding packages for your distribution. Common dependencies include:

```text
hyprland waybar fish kitty neovim yazi rofi fuzzel mako
wl-clipboard cliphist grim slurp swappy
fcitx5 starship cava playerctl jq curl
```

Some scripts also use `awww`, `mpvpaper`, `tesseract`, `bluetoothctl`, `pavucontrol`, and `nm-applet`. Install them as needed.

## ⚠️ Important Local Settings

Check the following hardware- and machine-specific settings after installation 🛠️:

- `hypr/awesomeconf/monitor.lua`: monitor names, resolutions, refresh rates, and layout.
- `hypr/awesomeconf/autostart.lua`: applications started when the session begins.
- `waybar/scripts/wallpaper*.sh`: local wallpaper paths that need to be changed.
- `waybar/scripts/live-wallpaper-engine.sh`: local dynamic wallpaper directory.
- `waybar/scripts/todo-list.sh`: reads `~/Documents/future-plans.md` by default.
- `waybar/scripts/weather.sh`: weather location and API configuration.
- `fish/config.fish`: proxy, input method, and environment variable settings.

Do not copy personal paths, proxy addresses, or API keys directly to another machine. 🔒

## ⌨️ Keybindings

The default main modifier is `Super`:

| Shortcut | Action |
| --- | --- |
| `Super + Enter` | Open Kitty |
| `Super + Space` | Open the Rofi application launcher |
| `Super + C` | Open clipboard history |
| `Super + S` | Take a screenshot and open Swappy |
| `Super + F` | Toggle fullscreen |
| `Super + O` | Screenshot OCR |
| `Super + L` | Open the power menu |
| `Super + N` | Open Nemo |
| `Super + P` | Close the current window |
| `Super + 1..0` | Switch workspace |
| `Super + Shift + 1..0` | Move the current window to a workspace |
| `Super + Left mouse button` | Move a window |
| `Super + Right mouse button` | Resize a window |

Keybindings are defined in `hypr/awesomeconf/binds.lua` and can be customized.

## 📝 Notes

- This configuration is primarily intended for Linux + Wayland + Hyprland.
- Neovim uses LazyVim; plugin versions are recorded in `nvim/lazy-lock.json`.
- Third-party themes in this repository retain their respective upstream license files.
- Applications usually need to be restarted after configuration changes. Restart the Hyprland session after changing startup tasks or environment variables.

## 📜 License

This repository is mainly intended as a personal configuration backup. Third-party themes, plugins, and resources retain the licenses provided in their respective directories.
