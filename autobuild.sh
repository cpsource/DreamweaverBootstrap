#!/bin/bash

gif [ ! $# -eq 1 ]; then
    echo "Error: missing module name as argument"
    exit 0;
fi

if [ ! -f /mnt/hgfs/buildshare/Documents/$1.md ]; then
    echo "Error: file /mnt/hgfs/buildshare/$1.md missing"
    exit 0
fi

# fetch the .md file from Windoz
cp /mnt/hgfs/buildshare/Documents/$1.md /sdb1/one-click-hugo-cms/site/content/post/.

# generate the html file
pushd /sdb1/one-click-hugo-cms/site
../bin/hugo.linux
if [ $? -eq 0 ]; then
    echo Site Builds - OK
else
    echo Site Failed, exiting - FAIL
    exit 0
fi
popd

# edit html
./sdb1/DreamweaverBootstrap/autoedit $1

# copy /tmp/case-studies.html
if [ -f /tmp/case-studies.html ]; then
    cp -f /tmp/case-studies.html /sdb1/DreamweaverBootstrap/casestudies/.
else
    echo "can't find /tmp/case-studies.html"
    exit 0
fi

# release DreamweaverBootstrap site
pushd /sdb1/DreamweaverBootstrap
./package-and-send.sh
popd
