// Area mutex
#ifndef Area_Mutex_h
#define Area_Mutex_h
 typedef struct{
    bool ocupado;
    int turno;
    bool flag[3];  //se usan flag[1] y flag[2]
} AreaMutex;
#endif