#!/bin/bash

#cd /rubbish
mkdir rubbish
mv /rubbish/* rubbish/
ls -lhR >> rubbish/rubbish-log
cd rubbish
date >> rubbish-blog
cd ..
mv rubbish/ /tmp

