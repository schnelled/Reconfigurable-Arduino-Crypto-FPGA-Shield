#include "aes.h"

/* defines */
#define MAX_BIN_VAL 255
#define TRIALS      20
#define VEC_SIZE    16

//Function prototype
int AES_Test();

void setup() {
  //Initialize the serial port for displaying messages
  Serial.begin(9600);
}

void loop() {
  //Obtain and display the time since the program started
  //Change name from main to ASE_Test because Arduino .ino has built in main function
  AES_Test();
}

int AES_Test()
{
  //Declare and initialize a counter and time variables
  int count = 0;
  unsigned long startTime;

  //Declare buffer and key vectors for AES
  unsigned char buf[VEC_SIZE];
  unsigned char key[VEC_SIZE];

  //Declare a key for the AES algorithm
  AES_KEY aes_ks1;

  /* Same key that OpenSSL uses for aes-128 */
  //Used for testing the functionality of AES-128 algorithm
  static const unsigned char key16[VEC_SIZE] = {
    0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
    0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x12, 
  };/* Just for testing, key is random down below */

  //Declare and initialize the variables used for benchmarking the algorithm
  int count_vector[TRIALS];
  unsigned long count_tot = 0;
  float count_avg = 0;

  /* Do x trials just for fun, change value in benchm.h */
  for(int k = 0; k < TRIALS; k++){

    //Initialize the current count vector
    count_vector[k] = 0;

    //Display information about the current trial
    Serial.print("\n\nTrial ");
    Serial.print(k+1);
    Serial.print("\n\n");

    /* Generate a random buffer to start with */
    Serial.print("\nStarting Input Vector: ");
    for(int i = 0; i < VEC_SIZE; i++){
      buf[i] = rand() % MAX_BIN_VAL;
      Serial.print(buf[i], HEX);
    }
    Serial.print("\n\n");

    /* Also uses a random key */
    Serial.print("\nStarting Key Vector: ");
    for(int i = 0; i < VEC_SIZE; i++){
      key[i] = rand() % MAX_BIN_VAL;
      Serial.print(key[i], HEX);
    }

    /* OpenSSL function, aes_core.c */
    //Expand the cipher key into encryption key schedule
    AES_set_encrypt_key(key, 128, &aes_ks1);

    //Display information the current trial has began running
    Serial.print("\n\nRunning....\n\n");

    //Initialize the Arduino timer
    startTime = millis();

    //Preform will current trial is under 3 seconds
    do {
      /* aes_core.c */
      AES_encrypt(buf,buf,&aes_ks1);
      ++count_vector[k];
    }while((millis() - startTime) < 3000);

    //Add the current trial encrptions to the count vector
    count_tot += count_vector[k];

    //Display information about the number of blocks encrypted during the past 3 seconds
    Serial.print("\n\nTotal blocks encrypted in 3 seconds: ");
    Serial.print(count_vector[k]);
    Serial.print("\n\n");

  }
  //Calculate the average number of blocks encrypted during the trials and display the information
  count_avg = count_tot / TRIALS;
  Serial.print("\n\nAverage blocks encrypted per ");
  Serial.print(TRIALS);
  Serial.print(" trials: ");
  Serial.print(count_avg);
  Serial.print("\n\n");

  //Freeze data for testing
  delay(60000);

  //Return nothing
  return 0;
}
