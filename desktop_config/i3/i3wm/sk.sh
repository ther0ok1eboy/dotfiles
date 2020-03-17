result=$(ps ax|grep -v grep|grep screenkey)
if [ "$result" == "" ]; then
  eval "screenkey --opacity 0.3"
else
  eval "killall screenkey"
fi
