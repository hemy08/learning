/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/3.
 */

#ifndef ____HEMY_CODE_REPO__SRC__PUBLIC__STUB__H____
#define ____HEMY_CODE_REPO__SRC__PUBLIC__STUB__H____

typedef struct MOUNTAIN_ARRAY {
    char* name;
}MountainArray;

typedef struct  MASTER {
    char *name;
}Master;


extern int guess(Master *a, char *word);
extern bool isBadVersion(int version);
extern int get(MountainArray *m, int index);
extern int length(MountainArray *m);

#endif //____HEMY_CODE_REPO__SRC__PUBLIC__STUB__H____
