# THIS MarkDown script describe the usage of "cut"
## "cut" is used to get the wanted columu of file

> cut -d " " -f 1,3 test.txt
ID 
1 
2 
3 
4

> df -h | cut -f 5
Filesystem      Size  Used Avail Use% Mounted on
udev            3.9G     0  3.9G   0% /dev
tmpfs           794M  2.1M  792M   1% /run
/dev/sda1        98G   92G  975M  99% /
tmpfs           3.9G   76M  3.9G   2% /dev/shm
tmpfs           5.0M  4.0K  5.0M   1% /run/lock
tmpfs           3.9G     0  3.9G   0% /sys/fs/cgroup
/dev/loop0       56M   56M     0 100% /snap/core18/2074
/dev/loop1      165M  165M     0 100% /snap/gnome-3-28-1804/161
/dev/loop2      100M  100M     0 100% /snap/core/11420
/dev/loop4      163M  163M     0 100% /snap/gnome-3-28-1804/145
/dev/loop5      640K  640K     0 100% /snap/gnome-logs/103
/dev/loop6       65M   65M     0 100% /snap/gtk-common-themes/1514
/dev/loop3      2.5M  2.5M     0 100% /snap/gnome-system-monitor/163
/dev/loop7       62M   62M     0 100% /snap/core20/1081
/dev/loop8       66M   66M     0 100% /snap/gtk-common-themes/1515
/dev/loop9      640K  640K     0 100% /snap/gnome-logs/106
/dev/loop10      56M   56M     0 100% /snap/core18/2128
/dev/loop11     2.5M  2.5M     0 100% /snap/gnome-calculator/826
/dev/loop12     2.3M  2.3M     0 100% /snap/gnome-system-monitor/157
/dev/loop13     768K  768K     0 100% /snap/gnome-characters/726
/dev/loop14      62M   62M     0 100% /snap/core20/1026
/dev/loop15     244M  244M     0 100% /snap/gnome-3-38-2004/39
/dev/loop16     219M  219M     0 100% /snap/gnome-3-34-1804/72
/dev/loop17     384K  384K     0 100% /snap/gnome-characters/708
/dev/loop18     100M  100M     0 100% /snap/core/11606
tmpfs           794M   16K  794M   1% /run/user/121
/dev/loop19     2.5M  2.5M     0 100% /snap/gnome-calculator/884
/dev/loop20     219M  219M     0 100% /snap/gnome-3-34-1804/66
/dev/loop21     242M  242M     0 100% /snap/gnome-3-38-2004/70
vmhgfs-fuse      81G   80G  554M 100% /mnt/hgfs
tmpfs           794M   24K  794M   1% /run/user/1000
/dev/sr0        2.0G  2.0G     0 100% /media/wh/Ubuntu 18.04.4 LTS amd64

## well, absolutely this fails to get the 5th column, can be solved by awk