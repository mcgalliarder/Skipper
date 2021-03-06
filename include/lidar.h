#ifndef _LIDAR_H_
#define _LIDAR_H_

#define SCAN_DATA_LEN 5
#define EXPRESS_SCAN_DATA_LEN 84
#define FORCE_SCAN_DATA_LEN 5
#define GET_INFO_LEN 20
#define HEALTH_DATA_LEN 3
#define GET_SAMPLERATE_LEN 4

#define HEADER_LENGTH 7

//char SCAN_HEADER[]   = {0xA5, 0x5A, 0x05, 0x00, 0x00, 0x40, 0x81};
//char HEALTH_HEADER[] = {0xA5, 0x5A, 0x03, 0x00, 0x00, 0x00, 0x06};

void lidarStop();

void lidarReset();

int checkByteIntegrity(char b, int * i);

void lidarScan(char * r_Array, int * numPoints);

void lidarExpressScan();

int initLidar();

void lidarGetHealth();

void lidarGetSamplerate(char * array);

int checkC(char r);

int checkS(char r);

void responseWait(int responseLen, char * r_Array, int size);

/**
 * Finds the and checks the header
 * Strips header from raw data and places it
 * in header field
 */
int checkHeader(char * descripter, char * r_Array,
                                       int responseLen, int numPoints);

/**
 * Discards shit data
 */
void checkScanIntegrity(char * r_Array, int * numPoints);

int checkSum(char * packet);

void decodeScanResponse(char * dataArray, unsigned int * rArray, int size);

void lidarRequest();

void printHeader();

#endif
