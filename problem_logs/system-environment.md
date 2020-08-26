### If you are bash user, you may know how to add and change system environment.

**Modify current terminal system environment(it is contemporary)**

Run `$ export PATH="/usr/bin:$PATH"` but when you startup a new terminal it is will invalid.

**Edit `~/.profile` and `~/.bashrc` it impacts current user**

Add `$ export PATH="/usr/bin:$PATH"` into `~/.profile` and `~/.bashrc` but when other user open a new terminal it is not effected. 

**Add into `/root/.profile` it is effected for all users** 

Add `$ export PATH="/usr/bin:$PATH"` into `/root/.profile`.

### But if you are a fish shell user like me, something dislike above.

Add `set --export PATH /usr/bin` into `~/.config/fish/config.fish`(if you do not have this file `touch` it).

Run `$ help set` to browse its official documents to get more information about `set`. 
