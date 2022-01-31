#!/bin/bash
#find . -name \*~ -exec rm -f {} \;

#tar -cvf /tmp/dw.tar --exclude=.git *
#pushd /mnt/hgfs/buildshare/DreamweaverBootstrap
tar -cvf /tmp/dw.tar --exclude=.git --exclude=autoedit\* --exclude=\*~ *
#popd

scp /tmp/dw.tar ubuntu@calpage.sytes.net:~/.
ssh ubuntu@calpage.sytes.net install.sh

