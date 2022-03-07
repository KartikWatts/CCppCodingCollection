#!/bin/sh

clear
diff -bB __Build_Config_VS/output.txt __Build_Config_VS/solution.txt > __Build_Config_VS/difference.txt
clear

# echo Building... > output.txt && g++ -g ${relativeFile} -o output.out && clear && timeout 10 /usr/bin/time -v --output sys.txt ./output.out < input.txt > output.txt && clear && rm *out