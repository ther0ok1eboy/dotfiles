---
layout: post
title: Give your github a personal domain
date:  2020-02-17
tags: Github
---

### Introduction    

If you put your personal website into github page, you may suffer some problems. Such as the speeds of accessing website, modify difficulty and the original github domain is so long. I think make you most painful is the access speeds(Due to the github servers are setted in abroad, the speeds have been limited). OK, let's increase its speeds together.

### Prerequisite

- This tutorial is base on you have got a github website like that [http://jasonsorria.github.io](http://blog.coolshark.xyz/) and a international domain.
- In this test, i will use my github website to teach you how to add a new domain.    

### Quick start

- Clone your repositories to local: `git clone https://github.com/JasonSorria/JasonSorria.github.io && cd JasonSorria.github.io/`  

- Add a `CNAME` file and input your domain in it:`echo "blog.coolshark.xyz" >> CNAME`. Warning: not add `www` or `http`.

- Update your repositories:`git add CNAME && git commit -a "cname" && git push`  

- Add record for your domain like that:(I recommend [cloudflare](https://dash.cloudflare.com/) because it offers CDN and DNSSEC service)

    ![](../problem_logs/GCP+V2ray+WebSocks+tls-to-surfing/2.png)

- Why your github website will access faster and more beautiful? Because the github servers are setted in abroad, the CDN will get more effect than use the way of forwarding access your website from domestic. If you do not know how to obtain CDN for your domain, you can see [this article](http://blog.coolshark.xyz/2019/12/scure-surfing/).


