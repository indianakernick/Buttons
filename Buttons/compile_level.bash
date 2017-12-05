#!/bin/bash

if [ -z "$1" ] ; then
  echo "Compiling all levels..."
  LEVEL="*"
else
  echo "Compiling level $1"
  LEVEL="$1"
fi

find /Users/indikernick/Dev/Projects/C++/Games/Buttons/Buttons/Resources/ -name "level $LEVEL.jsonnet" | egrep --only-matching "level \d+" | xargs -I {} jsonnet --output-file "/Users/indikernick/Library/Developer/Xcode/DerivedData/Buttons-etwygbpumdfbpjfbjwtjfrrpwvxk/Build/Products/Debug/Buttons.app/Contents/Resources/{}.json" "/Users/indikernick/Dev/Projects/C++/Games/Buttons/Buttons/Resources/{}.jsonnet"
