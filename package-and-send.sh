#!/bin/bash
tar -cvf /tmp/dw.tar --exclude=.git *
scp /tmp/dw.tar ubuntu@calpage.sytes.net:~/.

