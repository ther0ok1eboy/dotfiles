# 反向糖豆人字体图标

这个字体包含两个终端字符：

| 用途 | 字符 | Unicode |
|---|---|---|
| 原始图标 | 󰮯 | U+F0BAF |
| 水平镜像图标 | 󱫱 | U+F1AF1 |

## 安装

### Linux

将 `ComicShannsMonoNerdFont-Reverse-v2.otf` 复制到：

```bash
mkdir -p ~/.local/share/fonts
cp ComicShannsMonoNerdFont-Reverse-v2.otf ~/.local/share/fonts/
fc-cache -f
```

### macOS

双击字体文件，点击“安装字体”。

### Windows

右键字体文件，选择“为所有用户安装”。

## Kitty

在 `kitty.conf` 中设置：

```conf
font_family ComicShannsMono Nerd Font Reverse V2
```

然后重启 Kitty，或使用 Kitty 的配置重载功能。

## 使用

```bash
printf '%s\n' '󰮯 󱫱'
```

也可以直接复制字符：

```text
󰮯 󱫱
```

注意：这两个字符位于 Unicode 私用区，不同字体或应用程序可能无法显示。使用者必须安装本字体，并让终端或应用实际使用它。
