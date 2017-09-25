//
//  turnon_ntfs.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/3.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
diskutil list
sudo nano /etc/fstab
LABEL=C none ntfs rw,auto,nobrowse
sudo ln -s /Volumes ~/Desktop/Volumes
