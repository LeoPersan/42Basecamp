#!/bin/sh
cat /etc/passwd | sed 's/:$//' | sed -n 2~2p | rev | sort -r | head -n$FT_LINE2 | tail -n+$FT_LINE1 | tr '\n' ',' | sed 's/,$/./'