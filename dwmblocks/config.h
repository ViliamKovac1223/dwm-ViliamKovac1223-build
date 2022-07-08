//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                          /*Update Interval*/	/*Update Signal*/
	// {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

	// {" ", "$HOME/.local/src/dwm/dwmblocks/scripts/kernel-status.sh",      0,		14},
	{" ", "$HOME/.local/src/dwm/scripts/kernel-status.sh",					0,			0},
	{" ", "$HOME/.local/src/dwm/scripts/keyboard.sh",						0,			10},
	{" ", "$HOME/.local/src/dwm/scripts/volume.sh",							30,			11},
	{" ", "$HOME/.local/src/dwm/scripts/brightness.sh",						360,		12},
	// {" ", "$HOME/.local/src/dwm/scripts/battery.sh",						30,			0},
	{" ", "$HOME/.local/src/dwm/scripts/temp.sh",							30,			0},
	{" ", "$HOME/.local/src/dwm/scripts/mic.sh",							45,			13},
	{" ", "$HOME/.local/src/dwm/scripts/date.sh",							45,			0},

	// {"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
  // battery.sh  brightness.sh  date.sh  kernel-status.sh  keyboard.sh  mic.sh  temp.sh  volume.sh
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " |";
static unsigned int delimLen = 2;
