function openvpn_listentide --wraps='sudo openvpn ~/Downloads/HackTheBox/ListenTide.vpn' --wraps='sudo openvpn ~/Downloads/HackTheBox/ListenTide.vpn &' --description 'alias openvpn_listentide sudo openvpn ~/Downloads/HackTheBox/ListenTide.vpn'
  sudo openvpn ~/Downloads/HackTheBox/ListenTide.vpn $argv
        
end
