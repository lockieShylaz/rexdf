#include <unistd.h>
#include <stdio.h>
#include <vfs/fs.h>
#include <stdlib.h>
#include <kstring.h>

int main(int argc, char* argv[]) {
	char name[FULL_NAME_MAX];
	if(argc < 2) {
		fs_full_name("", name, FULL_NAME_MAX);
	}
	else {
		fs_full_name(argv[1], name, FULL_NAME_MAX);
	}

	int fd = open(name, O_RDONLY);
	if(fd >= 0) {
		fs_info_t dir_info;
		if(fs_info(fd, &dir_info) != 0 || dir_info.type != FS_TYPE_DIR) {
			close(fd);
			return -1;
		}
		printf(" total: %d\n", dir_info.size);

		uint32_t i = 0;
		while(i < dir_info.size) {
			fs_info_t info;
			if(fs_kid(fd, i, &info) != 0)
				break;
			if(info.type == FS_TYPE_FILE)
				printf("  %16s -f-  %4d  %d\n", info.name, info.owner, info.size);
			else if(info.type == FS_TYPE_DIR)
				printf(" +%16s -d-  %4d  %d\n", info.name, info.owner, info.size);
			i++;
		}
		close(fd);
	}

	return 0;
}
