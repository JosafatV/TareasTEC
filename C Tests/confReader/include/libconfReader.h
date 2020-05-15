#ifndef CONFREADER
#define CONFREADER

typedef struct {
    int ID;
    int val;
    int t;
} config_t;

get_config(const char* conf_path);

print_config(config_t *conf);

#endif
