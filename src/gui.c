
typedef struct Sector {
    int id;
    int isVisible;
    float *size;
    float *position;
    Sector *parent;
    Sector **children;
    int childCount;
    int childCapacity;
    void *data; // Pointer to any data associated with the sector
} Sector;


typedef struct Panel {
    unsigned int VAO;
    float *position;
    float *size;
    float *color;

    
    
} Panel;

typedef struct GUI{
    Panel *panels;
    int panelCount;
} GUI;



