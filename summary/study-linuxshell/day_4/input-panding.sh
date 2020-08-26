#!/bin/bash

read -p "press any key..." key

case $key in
    [a-z]|[A-Z])
        echo "aphib..."
        ;;
    [0-9])
        echo "number..."
        ;;
        *)
        echo "function key..."
        ;;
esac
