#!/bin/bash

gif [ ! $# -eq 1 ]; then
    echo "Error: missing module name as argument"
    exit 0;
fi

if [ ! -f /mnt/hgfs/buildshare/$1.md ]; then
    echo "Error: file /mnt/hgfs/buildshare/$1.md missing"
    exit 0
fi

cp /mnt/hgfs/buildshare/$1.md /sdb1/one-click-hugo-cms/site/content/post/.
pushd /sdb1/one-click-hugo-cms/site
../bin/hugo.linux
if [ $? -eq 0 ]; then
    echo Site Builds - OK
else
    echo Site Failed, exiting - FAIL
    exit 0
fi
popd

# build html
./sdb1/DreamweaverBootstrap/autoedit $1

# copy html to our DreamweaverBootstrap site
cp /sdb1/one-click-hugo-cms/site/public/post/$1/index.html /sdb1/DreamweaverBootstrap/casestudies/$1.html

# edit case-studies.html
# TBD

# release DreamweaverBootstrap site
pushd /sdb1/DreamweaverBootstrap
./package-and-send.sh
popd
