#!/bin/sh

# dependency yad

config_file="$HOME/.local/src/dwm/config.def.h"

sed -n '/START_KEYS/,/END_KEYS/p' "$config_file" | `# get all lines between START_KEYS and END_KEYS` \
	sed 's/^\s//' | `# delete empty spaces at the beginning` \
	grep -e "^{" -e "GROUP \S" | \
	yad --text-info \
	--back=#282c34 \
	--fore=#46d9ff \
	--no-buttons \
	--fullscreen
