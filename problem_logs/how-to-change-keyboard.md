---
layout: post
title: How to change keyboard binding
date: 2019-12-28
tags: linux   
---

### Introduction

I guest that you may get bored with your traditional keyboard binding and many usually key are not at these positions in which you can convenient to touch. Today i will share a powerful and easy-to-use application named xmodmap who is a part of family of Xorg and supports permanent modify your traditional keyboard binding, so you should install some dependence of Xorg. 

### Install

**download:**

`$ sudo pacman -S xorg`

**2 show your recent keybord layouts:**

`$ xmodmap`

**3 show id of your of all keybord layouts:**

`$ xev` when you press any keyboard you can see its id

**4 input your layouts into .xmodmap:**

`$ xmodmap -pke > ~/.xmodmap && vim .xmodmap`

**5 change key you want**

I recommend to change the Esc and CapLock because you will usually use key Esc when you edit your articles but the headache is the key Esc is far from your finger, which make you uncomfortable touch it.

Change their contents behind the id and input 'clear lock' into header of file and 'add lock = Cap_Lock'

**6 save config:**

`$ xmodmap ~/.xmodmap`
