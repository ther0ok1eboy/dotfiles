function rm --wraps=echo\ \'aaa\' --wraps=echo\ \'rm\ is\ unsafe,\ use\ rip\ plz\' --description alias\ rm\ echo\ \'rm\ is\ unsafe,\ use\ rip\ plz\'
  echo 'rm is unsafe, use rip plz' $argv
        
end
