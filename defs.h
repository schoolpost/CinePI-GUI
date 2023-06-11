typedef struct{
    uint16_t framerate;
    uint32_t frames;
}cinepi_ipc_t;

typedef struct{
    bool tc_on;
    bool doRec;
    int lvEn;
    int zoomDir;
    bool setLock;
    bool loadClips;
    int stateSet;
    int uIso;
    int uFps;
    int uWb;
    int uSh;
}cinepi_lv_t;

typedef struct{
  const int iso[13];
  const int shutter[12];
  const int wb[6];
  const float fps[17];
}controls_t;

typedef struct{
  int state;
  int lastState;
  unsigned long pressTime;
  bool down;
}button_t;

#define KEY_PRESSED 0
#define KEY_DURATION 2000

struct wiringPiNodeStruct
{
  int     pinBase ;
  int     pinMax ;

  int          fd ;	// Node specific
  unsigned int data0 ;	//  ditto
  unsigned int data1 ;	//  ditto
  unsigned int data2 ;	//  ditto
  unsigned int data3 ;	//  ditto

  void   (*pinMode)         (struct wiringPiNodeStruct *node, int pin, int mode) ;
  void   (*pullUpDnControl) (struct wiringPiNodeStruct *node, int pin, int mode) ;
  int    (*digitalRead)     (struct wiringPiNodeStruct *node, int pin) ;
  void   (*digitalWrite)    (struct wiringPiNodeStruct *node, int pin, int value) ;
  void   (*pwmWrite)        (struct wiringPiNodeStruct *node, int pin, int value) ;
  int    (*analogRead)      (struct wiringPiNodeStruct *node, int pin) ;
  void   (*analogWrite)     (struct wiringPiNodeStruct *node, int pin, int value) ;

  struct wiringPiNodeStruct *next ;
} ;