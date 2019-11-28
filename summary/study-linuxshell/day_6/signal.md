## Type of system signal

- **show all system signals** 

    - `$ kill -l`   

    - `$ kill [signal number] [process PID]`   

    - `$ pkill [signal number] [process number]`   

- **in common use** 
        
    - SIGHUB[1]: hang out process 

        *if you want to change some configurations such as service port but do not want to restart it to make it valid, you can `pkill -1 httpd`* 

        *but not all applications will accept this signal*  

    - SIGING[2]: break keyboard input Ctrl+c

    - SIGQUIT[3]: quit form keyboard Ctrl+\ 

    - SIGKILL[9]: unconditional termination 
     

- **trap (capture signal)** 
    - usage: 

        *`$ trap '[option]' [signal number]` //option is a executive function*  
