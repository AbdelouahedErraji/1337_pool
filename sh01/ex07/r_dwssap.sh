#!/bin/sh
cat /etc/passwd \
	| grep -v '^#' \
	| awk 'NR % 2 == 0' \
	| cut -d ':' -f1 \
	| rev \
	| sort -r \
	| tr '\n' ',' \
	| sed 's/,/, /g' \
	| sed 's/, $/./'
