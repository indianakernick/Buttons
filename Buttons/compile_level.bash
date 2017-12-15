#!/bin/bash

if [ -z "$1" ] ; then
  echo "Compiling all levels..."
  LEVEL="*"
else
  echo "Compiling level $1"
  LEVEL="$1"
fi

PROJECT_RES="/Users/indikernick/Dev/Projects/C++/Games/Buttons/Buttons/Resources"
PRODUCT_RES="/Users/indikernick/Library/Developer/Xcode/DerivedData/Buttons-etwygbpumdfbpjfbjwtjfrrpwvxk/Build/Products/Release/Buttons.app/Contents/Resources"

find $PROJECT_RES -name "level $LEVEL.jsonnet" |
egrep --only-matching "level (\d+|final)" |
xargs -I {} jsonnet --output-file "$PRODUCT_RES/{}.json" "$PROJECT_RES/{}.jsonnet"
