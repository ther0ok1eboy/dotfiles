# 终端吃豆人图标字体

字体名称：`ComicShannsMono Nerd Font Reverse V14`

## 字符

| 用途 | 字符 | 说明 |
|---|---|---|
| 吃豆人原始图标 | 󰮯 | 1 个字符 |
| 吃豆人反方向图标 | 󱫱 | 1 个字符 |
| 自定义圆角正方形 | 󱫴󱫵 | 两个全新私用区字符拼接，占 2 格 |

使用：

```text
󱫴󱫵
```

## Linux 安装

```bash
mkdir -p ~/.local/share/fonts
cp ComicShannsMonoNerdFont-Reverse-v14.otf ~/.local/share/fonts/
fc-cache -f
```

## macOS 安装

双击 `.otf` 文件，然后点击“安装字体”。

## Windows 安装

右键 `.otf` 文件，选择“为所有用户安装”。

## Kitty 配置

```conf
font_family ComicShannsMono Nerd Font Reverse V14
```

## 使用

```bash
printf '%s\n' '󰮯󱫴󱫵󱫱'
```
