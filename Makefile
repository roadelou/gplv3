################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2020-12-17
# Language: Makefile

################################### ALIASES ####################################

# Source file
src = src/main.c

# Compiled executable
out = dist/gplv3.elf

# Installed executable
exec = /usr/bin/gplv3

# Source license file
src_gplv3 = LICENSE

# Installed license directory
dir_gplv3 = /etc/roadelou_gplv3

# Installed license file
installed_gplv3 = $(dir_gplv3)/GPLv3_LICENSE

################################### SPECIAL ####################################

.PHONY: install uninstall clean

#################################### RULES #####################################

$(out): $(src)
	mkdir -p ./dist
	$(CC) $(src) -o $(out)

install: $(out)
	cp $(out) $(exec)
	mkdir -p $(dir_gplv3)
	cp $(src_gplv3) $(installed_gplv3)

uninstall:
	rm -rf $(dir_gplv3)
	rm -r $(exec)

clean:
	rm -r $(out)

##################################### EOF ######################################
