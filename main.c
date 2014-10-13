#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>




int main()
{
	char dir_to[64]; //путь к директории
        char dir_min[32]; 
	struct dirent *dir_entry; // структура директории

  //выглядит следующим образом

	//struct dirent {
  //ino_t          d_ino;       /* inode number */
  //off_t          d_off;       /* offset to the next dirent */
  //unsigned short d_reclen;    /* length of this record */
  //unsigned char  d_type;      /* type of file; not supported
  //                               by all file system types */
  //char           d_name[256]; /* filename */
  //};  
	struct stat stat_b; //структура информации о каталоге

  //выглядит следующим образом

  //	 struct stat {
  //             dev_t     st_dev;         /* ID of device containing file */
  //             ino_t     st_ino;         /* inode number */
  //             mode_t    st_mode;        /* protection */
  //             nlink_t   st_nlink;       /* number of hard links */
  //             uid_t     st_uid;         /* user ID of owner */
  //             gid_t     st_gid;         /* group ID of owner */
  //             dev_t     st_rdev;        /* device ID (if special file) */
  //             off_t     st_size;        /* total size, in bytes */
  //             blksize_t st_blksize;     /* blocksize for filesystem I/O */
  //             blkcnt_t  st_blocks;      /* number of 512B blocks allocated */
  //
  //             /* Since Linux 2.6, the kernel supports nanosecond
  //                precision for the following timestamp fields.
  //                For the details before Linux 2.6, see NOTES. */
  //
  //             struct timespec st_atim;  /* time of last access */
  //             struct timespec st_mtim;  /* time of last modification */
  //             struct timespec st_ctim;  /* time of last status change */
  //
  //         #define st_atime st_atim.tv_sec      /* Backward compatibility */
  //         #define st_mtime st_mtim.tv_sec
  //         #define st_ctime st_ctim.tv_sec
  //         };
	DIR *directory; //работа с директорией (для открытия и закрытия)

    printf("\n Input you directory \n");
    scanf("%s",dir_min);
    strcpy(dir_to,dir_min);
    if ( (directory = opendir(dir_min) ) != NULL )
    {
    	while( (dir_entry = readdir(directory)) != NULL )
    	{
    	    strcat(dir_to,dir_entry->d_name);
            if ( stat(dir_to->d_name, &stat_b) != (-1) )
            {
            	
            	printf("File name: %s\n",dir_entry->d_name);
            	if (dir_entry->d_type == DT_UNKNOWN){ printf("File type : UNKNOWN \n");}
            	if (dir_entry->d_type == DT_REG){ printf("File type : REGULAR \n");}
            	if (dir_entry->d_type == DT_DIR){ printf("File type : DIRECTORY \n");}
            	if (dir_entry->d_type == DT_SOCK){ printf("File type : LOCAL DOMAIN SOCKET \n");}
            	if (dir_entry->d_type == DT_CHR){ printf("File type : CHARACTER DEVICE \n");}
            	if (dir_entry->d_type == DT_BLK){ printf("File type : BLOCK DEVICE \n");}
            	if (dir_entry->d_type == DT_LNK){ printf("File type : SYMBOLIC DEVICE \n");}
                printf("Inode number: %ld\n", (long) stat_b.st_ino);
                printf("Protection: %lo (octal)\n", (unsigned long) stat_b.st_mode);
                printf("Number of hard links: %ld\n", (long) stat_b.st_nlink);
                printf("User/group ID of owner: UID=%ld GID=%ld\n", (long)stat_b.st_uid, (long)stat_b.st_gid);
                printf("Blocksize for filesystem I/O: %ld bytes\n", (long) stat_b.st_blksize);
                printf("File size: %lld bytes\n",(long long) stat_b.st_size);
                printf("Blocks allocated: %lld\n",(long long) stat_b.st_blocks);
                printf("Last status change: %s", ctime(&stat_b.st_ctime));
                printf("Last file access: %s", ctime(&stat_b.st_atime));
                printf("Last file modification: %s\n", ctime(&stat_b.st_mtime));
                strcpy(dir_to,dir_min);
            } else 
            continue;

    	}


    } else
    {
       printf("Cannot open your directory");	
    }
    closedir(directory);
   
    return 0;
}
