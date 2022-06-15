int compMaxspeed_ao(const void* car1p, const void* car2p);
int compMaxspeed_do(const void* car1p, const void* car2p);
int compModel_ao(const void* car1p, const void* car2p);
int compModel_do(const void* car1p, const void* car2p);
int compPrice_ao(const void* car1p, const void* car2p);
int compPrice_do(const void* car1p, const void* car2p);

int (*getComparator(int n))(const void*, const void*);

int randint(int min, int max);
double randReal(double min, double max);
char* randomName(char* name);