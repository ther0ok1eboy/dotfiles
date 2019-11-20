- **1 create a fonts directory:**

    `$ cd /usr/share/fonts && mkdir new-fonts && cd new-fonts`

- **2 download fonts style on baidu or google(nerd fonts: https://www.nerdfonts.com/) and unzip it**

- **3 add your ttf file into this new-fonts directory**
    
    `$ mv xxx*.ttf .`

- **4 load the fonts:**

    `$ fc-cache -fv (yum install fontconfig)`

- **5 list all fonts on linux:**
    
    `$ fc-list`
