#!/bin/sh
groups $FT_USER | sed -r 's/ /,/g' | head -c-1
