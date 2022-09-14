#!/usr/bin/env bash

MANPATH=$(manpath)

extract_header() {
  # Args:
  #   $1 -- content of man entry

  echo $1 | grep -m 1 -Eo '<[a-zA-Z\./]+>' | grep -Eo '[a-zA-Z\./]+'
}

find_include() {
  # Args:
  #   $1 -- name of function
  IFS=':'
  for dir in $MANPATH
  do
    compressed_page="$dir/man3/$1.3.gz"
    uncompressed_page="$dir/man3/$1.3"

    if [ -f "$uncompressed_page" ]
    then
      extract_header "$(cat $uncompressed_page)" && return 0
    elif [ -f "$compressed_page" ]
    then
     extract_header "$(gunzip -c $compressed_page)" && return 0
    fi
  done

  return 1
}

find_include $1 || echo '---'
