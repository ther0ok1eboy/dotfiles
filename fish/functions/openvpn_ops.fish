function openvpn_ops --wraps='sudo openvpn --config /etc/openvpn/client/OPS.conf >> /home/sorria/.config/openvpn/openvpn_client.log 2>&1 &' --description 'alias openvpn_ops sudo openvpn --config /etc/openvpn/client/OPS.conf >> /home/sorria/.config/openvpn/openvpn_client.log 2>&1 &'
  sudo openvpn --config /etc/openvpn/client/OPS.conf >> /home/sorria/.config/openvpn/openvpn_client.log 2>&1 &
        
end
